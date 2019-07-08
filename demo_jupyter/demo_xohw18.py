%matplotlib inline

import numpy as np
import sys
import zmq
import time
import os
import pickle

import matplotlib.pyplot as plt

# Use here the path where you installed fard-ds.
# If you installed fard-ds through pip3.6 shouldn't be necessary
PATH = '/home/xilinx/fard-ds/'
sys.path.append(PATH)

from fard_api import FardAPI

TIME = 300 # Time before killing all tasks [seconds]
LOG = 0
x = [] # List that keep
y1 = []
y2 = []
y3 = []
plotWidth = 10

# Instantiate the APIs
api = FardAPI()

# Connect to the local node manager
api.connect()

# Send an application to the node manager
appid = api.send_app(PATH + 'traffic_count/')
print("App id: " + str(appid))

# Ask the node manager to start sending output
api.send_set_output_collection(appid, True)
end = time.time() + TIME
while time.time() < end:
    # Consume the output
    out = api.consume_output(appid)
       
    if out == None:
        time.sleep(1)
    else: # Plot
        LOG += 1
        if LOG > plotWidth:
            x.pop(0)
            y1.pop(0)
            y2.pop(0)
            y3.pop(0)
            
        x.append(LOG)
        
        y1.append(out.get('data').get('0'))
        y2.append(out.get('data').get('1'))
        y3.append(out.get('data').get('2'))
        
        # print(out)
        plt.plot(x, y1)
        plt.plot(x, y2)
        plt.plot(x, y3)
        plt.show()

api.send_set_output_collection(appid, False)

r = api.send_kill_app(appid)
print("App closed correctly") if r else print("App still running")
api.close()