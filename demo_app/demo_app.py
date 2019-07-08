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

    # handle()
    # this method receives the messages sent by other nodes and prints something
    def handle(self, content):
        print("message delivered correctly! " + content.sender_peer + " "+ content.message)

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
        self.demo_event = DemoEvent()

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
        # get the peers connected for this application
        print("Demo app is alive, " + str(self.task_name) + " peers: " + \
            str(self.get_network_manager().get_peers()))
        # send a broadcast event
        self.demo_event.fire(content="event")
        # send data to the FARD APIs if output is requested
        self.send_output_data({"test_data":"test_data", "data": 1})
        time.sleep(1)

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
