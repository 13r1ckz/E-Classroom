/******************************************************************************
 * File : Battery.cpp
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "battery.h"
// ----------------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------------
uint8_t mosfet = D3;
uint8_t percentage = 0;
// ----------------------------------------------------------------------------
// Functions
// ----------------------------------------------------------------------------
void Battery::batteryPercentage(){
  pinMode(mosfet, OUTPUT);
  digitalWrite(mosfet, HIGH);
  float volt = getVoltage();
  percentage = (volt - BATTER_MIN_VOLT) * 100;
  digitalWrite(mosfet, LOW);
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
  volt = VOLT_REDUCTION * sample * ESP_VOLTAGE/ MAX_ANALOG_VALUE; 
  volt = volt - OFFSET;
  Serial.println(volt);
  return volt;
}
 uint8_t getBatteryPercentage(){
   return percentage;
 }