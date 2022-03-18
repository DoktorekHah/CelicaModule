#ifndef CONFIGURATION_H
#define CONFIGURATION_H

//DEBUG MODE
//#define DEBUG
//#define DEBUG_MPU  //MPU6050_Debug
//#define DEBUG_SENSOR_OIL
#define DEBUG_EGT
//DEBUG MODE

//Pins 
#define PIN_D2_CHANGE_COLOR_AUTOGAUGE    2
#define PIN_D4_RTC_RST                   4
#define PIN_D6_RTC_DAT                   6
#define PIN_D8_RTC_CLK                   8
#define PIN_D10_BACKPLANE_SPEED          10
#define PIN_D12_FRONTPLANE_RPM           12
#define PIN_D14_BACKPLANE_RPM            14
#define PIN_D16_FRONTPLANE_SPEED         16
#define PIN_D20_SDA_OLED_MPU6050         20
#define PIN_D21_SCL_OLED_MPU6050         21
#define PIN_D38_CHANGE_MAPS              38
#define PIN_D42_DISPLAY_GAUGE            42
//#define PIN_D42_LC_ACTIVE                42  
#define PIN_D44_BUTTON_WHEEL_RIGHT       44
#define PIN_D46_BUTTON_WHEEL_LEFT        46
#define PIN_D47_CRUISE_CONTROL_UP        47
#define PIN_A0_CRUISE_CONTROL            A0
#define PIN_A2_SENSOR_TEMP_OIL           A2
#define PIN_A4_SENSOR_PRESSURE_OIL       A4
#define PIN_A6_EGT_CYL4                  A6
#define PIN_A8_EGT_CYL2                  A8
#define PIN_A10_EGT_CYL1                 A10
//Pins 

//Serial
#define SERIAL                     9600     //Predkosc w bitach na sekunde(baud)
//Serial

//Loop
#define TRUE                       1        //Wartosc dla petli while
#define FALSE                      0
//Loop

//GAUGE_RPM_AND_SPEED_CONFIG

//RPM_GAUGE
//#define PIN_D7_BACKPLANE_RPM D7
//#define PIN_D6_FRONTPLANE_RPM D6
#define QUANTITY_LED_BACKPLANE_RPM  4
#define QUANTITY_LED_FRONTPLANE_RPM 13

//SPEED_GAUGE
//#define PIN_D5_FRONTPLANE_SPEED D5
//#define PIN_D8_BACKPLANE_SPEED D8
#define QUANTITY_LED_BACKPLANE_SPEED 5
#define QUANTITY_LED_FRONTPLANE_SPEED 18

//DISPLAY
//#define PIN_D1_DISPLAY D1
#define QUANTITY_LED_DISPLAY 9

//Brightness gauge
#define BRIGHTNESS_FRONTPLANE 60 //75
#define BRIGHTNESS_BACKPLANE 60  //75
#define BRIGHTNESS_DISPLAY 60   //75

//Speed on Led Gauge
#define TIME_WAITING 80

#define NON_COLOR 0
#define RED_COLOR 255
#define GREEN_COLOR 255
#define BLUE_COLOR 255

#define ORANGE_COLOR_FIRST 49
#define ORANGE_COLOR_SECOND 229
#define ORANGE_COLOR_THIRD 36

#define FUNNY_COLOR_FIRST 150
#define FUNNY_COLOR_SECOND 90
#define FUNNY_COLOR_THIRD 200
//GAUGE_RPM_AND_SPEED_CONFIG

//Analog_Value
#define CRUISE_CONTROL_UP_VALUE    100
#define CRUISE_CONTROL_DOWN_VALUE  200
#define CRUISE_CONTROL_ROUND_VALUE 500
//Analog_Value

//Button_Gauge_Control
#define MAX_VALUE_GAUGE 5
/**-----------------------------------------------------------------------**/

//EGT_CONFIG
#define EGT_CYL_1 1
#define EGT_CYL_2 2
#define EGT_CYL_4 4
//EGT_CONFIG

//OLED
#define SCREEN_ADDRESS 0x3C
#define SCREEN_WIDTH  128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define DELAY_OLED    1000
#define TEXT_SIZE_2_5 2.5
#define TEXT_SIZE_3   3
#define TEXT_SIZE_3_5 3.5
#define TEXT_SIZE_4   4
#define OLED_RESET     4
//OLED

//MPU6050
//Ax: 0.11 Ay: 0.93 Az: -0.25
//Ax: 0.83 Ay: 0.54 Az: 0.36 T: 28.86

#define STILL_x 0.5
#define STILL_y 0.5
#define STILL_z 1.0
#define DELAY 500
//MPU6050

//SENSOR OIL TEMP/PRESSURE - DO KALIBRACJI
#define TEMP_OIL_MAX 130
#define TEMP_OIL_MAP_2 70
#define TEMP_OIL_WARINING 125
//SENSOR OIL TEMP/PRESSURE 

//EGT
#define AREF 3.3           // set to AREF, typically board voltage like 3.3 or 5.0
#define ADC_RESOLUTION 10  // set to ADC bit resolution, 10 is default
//EGT
 
#endif