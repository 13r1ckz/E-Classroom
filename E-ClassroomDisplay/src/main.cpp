/******************************************************************************
 * File : Main program
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Defines -------------------------------------------------------------------*/
#define SLEEP 0

Display display;
Connection connection;
Main main;

// ----------------------------------------------------------------------------
// Main (Setup)
// ----------------------------------------------------------------------------
void setup(){
  display.initDisplay();
  while(!Serial);
  display.updateDisplay();
  connection.WiFi_innit(display);
  #if SLEEP
    main.setSleep(connection.getMin(), connection.getSec());
  #else
    Serial.println("Running without sleep mode.");
  #endif
}

// ----------------------------------------------------------------------------
// Main (Loop)
// ----------------------------------------------------------------------------
void loop(){
  //do nothing
}

// ----------------------------------------------------------------------------
// Functions
// ----------------------------------------------------------------------------
void Main::setSleep(uint32_t min, uint8_t sec){
  uint32_t time;
  time = (min + sec)*10^6;
  ESP.deepSleep(time);
}