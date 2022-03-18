#include "AutoGauge.h"

//Control color BLUE/RED with BC547 and relay
void autoGauge_colorRED_ON(){
    digitalWrite(PIN_D2_CHANGE_COLOR_AUTOGAUGE, HIGH);
}

void autoGauge_colorRED_OFF(){
    digitalWrite(PIN_D2_CHANGE_COLOR_AUTOGAUGE, LOW);
}