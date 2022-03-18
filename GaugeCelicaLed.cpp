#include "GaugeCelicaLed.h"

//Configuration for LED_RPM_GAUGE
Adafruit_NeoPixel backplane_rpm = Adafruit_NeoPixel(QUANTITY_LED_BACKPLANE_RPM, PIN_D14_BACKPLANE_RPM, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel frontplane_rpm = Adafruit_NeoPixel(QUANTITY_LED_FRONTPLANE_RPM, PIN_D12_FRONTPLANE_RPM, NEO_GRB + NEO_KHZ800);
//Configuration for LED_SPEED_GAUGE
Adafruit_NeoPixel backplane_speed = Adafruit_NeoPixel(QUANTITY_LED_BACKPLANE_SPEED, PIN_D10_BACKPLANE_SPEED, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel frontplane_speed = Adafruit_NeoPixel(QUANTITY_LED_FRONTPLANE_SPEED, PIN_D16_FRONTPLANE_SPEED, NEO_GRB + NEO_KHZ800);
//Configuration for DISPLAY
Adafruit_NeoPixel display_lcd = Adafruit_NeoPixel(QUANTITY_LED_DISPLAY, PIN_D42_DISPLAY_GAUGE, NEO_GRB + NEO_KHZ800);

//variable for functions
int daily_gauge_loop;
int brightenss_FrontPlane = BRIGHTNESS_FRONTPLANE;
int brightenss_BackPlane  = BRIGHTNESS_BACKPLANE;
int brightenss_display    = BRIGHTNESS_DISPLAY;
int firstStart = TRUE;

//FUNCTIONS FOR LED'S
/**TODO napisac funkcje z parametrami i zmniejszyc ilosc kodu i zmienić delay na millis()**/
int BackPlane_RPM(int FirstColor, int SecondColor, int ThirdColor){
  for(daily_gauge_loop = 0; daily_gauge_loop < backplane_rpm.numPixels(); daily_gauge_loop++){
    #ifdef DEBUG
      Serial.print("Backplane_rpm = ");
      Serial.println(daily_gauge_loop);
    #endif
    backplane_rpm.setPixelColor(daily_gauge_loop, FirstColor, SecondColor, ThirdColor); // Dioda "i" oraz skladowe R=255 G=0 B=0
    backplane_rpm.show(); // Wysylamy dane do lancucha
    delay(TIME_WAITING);
  }
}
int FrontPlane_RPM(int FirstColor, int SecondColor, int ThirdColor){
  for(daily_gauge_loop = frontplane_rpm.numPixels(); daily_gauge_loop >= 0 ; daily_gauge_loop--){
    #ifdef DEBUG
      Serial.print("Frontplane_rpm = ");
      Serial.println(daily_gauge_loop);
    #endif
    frontplane_rpm.setPixelColor(daily_gauge_loop, FirstColor, SecondColor, ThirdColor); // Dioda "i" oraz skladowe R=255 G=0 B=0
    frontplane_rpm.show(); // Wysylamy dane do lancucha
    delay(TIME_WAITING);
  }
}
int BackPlane_Speed(int FirstColor, int SecondColor, int ThirdColor){
  for(daily_gauge_loop = 0; daily_gauge_loop < backplane_speed.numPixels(); daily_gauge_loop++){
    #ifdef DEBUG
      Serial.print("Backplane_Speed = ");
      Serial.println(daily_gauge_loop);
    #endif
    backplane_speed.setPixelColor(daily_gauge_loop, FirstColor, SecondColor, ThirdColor); // Dioda "i" oraz skladowe R=255 G=0 B=0
    backplane_speed.show(); // Wysylamy dane do lancucha
    delay(TIME_WAITING);
  }
}
int FrontPlane_Speed(int FirstColor, int SecondColor, int ThirdColor){
  for(daily_gauge_loop = frontplane_speed.numPixels(); daily_gauge_loop >= 0 ; daily_gauge_loop--){
    #ifdef DEBUG
      Serial.print("Frontplane_speed = ");
      Serial.println(daily_gauge_loop);
    #endif
    frontplane_speed.setPixelColor(daily_gauge_loop, FirstColor, SecondColor, ThirdColor); // Dioda "i" oraz skladowe R=255 G=0 B=0
    frontplane_speed.show(); // Wysylamy dane do lancucha
    delay(TIME_WAITING);
  }
}
int Display_LCD(int FirstColor, int SecondColor, int ThirdColor){
  for(daily_gauge_loop = 0; daily_gauge_loop < display_lcd.numPixels(); daily_gauge_loop++){
    #ifdef DEBUG
      Serial.print("Display = ");
      Serial.println(daily_gauge_loop);
    #endif
    display_lcd.setPixelColor(daily_gauge_loop, FirstColor, SecondColor, ThirdColor); // Dioda "i" oraz skladowe R=255 G=0 B=0
    display_lcd.show(); // Wysylamy dane do lancucha
    delay(TIME_WAITING);
  }
}

//FUNCTIONS FOR LED'S
void GaugeOFF(){
  #ifdef DEBUG
     Serial.println("GaugeOFF");
  #endif
  BackPlane_RPM(NON_COLOR, NON_COLOR, NON_COLOR);
  FrontPlane_RPM(NON_COLOR, NON_COLOR, NON_COLOR);
  BackPlane_Speed(NON_COLOR, NON_COLOR, NON_COLOR);
  FrontPlane_Speed(NON_COLOR, NON_COLOR, NON_COLOR);
  Display_LCD(NON_COLOR, NON_COLOR, NON_COLOR);
}

void DailyGauge(){
  #ifdef DEBUG
     Serial.println("DailyGauge");
  #endif
  BackPlane_RPM(ORANGE_COLOR_FIRST, ORANGE_COLOR_SECOND, ORANGE_COLOR_THIRD);
  FrontPlane_RPM(ORANGE_COLOR_FIRST, ORANGE_COLOR_SECOND, ORANGE_COLOR_THIRD);
  BackPlane_Speed(ORANGE_COLOR_FIRST, ORANGE_COLOR_SECOND, ORANGE_COLOR_THIRD);
  FrontPlane_Speed(ORANGE_COLOR_FIRST, ORANGE_COLOR_SECOND, ORANGE_COLOR_THIRD);
  Display_LCD(ORANGE_COLOR_FIRST, ORANGE_COLOR_SECOND, ORANGE_COLOR_THIRD);
}

void RacingGauge(){
  #ifdef DEBUG
     Serial.println("RacingGauge");
  #endif 
  BackPlane_RPM(RED_COLOR, NON_COLOR, NON_COLOR);
  FrontPlane_RPM(RED_COLOR, NON_COLOR, NON_COLOR);
  BackPlane_Speed(RED_COLOR, NON_COLOR, NON_COLOR);
  FrontPlane_Speed(RED_COLOR, NON_COLOR, NON_COLOR);
  Display_LCD(RED_COLOR, NON_COLOR, NON_COLOR);
}

void FunnyGauge(){
  #ifdef DEBUG
     Serial.println("FunnyGauge");
  #endif
  BackPlane_RPM(FUNNY_COLOR_FIRST, FUNNY_COLOR_SECOND, FUNNY_COLOR_THIRD);
  FrontPlane_RPM(FUNNY_COLOR_FIRST, FUNNY_COLOR_SECOND, FUNNY_COLOR_THIRD);
  BackPlane_Speed(FUNNY_COLOR_FIRST, FUNNY_COLOR_SECOND, FUNNY_COLOR_THIRD);
  FrontPlane_Speed(FUNNY_COLOR_FIRST, FUNNY_COLOR_SECOND, FUNNY_COLOR_THIRD);
  Display_LCD(FUNNY_COLOR_FIRST, FUNNY_COLOR_SECOND, FUNNY_COLOR_THIRD);
}

void FrontPlane(){
  #ifdef DEBUG
     Serial.println("FrontPlane");
  #endif
  BackPlane_RPM(NON_COLOR, NON_COLOR, NON_COLOR);
  FrontPlane_RPM(0, 0, BLUE_COLOR);
  BackPlane_Speed(NON_COLOR, NON_COLOR, NON_COLOR);
  FrontPlane_Speed(0, 0, BLUE_COLOR);
  Display_LCD(0, 0, BLUE_COLOR);
}

void BackPlane(){
  #ifdef DEBUG
     Serial.println("BackPlane");
  #endif
  BackPlane_RPM(RED_COLOR, GREEN_COLOR, BLUE_COLOR);
  FrontPlane_RPM(NON_COLOR, NON_COLOR, NON_COLOR);
  BackPlane_Speed(RED_COLOR, GREEN_COLOR, BLUE_COLOR);
  FrontPlane_Speed(NON_COLOR, NON_COLOR, NON_COLOR);
  Display_LCD(RED_COLOR, GREEN_COLOR, BLUE_COLOR);
}
