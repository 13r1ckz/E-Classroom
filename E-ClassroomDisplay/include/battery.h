/******************************************************************************
 * File : Battery.h
 ******************************************************************************/
#ifndef BATTERY_H
#define BATTERY_H

/* Includes ------------------------------------------------------------------*/
#include <Arduino.h>

/* Defines -------------------------------------------------------------------*/
#define VOLT_REDUCTION 11 // R2/(R1+R2 ) R1 = 10k ohm, R2 = 1k ohm
#define ESP_VOLTAGE 3.2
#define MAX_ANALOG_VALUE 1024
#define OFFSET 0.30
#define BATTER_MIN_VOLT 3.5
/* Classes -------------------------------------------------------------------*/
class Battery{
public:
void batteryPercentage();
private:
float getVoltage();
};

uint8_t getBatteryPercentage();

#endif