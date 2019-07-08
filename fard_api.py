# (c) copyright by Politecnico di Milano
# original authors: Samuele Barbieri, Fabiola Casasopra, Rolando Brondolin
#
# fard_api.py
# This file contains the APIs that a user can call to interact with the
# distributed system. Communication is supported only on local node managers.

import zmq
import time
import os
import pickle

#
# FardAPI
# This class contains methods to connect to, operate on and disconnect from
# a local node manager. Operations are related to task launch, task removal
# and output logging.
#
class FardAPI():

    # FardAPI constructor
    # Set up context and conntection address
    def __init__(self):
        self.node_manager_addr = 'tcp://127.0.0.1:37000'
        self.ctx = zmq.Context()

    # connect()
    # This method connects to the local FARD node manager
    def connect(self):
        self.node_pipe = self.ctx.socket(zmq.REQ)
        self.node_pipe.connect(self.node_manager_addr)
        self.poller = zmq.Poller()
        self.poller.register(self.node_pipe, zmq.POLLIN)

    # close()
    # This method closes the connection between the API and the FARD node manager.
    def close(self):
        self.poller.unregister(self.node_pipe)
        self.node_pipe.disconnect(self.node_manager_addr)
        self.node_pipe.close()

    # send_app()
    # This method sends an app to the node manager for scheduling.
    # folder_path is a string representing an absolute path on the host where
    # the application is stored. Inside the application folder it must be stored
    # a yaml config file that describes tasks, replicas and main file for each
    # task specification. The method returns a string containing the app id
    # inside the system, False if scheduling of app went wrong.
    def send_app(self, folder_path):
        self.node_pipe.send(pickle.dumps({"command": "start_app", "data": folder_path}))
        self.poller.poll()
        result = self.node_pipe.recv()
        return pickle.loads(result)

    # send_kill_app()
    # This method asks the node manager to delete an application running in the
    # FARD distributed system. The method takes as input the app id and returns
    # True if app removal was successful, False otherwise.
    def send_kill_app(self, app_id):
        self.node_pipe.send(pickle.dumps({"command": "stop_app", "data": app_id}))
        self.poller.poll()
        result = self.node_pipe.recv()
        return pickle.loads(result)

    # send_restart_app()
    # This method stops and restarts the application with the given app_id. Then
    # it restarts the application depending on the folder path specified as input.
    # The method returns the new app id.
    def send_restart_app(self, app_id, folder_path):
        self.node_pipe.send(pickle.dumps({"command": "restart_app", "key": app_id, "data": folder_path}))
        self.poller.poll()
        result = self.node_pipe.recv()
        return pickle.loads(result)

    # send_set_output_collection()
    # This method enables or disables output data collection for the application
    # identified by the input app id. output_collection is set to True to enable
    # output data collection, false otherwise.
    # The method returns True if the property was set correctly, False otherwise
    def send_set_output_collection(self, app_id, output_collection):
        self.node_pipe.send(pickle.dumps({"command": "output", "key": app_id, "data": output_collection}))
        self.poller.poll()
        result = self.node_pipe.recv()
        return pickle.loads(result)

    # consume_output()
    # This methods consumes the output of the app specified by app_id.
    # When enabling output collection, this should be used to collect data.
    def consume_output(self, app_id):
        self.node_pipe.send(pickle.dumps({"command": "consume_output", "data": app_id}))
        self.poller.poll()
        result = self.node_pipe.recv()
        return pickle.loads(result)


# example usage of the FARD APIs
if __name__ == '__main__':
    TIME = 300 # Time before killing all tasks [seconds]
    # instantiate the APIs
    api = FardAPI()
    # connect to the local node manager
    api.connect()
    # send an application to the node manager
    r = api.send_app(str(os.path.dirname(os.path.abspath(__file__))) + "/traffic_count")
    print(r)

    # ask the node manager to start sending output
    api.send_set_output_collection(r, True)
    end = time.time() + TIME
    while time.time() < end:
        # consume the output
        out = api.consume_output(r)
        if out == None:
            time.sleep(1)
        else:
            print(out)

    #
    # api.send_set_output_collection(r, False)
    # print("stopping output")
    #
    # end = time.time() + 10
    # while time.time() < end:
    #     out = api.consume_output(r)
    #     if out == None:
    #         time.sleep(1)
    #     else:
    #         print(out)
    #
    # api.send_set_output_collection(r, True)
    # print("restarting output")
    #
    # end = time.time() + 10
    # while time.time() < end:
    #     out = api.consume_output(r)
    #     if out == None:
    #         time.sleep(1)
    #     else:
    #         print(out)

    api.send_set_output_collection(r, False)

    r = api.send_kill_app(r)
    print(r)
    # r = api.send_restart_app("07974761-c04c-4bb5-8820-c05881053135", str(os.path.dirname(os.path.abspath(__file__))) + "/demo_app")
    # print(r)
    api.close()
