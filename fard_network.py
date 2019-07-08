# (c) copyright by Politecnico di Milano
# original authors: Samuele Barbieri, Fabiola Casasopra, Rolando Brondolin
#
# fard_network.py
# This file provides the classes that abstracts the network layer to the tasks
# managed by the FARD distributed system.

import zmq
import uuid
from threading import Thread
from queue import Queue, Empty
from concurrent.futures import ThreadPoolExecutor
import pickle
from fard_overlay_network_manager import OverlayNetworkManager
from fard_network_data_objects import FardNetworkData, \
    FardNetworkDataAsync, FardNetworkDataSync, FardNetworkEnvelope

#
# FardNetwork
# Python class that abstracts the network layer from to the tasks. Each FARD
# task has a FardNetwork object and uses it to send messages through events.
#
class FardNetwork():

    # FardNetwork constructor
    # The method receives a service_name and a group_network. The service_name
    # is mapped to the task name, while the group_network field is mapped to
    # the app_name.
    # Here we instantiate the OverlayNetworkManager, the queue of requests that
    # should be redirected to the OverlayNetworkManager, one thread to retrieve
    # messages from the queue and send them to the OverlayNetworkManager and
    # one thread that listens for data coming from the OverlayNetworkManager.
    def __init__(self, service_name="default", group_network="default"):
        self.service_name = service_name
        self.overlay_network_name = group_network
        self.network_manager = OverlayNetworkManager(node_name=service_name,\
            overlay_network_name=group_network)
        self.network_request_queue = Queue()
        self.stop_flag = False
        self.network_thread = Thread(target=self.network_run).start()
        self.event_thread = Thread(target=self.event_run).start()
        self.event_dictionary = {}

    def get_zmq_context(self):
        return self.network_manager.ctx

    # stop()
    # this method is called when the task stops the execution and cleans the
    # network state, sending a stop message to the OverlayNetworkManager.
    def stop(self):
        # generate an asynchronous network data object
        data = FardNetworkDataAsync(str(self.overlay_network_name), "", "", "", "", False)
        # group data into a network envelope, setting the wait flag to False
        envelope = FardNetworkEnvelope(str("$$STOP"), False, data)
        # put the envelope inside the queue
        self.network_request_queue.put(envelope, block=True)
        self.stop_flag = True

    # get_peers()
    # This method collects the peers running in the same network, asking to the
    # OverlayNetworkManager to retrieve the data.
    def get_peers(self):
        # generate a synchronous network data object, we wait for results
        data = FardNetworkDataSync(str(self.overlay_network_name), "", "", "", "", False)
        # group data into a network envelope, setting the wait flag to True
        envelope = FardNetworkEnvelope(str("$$GET_PEERS"), True, data)
        # put the envelope inside the queue
        self.network_request_queue.put(envelope, block=True)
        # waiting here
        list_of_str = data.get_result().split(";")
        list_of_peers = []
        for peer in list_of_str:
            if peer != '':
                list_of_peers.append(uuid.UUID(peer))
        return list_of_peers

    # send_message()
    # This method allows events to send a message to a single peer
    def send_message(self, peer, event, message, auto_send):
        # generate an asynchronous network data object
        data = FardNetworkDataAsync(str(self.overlay_network_name), \
            "", str(peer), str(event), message, auto_send)
        # group data into a network envelope, setting the wait flag to False
        envelope = FardNetworkEnvelope(str("$$SEND_MESSAGE"), False, data)
        # waiting for successful delivery of message in the queue
        self.network_request_queue.put(envelope, block=True)

    # send_task_message()
    # This method allows events to send a message to a group of peers identified
    # by their task name
    def send_task_message(self, task_name, event, message, auto_send):
        # generate an asynchronous network data object
        data = FardNetworkDataAsync(str(self.overlay_network_name), \
            str(task_name), "", str(event), message, auto_send)
        # group data into a network envelope, setting the wait flag to False
        envelope = FardNetworkEnvelope(str("$$SEND_TASK_MESSAGE"), False, data)
        # waiting for successful delivery of message in the queue
        self.network_request_queue.put(envelope, block=True)

    # send_group_message()
    # This method allows events to send a message to all peers connected
    def send_group_message(self, event, message, auto_send):
        # generate an asynchronous network data object
        data = FardNetworkDataAsync(str(self.overlay_network_name), \
            "", "", str(event), message, auto_send)
        # group data into a network envelope, setting the wait flag to False
        envelope = FardNetworkEnvelope(str("$$SEND_GROUP_MESSAGE"), False, data)
        # waiting for successful delivery of message in the queue
        self.network_request_queue.put(envelope, block=True)

    # register_event()
    # This method allows to store event information inside FardNetwork to be
    # called when an event of the same type arrives to the peer.
    def register_event(self, event):
        self.event_dictionary[str(type(event).__name__)] = event
        event.event_registered(self)

    # get_events()
    # This method returns the dictionary of events currently registered.
    def get_events(self):
        return self.event_dictionary

    # network_run()
    # This method is the main method of the thread that handles the
    # network_request_queue. Using a thread allows to decouple the fire call
    # on the event and the actual message delivery. In this way communication
    # becomes asyncronous. This method manages also the write pipe to the
    # OverlayNetworkManager and waits for results if requested by FardNetwork
    def network_run(self):
        poller = zmq.Poller()
        poller.register(self.network_manager.get_write_pipe(), zmq.POLLIN)

        # here listen for queue messages and send data to pipe
        # if the request is a getter, then wait for data from the pipe
        while not self.stop_flag:
            try:
                envelope = self.network_request_queue.get(block=True, timeout=0.1)
                message = pickle.dumps([(str(envelope.command)), envelope.network_data.data])
                self.network_manager.get_write_pipe().send(message)
                if envelope.waiting_for_result:
                    poller.poll()
                    result = pickle.loads(self.network_manager.get_write_pipe().recv())
                    envelope.network_data.put_result(result)
            except Empty:
                pass

    # event_run()
    # This method is the main method of the thread that handles arrival of
    # external communication. In order to make communication and execution
    # asynchronous, we use a ThreadPoolExecutor to handle multiple events
    # concurrently. When a message arrives from the OverlayNetworkManager, the
    # handle() method of the corresponding event is called.
    def event_run(self):
        # create and register to poll the read pipe OverlayNetworkManager
        poller = zmq.Poller()
        poller.register(self.network_manager.get_read_pipe(), zmq.POLLIN)

        # define thread pool for event handling execution
        executor = ThreadPoolExecutor(max_workers=10)

        while not self.stop_flag:
            # poll with timeout to not hang the thread
            poll_ret = poller.poll(100)
            if poll_ret != []:
                # receive network message
                message = self.network_manager.get_read_pipe().recv()
                decoded_message = pickle.loads(message)
                # if task is set in decoded_message, check if I have to receive
                # the message, otherwise ignore it
                if decoded_message.task_name != "":
                    if decoded_message.task_name != self.service_name:
                        pass
                # get event type and fire method accordingly
                if decoded_message.event in self.event_dictionary.keys():
                    # for debugging purposes only substitute this two lines:
                    #self.event_dictionary[decoded_message.event].handle(decoded_message)
                    executor.submit(self.event_dictionary[decoded_message.event].handle, decoded_message)
        # clean resources before exiting
        executor.shutdown()
