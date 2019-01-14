/******************************************************************************
 * File : Battery.cpp
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "battery.h"
// ----------------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------------
uint8_t MOSFET = D3; // Mosfet gate trigger pin 
uint8_t percentage; // Battery percentage 
// ----------------------------------------------------------------------------
// Functions
// ----------------------------------------------------------------------------
void Battery::batteryPercentage(){ 
  pinMode(MOSFET, OUTPUT);
  digitalWrite(MOSFET, HIGH);
  float volt = getVoltage(); //gets a double back 
  percentage = (volt - batteryMinVolt) * 100; //voltage minus battery * 100 to get a range between 0 and 100
  digitalWrite(MOSFET, LOW);
}

float Battery::getVoltage(){
  float sample = 0;
  float volt = 0;
  for(int i=0;i< numberOfMeasurings ;i++)
  {
   sample = sample + analogRead(A0); //read the voltage from the divider circuit
   delay(5); //wait 5 milis for an accurate measuring 
  }
  sample = sample / numberOfMeasurings; //average of the 10 measurings 
  volt = voltReduction * sample * espVoltage/ maxAnalogValue; //formula to calculate the battery voltage
  volt = volt - offset;
  return volt;
}
 uint8_t getBatteryPercentage(){
   return percentage;
 }