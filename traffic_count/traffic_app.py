# (c) copyright by Politecnico di Milano
# original authors: Samuele Barbieri, Fabiola Casasopra, Rolando Brondolin
#
# traffic_app.py
# This file contains the software code for the traffic count app.

import os
import cv2
import sys
from sys import argv
# this can be removed if FARD is installed with pip
sys.path.append('../../')

import netifaces
import time
import yaml
import random
import time
import numpy as np

from pynq import Overlay
from pynq import Xlnk
from pynq import MMIO

from fard_event import FardEvent
from fard_task import FardTask
from fard_task_container import FardTaskContainer

# FILE PATH DEFINITION
CONFIG_FILE = str(os.path.dirname(os.path.abspath(__file__))) + "/traffic_map.yaml"
BITSTREAM = str(os.path.dirname(os.path.abspath(__file__))) + "/fromFrameToBlobCount.bit"
VIDEO = str(os.path.dirname(os.path.abspath(__file__))) + "/square_final.webm"
BACKGROUND = str(os.path.dirname(os.path.abspath(__file__))) + "/square_bg.bmp"
PATH = "bmp_frames" # path where the processed frames are saved

## CONSTANTS DEFINITION
# Masks on the original video
crop = False # Decide or not to crop the image
scale = True # Decide or not to scale the image
save_frames = False # Save or not .bmp frames in './frames_bmp'
sync = True # Run at the same frame rate as the video

video_start_frame = 20 # Start video at a certain frame
write = False

# Crop variables
areaV = 544
areaH = 544 # Not used right now
methods=[("area", cv2.INTER_AREA), 
        ("nearest", cv2.INTER_NEAREST), 
        ("linear", cv2.INTER_LINEAR), 
        ("cubic", cv2.INTER_CUBIC), 
        ("lanczos4", cv2.INTER_LANCZOS4)]

# Scale variables
width = 180
height = 180
depth = 3

data_size = int((width * height * depth) / 4) # Data size in [Byte]

# Threshold for the foreground extraction
md_threshold = 10 #12

# Filters tuning to remove noise
erosion = 0 #2
dilate = 18 #30
second_erosion = 0 #1

# Action variable
load = 0       # When sending background
process = 1    # When processing frames

#
# CarsCount
# This class extends FardEvent and is used to send the number of cars counted
# by each node to the next one.
#
class CarsCount(FardEvent):

    # CarsCount constructor
    # the method takes as input the task to update its transit_cars counter
    def __init__(self, traffic_monitor_task, *args, **kwargs):
        self.traffic_monitor_task = traffic_monitor_task
        super(CarsCount, self).__init__(*args, **kwargs)

    # handle()
    # method called when the event arrives at the node, update the number of
    # cars in transit.
    def handle(self, content):
        #print("CarsCount received! " + content.sender_peer + " "+ str(content.message))
        self.traffic_monitor_task.transit_cars = \
            self.traffic_monitor_task.transit_cars + content.message

#
# FlowStatus
# This class extends FardEvent and is used to send the number of estimated
# cars on the road between two nodes.
#
class FlowStatus(FardEvent):

    # CarsCount constructor
    # the method takes as input the task to update the flow status
    def __init__(self, traffic_monitor_task, *args, **kwargs):
        self.traffic_monitor_task = traffic_monitor_task
        super(FlowStatus, self).__init__(*args, **kwargs)

    # handle()
    # this method is called only on the last task, as the other tasks sends it
    # only to him. Here update the flow status.
    def handle(self, content):
        print("######## Traffic status at channels ########")
        # update the status here
        self.traffic_monitor_task.flow_status[str(content.message["index"])] = content.message["transit"]

        # print overall status
        for i in range(0, self.traffic_monitor_task.node_count):
            print("channel: " +str(i-1)+ " - " + str(i) + ", count: " + str(self.traffic_monitor_task.flow_status[str(i)]))
        print("######## Traffic status at channels ########")
        # send flow status to the FARD APIs if requested
        self.traffic_monitor_task.send_output_data(self.traffic_monitor_task.flow_status)

#
# WhoAmI
# This class extends FardEvent and is used to self organize the nodes w.r.t.
# their IP. From the IP the node understands its position in the flow and tells
# the position to the others. The handle event registers the next node in the
# line (to send CarsCount events) and the last node (to send FlowStatus events).
#
class WhoAmI(FardEvent):

    # WhoAmI constructor
    # the method takes as input the task to update data about peers
    def __init__(self, traffic_monitor_task, *args, **kwargs):
        self.traffic_monitor_task = traffic_monitor_task
        super(WhoAmI, self).__init__(*args, **kwargs)

    # handle()
    # the method is called when peers are self organizing w.r.t the order and
    # the recognition of the last peer in the line.
    def handle(self, content):
        #print("whoami received! " + content.sender_peer + " "+ str(content.message))

        # if the sender is my next peer, save its uuid
        if content.message == self.traffic_monitor_task.position + 1:
            self.traffic_monitor_task.next_peer = content.sender_peer

        # if the last peer sent this message, then register uuid as last peer
        if content.message == self.traffic_monitor_task.node_count - 1:
            self.traffic_monitor_task.last_peer = content.sender_peer

            # if the last peer is also myself, then I finished
            if self.traffic_monitor_task.position == content.message:
                self.traffic_monitor_task.internal_setup_done = True

        # if I have both next and last peer, I finished setup
        if self.traffic_monitor_task.next_peer != None \
            and self.traffic_monitor_task.last_peer != None:
            self.traffic_monitor_task.internal_setup_done = True

#
# TrafficMonitorTask
# This is the main task of the traffic count app. This class is launched on all
# nodes. At first it set up the bitstream and then connects to the other nodes
# using a config file with the nodes IP to understand the order on the route.
# Then, each task communicate with the subsequent, sending data about how many
# cars it saw in the last frame. At the same time it sends the flow status
# between itself and the previous node to the last node.
#
class TrafficMonitorTask(FardTask):

    # TrafficMonitorTask constructor
    # It takes the task name and the app name, setting up internal status and
    # events
    def __init__(self, task_name, app_name):
        FardTask.__init__(self, task_name, app_name)
        # configuration map
        self.config = None
        # status about next and last peer
        self.position = -1
        self.transit_cars = 0
        self.flow_status = {}
        self.next_peer = None
        self.last_peer = None
        self.last = False
        self.node_count = -1
        # flag to understand if we have finished setup
        self.internal_setup_done = False
        # instantiate events
        self.cars_count_event = CarsCount(self)
        self.flow_status_event = FlowStatus(self)
        self.whoami_event = WhoAmI(self)

        # app and accelerator parameters
        self.video_input = False
        self.vidcap = None
        self.fcount = 0
        self.input_buffer = None
        self.output_buffer = None
        self.dma0 = None
        self.interface = None

        # real-time correction parameters
        self.next_frame = None
        self.time_gap = None
        self.fps = None
        self.total_frames = None


    # setup()
    # this method is called when the task is started, it reads a config file
    # and set up the accelerator and the events
    def setup(self):
        print("setup")
        # read the config file
        with open(CONFIG_FILE, 'r') as stream:
            try:
                self.config = yaml.load(stream)
            except yaml.YAMLError as exc:
                print(exc)

        # obtain the list of IPs of the host
        ips = [netifaces.ifaddresses(iface)[netifaces.AF_INET][0]['addr'] \
            for iface in netifaces.interfaces() \
            if netifaces.AF_INET in netifaces.ifaddresses(iface)]

        # obtain the position in the line from config file and IP
        position = 0
        for item in self.config["nodes"]:
            if item["ip"] in ips:
                break
            position = position + 1
        self.node_count = len(self.config["nodes"])
        self.position = position

        # If this task is the last in line, instantiate the flow status dictionary
        if self.position == self.node_count - 1:
            self.last = True
            #init flow dictionary
            pos = 0
            for item in self.config["nodes"]:
                self.flow_status[str(pos)] = 0
                pos = pos + 1

        # register events for communication
        self.register_event(self.cars_count_event)
        self.register_event(self.flow_status_event)
        self.register_event(self.whoami_event)

        # wait not to kill setup of the other nodes
        if self.last:
            time.sleep(1)

		# Import video
        self.vidcap = cv2.VideoCapture(VIDEO) # Target and capture the input video
        # Set video parameters
        self.time_gap = 0
        self.fps = self.vidcap.get(cv2.CAP_PROP_FPS)
        self.total_frames = self.vidcap.get(cv2.CAP_PROP_FRAME_COUNT)
        self.next_frame = video_start_frame

        xlnk = Xlnk()

        # Import overlay
        print("Sending bitstream")
        ol = Overlay(BITSTREAM)
        ol.download()

        # Linking DMA
        self.dma_0 = ol.axi_dma_0

        # Buffer for data transfer
        input_buffer_bg = xlnk.cma_array(shape = (data_size), dtype = np.uint32)
        self.input_buffer = xlnk.cma_array(shape = (data_size), dtype = np.uint32)
        self.output_buffer = xlnk.cma_array(shape = 1, dtype = np.uint32)

        # Initialize interface
        self.interface = MMIO(ol.ip_dict['fromFrameToBlobCount_0']['phys_addr'], ol.ip_dict['fromFrameToBlobCount_0']['addr_range'], debug = False)

        # Initialize parameters
        self.interface.write(0x10, load)
        self.interface.write(0x18, md_threshold)
        self.interface.write(0x20, erosion)
        self.interface.write(0x28, dilate)
        self.interface.write(0x30, second_erosion)

		# Import background
        img_bg = cv2.imread(BACKGROUND, 1)
        img_bg = np.reshape(img, width*height*depth)

        # Fill background buffer
        img_bg.dtype=np.uint32
        input_buffer_bg[:] = img_bg[:]

        # Starting core
        print("Starting core")
        self.interface.write(0x0, 1)

        # Sending background
        print("Sending background")
        self.dma_0.sendchannel.transfer(input_buffer_bg)
        self.dma_0.sendchannel.wait()

        # Prepare to process images
        self.interface.write(0x10, process)

        # Initialize channels to process images
        self.dma_0.sendchannel.transfer(self.input_buffer)
        self.dma_0.recvchannel.transfer(self.output_buffer)

    # stop()
    # this method is called when the system stops the task. Clean everything
    # and call superclass stop method
    def stop(self):
        super(TrafficMonitorTask, self).stop()
        print("closing traffic monitoring task")

    # run()
    # this is the main method of the task and is continuously called. If not
    # done yet, set up ordering of peers, then collect data from accelerator
    # and start send events to the other nodes.
    def run(self):
        # setup ordering of nodes
        while not self.internal_setup_done:
            self.whoami_event.fire(content=self.position, auto_send=True)
            time.sleep(0.1)

        # get cars from accelerator
        outgoing_cars = self.get_car_count()
        # compute the transit cars in the flow from the previous node to our
        self.transit_cars = self.transit_cars - outgoing_cars
        # If this peer is not the last, send outgoing cars to the next peer
        if self.next_peer != None:
            self.cars_count_event.fire(peer=self.next_peer, content=outgoing_cars)
        # send the amount of cars in transit to the last node, even if we are
        # the last node in the line
        self.flow_status_event.fire(peer=self.last_peer, content={"index": self.position, "transit": self.transit_cars}, auto_send=True)

    # get_car_count()
    # this method prepares the video image using opencv and then sends a frame
    # to the accelerator, waiting for result
    def get_car_count(self):
        # Set the tight frame to take, at the beginning next_frame = video_start_frame
        self.vidcap.set(cv2.CAP_PROP_POS_FRAMES, self.next_frame)
        # Take next frame to be processed
        (self.video_input, img) = self.vidcap.read()

        if self.video_input:
            # Start fpga core
            self.interface.write(0x0, 1)

            # Take the start time to calculate the processing gap (time_gap)
            start_processing = time.perf_counter()
            print("entered img processing")

            # Scale image only if scale is True
            if scale: # scale = True
                img = cv2.resize(img, (width, height), interpolation = cv2.INTER_LANCZOS4)

            # Reshape to np.array
            img = np.reshape(img, width * height * depth)

            # Fill frame buffer
            print("Sending frame " + str(self.fcount) + " to FPGA")
            img.dtype=np.uint32
            self.input_buffer[:] = img[:]

            # Send data to FPGA
            self.dma_0.sendchannel.wait()

            # Receive data from FPGA
            self.dma_0.recvchannel.wait()

            if save_frames:
                try:
                    os.stat(PATH)
                except:
                    os.mkdir(PATH)
                cv2.imwrite(os.path.join(PATH, "frame" + str(self.fcount) + "-cc" + str(int(self.output_buffer)) + ".bmp"), imgToSave)

            self.fcount += 1
            print("    Cars: " + str(int(self.output_buffer)))

            # Take the end time to calculate the processing gap (time_gap)
            end_processing = time.perf_counter()
            # Update parameters
            self.time_gap = end_processing - start_processing
            self.next_frame += int(video_start_frame + (self.time_gap * self.fps))

            #Loop the video
            if(self.next_frame >= self.total_frames):
                self.next_frame = video_start_frame

            return int(self.output_buffer)
        return 0


# main requested to launch the task
if __name__ == '__main__':
    # get the arguments: file name, app_id and task_id
    script_name, app_id, task_id = argv
    # create the traffic monitor task object
    traffic = TrafficMonitorTask("monitor_traffic_task", "TrafficApp")
    # pass the traffic object to the FardTaskContainer for execution
    traffic_container = FardTaskContainer(traffic, app_id, task_id)
    # ask the container to execute the task and wait
    traffic_container.execute()
