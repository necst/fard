# (c) copyright by Politecnico di Milano
# original authors: Samuele Barbieri, Fabiola Casasopra, Rolando Brondolin
#
# fard_overlay_network_manager.py
# This file contains the class that handles all the communications between tasks
# in the FARD distributed system.

from pyre import Pyre
from pyre import zhelper
import zmq
import binascii
import os
import json
import logging
import sys
import uuid
import pickle

#
# OverlayNetworkManager
# This class handles network communications among tasks from the same app.
# For each task, an OverlayNetworkManager object is created to handle
# communication. The class creates a thread that receives commands from a pipe,
# sending messages coming from the network through another pipe. Both pipes
# are connected to a FardNetwork object, which abstracts the networking
# implementation.
#
class OverlayNetworkManager():

    # OverlayNetworkManager constructor
    # The method takes the node_name and the overlay_network_name, which is
    # usually mapped to the app name.
    # In this method the pyre thread and the two communication pipes are created.
    def __init__(self, node_name="default", overlay_network_name="default"):
        self.ctx = zmq.Context()

        # define read pipe here
        frontend, backend = zhelper.zcreate_pipe(self.ctx)
        self.read_pipe = backend

        self.write_pipe = zhelper.zthread_fork(self.ctx, self.network_manager, \
            node_name, overlay_network_name, frontend)
        self.node_name = node_name
        self.overlay_network_name = overlay_network_name

    def get_write_pipe(self):
        return self.write_pipe

    def get_read_pipe(self):
        return self.read_pipe

    # OverlayNetworkManager network_manager
    # This method is the main method of the thread that runs the communications.
    # The communication process is implemented through ZeroMQ, in particular
    # using pyre, which is a messaging system between network peers.
    def network_manager(self, ctx, write_pipe, node_name, overlay_network_name, read_pipe):
        # create the poller to wait for messages from pipes and network
        poller = zmq.Poller()
        poller.register(write_pipe, zmq.POLLIN)
        # create the Pyre node object
        node = Pyre(node_name + str(uuid.uuid4()))
        # register node to the network, start it and register for events with
        # the poller.
        node.join(overlay_network_name)
        node.start()
        poller.register(node.socket(), zmq.POLLIN)

        while(True):
            # do stuff, aka wait and decode messages
            items = dict(poller.poll())

            if write_pipe in items and items[write_pipe] == zmq.POLLIN:
                # here is where the thread receives internal data
                # check if we have to send something outside
                # or eventually die gracefully
                message = write_pipe.recv()
                # here I have a Command + a FardNetworkData object
                decoded_message = pickle.loads(message)

                command = decoded_message[0]
                network_data = decoded_message[1]

                if command == "$$STOP":
                    # message to quit here
                    break
                elif command == "$$GET_PEERS":
                    # only synchronous command, retrieves the peers inside the
                    # network of tasks.
                    group = network_data.group
                    peers = node.peers_by_group(group)
                    list_of_peers = []
                    for peer in peers:
                        list_of_peers.append(str(peer))
                    write_pipe.send(pickle.dumps(str(";".join(list_of_peers))))
                elif command == "$$SEND_MESSAGE" in decoded_message:
                    # send message to a single peer using Pyre
                    # if requested, send back the message to the same node that
                    # sent it.
                    peer = network_data.peer
                    network_data.sender_peer = str(node.uuid())
                    network_data.message_type = "peer"
                    node.whisper(uuid.UUID(peer), pickle.dumps(network_data))
                    if network_data.auto_send and peer == network_data.sender_peer:
                        read_pipe.send(pickle.dumps(network_data))
                elif command == "$$SEND_TASK_MESSAGE":
                    # send message to a group of identical tasks using Pyre.
                    # Currently implemented with a shout that is ignored by a
                    # receiver if the task name is different from his.
                    # if requested, send back the message to the same node that
                    # sent it.
                    network_data.sender_peer = str(node.uuid())
                    network_data.message_type = "task"
                    node.shout(group, pickle.dumps(network_data))
                    if network_data.auto_send:
                        read_pipe.send(pickle.dumps(network_data))
                elif command == "$$SEND_GROUP_MESSAGE":
                    # send message to the whole application using Pyre
                    # if requested, send back the message to the same node that
                    # sent it.
                    group = network_data.group
                    network_data.sender_peer = str(node.uuid())
                    network_data.message_type = "group"
                    node.shout(group, pickle.dumps(network_data))
                    if network_data.auto_send:
                        read_pipe.send(pickle.dumps(network_data))
            else:
                # here is where the thread receives data from the outside
                # decode messages and reroute them accordingly
                cmds = node.recv()
                msg_type = cmds.pop(0).decode('utf-8')
                peer_uuid = uuid.UUID(bytes=cmds.pop(0))
                sender_node_name = cmds.pop(0).decode('utf-8')
                if msg_type == "SHOUT":
                    group = cmds.pop(0).decode('utf-8')
                    read_pipe.send(cmds.pop(0))
                elif msg_type == "WHISPER":
                    read_pipe.send(cmds.pop(0))
                # elif msg_type == "ENTER":
                #     headers = json.loads(cmds.pop(0).decode('utf-8'))
                    # print("NODE_MSG HEADERS: %s" % headers)
                    # for key in headers:
                    #     print("key = {0}, value = {1}".format(key, headers[key]))
                    # print("NODE_MSG CONT: %s" % cmds)

        node.stop()
