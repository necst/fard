# FARD: Fog Acceleration Through Reconfigurable Devices

This is the repository of FARD. FARD is a fog computing distributed system to run heterogeneous fog computing applications on FPGAs. The distributed system works with the PYNQ-Z1 board and software stack, although it can be adapted for any linux system. FARD is a tool built at [NECSTLab](https://necst.it).


## Contents and repository structure

This repository contains the software code of the distributed system and the code needed to generate the bitstream for the counting cars application.

- *traffic_count_hw_design* contains the c++ code and the vivado projects to synthesize the hw accelerator
- *traffic_count* contains the counting cars application that runs on top of FARD (with bitstream and tcl files for the PYNQ-Z1)
- *demo_app* contains some examples on how to build a FARD fog application
- *demo_jupyter* contains code to control the counting cars application from a jupyter notebook

## Dependencies (PYNQ)

You need to have your PYNQ boards up and running, and for each of them install these dependencies:

 - python3 and pip3: sudo apt-get install python3 python3-pip
 - install zeromq: sudo apt-get install libzmq3-dev
 - install python bindings for zeromq: sudo pip3.6 install pyzmq
 - install pyre: sudo pip3.6 install https://github.com/zeromq/pyre/archive/master.zip
 - install uuid: sudo pip3.6 install uuid
 - install pyyaml: sudo pip3.6 install pyyaml
 - install netifaces: sudo pip3.6 install netifaces

## Running FARD (and the counting cars app)

### Run on PYNQ board
 - Download on your computer the repository our FARD code and do the following:
  - If you generated the bitstream you need to put your `fromFrameToBlobCount.bit` and `fromFrameToBlobCount.tcl` toghether in `fard/traffic_count/`. You also need to rename them as is, or change the `BITSTREAM` variable consequently in the `fard/traffic_count/traffic_app.py`.
  - Reach the file `fard/traffic_count/config.yaml` and modify the parameter `task_count` to the number of the PYNQ boards you intend to use. For example if you want to use three PYNQ boards you will write `task_count: 3`.
  - Reach the file `fard/traffic_count/traffic_map.yaml` and insert all and only the IP addresses of all the PYNQ board you connected to the
 - Connect all the PYNQ boards you decided to use and your computer to the same local network.
 - Make sure you installed all the dependencies above.
 - Copy the project main directory in every PYNQ.
From now on you can decide either to run the demo from terminal or from Jupyter.

#### From terminal
 - On each PYNQ run the command `sudo python3.6 fard/fard_node_manager.py`. This will launch the fard node manager. NOTE: you need to do this on all the board you intend to use.
 - From another terminal `ssh` to a PYNQ board with the fard node manager up and running and run the command `sudo python3.6 fard/fard_api.py`. This will distribute the tasks and will start data and output collection.

#### From Jupyter
 - With your computer open a browser and in the addresses bar input the IP address of one of the PYNQ board you intend to use. It will show a Jupyter interface.
 - Create a new 'Python 3' notebook and paste the code in `fard/demo_jupyter/demo_xohw18.py`.
 - You may need to change some plot parameters based on the number of PYNQ board you use. The example uses three PYNQ boards.
 - On each PYNQ run the command `sudo python3.6 fard/fard_node_manager.py`. This will launch the fard node manager. NOTE: you need to do this on all the board you intend to use, included the one with the created notebook.
 - Go back to the notebook you created, select the piece of code you pasted and press `Run`.

## Publications

- More details on the counting cars application can be found at "S. Barbieri, F. Casasopra, R. Brondolin, and M. D. Santambrogio, “Fog Acceleration Through Reconfigurable Devices,” in Research and Technologies for Society and Industry (RTSI), 2019 IEEE 5th International Forum on. IEEE, 2019, pp. 138–143."

- More details on the FARD distributed system can be found at "S. Barbieri, F. Casasopra, R. Brondolin, and M. D. Santambrogio, “FARD: Accelerating Distributed Fog Computing Workloads through Embedded FPGAs,” in EWiLi 2019"

If you use the distributed system and/or the counting cars application, we ask that you please cite the papers above.
