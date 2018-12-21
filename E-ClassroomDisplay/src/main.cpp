/******************************************************************************
 * File : Main program
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Defines -------------------------------------------------------------------*/
#define SLEEP 1
#define ESP8266_sec 1000000

Display display;
Connection connection;
Main main;

// ----------------------------------------------------------------------------
// Main (Setup)
// ----------------------------------------------------------------------------
void setup(){
  main.setTestData();
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
  time = (min + sec)*ESP8266_sec;
  ESP.deepSleep(time);
}

void Main::setTestData(){
  display.setClassroom("T5.66");
  display.setClassroomText("Collegezaal-(M)-Theorie");
  display.setTime1("8:30 - 10:30");
  display.setTime2("11:30 - 14:30");
  display.setLecture1("Engels 2");
  display.setLecture2("Microprocessor Architectuur");
  display.setTeacher1("Bailey, Marlies");
  display.setTeacher2("Hakvoort, Gido");
  display.setTimeFree("10:30 - 11:30");
}