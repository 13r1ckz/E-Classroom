/******************************************************************************
 * File : Battery.cpp
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "battery.h"

// ----------------------------------------------------------------------------
// Functions
// ----------------------------------------------------------------------------
int Battery::batteryPercentage(){
  int percentage = 0; 
  float volt = getVoltage();
  percentage = (volt - 3.2) * 100;
  return percentage;
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
  return volt;
}