/*
 * ADAPTIVE LED MATRIX HEADLIGHT PROJECT
 * BY: CAN OZCIVELEK
 * DATE: OCTOBER 2018
 * DESCRIPTION: THIS PROJECT MAKES USE OF A CAMERA TO ANALYZE THE ROAD AND DETECT
 *              VEHICLES. THEN  SENDS  THE  DETECTED  VEHICLES  POSITIONS TO  THE
 *              CONTROLLER  WHICH  CONTROLS  THE  LED  MODULE TO TURN  INDIVIDUAL
 *              PARTS ON/OFF SO  AS TO NOT DAZZLE OTHER DRIVERS. TO MAKE  VEHICLE
 *              DETECTION POSSIBLE AT NIGHT, THE PROJECT MADE USE OF TENSORFLOW'S
 *              OBJECT DETECTION API. CUSTOM  TRAINING HAS BEEN  DONE  USING OVER
 *              500 IMAGES TO TRAIN  VIA TENSORFLOW'S ssd_inception_v2_coco MODEL
 * 
 * SOFTWARE OF THIS PROJECT CONSISTS OF 2 PARTS:
 * 1. PYTHON (VEHICLE DETECTION AT NIGHT)
 * 2. ARDUINO (LED MODULE CONTROL)
 */

//Importing libraries
#include "FastLED.h"

//Define number of LEDs, data pin
#define NUM_LEDS 64                               //Number of LEDs on the matrix module
#define DATA_PIN 5                                //Send signal over the Arduino pin 5

CRGB led_matrix[NUM_LEDS];                        //Define the LED matrix

char ch[3] = "";                                  //An array to store the received data from serial port


////START - FUNCTIONS TO HANDLE SINGLE CAR DETECTION////
////////////////////////////////////////////////////////
void position0()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::White;  //column 1
        led_matrix[i+1] = CRGB::White;  //column 2
        led_matrix[i+2] = CRGB::White;  //column 3
        led_matrix[i+3] = CRGB::White;  //column 4
        led_matrix[i+4] = CRGB::White;  //column 5
        led_matrix[i+5] = CRGB::White;  //column 6
        led_matrix[i+6] = CRGB::White;  //column 7
        led_matrix[i+7] = CRGB::White;  //column 8
        FastLED.show();
    }
}


void position1()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::Black;  //column 1
        led_matrix[i+1] = CRGB::Black;  //column 2
        led_matrix[i+2] = CRGB::White;  //column 3
        led_matrix[i+3] = CRGB::White;  //column 4
        led_matrix[i+4] = CRGB::White;  //column 5
        led_matrix[i+5] = CRGB::White;  //column 6
        led_matrix[i+6] = CRGB::White;  //column 7
        led_matrix[i+7] = CRGB::White;  //column 8
        FastLED.show();
    }            
}


void position2()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::Black;  //column 1
        led_matrix[i+1] = CRGB::Black;  //column 2
        led_matrix[i+2] = CRGB::Black;  //column 3
        led_matrix[i+3] = CRGB::White;  //column 4
        led_matrix[i+4] = CRGB::White;  //column 5
        led_matrix[i+5] = CRGB::White;  //column 6
        led_matrix[i+6] = CRGB::White;  //column 7
        led_matrix[i+7] = CRGB::White;  //column 8
        FastLED.show();
    }            
}


void position3()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::White;  //column 1
        led_matrix[i+1] = CRGB::White;  //column 2
        led_matrix[i+2] = CRGB::Black;  //column 3
        led_matrix[i+3] = CRGB::Black;  //column 4
        led_matrix[i+4] = CRGB::Black;  //column 5
        led_matrix[i+5] = CRGB::White;  //column 6
        led_matrix[i+6] = CRGB::White;  //column 7
        led_matrix[i+7] = CRGB::White;  //column 8
        FastLED.show();
    }            
}


void position4()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::White;  //column 1
        led_matrix[i+1] = CRGB::White;  //column 2
        led_matrix[i+2] = CRGB::White;  //column 3
        led_matrix[i+3] = CRGB::Black;  //column 4
        led_matrix[i+4] = CRGB::Black;  //column 5
        led_matrix[i+5] = CRGB::White;  //column 6
        led_matrix[i+6] = CRGB::White;  //column 7
        led_matrix[i+7] = CRGB::White;  //column 8
        FastLED.show();
    }            
}


void position5()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::White;  //column 1
        led_matrix[i+1] = CRGB::White;  //column 2
        led_matrix[i+2] = CRGB::White;  //column 3
        led_matrix[i+3] = CRGB::White;  //column 4
        led_matrix[i+4] = CRGB::Black;  //column 5
        led_matrix[i+5] = CRGB::Black;  //column 6
        led_matrix[i+6] = CRGB::White;  //column 7
        led_matrix[i+7] = CRGB::White;  //column 8
        FastLED.show();
    }            
}


void position6()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::White;  //column 1
        led_matrix[i+1] = CRGB::White;  //column 2
        led_matrix[i+2] = CRGB::White;  //column 3
        led_matrix[i+3] = CRGB::White;  //column 4
        led_matrix[i+4] = CRGB::White;  //column 5
        led_matrix[i+5] = CRGB::Black;  //column 6
        led_matrix[i+6] = CRGB::Black;  //column 7
        led_matrix[i+7] = CRGB::Black;  //column 8
        FastLED.show();
    }            
}


void position7()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::White;  //column 1
        led_matrix[i+1] = CRGB::White;  //column 2
        led_matrix[i+2] = CRGB::White;  //column 3
        led_matrix[i+3] = CRGB::White;  //column 4
        led_matrix[i+4] = CRGB::White;  //column 5
        led_matrix[i+5] = CRGB::White;  //column 6
        led_matrix[i+6] = CRGB::Black;  //column 7
        led_matrix[i+7] = CRGB::Black;  //column 8
        FastLED.show();
    }            
}


void position8()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::White;  //column 1
        led_matrix[i+1] = CRGB::White;  //column 2
        led_matrix[i+2] = CRGB::White;  //column 3
        led_matrix[i+3] = CRGB::White;  //column 4
        led_matrix[i+4] = CRGB::White;  //column 5
        led_matrix[i+5] = CRGB::White;  //column 6
        led_matrix[i+6] = CRGB::White;  //column 7
        led_matrix[i+7] = CRGB::Black;  //column 8
        FastLED.show();
    }            
}


void position9()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::Black;  //column 1
        led_matrix[i+1] = CRGB::Black;  //column 2
        led_matrix[i+2] = CRGB::Black;  //column 3
        led_matrix[i+3] = CRGB::Black;  //column 4
        led_matrix[i+4] = CRGB::Black;  //column 5
        led_matrix[i+5] = CRGB::Black;  //column 6
        led_matrix[i+6] = CRGB::Black;  //column 7
        led_matrix[i+7] = CRGB::Black;  //column 8
        FastLED.show();
    }            
}
////////////////////////////////////////////////////////
/////END - FUNCTIONS TO HANDLE SINGLE CAR DETECTION/////



////START - FUNCTIONS TO HANDLE 2 CARS DETECTED//////////
////////////////////////////////////////////////////////
void position01()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::Black;  //column 1
        led_matrix[i+1] = CRGB::Black;  //column 2
        led_matrix[i+2] = CRGB::White;  //column 3
        led_matrix[i+3] = CRGB::White;  //column 4
        led_matrix[i+4] = CRGB::White;  //column 5
        led_matrix[i+5] = CRGB::White;  //column 6
        led_matrix[i+6] = CRGB::White;  //column 7
        led_matrix[i+7] = CRGB::White;  //column 8
        FastLED.show();
    }
}


void position02()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::Black;  //column 1
        led_matrix[i+1] = CRGB::Black;  //column 2
        led_matrix[i+2] = CRGB::Black;  //column 3
        led_matrix[i+3] = CRGB::White;  //column 4
        led_matrix[i+4] = CRGB::White;  //column 5
        led_matrix[i+5] = CRGB::White;  //column 6
        led_matrix[i+6] = CRGB::White;  //column 7
        led_matrix[i+7] = CRGB::White;  //column 8
        FastLED.show();
    }
}


void position03()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::White;  //column 1
        led_matrix[i+1] = CRGB::White;  //column 2
        led_matrix[i+2] = CRGB::Black;  //column 3
        led_matrix[i+3] = CRGB::Black;  //column 4
        led_matrix[i+4] = CRGB::Black;  //column 5
        led_matrix[i+5] = CRGB::White;  //column 6
        led_matrix[i+6] = CRGB::White;  //column 7
        led_matrix[i+7] = CRGB::White;  //column 8
        FastLED.show();
    }
}


void position04()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::White;  //column 1
        led_matrix[i+1] = CRGB::White;  //column 2
        led_matrix[i+2] = CRGB::White;  //column 3
        led_matrix[i+3] = CRGB::Black;  //column 4
        led_matrix[i+4] = CRGB::Black;  //column 5
        led_matrix[i+5] = CRGB::White;  //column 6
        led_matrix[i+6] = CRGB::White;  //column 7
        led_matrix[i+7] = CRGB::White;  //column 8
        FastLED.show();
    }
}


void position05()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::White;  //column 1
        led_matrix[i+1] = CRGB::White;  //column 2
        led_matrix[i+2] = CRGB::White;  //column 3
        led_matrix[i+3] = CRGB::White;  //column 4
        led_matrix[i+4] = CRGB::Black;  //column 5
        led_matrix[i+5] = CRGB::Black;  //column 6
        led_matrix[i+6] = CRGB::White;  //column 7
        led_matrix[i+7] = CRGB::White;  //column 8
        FastLED.show();
    }
}


void position06()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::White;  //column 1
        led_matrix[i+1] = CRGB::White;  //column 2
        led_matrix[i+2] = CRGB::White;  //column 3
        led_matrix[i+3] = CRGB::White;  //column 4
        led_matrix[i+4] = CRGB::White;  //column 5
        led_matrix[i+5] = CRGB::Black;  //column 6
        led_matrix[i+6] = CRGB::Black;  //column 7
        led_matrix[i+7] = CRGB::Black;  //column 8
        FastLED.show();
    }
}


void position07()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::White;  //column 1
        led_matrix[i+1] = CRGB::White;  //column 2
        led_matrix[i+2] = CRGB::White;  //column 3
        led_matrix[i+3] = CRGB::White;  //column 4
        led_matrix[i+4] = CRGB::White;  //column 5
        led_matrix[i+5] = CRGB::White;  //column 6
        led_matrix[i+6] = CRGB::Black;  //column 7
        led_matrix[i+7] = CRGB::Black;  //column 8
        FastLED.show();
    }
}


void position08()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::White;  //column 1
        led_matrix[i+1] = CRGB::White;  //column 2
        led_matrix[i+2] = CRGB::White;  //column 3
        led_matrix[i+3] = CRGB::White;  //column 4
        led_matrix[i+4] = CRGB::White;  //column 5
        led_matrix[i+5] = CRGB::White;  //column 6
        led_matrix[i+6] = CRGB::White;  //column 7
        led_matrix[i+7] = CRGB::Black;  //column 8
        FastLED.show();
    }
}


void position12()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::Black;  //column 1
        led_matrix[i+1] = CRGB::Black;  //column 2
        led_matrix[i+2] = CRGB::Black;  //column 3
        led_matrix[i+3] = CRGB::White;  //column 4
        led_matrix[i+4] = CRGB::White;  //column 5
        led_matrix[i+5] = CRGB::White;  //column 6
        led_matrix[i+6] = CRGB::White;  //column 7
        led_matrix[i+7] = CRGB::White;  //column 8
        FastLED.show();
    }
}


void position13()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::Black;  //column 1
        led_matrix[i+1] = CRGB::Black;  //column 2
        led_matrix[i+2] = CRGB::Black;  //column 3
        led_matrix[i+3] = CRGB::Black;  //column 4
        led_matrix[i+4] = CRGB::Black;  //column 5
        led_matrix[i+5] = CRGB::White;  //column 6
        led_matrix[i+6] = CRGB::White;  //column 7
        led_matrix[i+7] = CRGB::White;  //column 8
        FastLED.show();
    }
}


void position14()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::Black;  //column 1
        led_matrix[i+1] = CRGB::Black;  //column 2
        led_matrix[i+2] = CRGB::White;  //column 3
        led_matrix[i+3] = CRGB::Black;  //column 4
        led_matrix[i+4] = CRGB::Black;  //column 5
        led_matrix[i+5] = CRGB::White;  //column 6
        led_matrix[i+6] = CRGB::White;  //column 7
        led_matrix[i+7] = CRGB::White;  //column 8
        FastLED.show();
    }
}


void position15()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::Black;  //column 1
        led_matrix[i+1] = CRGB::Black;  //column 2
        led_matrix[i+2] = CRGB::White;  //column 3
        led_matrix[i+3] = CRGB::White;  //column 4
        led_matrix[i+4] = CRGB::Black;  //column 5
        led_matrix[i+5] = CRGB::Black;  //column 6
        led_matrix[i+6] = CRGB::White;  //column 7
        led_matrix[i+7] = CRGB::White;  //column 8
        FastLED.show();
    }
}


void position16()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::Black;  //column 1
        led_matrix[i+1] = CRGB::Black;  //column 2
        led_matrix[i+2] = CRGB::White;  //column 3
        led_matrix[i+3] = CRGB::White;  //column 4
        led_matrix[i+4] = CRGB::White;  //column 5
        led_matrix[i+5] = CRGB::Black;  //column 6
        led_matrix[i+6] = CRGB::Black;  //column 7
        led_matrix[i+7] = CRGB::Black;  //column 8
        FastLED.show();
    }
}


void position17()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::Black;  //column 1
        led_matrix[i+1] = CRGB::Black;  //column 2
        led_matrix[i+2] = CRGB::White;  //column 3
        led_matrix[i+3] = CRGB::White;  //column 4
        led_matrix[i+4] = CRGB::White;  //column 5
        led_matrix[i+5] = CRGB::White;  //column 6
        led_matrix[i+6] = CRGB::Black;  //column 7
        led_matrix[i+7] = CRGB::Black;  //column 8
        FastLED.show();
    }
}


void position18()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::Black;  //column 1
        led_matrix[i+1] = CRGB::Black;  //column 2
        led_matrix[i+2] = CRGB::White;  //column 3
        led_matrix[i+3] = CRGB::White;  //column 4
        led_matrix[i+4] = CRGB::White;  //column 5
        led_matrix[i+5] = CRGB::White;  //column 6
        led_matrix[i+6] = CRGB::White;  //column 7
        led_matrix[i+7] = CRGB::Black;  //column 8
        FastLED.show();
    }
}


void position23()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::Black;  //column 1
        led_matrix[i+1] = CRGB::Black;  //column 2
        led_matrix[i+2] = CRGB::Black;  //column 3
        led_matrix[i+3] = CRGB::Black;  //column 4
        led_matrix[i+4] = CRGB::White;  //column 5
        led_matrix[i+5] = CRGB::White;  //column 6
        led_matrix[i+6] = CRGB::White;  //column 7
        led_matrix[i+7] = CRGB::White;  //column 8
        FastLED.show();
    }
}


void position24()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::Black;  //column 1
        led_matrix[i+1] = CRGB::Black;  //column 2
        led_matrix[i+2] = CRGB::Black;  //column 3
        led_matrix[i+3] = CRGB::Black;  //column 4
        led_matrix[i+4] = CRGB::Black;  //column 5
        led_matrix[i+5] = CRGB::White;  //column 6
        led_matrix[i+6] = CRGB::White;  //column 7
        led_matrix[i+7] = CRGB::White;  //column 8
        FastLED.show();
    }
}


void position25()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::Black;  //column 1
        led_matrix[i+1] = CRGB::Black;  //column 2
        led_matrix[i+2] = CRGB::Black;  //column 3
        led_matrix[i+3] = CRGB::White;  //column 4
        led_matrix[i+4] = CRGB::Black;  //column 5
        led_matrix[i+5] = CRGB::Black;  //column 6
        led_matrix[i+6] = CRGB::White;  //column 7
        led_matrix[i+7] = CRGB::White;  //column 8
        FastLED.show();
    }
}


void position26()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::Black;  //column 1
        led_matrix[i+1] = CRGB::Black;  //column 2
        led_matrix[i+2] = CRGB::Black;  //column 3
        led_matrix[i+3] = CRGB::White;  //column 4
        led_matrix[i+4] = CRGB::White;  //column 5
        led_matrix[i+5] = CRGB::Black;  //column 6
        led_matrix[i+6] = CRGB::Black;  //column 7
        led_matrix[i+7] = CRGB::Black;  //column 8
        FastLED.show();
    }
}


void position27()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::Black;  //column 1
        led_matrix[i+1] = CRGB::Black;  //column 2
        led_matrix[i+2] = CRGB::Black;  //column 3
        led_matrix[i+3] = CRGB::White;  //column 4
        led_matrix[i+4] = CRGB::White;  //column 5
        led_matrix[i+5] = CRGB::White;  //column 6
        led_matrix[i+6] = CRGB::Black;  //column 7
        led_matrix[i+7] = CRGB::Black;  //column 8
        FastLED.show();
    }
}


void position28()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::Black;  //column 1
        led_matrix[i+1] = CRGB::Black;  //column 2
        led_matrix[i+2] = CRGB::Black;  //column 3
        led_matrix[i+3] = CRGB::White;  //column 4
        led_matrix[i+4] = CRGB::White;  //column 5
        led_matrix[i+5] = CRGB::White;  //column 6
        led_matrix[i+6] = CRGB::White;  //column 7
        led_matrix[i+7] = CRGB::Black;  //column 8
        FastLED.show();
    }
}


void position34()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::White;  //column 1
        led_matrix[i+1] = CRGB::White;  //column 2
        led_matrix[i+2] = CRGB::Black;  //column 3
        led_matrix[i+3] = CRGB::Black;  //column 4
        led_matrix[i+4] = CRGB::Black;  //column 5
        led_matrix[i+5] = CRGB::White;  //column 6
        led_matrix[i+6] = CRGB::White;  //column 7
        led_matrix[i+7] = CRGB::Black;  //column 8
        FastLED.show();
    }
}


void position35()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::White;  //column 1
        led_matrix[i+1] = CRGB::White;  //column 2
        led_matrix[i+2] = CRGB::Black;  //column 3
        led_matrix[i+3] = CRGB::Black;  //column 4
        led_matrix[i+4] = CRGB::Black;  //column 5
        led_matrix[i+5] = CRGB::Black;  //column 6
        led_matrix[i+6] = CRGB::White;  //column 7
        led_matrix[i+7] = CRGB::Black;  //column 8
        FastLED.show();
    }
}


void position36()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::White;  //column 1
        led_matrix[i+1] = CRGB::Black;  //column 2
        led_matrix[i+2] = CRGB::Black;  //column 3
        led_matrix[i+3] = CRGB::Black;  //column 4
        led_matrix[i+4] = CRGB::White;  //column 5
        led_matrix[i+5] = CRGB::Black;  //column 6
        led_matrix[i+6] = CRGB::Black;  //column 7
        led_matrix[i+7] = CRGB::Black;  //column 8
        FastLED.show();
    }
}


void position37()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::White;  //column 1
        led_matrix[i+1] = CRGB::Black;  //column 2
        led_matrix[i+2] = CRGB::Black;  //column 3
        led_matrix[i+3] = CRGB::Black;  //column 4
        led_matrix[i+4] = CRGB::White;  //column 5
        led_matrix[i+5] = CRGB::White;  //column 6
        led_matrix[i+6] = CRGB::Black;  //column 7
        led_matrix[i+7] = CRGB::Black;  //column 8
        FastLED.show();
    }
}


void position38()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::White;  //column 1
        led_matrix[i+1] = CRGB::Black;  //column 2
        led_matrix[i+2] = CRGB::Black;  //column 3
        led_matrix[i+3] = CRGB::Black;  //column 4
        led_matrix[i+4] = CRGB::White;  //column 5
        led_matrix[i+5] = CRGB::White;  //column 6
        led_matrix[i+6] = CRGB::White;  //column 7
        led_matrix[i+7] = CRGB::Black;  //column 8
        FastLED.show();
    }
}


void position45()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::White;  //column 1
        led_matrix[i+1] = CRGB::White;  //column 2
        led_matrix[i+2] = CRGB::White;  //column 3
        led_matrix[i+3] = CRGB::Black;  //column 4
        led_matrix[i+4] = CRGB::Black;  //column 5
        led_matrix[i+5] = CRGB::Black;  //column 6
        led_matrix[i+6] = CRGB::White;  //column 7
        led_matrix[i+7] = CRGB::White;  //column 8
        FastLED.show();
    }
}


void position46()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::White;  //column 1
        led_matrix[i+1] = CRGB::White;  //column 2
        led_matrix[i+2] = CRGB::White;  //column 3
        led_matrix[i+3] = CRGB::Black;  //column 4
        led_matrix[i+4] = CRGB::Black;  //column 5
        led_matrix[i+5] = CRGB::Black;  //column 6
        led_matrix[i+6] = CRGB::Black;  //column 7
        led_matrix[i+7] = CRGB::Black;  //column 8
        FastLED.show();
    }
}


void position47()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::White;  //column 1
        led_matrix[i+1] = CRGB::White;  //column 2
        led_matrix[i+2] = CRGB::White;  //column 3
        led_matrix[i+3] = CRGB::Black;  //column 4
        led_matrix[i+4] = CRGB::Black;  //column 5
        led_matrix[i+5] = CRGB::White;  //column 6
        led_matrix[i+6] = CRGB::Black;  //column 7
        led_matrix[i+7] = CRGB::Black;  //column 8
        FastLED.show();
    }
}


void position48()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::White;  //column 1
        led_matrix[i+1] = CRGB::White;  //column 2
        led_matrix[i+2] = CRGB::White;  //column 3
        led_matrix[i+3] = CRGB::Black;  //column 4
        led_matrix[i+4] = CRGB::Black;  //column 5
        led_matrix[i+5] = CRGB::White;  //column 6
        led_matrix[i+6] = CRGB::White;  //column 7
        led_matrix[i+7] = CRGB::Black;  //column 8
        FastLED.show();
    }
}


void position56()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::White;  //column 1
        led_matrix[i+1] = CRGB::White;  //column 2
        led_matrix[i+2] = CRGB::White;  //column 3
        led_matrix[i+3] = CRGB::White;  //column 4
        led_matrix[i+4] = CRGB::Black;  //column 5
        led_matrix[i+5] = CRGB::Black;  //column 6
        led_matrix[i+6] = CRGB::Black;  //column 7
        led_matrix[i+7] = CRGB::Black;  //column 8
        FastLED.show();
    }
}


void position57()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::White;  //column 1
        led_matrix[i+1] = CRGB::White;  //column 2
        led_matrix[i+2] = CRGB::White;  //column 3
        led_matrix[i+3] = CRGB::White;  //column 4
        led_matrix[i+4] = CRGB::Black;  //column 5
        led_matrix[i+5] = CRGB::Black;  //column 6
        led_matrix[i+6] = CRGB::Black;  //column 7
        led_matrix[i+7] = CRGB::Black;  //column 8
        FastLED.show();
    }
}


void position58()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::White;  //column 1
        led_matrix[i+1] = CRGB::White;  //column 2
        led_matrix[i+2] = CRGB::White;  //column 3
        led_matrix[i+3] = CRGB::White;  //column 4
        led_matrix[i+4] = CRGB::Black;  //column 5
        led_matrix[i+5] = CRGB::Black;  //column 6
        led_matrix[i+6] = CRGB::White;  //column 7
        led_matrix[i+7] = CRGB::Black;  //column 8
        FastLED.show();
    }
}


void position67()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::White;  //column 1
        led_matrix[i+1] = CRGB::White;  //column 2
        led_matrix[i+2] = CRGB::White;  //column 3
        led_matrix[i+3] = CRGB::White;  //column 4
        led_matrix[i+4] = CRGB::White;  //column 5
        led_matrix[i+5] = CRGB::Black;  //column 6
        led_matrix[i+6] = CRGB::Black;  //column 7
        led_matrix[i+7] = CRGB::Black;  //column 8
        FastLED.show();
    }
}


void position68()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::White;  //column 1
        led_matrix[i+1] = CRGB::White;  //column 2
        led_matrix[i+2] = CRGB::White;  //column 3
        led_matrix[i+3] = CRGB::White;  //column 4
        led_matrix[i+4] = CRGB::White;  //column 5
        led_matrix[i+5] = CRGB::Black;  //column 6
        led_matrix[i+6] = CRGB::Black;  //column 7
        led_matrix[i+7] = CRGB::Black;  //column 8
        FastLED.show();
    }
}


void position78()
{
    for(int i = 0; i <= 24; i+=8)
    {
        led_matrix[i]   = CRGB::White;  //column 1
        led_matrix[i+1] = CRGB::White;  //column 2
        led_matrix[i+2] = CRGB::White;  //column 3
        led_matrix[i+3] = CRGB::White;  //column 4
        led_matrix[i+4] = CRGB::White;  //column 5
        led_matrix[i+5] = CRGB::White;  //column 6
        led_matrix[i+6] = CRGB::Black;  //column 7
        led_matrix[i+7] = CRGB::Black;  //column 8
        FastLED.show();
    }
}
////////////////////////////////////////////////////////
/////END - FUNCTIONS TO HANDLE 2 CARS DETECTED//////////



////START - MAIN FUNCTION///////////////////////////////
////////////////////////////////////////////////////////
void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);                           //Start serial connection
    pinMode (13, OUTPUT);

    //Define the LED matrix
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(led_matrix, NUM_LEDS);
   

    ////START - Animation on start-up////////////////////
    for(int i = 0; i <= 24; i+=8)
    {
        FastLED.setBrightness(70);
        led_matrix[i+0] = CRGB::White;   //column 1
        led_matrix[i+7] = CRGB::White;   //column 8
    }
    FastLED.show();
    delay(100);    
  
    for(int i = 0; i <= 24; i+=8)
    {
        FastLED.setBrightness(60);         
        led_matrix[i+1] = CRGB::White;   //column 2
        led_matrix[i+6] = CRGB::White;   //column 7
    }
    FastLED.show();
    delay(100);
  
    for(int i = 0; i <= 24; i+=8)
    {
        FastLED.setBrightness(50);         
        led_matrix[i+2] = CRGB::White;   //column 3
        led_matrix[i+5] = CRGB::White;   //column 6
    }
    FastLED.show();
    delay(100);
  
    for(int i = 0; i <= 24; i+=8)
    {
        FastLED.setBrightness(40);         
        led_matrix[i+3] = CRGB::White;   //column 4
        led_matrix[i+4] = CRGB::White;   //column 5
    }
    FastLED.show();
    delay(100);
  
    for(int i = 0; i <= 10; i++)      //Fade-in effect on start-up
    {
      FastLED.setBrightness(i);       //Set the brightness of the matrix
      FastLED.show();
      delay(50);
    }
    ////END - Animation on start-up//////////////////////
}
////////////////////////////////////////////////////////
////END - MAIN FUNCTION/////////////////////////////////


////START - LOOP FUNCTION///////////////////////////////
////////////////////////////////////////////////////////
void loop()
{
    ////START - Check serial connection status
    if(Serial.available() > 0)
    { 
        ////START - Handle detected vehicles
        //Data sent over the serial port will contain 3 characters
        //So the loop will be executed 3 times
        for(int i = 0; i < 3; i++)
        {
            ch[i] = Serial.read();                //Start reading characters from the received data
  
            ////START - If checks for single vehicle detected
            if(ch[0] == 'x' && ch[1] == 'y' && ch[2] == '0')
                position0();
    
            if(ch[0] == 'x' && ch[1] == 'y' && ch[2] == '1')
                position1();
    
            if(ch[0] == 'x' && ch[1] == 'y' && ch[2] == '2')
                position2();
    
            if(ch[0] == 'x' && ch[1] == 'y' && ch[2] == '3')
                position3();
    
            if(ch[0] == 'x' && ch[1] == 'y' && ch[2] == '4')
                position4();
  
            if(ch[0] == 'x' && ch[1] == 'y' && ch[2] == '5')
                position5();
  
            if(ch[0] == 'x' && ch[1] == 'y' && ch[2] == '6')
                position6();
  
            if(ch[0] == 'x' && ch[1] == 'y' && ch[2] == '7')
                position7();
  
            if(ch[0] == 'x' && ch[1] == 'y' && ch[2] == '8')
                position8();
  
            if(ch[0] == 'x' && ch[1] == 'y' && ch[2] == '9')
                position9();
            ////END - If checks for single vehicle detected
  
  
            ////START - If checks for double vehicle detected
              
            //START - ZEROTH COLUMN
            if(ch[0] == 'x' && ch[1] == '0' && ch[2] == '1' || ch[0] == 'x' && ch[1] == '1' && ch[2] == '0')
                position01();
  
            if(ch[0] == 'x' && ch[1] == '0' && ch[2] == '2' || ch[0] == 'x' && ch[1] == '2' && ch[2] == '0')
                position02();
  
            if(ch[0] == 'x' && ch[1] == '0' && ch[2] == '3' || ch[0] == 'x' && ch[1] == '3' && ch[2] == '0')
                position03();
            
            if(ch[0] == 'x' && ch[1] == '0' && ch[2] == '4' || ch[0] == 'x' && ch[1] == '4' && ch[2] == '0')
                position04();
  
            if(ch[0] == 'x' && ch[1] == '0' && ch[2] == '5' || ch[0] == 'x' && ch[1] == '5' && ch[2] == '0')
                position05();
  
            if(ch[0] == 'x' && ch[1] == '0' && ch[2] == '6' || ch[0] == 'x' && ch[1] == '6' && ch[2] == '0')
                position06();
  
            if(ch[0] == 'x' && ch[1] == '0' && ch[2] == '7' || ch[0] == 'x' && ch[1] == '7' && ch[2] == '0')
                position07();
  
            if(ch[0] == 'x' && ch[1] == '0' && ch[2] == '8' || ch[0] == 'x' && ch[1] == '8' && ch[2] == '0')
                position08();
            //END - ZEROTH COLUMN  
  
            //START - FIRST COLUMN
            if(ch[0] == 'x' && ch[1] == '1' && ch[2] == '2' || ch[0] == 'x' && ch[1] == '2' && ch[2] == '1')
                position12();
  
            if(ch[0] == 'x' && ch[1] == '1' && ch[2] == '3' || ch[0] == 'x' && ch[1] == '3' && ch[2] == '1')
                position13();
  
            if(ch[0] == 'x' && ch[1] == '1' && ch[2] == '4' || ch[0] == 'x' && ch[1] == '4' && ch[2] == '1')
                position14();
  
            if(ch[0] == 'x' && ch[1] == '1' && ch[2] == '5' || ch[0] == 'x' && ch[1] == '5' && ch[2] == '1')
                position15();
  
            if(ch[0] == 'x' && ch[1] == '1' && ch[2] == '6' || ch[0] == 'x' && ch[1] == '6' && ch[2] == '1')
                position16();
  
            if(ch[0] == 'x' && ch[1] == '1' && ch[2] == '7' || ch[0] == 'x' && ch[1] == '7' && ch[2] == '1')
                position17();
  
            if(ch[0] == 'x' && ch[1] == '1' && ch[2] == '8' || ch[0] == 'x' && ch[1] == '8' && ch[2] == '1')
                position18();
            //END - FIRST COLUMN  
  
            //START - SECOND COLUMN
            if(ch[0] == 'x' && ch[1] == '2' && ch[2] == '3' || ch[0] == 'x' && ch[1] == '3' && ch[2] == '2')
                position23();
  
            if(ch[0] == 'x' && ch[1] == '2' && ch[2] == '4' || ch[0] == 'x' && ch[1] == '4' && ch[2] == '2')
                position24();
  
            if(ch[0] == 'x' && ch[1] == '2' && ch[2] == '5' || ch[0] == 'x' && ch[1] == '5' && ch[2] == '2')
                position25();
  
            if(ch[0] == 'x' && ch[1] == '2' && ch[2] == '6' || ch[0] == 'x' && ch[1] == '6' && ch[2] == '2')
                position26();
  
            if(ch[0] == 'x' && ch[1] == '2' && ch[2] == '7' || ch[0] == 'x' && ch[1] == '7' && ch[2] == '2')
                position27();
  
            if(ch[0] == 'x' && ch[1] == '2' && ch[2] == '8' || ch[0] == 'x' && ch[1] == '8' && ch[2] == '2')
                position28();
            //END - SECOND COLUMN  
  
            //START - THIRD COLUMN
            if(ch[0] == 'x' && ch[1] == '3' && ch[2] == '4' || ch[0] == 'x' && ch[1] == '4' && ch[2] == '3')
                position34();
  
            if(ch[0] == 'x' && ch[1] == '3' && ch[2] == '5' || ch[0] == 'x' && ch[1] == '5' && ch[2] == '3')
                position35();
  
            if(ch[0] == 'x' && ch[1] == '3' && ch[2] == '6' || ch[0] == 'x' && ch[1] == '6' && ch[2] == '3')
                position36();
  
            if(ch[0] == 'x' && ch[1] == '3' && ch[2] == '7' || ch[0] == 'x' && ch[1] == '7' && ch[2] == '3')
                position37();
  
            if(ch[0] == 'x' && ch[1] == '3' && ch[2] == '8' || ch[0] == 'x' && ch[1] == '8' && ch[2] == '3')
                position34();
            //END - THIRD COLUMN  
  
            //START - FOURTH COLUMN
            if(ch[0] == 'x' && ch[1] == '4' && ch[2] == '5' || ch[0] == 'x' && ch[1] == '5' && ch[2] == '4')
                position45();
  
            if(ch[0] == 'x' && ch[1] == '4' && ch[2] == '6' || ch[0] == 'x' && ch[1] == '6' && ch[2] == '4')
                position46();
  
            if(ch[0] == 'x' && ch[1] == '4' && ch[2] == '7' || ch[0] == 'x' && ch[1] == '7' && ch[2] == '4')
                position47();
  
            if(ch[0] == 'x' && ch[1] == '4' && ch[2] == '8' || ch[0] == 'x' && ch[1] == '8' && ch[2] == '4')
                position48();
            //END - FOURTH COLUMN  
  
            //START - FIFTH COLUMN
            if(ch[0] == 'x' && ch[1] == '5' && ch[2] == '6' || ch[0] == 'x' && ch[1] == '6' && ch[2] == '5')
                position56();
  
            if(ch[0] == 'x' && ch[1] == '5' && ch[2] == '7' || ch[0] == 'x' && ch[1] == '7' && ch[2] == '5')
                position57();
  
            if(ch[0] == 'x' && ch[1] == '5' && ch[2] == '8' || ch[0] == 'x' && ch[1] == '8' && ch[2] == '5')
                position58();
            //END - FIFTH COLUMN            
  
            //START - SIXTH COLUMN
            if(ch[0] == 'x' && ch[1] == '6' && ch[2] == '7' || ch[0] == 'x' && ch[1] == '7' && ch[2] == '6')
                position67();
  
            if(ch[0] == 'x' && ch[1] == '6' && ch[2] == '8' || ch[0] == 'x' && ch[1] == '8' && ch[2] == '6')
                position68();
            //END - SIXTH COLUMN  
  
            //START - SEVENT COLUMN
            if(ch[0] == 'x' && ch[1] == '7' && ch[2] == '8' || ch[0] == 'x' && ch[1] == '8' && ch[2] == '7')
                position78();
            //END - SEVENTH COLUMN
            
            ////END - If checks for double vehicle detected

            //To make sure what is being received from the serial port
            //Wirte on the serial to double check the characters on the Pyhton side
            Serial.print(ch[i]);

            //Flush to clear the received data
            Serial.flush();  
        }
        ////END - Handle detected vehicles        
    }
    ////END - Check serial connection status    
}
////////////////////////////////////////////////////////
////END - LOOP FUNCTION/////////////////////////////////

























