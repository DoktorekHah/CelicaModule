#ifndef PROBE_EGT_H
#define PROBE_EGT_H

#include "Configuration.h"
#include "Display_OLED.h"

float get_voltage(int raw_adc);

float get_temperature(float voltage);

void egt_read_cyl_1();

void egt_read_cyl_2();

void egt_read_cyl_4();

#endif