#include <ThreeWire.h>  
#include <RtcDS1302.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include "Configuration.h"

void rtc_date_time(int value_delay);

ThreeWire myWire(PIN_D6_RTC_DAT, PIN_D8_RTC_CLK, PIN_D4_RTC_RST); // IO, SCLK, CE (INTERRPUT)
RtcDS1302<ThreeWire> Rtc(myWire);

#define countof(a) (sizeof(a) / sizeof(a[0]))

void printDateTime(const RtcDateTime& dt){
    char datestring[20];
    
    snprintf_P(datestring, 
            countof(datestring),
            PSTR("%02u:%02u:%02u"),
            dt.Hour(), dt.Minute(), dt.Second() );
    Serial.print(datestring);
    Display_Write(datestring, DELAY_OLED, TEXT_SIZE_4);
}
  
void rtc_date_time(int value_delay){
    RtcDateTime now = Rtc.GetDateTime();
    printDateTime(now);
    Serial.print(now);
    delay(value_delay);
}
