#include "ChooseMapEngine.h"

void Map_Engine_First(){
    digitalWrite(PIN_D38_CHANGE_MAPS, LOW); //First ON -> MAP1
    //GaugeOFF();
    DailyGauge();
    autoGauge_colorRED_OFF();
    Display_Write("MAP 1", DELAY_OLED, TEXT_SIZE_4);
    //rtc_date_time(DELAY_OLED); //Run o'clock
}

void Map_Engine_Second(){
    //if(Read_Temp_Oil() >= TEMP_OIL_MAP_2){
    //    digitalWrite(PIN_D38_CHANGE_MAPS, HIGH); //First ON -> MAP1
    //}
    RacingGauge();
    autoGauge_colorRED_ON();
   // Display_Write("MAP 2", DELAY_OLED, TEXT_SIZE_4);
}