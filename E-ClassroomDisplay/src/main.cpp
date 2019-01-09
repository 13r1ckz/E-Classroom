/******************************************************************************
 * File : Main program
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Defines -------------------------------------------------------------------*/
#define SLEEP 0
#define ESP8266_sec 1000000

Display display;
Connection connection;
Main main;
int8_t error;

// ----------------------------------------------------------------------------
// Main (Setup)
// ----------------------------------------------------------------------------
void setup(){
  pinMode(MOSFET, OUTPUT);
  display.initDisplay();
  while(!Serial);
  error = connection.WiFi_innit(display);
  if(error == -1){
    Serial.println("Going into bitch ass sleep");
    main.setSleep(0, 30);
  }
  display.updateDisplay();
  #if SLEEP
    Serial.println("Going to sleep.");
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