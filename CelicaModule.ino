#include <Adafruit_NeoPixel.h>
#include "Configuration.h"
#include "Gauge_function.h"
#include "O_clock.h"
#include "Warning_Info.h"
#include "MPU_6050_Config.h"
#include "ChooseMapEngine.h"
#include "OilSensor.h"
#include "Probe_EGT.h"

void setup() {
  //Pins_Digital_config
  
  pinMode(PIN_D2_CHANGE_COLOR_AUTOGAUGE,  OUTPUT); //zmiana koloru zegarow autogauge
  pinMode(PIN_D42_LC_ACTIVE,              OUTPUT); //Sterowanie Lauch Control ON/OFF -> OUT
  //pinMode(PIN_D6_RTC_CLK,               OUTPUT); //RTC
  //pinMode(PIN_D8_RTC_DAT,               OUTPUT); //RTC
  pinMode(PIN_D10_BACKPLANE_SPEED,        OUTPUT); //Steorwanie ledami back_speed
  pinMode(PIN_D12_FRONTPLANE_RPM,         OUTPUT); //Sterowanie ledami front_RPM
  pinMode(PIN_D14_BACKPLANE_RPM,          OUTPUT); //Sterowanie ledami back_RPM
  pinMode(PIN_D16_FRONTPLANE_SPEED,       OUTPUT); //Sterowanie ledami front_speed
  //pinMode(PIN_D20_SDA_OLED_MPU6050,     OUTPUT); //SDA dla OLED i MPU6050
  //pinMode(PIN_D21_SCL_OLED_MPU6050,     OUTPUT); //SCL dla OLED i MPU6050
  pinMode(PIN_D38_CHANGE_MAPS,            OUTPUT); //Sterowanie MAP1/MAP2
  pinMode(PIN_D40_DISPLAY_GAUGE,          OUTPUT); //Sterowanie ledami display_LCD_Gauge
  //pinMode(PIN_D42_RTC_RST,              OUTPUT); //RTC
  pinMode(PIN_D44_BUTTON_WHEEL_RIGHT,     INPUT);  //INPUT_PULLUP, Przycisk prawy w kierownicy
  pinMode(PIN_D46_BUTTON_WHEEL_LEFT,      INPUT);  //INPUT_PULLUP, PRzycisk lewy w kierownicy
  pinMode(PIN_D47_CRUISE_CONTROL_UP,      INPUT);  //INPUT_PULLUP, PRzycisk na końcu manetki tempomatu - zmiana MAP1/MAP2
  //Pins_Digital_config
  
  pinMode(PIN_A0_CRUISE_CONTROL,          INPUT_PULLUP);    //Sterowanie manetką tempomatu góra/dół/do siebie
/** Pins_Analog
  pinMode(PIN_A2_SENSOR_TEMP_OIL, INPUT);                           
  pinMode(PIN_A4_SENSOR_PRESSURE_OIL, INPUT);                           
  pinMode(PIN_A6_EGT_CYL4, INPUT);                           
  pinMode(PIN_A8_EGT_CYL2, INPUT);                               
  pinMode(PIN_A10_EGT_CYL1, INPUT);                          
Pins_Analog **/
/**------------------------------------------------------------------**/
 
//Pixel_config
  backplane_rpm.begin();
  backplane_rpm.setBrightness(brightenss_BackPlane);
  frontplane_rpm.begin();
  frontplane_rpm.setBrightness(brightenss_FrontPlane);
  backplane_speed.begin();
  backplane_speed.setBrightness(brightenss_BackPlane);
  frontplane_speed.begin();
  frontplane_speed.setBrightness(brightenss_FrontPlane);
  display_lcd.begin();
  display_lcd.setBrightness(brightenss_display);
  
//Pixel_config
/**------------------------------------------------------------------**/
//Serial_config
  Serial.begin(SERIAL);
//Serial_config

//RTC config
  RtcDateTime compiled = RtcDateTime(__TIME__);
  Rtc.Begin();
//RTC config

//DisplayOLED config
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
  }
//DisplayOLED config

//MPU_6050
  Wire.begin();
  MPU6050_Init();
//MPU_6050

Map_Engine_First(); //

}

void loop() {
  //Accelerometer();
  rtc_date_time(DELAY_OLED); //Run o'clock
}
