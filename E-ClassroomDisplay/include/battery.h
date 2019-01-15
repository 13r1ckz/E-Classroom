/******************************************************************************
 * File : Battery.h
 ******************************************************************************/
#ifndef BATTERY_H
#define BATTERY_H

/* Includes ------------------------------------------------------------------*/
#include <Arduino.h>

/* Defines -------------------------------------------------------------------*/
<<<<<<< HEAD
#define VOLT_REDUCTION 11 // R2/(R1+R2 ) R1 = 10k ohm, R2 = 1k ohm
#define ESP_VOLTAGE 3.2
#define MAX_ANALOG_VALUE 1024
#define OFFSET 0.30
#define BATTER_MIN_VOLT 3.5
=======
#define voltReduction 11 // 1/(R2/(R1+R2 ) R1 = 10k ohm, R2 = 1k ohm
#define espVoltage 3.2 //the max input voltage for nodemcu 1.0
#define maxAnalogValue 1024 //the max analog value of the esp8266
#define offset 0.30 //offset for getting a accurate measuring 
#define batteryMinVolt 3.2 // lowest voltage that the battery can give 
#define numberOfMeasurings 10 // how much measurings
>>>>>>> ESP8266-Display
/* Classes -------------------------------------------------------------------*/
class Battery{
public:
void batteryPercentage();
private:
float getVoltage();
};
uint8_t getBatteryPercentage();

#endif