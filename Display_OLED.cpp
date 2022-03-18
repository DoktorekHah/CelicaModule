#include "Display_OLED.h"

//Config
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
//Config

//Show information on OLED display
void Display_Write(String value_print, uint16_t value_delay, int textSize){ //Definition
  display.clearDisplay();
  display.setCursor(5,5);
  display.setTextSize(textSize);
  display.setTextColor(SSD1306_WHITE); 
  display.println(value_print);
  display.display();
  //Serial.println("TEST_DW");
  delay(value_delay);
}
/** Check colors on display from Adafruit_SSD1306.h
#define BLACK SSD1306_BLACK     ///< Draw 'off' pixels
#define WHITE SSD1306_WHITE     ///< Draw 'on' pixels
#define INVERSE SSD1306_INVERSE ///< Invert pixels
**/
//Show value from EGT sensor

void Display_Write_EGT(float value_print, int value_delay, int textSize){
  display.clearDisplay();
  display.setCursor(5,5);
  display.setTextSize(textSize);

  display.print(value_print);
  display.println(" C");

  display.display();
  delay(value_delay);
}

/**
//Show value from acceleration on OLED display
void Display_Write_Acceleration(String string_print, int value_print, String string_print2, int value_print2, String string_print3, int value_print3, int textSize){
  display.clearDisplay();
  display.setCursor(5,5);
  display.setTextSize(textSize);

  display.print(string_print);
  display.print(": ");
  display.println(value_print);

  display.print(string_print2);
  display.print(": ");
  display.println(value_print2);

  display.print(string_print3);
  display.print(": ");
  display.println(value_print3);
  
  display.display();
}

/**
display.println("MAP 1");

display.print("EGT #1 ");
display.print(EGT_CYL_1);

display.print("EGT #2 ");
display.print(EGT_CYL_2);

display.print("EGT #4 ");
display.print(EGT_CYL_4);
**/
