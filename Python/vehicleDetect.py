################################################################################
######## ADAPTIVE LED MATRIX HIGH BEAM PROJECT #################################
################################################################################
# BY: CAN OZCIVELEK
# DATE: OCTOBER 2018
# DESCRIPTION: THIS PROJECT MAKES USE OF A CAMERA TO ANALYZE THE ROAD AND DETECT
#              VEHICLES. THEN  SENDS  THE  DETECTED  VEHICLES  POSITIONS TO  THE
#              CONTROLLER  WHICH  CONTROLS  THE  LED  MODULE TO TURN  INDIVIDUAL
#              PARTS ON/OFF SO  AS TO NOT DAZZLE OTHER DRIVERS. TO MAKE  VEHICLE
#              DETECTION POSSIBLE AT NIGHT, THE PROJECT MADE USE OF TENSORFLOW'S
#              OBJECT DETECTION API. CUSTOM  TRAINING HAS BEEN  DONE  USING OVER
#              500 IMAGES TO TRAIN  VIA TENSORFLOW'S ssd_inception_v2_coco MODEL
#
# THIS PROJECT CONSISTS OF 2 SYSTEMS IN COMMUNICATION:
# 1. PYTHON (VEHICLE DETECTION AT NIGHT)
# 2. ARDUINO (LED MODULE CONTROL)
################################################################################


# IMPORT NECESSARY LIBRARIES
import os
import cv2
import numpy as np
import tensorflow as tf
import time
import pyautogui, sys
import serial
from utils import label_map_util
from utils import visualization_utils as vis_util



################################################################################
######## START - FUNCTIONS TO SEND DATA TO LED MODULE ##########################
################################################################################

################################################################################
#### START - FUNCTION TO HANDLE SINGLE VEHICLE DETECTED ########################
def drawCurtainSingle(inpFrame, inpX, inpSer):

    ##Get the frame width
    fWidth = inpFrame.shape[1]
    print("Frame", fWidth)
    print("Single Car Detected")

    # Calculate the width of each column to be turned
    # ON/OFF based on the detected vehicle positions
    col1 = fWidth * 0.1 - 20
    col2 = fWidth * 0.2
    col3 = fWidth * 0.3
    col4 = fWidth * 0.4
    col5 = fWidth * 0.5
    col6 = fWidth * 0.6
    col7 = fWidth * 0.7
    col8 = fWidth * 0.8
    col9 = fWidth * 0.9

    # A slight delay to prevent LEDs from flickering too much
    time.sleep(0.15)

    ### START - If checks to determine which column to be turned ON/OFF ########
    ### ############################################################### ########
    if(inpX < col1):
        posX1 = "0"
        print("POSX1:", posX1.encode())

    elif(inpX >= col1 and inpX < col2):
        posX1 = "1"
        print("POSX1:", posX1.encode())

    elif(inpX >= col2 and inpX < col3):
        posX1 = "2"
        print("POSX1:", posX1.encode())

    elif(inpX >= col3 and inpX < col4):
        posX1 = "3"
        print("POSX1:", posX1.encode())

    elif(inpX >= col4 and inpX < col5):
        posX1 = "4"
        print("POSX1:", posX1.encode())

    elif(inpX >= col5 and inpX < col6):
        posX1 = "5"
        print("POSX1:", posX1.encode())

    elif(inpX >= col6 and inpX < col7):
        posX1 = "6"
        print("POSX1:", posX1.encode())

    elif(inpX >= col7 and inpX < col8):
        posX1 = "7"
        print("POSX1:", posX1.encode())

    elif(inpX >= col8 and inpX < col9):

        posX1 = "8"
        print("POSX1:", posX1.encode())

    elif(inpX >= col9):
        posX1 = "9"
        print("POSX1:", posX1.encode())
    ### ############################################################# ##########
    ### END - If checks to determine which column to be turned ON/OFF ##########

    # Define the final variable to be sent over the serial connection
    # to the LED control module
    # In this project, the variables that are sent to the LED module
    # must start with an "x"
    # Since there is only one detected vehicle in this function,
    # Second character is "y" and only the third character holds
    # the position of the detected vehicle
    posX4 = "x" + "y" + posX1

    print("POSX4: ", posX4.encode())

    # Write the final data to the serial port
    inpSer.write(posX4.encode())
#### END - FUNCTION TO HANDLE SINGLE VEHICLE DETECTED ##########################
#### ################################################ ##########################


################################################################################
#### START - FUNCTION TO HANDLE TWO VEHICLES DETECTED ##########################
def drawCurtainDouble(inpFrame, inpX1, inpX2, inpSer):

    ##Get the frame width
    fWidth = inpFrame.shape[1]
    print("Frame", fWidth)
    print("2 Cars Detected")

    # Calculate the width of each column to be turned
    # ON/OFF based on the detected vehicle positions
    col1 = fWidth * 0.1 - 20
    col2 = fWidth * 0.2
    col3 = fWidth * 0.3
    col4 = fWidth * 0.4
    col5 = fWidth * 0.5
    col6 = fWidth * 0.6
    col7 = fWidth * 0.7
    col8 = fWidth * 0.8
    col9 = fWidth * 0.9

    # A slight delay to prevent LEDs from flickering too much
    time.sleep(0.15)

    ### START - If checks to determine which column to be turned ON/OFF ########
    ### For the first detected vehicle
    ### ############################################################### ########
    if(inpX1 < col1):
        posX1 = "0"
        print("POSX1:", posX1.encode())

    if(inpX1 >= col1 and inpX1 < col2):
        posX1 = "1"
        print("POSX1:", posX1.encode())

    if(inpX1 >= col2 and inpX1 < col3):
        posX1 = "2"
        print("POSX1:", posX1.encode())

    if(inpX1 >= col3 and inpX1 < col4):
        posX1 = "3"
        print("POSX1:", posX1.encode())

    if(inpX1 >= col4 and inpX1 < col5):
        posX1 = "4"
        print("POSX1:", posX1.encode())

    if(inpX1 >= col5 and inpX1 < col6):
        posX1 = "5"
        print("POSX1:", posX1.encode())

    if(inpX1 >= col6 and inpX1 < col7):
        posX1 = "6"
        print("POSX1:", posX1.encode())

    if(inpX1 >= col7 and inpX1 < col8):
        posX1 = "7"
        print("POSX1:", posX1.encode())

    if(inpX1 >= col8 and inpX1 < col9):
        posX1 = "8"
        print("POSX1:", posX1.encode())

    if(inpX1 >= col9):
        posX1 = "0"
        print("POSX1:", posX1.encode())
    ##END - If checks to determine which column to be turned ON/OFF
    ##For the first detected vehicle

    ##START - If checks to determine which column to be turned ON/OFF
    ##For the second detected vehicle
    if(inpX2 < col1):
        posX2 = "0"
        print("POSX2:", posX2.encode())

    if(inpX2 >= col1 and inpX2 < col2):
        posX2 = "1"
        print("POSX2:", posX2.encode())

    if(inpX2 >= col2 and inpX2 < col3):
        posX2 = "2"
        print("POSX2:", posX2.encode())

    if(inpX2 >= col3 and inpX2 < col4):
        posX2 = "3"
        print("POSX2:", posX2.encode())

    if(inpX2 >= col4 and inpX2 < col5):
        posX2 = "4"
        print("POSX2:", posX2.encode())

    if(inpX2 >= col5 and inpX2 < col6):
        posX2 = "5"
        print("POSX2:", posX2.encode())

    if(inpX2 >= col6 and inpX2 < col7):
        posX2 = "6"
        print("POSX2:", posX2.encode())

    if(inpX2 >= col7 and inpX2 < col8):
        posX2 = "7"
        print("POSX2:", posX2.encode())

    if(inpX2 >= col8 and inpX2 < col9):
        posX2 = "8"
        print("POSX2:", posX2.encode())

    if(inpX2 >= col9):
        posX2 = "0"
        print("POSX2:", posX2.encode())
    ### ############################################################### ########
    ### END - If checks to determine which column to be turned ON/OFF ##########
    ### For the second detected vehicle

    # Define the final variable to be sent over the serial connection
    # to the LED control module
    # In this project, the variables that are sent to the LED module
    # must start with an "x"
    # Since there is two detected vehicles in this function,
    # The second & third characters hold the position of the detected vehicles
    posX3 = "x" + posX1 + posX2

    print("POSX3: ", posX3.encode())

    # Write the final data to the serial port
    inpSer.write(posX3.encode())
#### END - FUNCTION TO HANDLE TWO VEHICLES DETECTED ############################
#### ############################################## ############################


#### ################################################################## ########
#### START - FUNCTION TO HANDLE ZERO OR MORE THAN TWO VEHICLES DETECTED ########
def ledOnOff(state, inpSer):
    # If state is 1, switch all the LEDs ON
    # Since there is no cars detected
    if state == 1:
        posX = "0"
        posX1 = "x" + "y" + posX
        print("POSX1: ", posX1)

    # If state is 0, switch all the LEDs OFF
    # Since there is more than 2 cars detected
    if state == 0:
        posX = "9"
        posX1 = "x" + "y" + posX
        print("POSX1: ", posX1)

    # Write the final data to the serial port
    inpSer.write(posX1.encode())
#### END - FUNCTION TO HANDLE ZERO OR MORE THAN TWO VEHICLES DETECTED ##########
################################################################################

################################################################################
######## END - FUNCTIONS TO SEND DATA TO LED MODULE ############################
################################################################################

################################################################################
################################################################################
################################################################################
################################################################################

################################################################################
######## START - MAIN FUNCTION #################################################
################################################################################

# Define the directory containing the object detection model we're using
MODEL_NAME = 'inference_graph'

# Get path to the current working directory
CWD_PATH = os.getcwd()

# Path to frozen detection graph .pb file, which contains the model that is used
# for object detection.
PATH_TO_CKPT = os.path.join(CWD_PATH,MODEL_NAME,'frozen_inference_graph.pb')

# Path to label map file
PATH_TO_LABELS = os.path.join(CWD_PATH, 'label_map.pbtxt')

# Number of classes the object detector can identify
NUM_CLASSES = 1

# Load the label map.
# Label maps map indices to category names, so that when our convolution
# network predicts `5`, we know that this corresponds to `king`.
# Here we use internal utility functions, but anything that returns a
# dictionary mapping integers to appropriate string labels would be fine
label_map = label_map_util.load_labelmap(PATH_TO_LABELS)
categories = label_map_util.convert_label_map_to_categories(label_map, max_num_classes = NUM_CLASSES, use_display_name = True)
category_index = label_map_util.create_category_index(categories)

# Load the Tensorflow model into memory.
detection_graph = tf.Graph()
with detection_graph.as_default():
    od_graph_def = tf.GraphDef()
    with tf.gfile.GFile(PATH_TO_CKPT, 'rb') as fid:
        serialized_graph = fid.read()
        od_graph_def.ParseFromString(serialized_graph)
        tf.import_graph_def(od_graph_def, name='')

    sess = tf.Session(graph=detection_graph)


# Define input and output tensors (ie data) for the object detection classifier

# Input tensor is the image
image_tensor = detection_graph.get_tensor_by_name('image_tensor:0')

# Output tensors are the detection boxes, scores, and classes
# Each box represents a part of the image where a particular object was detected
detection_boxes = detection_graph.get_tensor_by_name('detection_boxes:0')

# Each score represents level of confidence for each of the objects.
# The score is shown on the result image, together with the class label.
detection_scores = detection_graph.get_tensor_by_name('detection_scores:0')
detection_classes = detection_graph.get_tensor_by_name('detection_classes:0')

# Number of objects detected
num_detections = detection_graph.get_tensor_by_name('num_detections:0')

# Define serial object and ports
ser  = serial.Serial('COM3', 9600, timeout = 0)

# Initialize webcam feed
video = cv2.VideoCapture(0)

while(True):

    # Acquire frame and expand frame dimensions to have shape: [1, None, None, 3]
    # i.e. a single-column array, where each item in the column has the pixel RGB value
    ret, frame = video.read()
    frame_expanded = np.expand_dims(frame, axis=0)

    height, width = frame.shape[:2]

    # Perform the actual detection by running the model with the image as input
    (boxes, scores, classes, num) = sess.run(
        [detection_boxes, detection_scores, detection_classes, num_detections],
        feed_dict = {image_tensor: frame_expanded})


    # Visualize the result
    vis_util.visualize_boxes_and_labels_on_image_array(
        frame,
        np.squeeze(boxes),
        np.squeeze(classes).astype(np.int32),
        np.squeeze(scores),
        category_index,
        use_normalized_coordinates=True,
        line_thickness=4,
        min_score_thresh=0.40)


    # Processing the detected vehicles
    medX1 = None    # Variable for the position of first detected vehicle
    medX2 = None    # Variable for the position of second detected vehicle
    first = True    # Variable to turn False when the loop is entered 2nd time
    final_score = np.squeeze(scores)
    count = 0       # Variable to count the detected vehicles

    ############################################################################
    ### START - Loop to detect up to 100 vehicles per frame ####################
    for i in range(100):
        if scores is None or final_score[i] > 0.5:
            #Determining bounding box coordinates
            ymin = int((boxes[0][i][0] * height))
            xmin = int((boxes[0][i][1] * width))
            ymax = int((boxes[0][i][2] * height))
            xmax = int((boxes[0][i][3] * width))

            if first:       # If loop is entered for the first time
                medX1 = (xmin + xmax) / 2
                first = False
                second = True

            elif second:    # If loop is entered for the second time
                medX2 = (xmin + xmax) / 2
                second = False
            count = count + 1
    ### END - Loop to detect up to 100 vehicles per frame ######################
    ############################################################################


    # Print the positions and number of detected vehicles
    print(medX1, ":", medX2)
    print("Counted: ", count)

    # If single vehicle is detected, call the drawCurtainSingle() function
    if(count == 1):
        drawCurtainSingle(frame, medX1, ser)

    # If two vehicles are detected, call the drawCurtainDouble() function
    elif(count == 2):
        drawCurtainDouble(frame, medX1, medX2, ser)

    # If more than 2 vehicles detected, turn all the LEDs OFF
    elif(count > 2):
        ledOnOff(0, ser)
        print("More than two cars detected. High beams OFF.")

    # If zero vehicles detected, turn all the LEDs ON
    elif(count == 0):
        ledOnOff(1, ser)
        print("No cars detected. High beams ON.")


    # Read the data which is sent from Arduino to double check
    # what it actually received.
    msg = ser.readline()
    print("Arduino received: ", msg)


    # Display the final image
    cv2.imshow('Vehicle Detection at Night', frame)

    # Press 'ENTER' to quit
    if cv2.waitKey(1) == 13:
        break
################################################################################
### END - Loop to play the input video #########################################

# Clean up
video.release()
cv2.destroyAllWindows()

################################################################################
######## END - MAIN FUNCTION ###################################################
################################################################################




































################################################################################
