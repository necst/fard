# (c) copyright by Politecnico di Milano
# original authors: Samuele Barbieri, Fabiola Casasopra, Rolando Brondolin
#
# fard_node_manager.py
# This file contains classes for task management, task launch and FARD node
# management.
#
# FARD functionalities (completed and ongoing):
# - proxy network communication
#   - routing and distributed communication with pyre
#   - task naming and discovery
# - task management
#   - init local task
#   - receive task from remote
#   - kill task (from remote or from local)
#   - restart task if something goes wrong (WIP)
#   - check hardware/resource availability
# - file management
# - overlay management (WIP)
# - monitor status (WIP)
#   - health report (WIP)
#   - heartbeat (WIP)
#   - resource usage monitor (WIP)
#
# task model:
# - producers (main method that sends messages)
# - reactive consumers (code triggered when a message arrives)
# - mixed (producer code inside reactive consumer methods)

from pyre import Pyre
from pyre import zhelper
import zmq
import json
import logging
import sys
import uuid
import signal
import time
import itertools
import pickle
import shutil
import os
import yaml
import subprocess
import copy
from queue import Queue, Empty
from subprocess import STDOUT
from threading import Condition
from fard_task import FardTask
from fard_event import FardEvent
from fard_task_container import FardTaskContainer
from fard_task_container import SignalHandler

# tasks output redirect
try:
    from subprocess import DEVNULL # py3k
except ImportError:
    DEVNULL = open(os.devnull, 'wb')

# config files and base directory
BASE_DIR = str(os.path.dirname(os.path.abspath(__file__))) + "/app_folder"
CONFIG_FILE = str(os.path.dirname(os.path.abspath(__file__))) + "/node_specs.yaml"

#
# SendOutput
# This class extends FardEvent to provide an event that handles output data
# from the tasks to a single node_manager. This output is sent to the FARD
# APIs that requested it.
#
class SendOutput(FardEvent):

    # SendOutput constructor
    # It receives a thread safe output queue to push output data
    def __init__(self, output_queue, *args, **kwargs):
        self.output_queue = output_queue
        super(SendOutput, self).__init__(*args, **kwargs)

    # handle()
    # method called when a SendOutput event arrives at the node.
    # It pushes data to an output queue to the FARD APIs.
    def handle(self, content):
        self.output_queue.put(content.message, block=True)

#
# CollectOutput
# This class extends FardEvent and handles requests of output collection.
# When called, the handle event sets to the proper tasks if they have to log
# the output.
#
class CollectOutput(FardEvent):

    def __init__(self, node_manager, *args, **kwargs):
        self.node_manager = node_manager
        super(CollectOutput, self).__init__(*args, **kwargs)

    # handle()
    # method called when a CollectOutput event arrives at the node.
    def handle(self, content):
        sender = content.sender_peer
        app_id = content.message["app_id"]
        collect = content.message["set_collect"]
        self.node_manager.set_local_output_collection(app_id, collect, sender)

#
# KillApp
# This class extends FardEvent and handles events of app and tasks removal.
#
class KillApp(FardEvent):

    def __init__(self, node_manager, *args, **kwargs):
        self.node_manager = node_manager
        super(KillApp, self).__init__(*args, **kwargs)

    # handle()
    # method called when a KillApp event arrives at the node.
    def handle(self, content):
        app_id = content.message
        # check if we have the application inside the node, if yes remove it
        if app_id in self.node_manager.local_tasks.keys():
            for key, value in self.node_manager.local_tasks[app_id].items():
                value["proc_ref"].terminate()
                try:
                    value["proc_ref"].wait(2)
                except Exception as e:
                    value["proc_ref"].kill()
                    value["proc_ref"].wait()

                # clean resources and delete entry in local tasks
                self.node_manager.local_available_resources['cpu'] \
                    = self.node_manager.local_available_resources['cpu'] \
                    + value['cpu']
                self.node_manager.local_available_resources['fpga'] \
                    = self.node_manager.local_available_resources['fpga'] \
                    + value['fpga']
                del value
            del self.node_manager.local_tasks[app_id]

            # delete zip file on disk
            os.remove(BASE_DIR + '/' + app_id + ".zip")
            # delete also folder on disk
            shutil.rmtree(BASE_DIR + '/' + app_id, ignore_errors=True)

        print("app closed correctly " + content.message)

#
# LaunchCompleted
# This class extends FardEvent and is the last step of the task launch activity.
# The nodes that launched the tasks fire this event to the node manager that
# handled the task start up.
#
class LaunchCompleted(FardEvent):

    def __init__(self, *args, **kwargs):
        self.launch_completed = False
        self.end_round = False
        self.condition = Condition()
        self.tasks_count = 0
        self.reply_count = 0
        self.success_count = 0
        super(LaunchCompleted, self).__init__(*args, **kwargs)

    # handle()
    # method called when a LaunchCompleted event arrives at the node.
    def handle(self, content):
        # count how many events I received
        self.reply_count = self.reply_count + 1

        # count how many successful launches I had
        if content.message['answer'] == True:
            self.success_count = self.success_count + 1

        # if I received an answer from everybody I can close the operation
        if self.tasks_count == self.reply_count:
            if self.success_count == self.tasks_count:
                #ok, now all tasks needed are launched, I can update the status of the operation
                self.launch_completed = True
            else:
                # something went wrong, reply false and kill the app
                self.launch_completed = False

            # notify the node manager that everything went fine
            self.condition.acquire()
            self.end_round = True
            self.condition.notify()
            self.condition.release()

    # wait()
    # method called by the node manager to wait completion of task launch
    def wait(self):
        self.condition.acquire()
        while not self.end_round:
            self.condition.wait()
        self.condition.release()
        return self.launch_completed

    # reset_launch_completed()
    # prepare the system to receive events properly
    def reset_launch_completed(self, tasks_count):
        self.launch_completed = False
        self.end_round = False
        self.tasks_count = tasks_count
        self.reply_count = 0
        self.success_count = 0

#
# AbortLaunchTask
# This class extends FardEvent and is fired when a node was available to host a
# task but the task was not assigned to it.
#
class AbortLaunchTask(FardEvent):

    def __init__(self, available_resources, *args, **kwargs):
        self.available_resources = available_resources
        super(AbortLaunchTask, self).__init__(*args, **kwargs)

    # handle()
    # method called when a AbortLaunchTask event arrives at the node.
    def handle(self, content):
        # free temporary allocated resources
        msg = content.message['resources']
        self.available_resources['cpu'] = self.available_resources['cpu'] \
            + msg['cpu']
        self.available_resources['fpga'] = self.available_resources['fpga'] \
            + msg['fpga']

#
# LaunchTask
# This class extends FardEvent and is fired when the node is selected to host a
# task. The event should launch the task assigned to the node.
#
class LaunchTask(FardEvent):

    def __init__(self, node_manager, *args, **kwargs):
        self.node_manager = node_manager
        super(LaunchTask, self).__init__(*args, **kwargs)

    # handle()
    # method called when a LaunchTask event arrives at the node.
    def handle(self, content):
        newFile = open(BASE_DIR + "/" + content.message['id'] + ".zip", "wb")
        newFile.write(content.message['zip'])
        newFile.close()

        #unzip the folder here
        directory = BASE_DIR + "/" + content.message['id']
        if not os.path.exists(directory):
            os.makedirs(directory)
            shutil.unpack_archive(BASE_DIR + "/" + content.message['id'] \
                + ".zip", directory, "zip")

        #read app yaml config file
        app_config = None
        with open(directory + "/config.yaml", 'r') as stream:
            try:
                app_config = yaml.load(stream)
            except yaml.YAMLError as exc:
                print(exc)

        try:
            # for each item in the yaml task list check if it was assigned to us
            for item in app_config["tasks"]:
                task_name = item['task_name']
                task_id = task_name + "-" + str(uuid.uuid4())
                cpu = item['cpu_quota']
                fpga = item['fpga']
                task_count = item['task_count']
                main_file = item['main_file']

                if task_name == content.message["name"]:
                    # launch task
                    # redirect app logs onto stdout if requested
                    if self.node_manager.log_apps:
                        stdout_redirect = None
                    else:
                        stdout_redirect = DEVNULL

                    # launch the new task here
                    proc_ref = subprocess.Popen([self.node_manager.python_runtime, main_file, \
                        str(content.message['id']), task_id], cwd=directory, \
                        stdout=stdout_redirect, stderr=subprocess.STDOUT)

                    #here store data about the new task running
                    task_refs = {"app_id": content.message['id'], \
                        "app_name": app_config["app_name"], \
                        "task_name": task_name, "cpu": cpu, "fpga": fpga, \
                        "task_count": task_count, "main_file": main_file, \
                        "proc_ref": proc_ref, "collect_output": False, \
                        "collector_peer": None}

                    # if the app was not in the node, create an entry for it
                    if content.message['id'] not in self.node_manager.local_tasks:
                        self.node_manager.local_tasks[content.message['id']] = {}

                    #store data about local task
                    self.node_manager.local_tasks[content.message['id']][task_id] = task_refs
                    break

            # fire the launch completed event to the first node manager
            print("task launched correctly! " + content.message['id'])
            self.node_manager.launch_completed_event.fire(peer=content.sender_peer, \
                content={'answer': True}, auto_send=True)
        except Exception:
            # fire the launch completed (telling that something went wrong)
            # event to the first node manager
            print("task launch failed! " + content.message['id'])
            self.node_manager.launch_completed_event.fire(peer=content.sender_peer, \
                content={'answer': False}, auto_send=True)

#
# NodeAvailability
# This class extends FardEvent and is fired when the nodes have to reply to the
# first node that asked for availability of resources. The event should then
# start to ask to the nodes to launch tasks.
#
class NodeAvailability(FardEvent):

    def __init__(self, launch_task_event, abort_launch_event, *args, **kwargs):
        self.launch_task_event = launch_task_event
        self.abort_launch_event = abort_launch_event
        self.peer_count = 0
        self.available_count = 0
        self.reply_count = 0
        self.required_nodes = 0
        self.available_peer_list = []
        self.task = None
        self.task_id = ""
        self.task_name = ""
        self.end_round = False
        self.successfully_delevered = False
        self.condition = Condition()
        super(NodeAvailability, self).__init__(*args, **kwargs)

    # handle()
    # method called when a NodeAvailability event arrives at the node.
    def handle(self, content):
        # store how many replies we got so far
        self.reply_count = self.reply_count + 1
        if content.message['answer'] == True:
            # store also who is available
            self.available_peer_list.append(content.sender_peer)
            self.available_count = self.available_count + 1

        # if the amount of replies is equal to the number of available peers we
        # can proceed
        if self.reply_count == self.peer_count:
            # if we have enough free nodes, we can submit the tasks
            if self.required_nodes <= self.available_count:
                #iterate to all who replied yes
                fire_list = []
                abort_list = []

                for item in self.available_peer_list:
                    # select nodes to launch tasks depending on event arrival time
                    if self.required_nodes > 0:
                        fire_list.append(item)
                        self.required_nodes = self.required_nodes - 1
                    else:
                        abort_list.append(item)

                # for the first nodes up to required_nodes fire a launch task
                # event, they will launch the task for us
                for item in fire_list:
                    self.launch_task_event.fire(peer=item, \
                        content={'id': self.task_id, 'name': self.task_name, \
                        'zip': self.task}, auto_send=True)
                # for the other nodes ask to abort launch of tasks
                for item in abort_list:
                    self.abort_launch_event.fire(peer=item, \
                        content={'id': self.task_id, 'name': self.task_name, \
                        'resources': content.message['resources']}, \
                        auto_send=True)

                # clean state
                self.available_peer_list = []
                self.peer_count = 0
                self.available_count = 0
                self.reply_count = 0
                self.required_nodes = 0
                self.task = None
                self.task_id = ""
                self.successfully_delevered = True

            # notify node manager if tasks are being launching or if they aborted
            self.condition.acquire()
            self.end_round = True
            self.condition.notify()
            self.condition.release()

    # update_peer_count()
    # reset number of peers available in this case
    def update_peer_count(self, peer_count):
        self.peer_count = peer_count
        self.available_peer_list = []
        self.available_count = 0
        self.reply_count = 0

    # update_task_to_submit()
    # send here information about the task to submit, including zip archive
    def update_task_to_submit(self, id, name, task, required_nodes):
        self.task = task
        self.required_nodes = required_nodes
        self.task_id = id
        self.task_name = name
        self.successfully_delevered = False
        self.end_round = False

    # wait()
    # method called by the node_manager to wait for completion of the node
    # availability process
    def wait(self):
        self.condition.acquire()
        while not self.end_round:
            self.condition.wait()
        self.condition.release()
        return self.successfully_delevered

#
# AskForAvailability
# This class extends FardEvent and is fired when a new app must be scheduled
# on the FARD nodes. This event is fired by the node manager that is handling
# the app launch and all nodes listens for it.
#
class AskForAvailability(FardEvent):

    def __init__(self, available_event, available_resources, *args, **kwargs):
        self.available_event = available_event
        self.available_resources = available_resources
        super(AskForAvailability, self).__init__(*args, **kwargs)

    # handle()
    # method called when a AskForAvailability event arrives at the node.
    def handle(self, content):
        # here check if we have enough resources, in any case fire available_resources
        # event to notify the first node manager about the status
        msg = content.message
        if msg['cpu'] > self.available_resources['cpu']:
            self.available_event.fire(peer=content.sender_peer, \
                content={'answer': False, 'resources': msg}, auto_send=True)
        elif msg['fpga'] > self.available_resources['fpga']:
            self.available_event.fire(peer=content.sender_peer, \
                content={'answer': False, 'resources': msg}, auto_send=True)
        else:
            # book resources, so that other tasks cannot steal them
            self.available_resources['cpu'] = self.available_resources['cpu'] \
                - msg['cpu']
            self.available_resources['fpga'] = self.available_resources['fpga'] \
                - msg['fpga']
            self.available_event.fire(peer=content.sender_peer, \
                content={'answer': True, 'resources': msg}, auto_send=True)

#
# NodeManager
# This class is designed to handle the FARD distributed system. It allows to
# add, remove and recreate tasks, redirect outputs on an endpoint and allows
# to handle the communication between the distributed system and the external
# world.
#
class NodeManager(FardTask):

    def __init__(self, task_name, app_name):
        FardTask.__init__(self, task_name, app_name)
        # configurations and resources data structures
        self.config = {}
        self.local_tasks = {}
        self.local_available_resources = {}

        # node manager events declarations
        self.abort_launch_event = None
        self.launch_task_event = None
        self.node_available_event = None
        self.ask_availability_event = None
        self.kill_app_event = None
        self.collect_output_event = None
        self.send_output_event = None
        self.launch_completed_event = None

        # queues for direct task messaging and output retrieaval
        self.task_message_queue = Queue()
        self.output_queue = Queue()

        # configuration options
        self.log_apps = False
        self.python_runtime = "python3"

    #
    # task management methods
    #

    # add_app_from_local()
    # This method is called starting from the FARD APIs and drives the launch
    # of one app with all its tasks onto the FARD distributed system
    def add_app_from_local(self, path):
        # assign an ID for the application
        id = str(uuid.uuid4())
        app_config = None
        #read configuration yaml here
        with open(path + "/config.yaml", 'r') as stream:
            try:
                app_config = yaml.load(stream)
            except yaml.YAMLError as exc:
                print(exc)

        # zip the application folder
        shutil.make_archive(BASE_DIR + "/" + id, 'zip', path)
        zip_data = open(BASE_DIR + "/" + id + ".zip", "rb").read()
        delivered = False

        # iterate through the list of tasks
        for item in app_config['tasks']:
            task_name = item['task_name']
            cpu = item['cpu_quota']
            fpga = item['fpga']
            task_count = item['task_count']

            # ask for the number of available peers
            list_of_peers = self.get_network_manager().get_peers()
            node_count = len(list_of_peers) + 1
            if node_count > 0:
                # prepare the node events for the lunch task procedure
                self.launch_completed_event.reset_launch_completed(task_count)
                self.node_available_event.update_peer_count(node_count)
                self.node_available_event.update_task_to_submit(id, task_name, \
                    zip_data, task_count)
                # ask the nodes for available space
                self.ask_availability_event.fire(\
                    content={'cpu': cpu, 'fpga': fpga}, auto_send=True)
                # wait for node_available_event to finish collecting data
                delivered = self.node_available_event.wait()
                # here we should clean the state if something went wrong
                if not delivered:
                    self.delete_app(id)
                    return False
            else:
                # here we should clean the state if something went wrong
                self.delete_app(id)
                return False

        if delivered:
            # if everything ok, wait for the launch of all the tasks
            delivered = self.launch_completed_event.wait()
            if delivered:
                return id
        # here we should clean the state if something went wrong
        self.delete_app(id)
        return False

    # delete_app()
    # delete the app identified by the input key
    def delete_app(self, key):
        self.kill_app_event.fire(content=key, auto_send=True)
        return True

    # restart_app()
    # delete the app identified by the input key and restart it with the new path
    def restart_app(self, key, path):
        self.delete_app(key)
        id = self.add_app_from_local(path)
        return id

    # set_distributed_output_collection()
    # Enable or disable output collection
    def set_distributed_output_collection(self, app_id, set_collect):
        self.collect_output_event.fire(content={"app_id": app_id, \
            "set_collect": set_collect}, auto_send=True)
        return True

    # set_local_output_collection()
    # ask to all tasks belonging to the app identified by app_id to start or
    # stop the logging activity of its tasks. This method is called by the
    # CollectOutput event.
    def set_local_output_collection(self, app_id, set_collect, collector_peer):
        if app_id in self.local_tasks.keys():
            for key, value in self.local_tasks[app_id].items():
                value["collect_output"] = set_collect
                if set_collect:
                    value["collector_peer"] = collector_peer
                    self.task_message_queue.put({"app_id":app_id, \
                        "task_id":key, "command": "start_output"})
                else:
                    value["collector_peer"] = None
                    self.task_message_queue.put({"app_id":app_id, \
                        "task_id":key, "command": "stop_output"})

    # consume_output()
    # this method, starting from the app_id, retrieves logs from all the nodes
    # looking at a local queue.
    def consume_output(self, app_id):
        dequeued_events = []
        output_to_be_returned = None
        while not self.output_queue.empty():
            output_from_app = self.output_queue.get(block=False)
            if output_from_app!=None:
                if output_from_app["app_id"] == app_id:
                    # ok, I can take the output
                    output_to_be_returned = output_from_app
                    break
                else:
                    # put message inside dequeued events and re-enqueue later
                    dequeued_events.append(output_to_be_returned)

        # re-enqueue messages
        for item in dequeued_events:
            self.output_queue.put(item, block=True)

        return output_to_be_returned

    # stop()
    # method extended from FardTask that handles stop of the manager. In this
    # case we clean the state of local networking and delete the app from all
    # nodes, files and folders included.
    def stop(self):
        super(NodeManager, self).stop()
        self.poller.unregister(self.command_pipe)
        self.poller.unregister(self.tasks_pipe)
        self.command_pipe.close()
        self.tasks_pipe.close()
        #close tasks
        for key, value in self.local_tasks.items():
            for task_key, task_data in value.items():
                task_data["proc_ref"].terminate()
                try:
                    task_data["proc_ref"].wait(2)
                except Exception as e:
                    task_data["proc_ref"].kill()
                    task_data["proc_ref"].wait()
            # delete zip file on disk
            os.remove(BASE_DIR + '/' + key + ".zip")
            # delete also folder on disk
            shutil.rmtree(BASE_DIR + '/' + key, ignore_errors=True)

    # setup()
    # method extended from FardTask that handles the setup of the manager.
    def setup(self):
        #read resources available and configurations for the node manager
        with open(CONFIG_FILE, 'r') as stream:
            try:
                self.config = yaml.load(stream)
            except yaml.YAMLError as exc:
                print(exc)
        self.local_available_resources = copy.deepcopy(self.config["resources"])
        self.python_runtime = self.config["runtime"]
        self.log_apps = self.config["app_log_std_out"]
        # setup localhost pipes
        ctx = self.get_network_manager().get_zmq_context()

        cmd_addr = 'tcp://127.0.0.1:37000'
        self.command_pipe = ctx.socket(zmq.ROUTER)
        self.command_pipe.bind(cmd_addr)

        tasks_addr = 'tcp://127.0.0.1:37001'
        self.tasks_pipe = ctx.socket(zmq.ROUTER)
        self.tasks_pipe.bind(tasks_addr)

        # setup polling for ZeroMQ sockets
        self.poller = zmq.Poller()
        self.poller.register(self.command_pipe, zmq.POLLIN)
        self.poller.register(self.tasks_pipe, zmq.POLLIN)

        #create events
        self.launch_completed_event = LaunchCompleted()
        self.launch_task_event = LaunchTask(self)
        self.abort_launch_event = AbortLaunchTask(self.local_available_resources)
        self.node_available_event = NodeAvailability(self.launch_task_event, self.abort_launch_event)
        self.ask_availability_event = AskForAvailability(self.node_available_event, self.local_available_resources)
        self.kill_app_event = KillApp(self)
        self.collect_output_event = CollectOutput(self)
        self.send_output_event = SendOutput(self.output_queue)

        #register events
        self.register_event(self.launch_completed_event)
        self.register_event(self.abort_launch_event)
        self.register_event(self.launch_task_event)
        self.register_event(self.node_available_event)
        self.register_event(self.ask_availability_event)
        self.register_event(self.kill_app_event)
        self.register_event(self.collect_output_event)
        self.register_event(self.send_output_event)


    # run()
    # method extended from FardTask that handles the runtime of the fard node
    # manager. It implements a two sockets server which receives commands from
    # the APIs and exchanges data between the node manager and each task deployed
    def run(self):
        # check for availability of messages
        items = dict(self.poller.poll(100))
        # if something came from the FARD APIs reply to the request
        if self.command_pipe in items and items[self.command_pipe] == zmq.POLLIN:
            # receive command from APIs
            address, empty, message = self.command_pipe.recv_multipart()

            # interpret and execute command
            command = pickle.loads(message)
            if command["command"] == "start_app":
                id = self.add_app_from_local(command["data"])
                self.command_pipe.send_multipart([address, b'', pickle.dumps(id)])
            elif command["command"] == "stop_app":
                result = self.delete_app(command["data"])
                self.command_pipe.send_multipart([address, b'', pickle.dumps(result)])
            elif command["command"] == "restart_app":
                result = self.restart_app(command["key"], command["data"])
                self.command_pipe.send_multipart([address, b'', pickle.dumps(result)])
            elif command["command"] == "output":
                result = self.set_distributed_output_collection(command["key"], command["data"])
                self.command_pipe.send_multipart([address, b'', pickle.dumps(result)])
            elif command["command"] == "consume_output":
                result = self.consume_output(command["data"])
                self.command_pipe.send_multipart([address, b'', pickle.dumps(result)])
        # if something came from the tasks reply to the request
        elif self.tasks_pipe in items and items[self.tasks_pipe] == zmq.POLLIN:
            # receive message from FardTaskContainer
            address, empty, message = self.tasks_pipe.recv_multipart()

            # here manage if there are logs or outputs or something else
            app_message = pickle.loads(message)

            # if the message was an heartbeat, do nothing
            if app_message["command"] == "heartbeat":
                pass
            elif app_message["command"] == "output":
                # here fire events with output
                collector_peer = self.local_tasks[app_message["app_id"]][app_message["task_id"]]["collector_peer"]
                if collector_peer != None:
                    self.send_output_event.fire(peer=collector_peer, \
                        content=app_message, auto_send=True)

            # check if there are messages for the task
            # currently super expensive, can be done better
            dequeued_events = []
            something_to_send = False
            while not self.task_message_queue.empty():
                message_from_system = self.task_message_queue.get(block=False)

                if message_from_system["app_id"] == app_message["app_id"] and \
                    message_from_system["task_id"] == app_message["task_id"]:
                    # ok, I can send him new stuff
                    self.tasks_pipe.send_multipart([address, b'', \
                        pickle.dumps(message_from_system)])
                    something_to_send = True
                    break
                else:
                    # put message inside dequeued events and re-enqueue later
                    dequeued_events.append(message_from_system)

            # re-enqueue messages
            for item in dequeued_events:
                self.task_message_queue.put(item, block=True)

            if not something_to_send:
                new_message = pickle.dumps({"app_id": app_message["app_id"], \
                    "task_id": app_message["task_id"], "command": "heartbeat"})
                self.tasks_pipe.send_multipart([address, b'', new_message])


if __name__ == '__main__':
    signal_handler = SignalHandler()
    manager = NodeManager("FARD_man", "FARD_manager")
    manager.setup()

    while not signal_handler.check_exit_status():
        manager.run()
    manager.stop()
