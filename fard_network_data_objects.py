# (c) copyright by Politecnico di Milano
# original authors: Samuele Barbieri, Fabiola Casasopra, Rolando Brondolin
#
# fard_network_data_objects.py
# This file contains classes useful to host data that should be sent over the
# network of the FARD distributed system.

from threading import Condition

#
# FardNetworkData
# This is the class that hosts the raw data that the task wants to send to other
# peers. The data coming from the tasks is stored in the message field, while
# group, task_name and peer are used by FardNetwork to store data about the
# receiver. auto_send is set as a parameter of the events fire method to allow
# auto send of envents. sender_peer and message_type are set by the sender to
# identify the sender peer and the message type respectively.
#
class FardNetworkData():

    def __init__(self, group, task_name, peer, event, message, auto_send):
        self.group = group
        self.task_name = task_name
        self.peer = peer
        self.event = event
        self.message = message
        self.auto_send = auto_send
        self.sender_peer = None
        self.message_type = None

#
# FardNetworkDataAsync
# This class encapsulates FardNetworkData and tells the system that it should
# not wait for a reply by the other peers.
#
class FardNetworkDataAsync():

    def __init__(self, group, task_name, peer, event, message, auto_send):
        self.data = FardNetworkData(group, task_name, peer, event, message, auto_send)

#
# FardNetworkDataSync
# This class encapsulates FardNetworkData and tells the system that it should
# wait for replies from other peers.
#
class FardNetworkDataSync():

    # FardNetworkDataSync constructor
    # the constructor takes the field that should be set inside FardNetworkData
    # and initializes the synchronization process on the sender side
    def __init__(self, group, task_name, peer, event, message, auto_send):
        self.condition = Condition()
        self.data_available = False
        self.data = FardNetworkData(group, task_name, peer, event, message, auto_send)

    # get_result()
    # This method is called by the sender inside FardNetwork to wait for a result
    def get_result(self):
        self.condition.acquire()
        while not self.data_available:
            self.condition.wait()
        self.data_available = False
        self.condition.release()
        return self.data

    # put result()
    # This method is called when the reply comes from OverlayNetworkManager and
    # notifies FardNetwork of some data available.
    def put_result(self, data):
        self.condition.acquire()
        self.data_available = True
        self.data = data
        self.condition.notify()
        self.condition.release()

#
# FardNetworkEnvelope
# This class encapsulates either FardNetworkDataAsync or FardNetworkDataSync
# within FardNetwork threads.
#
class FardNetworkEnvelope():

    def __init__(self, command, wait, network_data):
        self.command = command
        self.waiting_for_result = wait
        self.network_data = network_data
