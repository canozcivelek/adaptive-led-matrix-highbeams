# Adaptive LED Matrix High Beams

## Project Description & Objective

This project was created to demonstrate a more sophisticated approach to modern/standard headlight technology used in present cars.
In addition to having mandatory low and high beams, this project aims to demonstrate how the flexibility of LEDs can be used to create safer driving environment under low light/dark conditions. The main objective of this technology is to illuminate as much of the 
road as possible while not dazzling other drivers for both oncoming and preceding traffic.
This is made possible in this project with 2 sub-systems in communication. 
First is the module to control the hardware (LED matrix), second is 
a camera feed with a trained object detection model to detect vehicles, locate them and determine where to lighten/darken.

#### [**Demo Video**](https://youtu.be/6VwgZgbertE) (Click to see the full video)

![](https://imgur.com/a9QZYnO.gif)

---

## Getting Started

To get this project up and running on your local machine, first, download both LEDController and Python folders. 
* [LEDController](LEDController) folder includes the file for an Arduino microcontroller and is responsible for controlling the LED matrix module based on the input from vehicle detection part (Python).
* [Python](Python) folder includes the Python script vehicleDetect.py for vehicle detection, an inference graph for the pretrained model and a label_map.pbtxt file to map the labels.

Once you're done downloading these folders, software part of this project would be complete. 
Hardware components used in this project is an Arduino UNO microcontroller, LED matrix (CJMCU 64 Bit WS2812 5050 RGB LED Driver Development Board), a headlight projector lens, cables and a USB webcam. See **Deployment** for notes on how to deploy the project in more detail.

#### Prerequisites
To successfully run the project, it is required to have the following software and their respective versions installed:
* Arduino IDE (https://www.arduino.cc/en/main/software)
* Python 3.6 or higher (https://www.python.org/downloads/)
* Tensorflow Object Detection API included in their models repository (https://github.com/tensorflow/models)
* Microsoft Visual Studio (https://visualstudio.microsoft.com/free-developer-offers/)

#### Dependencies and Environment
It should be noted that this project was developed on a Microsoft Windows 10 (64 Bit) machine, however, it should work on other platforms too with minor tweaks here and there. As for Python packages, OpenCV3, Tensorflow 1.10.0, Numpy 1.14.5, PyAutoGUI 0.9, Serial 0.0.70, Utils 0.9.0 should be installed via pip3 or any other preferred way. For Arduino to control the LED matrix, FastLED.h library should be installed.

## How the Code Works
A webcam feed is provided to the Python script ```vehicleDetect.py``` where it analyzes the road and the pretrained model recognizes vehicles (basically headlights and taillights) and wraps them around with a bounding box. The x coordinates of detected vehicles are stored in variables called medX1 (first detected vehicle) and medX2 (second detected vehicle) the name of these variables come from taking medium of the first and third indices of object called "boxes" which are xmin & xmax. To make the model recognize vehicles at night, over 500 images of traffic at night was used to train the model using _ssd_inception_v2_coco_ provided by Tensorflow. After storing the positions of detected vehicles, there is four possible conditions to be handled:
```
1. If only 1 vehicle is detected,
2. If only 2 vehicles are detected,
3. If more than 2 vehicles are detected,
4. If no vehicles are detected.
```

Based on these conditions, a specific variable is constructed called posX. As mentioned before, the system can handle a maximum of 2 vehicles simultaneously. That is why the posX variable has a length of 3 characters, first of which is constant 'x', second of which is 'y' if single vehicle detected, or a position from 0-8 if a second vehicle is also detected, and the third always holds the position of the single/first vehicle detected. After the final value of posX is constructed, it is then written onto the serial object called 'ser' to be sent over serial port (in this case COM3) and to be received by Arduino microcontroller to actuate LEDs individually. The LED module consists of 64 individual LED chips but for this project, only 32 of them are reserved for the "high beams", whereas the remaining 32 can be considered as low beams which are always turned ON. So we are dealing with 32 LED chips in 4 rows and 8 columns. To provide a glare-free environment for other drivers, the 32 LEDs are divided into 8 columns all of which can be individually turned ON/OFF. Having received (LEDController.ino) the positions of detected vehicles, aforementioned columns are turned ON/OFF following the logic that was defined in the beginning of LEDController.ino file. The area of detected vehicles are dynamically kept dark, while remaining areas are kept illuminated by the high beams, thus enhancing safety by increasing visibility. If more than 2 vehicles are detected, high beams are turned OFF altogether as the existing 8 columns would be divided too much to the point where the efficiency of illumination would be lost. The object detection model is capable of recognizing both oncoming and preceding vehicles and works with different types of vehicles (cars, trucks, buses etc.) To make the code understandable, comments are added where necessary.

### Object Detection with TensorFlow
As mentioned in the previous section, several hundreds of images of night time driving containing headlights and taillights are used to train a model that can detect vehicles at night with high percentage of accuracy and low error rate. Those images were seperated into train (80%) and test (20%) datasets. All of them were labeled using LabelImg application which is very useful when creating a custom object detection model. More information about LabelImg is provided in the **Acknowledgments** section. After labeling headlights and taillights, ssd_inception_v2_coco model provided by Tensorflow is used to train the model and that model is used in the script _vehicleDetect.py._

#### A simple animation to show how this system works
![](https://imgur.com/Dy1nyaF.gif)

---

## Deployment
Following steps will walk you through how this project can be installed and get to work properly.
#### 1. Download the Files
Launch command prompt and change directory to your preferred one. Then clone this repository by running the following command 
```
git clone https://github.com/canozcivelek/adaptive-led-matrix-highbeam.git
```
You need to have already installed previously mentioned software in the "Getting Started" section.

#### 2. Hardware Setup and Running the Script
The Python script checks if the serial connection is established and will give an error if it isn't already. So before running the script, first to make sure you get all the hardware set by doing the following:
1. Connect the Arduino Uno board to your PC via USB port
2. Open the ```LEDController.ino``` file and upload it to the board.
3. Make connections between Arduino and LED matrix. This will require 3 cables: one from Arduino GND pin to LED GND, another from Arduino 5V pin to LED 5V, finally, Arduino input pin number 5 to LED DOUT.
4. A projector lens will be needed to refract emitted light onto the road surface and to spread the beams evenly. This will _cross_ the columns with respect to both X and Y axes. Place the projector closely in front of the LED matrix.
5. Make sure the webcam is connected/activated and provide it with a night time driving video for it to analyze.
6. Open ```vehicleDetect.py``` script with your preferred editor and run. Be sure to keep **vehicleDetect.py**, **label_map.pbtxt** and the folder **inference_graph** with saved model and checkpoints under the same dircetory. The script will look for label_map and saved models to perform the object detection.

When the script is run, the LED matrix module will light up with a subtle animation and a window will be opened showing the webcam feed. Once it recognizes vehicles, it will show them wrapped around a bounding box, showing its label as "vehicle" and how confident it is with a percentage that it belongs to an actual vehicle. The LED module will start to lighten/darken specific columns as if it keeps the area of the detected vehicle dark.

#### Here is how my setup looks like (excluding the camera)
![](https://i.imgur.com/4JZg8ge.gif)

---

## Important Notes
It should be noted that this project is **only** a demonstration of how *I think* this technology works. It cannot by any means be used in production vehicles or other than educational purposes. The capabilities of this system is limited to my setup as of developing this project and was created with the sole purpose of self-improvement, educational applications and is a result of my personal interest in automotive technology, lighting technology as well as computer vision applications. Actual technology used in production vehicles makes use of much higher end hardware (i.e. ECU, camera) and is part of safety systems that must work with extremely low rates of error and with high precision.

## Acknowledgments
During the making of this project, a notable mention should be made to:
* Chris Dahms - https://github.com/MicrocontrollersAndMore for their tutorials on how to use Tensorflow's object detection API.
* darrenl - https://github.com/tzutalin/labelImg for their great work creating this useful tool.
* TensorFlow - https://github.com/tensorflow/models for their models repository to help object detection possible.





