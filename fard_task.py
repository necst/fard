# (c) copyright by Politecnico di Milano
# original authors: Samuele Barbieri, Fabiola Casasopra, Rolando Brondolin
#
# fard_task.py
# This file contains classes useful to implement tasks runing inside the FARD
# distributed system.

from fard_network import FardNetwork
from fard_event import FardEvent
import zmq
from queue import Queue

#
# FardTask
# Python class for the superclass definition of a task in the FARD distributed
# system. Every FARD task that should run under the FARD control should extend
# this base class.
# To create a task subclass, the subclass should override setup(), run() and
# stop(). The main method of the task should instantiate the task subclass
# object, instantiate a FardTaskContainer for that task adding task id and
# app id that are passed through argv, and finally call execute() on
# the FardTaskContainer object.
#
class FardTask():

    # FardTask constructor
    # input: task name, app name
    # the app name should be the same for all the tasks defined inside the app
    def __init__(self, task_name, app_name):
        self.task_name = task_name
        self.app_name = app_name
        self.setup_done = False
        self.send_output = False
        self.output_queue = Queue()
        self.network_manager = FardNetwork(\
            service_name=self.task_name, group_network=self.app_name)

    #
    # Getters of FardTask properties
    #

    def get_task_name(self):
        return self.task_name

    def get_app_name(self):
        return self.app_name

    def get_network_manager(self):
        return self.network_manager

    # register event registers an event that the task should listen on the
    # network. This allows communication among tasks in the distributed system.
    # the event attribute should be a FardEvent or a FardEvent subclass object.
    def register_event(self, event):
        if self.setup_done:
            raise Exception("Unable to register event after application setup")
        self.network_manager.register_event(event)


    # The setup method should be reimplemented by the extended class and it is
    # used to setup the task (e.g. load configurations and bitstreams).
    # Events should be registered inside this methods
    def setup(self):
        pass

    # Internal method called after setup. After this method is called, no more
    # events can be registered on the system for the task
    def setup_completed(self):
        self.setup_done = True

    # The run method should be reimplemented by the subclass.
    # run is the main event of the task. it is called continuously by the FARD
    # distributed system. Normal activities of the task should happen within
    # this method (e.g. reading sensors data, sending messages)
    def run(self):
        pass

    # The stop method is called when the task is removed from the system and
    # should be reimplemented by the subclass. Within this method, all cleaning
    # activities should be performed.
    def stop(self):
        self.network_manager.stop()

    # set_send_output is an internal method used to change settings about output
    # retireval. This should not be called by the subclass.
    def set_send_output(self, send):
        self.send_output = send

    # This method should be used by the subclass to send output to the API
    # caller. In this way, the output can reach the FARD APIs and can be used
    # inside jupyter notebooks.
    def send_output_data(self, content):
        if self.send_output:
            self.output_queue.put(content, block=True)
