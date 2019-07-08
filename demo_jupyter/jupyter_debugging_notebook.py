import cv2
import os
import numpy as np
from pynq import Overlay
from pynq import Xlnk
from pynq import MMIO
import time

# Masks on the original video
crop = False # Decide or not to crop the image
scale = True # Decide or not to scale the image
save_frames = False # Save or not .bmp frames in './frames_bmp'
video_start_frame = 25

# Crop variables
areaV = 544
areaH = 544 # Not used right now
methods=[("area", cv2.INTER_AREA), 
        ("nearest", cv2.INTER_NEAREST), 
        ("linear", cv2.INTER_LINEAR), 
        ("cubic", cv2.INTER_CUBIC), 
        ("lanczos4", cv2.INTER_LANCZOS4)]

# Scale variables - the product width*height must be multiple of 4
width = 180
height = 180
depth = 3

data_size = int((width * height * depth) / 4)

# Threshold for the foreground extraction
md_threshold = 12

# Filters tuning to remove noise
erosion = 2
dilate = 30
second_erosion = 1

# Input file names
inputVideo = "square_video.webm" # 'sqare_video.mp4'
backgroundFrame = "square_bg.bmp" # 'square_bg.bmp'
kernelBitstream = "fromFrameToBlobCount.bit" # for a 180x180 (or lower)
path = "bmp_frames" # path where the processed frames are saved

f = open('workfile_ARM+FPGA.txt', 'w+')

print("Demo started")
start_demo = time.perf_counter()

# Import video
vidcap = cv2.VideoCapture(inputVideo) # Target and capture the input video

xlnk = Xlnk()

# Import overlay
# print("Sending bitstream")
ol = Overlay(kernelBitstream)
ol.download()

# Linking DMA
dma_0 = ol.axi_dma_0

# Buffer for data transfer
input_buffer_bg = xlnk.cma_array(shape=(data_size), dtype=np.uint32)
input_buffer = xlnk.cma_array(shape=(data_size), dtype=np.uint32)
output_buffer = xlnk.cma_array(shape=1, dtype=np.uint32)

# Inizialize interface
interface = MMIO(ol.ip_dict['fromFrameToBlobCount_0']['phys_addr'], ol.ip_dict['fromFrameToBlobCount_0']['addr_range'], debug=False)

# Initialize parameters
interface.write(0x10, width)
interface.write(0x18, height)
interface.write(0x20, md_threshold)
interface.write(0x28, erosion)
interface.write(0x30, dilate)
interface.write(0x38, second_erosion)

# Import background
img_bg = cv2.imread(backgroundFrame, 1)
# a = np.asarray(img_bg) 
img_bg = np.reshape(img_bg, width*height*depth)

# Fill background buffer
start_prep = time.perf_counter()
for i in range (data_size):
    j = i*4
    input_buffer_bg[i] = (img_bg[j+3] << 24) | (img_bg[j+2] << 16) | (img_bg[j+1] << 8) | img_bg[j]

# Start core
# print("Starting core")
interface.write(0x0, 1)

# Background transfer
# print("Sending background image")
dma_0.sendchannel.transfer(input_buffer_bg)
dma_0.sendchannel.wait()

# Frames transfer

time_gap = 0

vidcap.set(cv2.CAP_PROP_POS_FRAMES, video_start_frame)
position = vidcap.get(cv2.CAP_PROP_POS_FRAMES)
print(position)

fps = vidcap.get(cv2.CAP_PROP_FPS)
print(fps)

total_frames = vidcap.get(cv2.CAP_PROP_FRAME_COUNT)
print(total)


next_frame = int(video_start_frame + (time_gap * fps))

vidcap.set(cv2.CAP_PROP_POS_FRAMES, next_frame)
(success, img) = vidcap.read() # Take a frame

count = video_start_frame;
while success: #and count < num_frame +1 :
    start_frame = time.perf_counter()
    if(True): #count != video_start_frame): #and count % 10 == 0):        
       
        start_processing = time.perf_counter()
        # Crop image to the desired area
        if crop: # crop = False
            img = img[areaV : ]
        
        # Scale image
        if scale: # scale = True
            img = cv2.resize(img, (width, height), interpolation = cv2.INTER_LANCZOS4)
        
        # if save_frames:
            # imgToSave = img
        
        # img = np.asarray(img)
        img = np.reshape(img, width*height*depth)
        
        # Fill frame buffer
        # print("Sending frame " + str(count) + " to FPGA")
        for i in range (data_size):
            j = i*4
            input_buffer[i] = (img[j+3] << 24) | (img[j+2] << 16) | (img[j+1] << 8) | img[j]

        
        dma_0.sendchannel.transfer(input_buffer)
        # dma_0.sendchannel.wait()

        dma_0.recvchannel.transfer(output_buffer)
        dma_0.recvchannel.wait()
        
        end_processing = time.perf_counter()

        #print_dma_status()
        # print("Frame number: " + str(count))
        # print("    Cars: " + str(int(output_buffer)))
        # print("")
        
        # if save_frames:
            # try:
                # os.stat(path)
            # except:
                # os.mkdir(path)
            # cv2.imwrite(os.path.join(path, "frame" + str(count) + "-cc" + str(int(output_buffer)) + ".bmp"), imgToSave)
        
    count += 1
    time_gap = end_processing - start_processing
    print(time_gap)
    next_frame += int(video_start_frame + (time_gap * fps))
    print(next_frame)
    
    # Loop the video
    if(next_frame > total_frames):
        next_frame = video_start_frame    
    
    vidcap.set(cv2.CAP_PROP_POS_FRAMES, next_frame)
    success, img = vidcap.read() # Take the following frame
    
    end_frame = time.perf_counter()
    f.write("frame_time:" + str(end_frame - start_frame) + "\n")
    f.write("processing_time: " + str(end_processing - start_processing) + "\n")
    
end_demo = time.perf_counter()
f.write("total_time: " + str(end_demo - start_demo) + "\n")
print("finished")