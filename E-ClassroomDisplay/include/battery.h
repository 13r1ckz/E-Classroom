/******************************************************************************
 * File : Battery.h
 ******************************************************************************/
#ifndef BATTERY_H
#define BATTERY_H

/* Includes ------------------------------------------------------------------*/
#include <Arduino.h>

/* Defines -------------------------------------------------------------------*/
#define voltReduction 11 // 1/(R2/(R1+R2 ) R1 = 10k ohm, R2 = 1k ohm
#define espVoltage 3.2 //the max input voltage for nodemcu 1.0
#define maxAnalogValue 1024 //the max analog value of the esp8266
#define offset 0.30 //offset for getting a accurate measuring 
#define batteryMinVolt 3.2 // lowest voltage that the battery can give 
#define numberOfMeasurings 10 // how much measurings
/* Classes -------------------------------------------------------------------*/
class Battery{
public:
void batteryPercentage();
private:
float getVoltage();
};
uint8_t getBatteryPercentage();

#endif