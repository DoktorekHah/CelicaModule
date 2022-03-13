#include "Probe_EGT.h"

float reading, voltage, temperature;

float get_voltage(int raw_adc) {
  return raw_adc * (AREF / (pow(2, ADC_RESOLUTION)-1));  
}

float get_temperature(float voltage) {
  return (voltage - 1.25) / 0.005;
}

void egt_read_cyl_1() {
  reading = analogRead(PIN_A10_EGT_CYL1);
  voltage = get_voltage(reading);
  temperature = get_temperature(voltage);
  Display_Write_EGT(temperature, DELAY_OLED, TEXT_SIZE_4);
  #ifdef DEBUG_EGT
    Serial.print("TempCyl1 = ");
    Serial.print(temperature);
    Serial.println(" C");
  #endif
  delay(500);
}


void egt_read_cyl_2() {
  reading = analogRead(PIN_A8_EGT_CYL2);
  voltage = get_voltage(reading);
  temperature = get_temperature(voltage);
  Display_Write_EGT(temperature, DELAY_OLED, TEXT_SIZE_4);
  #ifdef DEBUG_EGT
    Serial.print("TempCyl2 = ");
    Serial.print(temperature);
    Serial.println(" C");
  #endif
  delay(500);
}

void egt_read_cyl_4() {
  reading = analogRead(PIN_A6_EGT_CYL4);
  voltage = get_voltage(reading);
  temperature = get_temperature(voltage);
  Display_Write_EGT(temperature, DELAY_OLED, TEXT_SIZE_4);
  #ifdef DEBUG_EGT
    Serial.print("TempCyl4 = ");
    Serial.print(temperature);
    Serial.println(" C");
  #endif
  delay(500);
}