#ifndef DISPLAY_OLED_H
#define DISPLAY_OLED_H

#include "Configuration.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h> 
#include <Arduino.h>

extern Adafruit_SSD1306 display;

//Show information on OLED display
void Display_Write(String value_print, uint16_t value_delay, int textSize); //Declaration

//Show value from EGT sensor
void Display_Write_EGT(float value_print, int value_delay, int textSize);

/**
//Show value from acceleration on OLED display
void Display_Write_Acceleration(String string_print, int value_print, String string_print2, int value_print2, String string_print3, int value_print3, int textSize);
**/

#endif



