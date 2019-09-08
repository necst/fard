# (c) copyright by Politecnico di Milano
# original authors: Samuele Barbieri, Fabiola Casasopra, Rolando Brondolin
#
# demo_app_w_task_comm.py
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
        #print("DemoData received - ml! " + content.sender_peer + " "+ str(content.message))
        time_end = time.perf_counter()
        with open("/home/xilinx/fard/demo_app/times_end_multicast_182.txt","a+") as f_end:
            f_end.write(str({"Time": time_end, "Run": content.message["Run"], "It": content.message["It"], "Sender": content.sender_peer}) + "\n")

#
# DemoApp
# This is the class of the demo application, which implements a task that sends
# events in broadcast or to a group of tasks (identified by the task name)
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
        print("bye bye")

    # run()
    # this method is the main method of the task and it is called continuously
    # by the FARD runtime to keep the task alive
    def run(self):
        # get the peers connected for this application
        #print("Demo app with task communication is alive, " + \
        #    str(self.task_name) + " peers: " + \
        #    str(self.get_network_manager().get_peers()))
        self.get_network_manager().get_peers()
        # send a task event to a group of tasks
        if(self.run_it < 60):
            msg_time_start = time.perf_counter()
            for i in range(182):
                time_start = time.perf_counter()
                self.demo_event.fire(content= {"Run": self.run_it, "It": i}, task="Demo_task_1")
                with open("/home/xilinx/fard/demo_app/times_start_multicast_182.txt","a+") as f_start:
                    f_start.write(str({"Time": time_start, "Run": self.run_it, "It": i}) + "\n")
            msg_time_end = time.perf_counter()
            time.sleep(1 - (msg_time_start - msg_time_end))
            self.run_it = self.run_it + 1
        else:
            pass

# main requested to launch the task
if __name__ == '__main__':
    # get the arguments: file name, app_id and task_id
    script_name, app_id, task_id = argv
    # create the demo task object
    demo = DemoApp("Demo_task_w_task_comm", "Demo")
    # pass the demo object to the FardTaskContainer for execution
    demo_container = FardTaskContainer(demo, app_id, task_id)
    # ask the container to execute the task and wait
    demo_container.execute()
