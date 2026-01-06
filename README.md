# MQTT: ESP32 Next Level Library Using PubSubClient <a href="https://www.ohioiot.com"><img src="https://www.ohioiot.com/images/logo.jpg" width="40" ></a>

## Overview
This library augments the PubSubClient library and gives you tools to build scalable IoT devices. The code is explained in the YouTube video [MQTT - ESP32 Next-Level Library Using PubSubClient.h](https://youtu.be/Y-h9xaIT6jM](https://youtu.be/Y-h9xaIT6jM).


👉 Subscribe to the [OhioIoT YouTube Channel](https://www.youtube.com/@OhioIoT?sub_confirmation=1) for more on "All Things IoT": hardware, firmware, connectivity, cloud computing, and dev toolkit.


## Getting Started

`git clone https://github.com/OhioIoT-MQTT-Examples/ESP32-Next-Level-Library`


### PlatformIO
- Change ***lib/credentials/credentials_template*** to ***lib/credentials/credentials.h***, and edit the credentials
- Compile and upload your code


### Arduino IDE
#### Option 1 ####
- Copy all folders in ***lib/*** to your Arduino ***libraries/*** folder
- Copy ***credentials/credentials_template*** to ***credentials/credentials.h***, and edit the credentials
- Create a project folder, and copy ***src/main.cpp*** into that folder with a name that matches, ending in *.ino
- Download PubSubClient.h using the Arduino IDE Library Manager
#### Option 2 ####
- Copy all of the files from the subfolders inside ***lib/*** into the same project folder created above, and keep all of the files, including the *.ino, together

## About
*OhioIoT is an IoT platform designed for small-scale IoT projects (https://www.ohioiot.com).*
