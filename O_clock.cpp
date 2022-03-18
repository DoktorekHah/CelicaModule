#include "O_clock.h"

#define countof(a) (sizeof(a) / sizeof(a[0]))

//Config
ThreeWire myWire(PIN_D6_RTC_DAT, PIN_D8_RTC_CLK, PIN_D4_RTC_RST); // IO, SCLK, CE (INTERRPUT)
RtcDS1302<ThreeWire> Rtc(myWire);
//Config

void printDateTime(const RtcDateTime& dt){ //Definition
    char datestring[20];
    
    snprintf_P(datestring, 
            countof(datestring),
            PSTR("%02u:%02u"), //"%02u:%02u:%02u"
            dt.Hour(), dt.Minute()); //, dt.Second()
    Serial.println(datestring);
    Display_Write(datestring, DELAY_OLED, TEXT_SIZE_4);
}
  
void rtc_date_time(int value_delay){ //Definition
    //set_and_check_date_time();
    RtcDateTime now = Rtc.GetDateTime(); 
    printDateTime(now);
    delay(value_delay);
}