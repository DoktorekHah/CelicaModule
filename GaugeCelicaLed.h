#ifndef GAUGE_FUNCTION_H
#define GAUGE_FUNCTION_H

#include "Configuration.h"
#include <Adafruit_NeoPixel.h>

//Configuration for LED_RPM_GAUGE
extern Adafruit_NeoPixel backplane_rpm;
extern Adafruit_NeoPixel frontplane_rpm;
//Configuration for LED_SPEED_GAUGE
extern Adafruit_NeoPixel backplane_speed;
extern Adafruit_NeoPixel frontplane_speed;
//Configuration for DISPLAY
extern Adafruit_NeoPixel display_lcd;

//variable for functions
extern int daily_gauge_loop;
extern int brightenss_FrontPlane;
extern int brightenss_BackPlane;
extern int brightenss_display;
extern int firstStart;

// function 
void DailyGauge();
void RacingGauge();
void FunnyGauge();
void BackPlane();
void FrontPlane();
void GaugeOFF();  
void BrightnessDeafult();
void BrightnessBrighter();
//handler

//FUNCTIONS FOR LED'S
/**TODO napisac funkcje z parametrami i zmniejszyc ilosc kodu i zmienić delay na millis()**/
int BackPlane_RPM(int FirstColor, int SecondColor, int ThirdColor);

int FrontPlane_RPM(int FirstColor, int SecondColor, int ThirdColor);

int BackPlane_Speed(int FirstColor, int SecondColor, int ThirdColor);

int FrontPlane_Speed(int FirstColor, int SecondColor, int ThirdColor);

int Display_LCD(int FirstColor, int SecondColor, int ThirdColor);

#endif