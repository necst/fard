# (c) copyright by Politecnico di Milano
# original authors: Samuele Barbieri, Fabiola Casasopra, Rolando Brondolin
#
# fard_task_container.py
# Internal classes to manage tasks during their execution

import threading
import zmq
import time
import pickle
import signal
from queue import Queue, Empty
from fard_task import FardTask

#
# SignalHandler
# This class is used to capture termination and interrupt signals, propagating
# the signal to stop all the threads of the tasks
#
class SignalHandler():

    def __init__(self):
        self.exit = False
        signal.signal(signal.SIGINT, self.exit_gracefully)
        signal.signal(signal.SIGTERM, self.exit_gracefully)

    def exit_gracefully(self, signum, frame):
        self.exit = True

    def check_exit_status(self):
        return self.exit

#
# FardTaskContainer
# This class contains and executes the FARD tasks, handling run, setup and
# termination of tasks, as well as proxying the output to the local node manager
#
class FardTaskContainer():

    # FardTaskContainer constructor, takes the task object, which is a FardTask
    # subclass, the app id and the task id. The constructor creates two threads,
    # one for the task itself, the other for communication with the node
    # manager.
    def __init__(self, task, app_id, task_id):
        self.task = task
        self.app_id = app_id
        self.task_id = task_id
        self.task.setup()
        self.task.setup_completed()
        self.handler = SignalHandler()
        self.thread = threading.Thread(target=self.run_task).start()
        self.thread_checks = threading.Thread(target=self.run_checks).start()

    # run_task is the main method that handles the task run method
    def run_task(self):
        while not self.handler.check_exit_status():
            self.task.run()
        self.task.stop()

    # run_checks is the main method for the communication thread
    def run_checks(self):
        # connect to the pipe with the node manager
        ctx = zmq.Context()
        task_addr = 'tcp://127.0.0.1:37001'
        task_pipe = ctx.socket(zmq.REQ)
        task_pipe.connect(task_addr)
        poller = zmq.Poller()
        poller.register(task_pipe, zmq.POLLIN)

        # do stuff and take the thread alive
        while not self.handler.check_exit_status():
            # check if we have to send some output
            if self.task.send_output:
                try:
                    output_data = self.task.output_queue.get(block=True, timeout=1)
                    task_pipe.send(pickle.dumps({"app_id": self.app_id, \
                        "task_id": self.task_id, "command": "output", \
                        "data": output_data}))
                except Empty:
                    #ok, the thing is empty, send a heartbeat
                    task_pipe.send(pickle.dumps({"app_id": self.app_id, \
                    "task_id": self.task_id, "command": "heartbeat"}))
            else:
                # ok, nothing to send, just tell I am alive
                task_pipe.send(pickle.dumps({"app_id": self.app_id, \
                "task_id": self.task_id, "command": "heartbeat"}))

            # wait for reply from the node manager
            items = dict(poller.poll())
            if task_pipe in items and items[task_pipe] == zmq.POLLIN:
                # retireve message content
                message = pickle.loads(task_pipe.recv())
                # check if we have to start or stop sending output from task
                if message["command"] == "start_output":
                    self.task.send_output = True
                if message["command"] == "stop_output":
                    self.task.send_output = False

            # if we do not have to send output, we can just sleep for a second
            if not self.task.send_output:
                time.sleep(1)

        # when the thread exits, clean status
        poller.unregister(task_pipe)
        task_pipe.disconnect(task_addr)
        task_pipe.close()

    # this method should be called by the main thread of the task,
    # which has to create the task object, the task container object and
    # then it can hold.
    def execute(self):
        while not self.handler.check_exit_status():
            time.sleep(1)
