/******************************************************************************
 * File : Battery.cpp
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "battery.h"
// ----------------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------------
uint8_t MOSFET = D3;
uint8_t percentage = 0;
// ----------------------------------------------------------------------------
// Functions
// ----------------------------------------------------------------------------
void Battery::batteryPercentage(){
  pinMode(MOSFET, OUTPUT);
  digitalWrite(MOSFET, HIGH);
  float volt = getVoltage();
  percentage = (volt - batteryMinVolt) * 100;
  digitalWrite(MOSFET, LOW);
}

float Battery::getVoltage(){
  float sample = 0;
  float volt = 0;
  for(int i=0;i< 10 ;i++)
  {
   sample = sample + analogRead(A0); //read the voltage from the divider circuit
   delay(5);
  }
  sample = sample / 10; 
  volt = voltReduction * sample * espVoltage/ maxAnalogValue; 
  volt = volt - offset;
  Serial.println(volt);
  return volt;
}
 uint8_t getBatteryPercentage(){
   return percentage;
 }