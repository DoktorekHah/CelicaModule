#ifndef O_CLOCK_H
#define O_CLOCK_H

#include "Configuration.h"
#include "Display_OLED.h"
#include <Arduino.h>
#include <ThreeWire.h>  
#include <RtcDS1302.h>
#include <SPI.h>

extern ThreeWire myWire; // IO, SCLK, CE (INTERRPUT)
extern RtcDS1302<ThreeWire> Rtc;

void printDateTime(const RtcDateTime& dt); //Declaration

void rtc_date_time(int value_delay); //Declaration

#endif