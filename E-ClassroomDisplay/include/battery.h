/******************************************************************************
 * File : Battery.h
 ******************************************************************************/
#ifndef BATTERY_H
#define BATTERY_H

/* Includes ------------------------------------------------------------------*/
#include <Arduino.h>

/* Defines -------------------------------------------------------------------*/
#define voltReduction 11 // R2/(R1+R2 ) R1 = 10k ohm, R2 = 1k ohm
#define espVoltage 3.2
#define maxAnalogValue 1024
#define offset 0.30
#define batteryMinVolt 3.5
/* Classes -------------------------------------------------------------------*/
class Battery{
public:
void batteryPercentage();
private:
float getVoltage();
};

uint8_t getBatteryPercentage();

#endif