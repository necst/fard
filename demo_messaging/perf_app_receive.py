# (c) copyright by Politecnico di Milano
# original authors: Samuele Barbieri, Fabiola Casasopra, Rolando Brondolin
#
# demo_app.py
# This file contains a test application for FARD distributed system

import sys
from sys import argv
# this can be removed if FARD is installed with pip
sys.path.append('../../')

import time
from fard_event import FardEvent
from fard_task import FardTask
from fard_task_container import FardTaskContainer

#
# DemoEvent
# This class extends FardEvent and is used to send a demo event
#
class DemoEvent(FardEvent):

    def __init__(self, fard_task, *args, **kwargs):
        self.fard_task = fard_task
        super(DemoEvent, self).__init__(*args, **kwargs)

    # handle()
    # this method receives the messages sent by other nodes and prints something
    def handle(self, content):
        #print("DemoData received -rv!" + content.sender_peer + " "+ str(content.message))
        self.fire(peer = content.sender_peer, content= content.message)
#
# DemoApp
# This is the class of the demo application, which implements a task that sends
# events in broadcast
#
class DemoApp(FardTask):

    # DemoApp constructor
    # this method builds the task and takes as input the task name and the app
    # name
    def __init__(self, task_name, app_name):
        FardTask.__init__(self, task_name, app_name)
        self.demo_event = DemoEvent(self)
        self.demo_sender = None

    # setup()
    # the setup method is called before starting the task, and it set up the
    # events of the task
    def setup(self):
        # register event
        self.register_event(self.demo_event)

    # stop()
    # this method is called when the task is removed from execution and it should
    # clean state and gracefully close things
    def stop(self):
        super(DemoApp, self).stop()
        print("ciao ciao")

    # run()
    # this method is the main method of the task and it is called continuously
    # by the FARD runtime to keep the task alive
    def run(self):
        pass

# main requested to launch the task
if __name__ == '__main__':
    # get the arguments: file name, app_id and task_id
    script_name, app_id, task_id = argv
    # create the demo task object
    demo = DemoApp("Demo_task", "Demo")
    # pass the demo object to the FardTaskContainer for execution
    demo_container = FardTaskContainer(demo, app_id, task_id)
    # ask the container to execute the task and wait
    demo_container.execute()
