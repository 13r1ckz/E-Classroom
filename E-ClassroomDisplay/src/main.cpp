/******************************************************************************
 * File : Main program
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "main.h"

// ----------------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------------
int8_t state;
uint8_t batteryPercentage;

Display display;
Connection connection;
Battery battery;
Main main;

// ----------------------------------------------------------------------------
// Main (Setup)
// ----------------------------------------------------------------------------
void setup(){
  display.initDisplay();
  battery.batteryPercentage();
  while(!Serial);
  state = connection.WiFi_innit(display);
  if(state == 3){
    #if DEBUG
      Serial.println("Sleeping for 60 min");
    #endif
    main.setSleep(60, 0);
  }
  if(state == -1){
    #if DEBUG
      Serial.println("Sleeping for 10 seconds");
    #endif
    main.setSleep(0, 10);
  }
  if(state == -2){
	#if DEBUG
    	Serial.println("Sleeping for 10 seconds");
    #endif
	main.setSleep(0, 10);
  }
  display.updateDisplay();
  #if SLEEP
  	#if DEBUG
    	//Serial.println("Going to sleep.");
    #endif
	main.setSleep(connection.getMin(), connection.getSec());
  #else
	#if DEBUG
    	Serial.println("Running without sleep mode.");
	#endif
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
/**
* @brief Sets system to Sleep for given amount of time
* @retuns None
* @note Needs min and sec
*/
void Main::setSleep(uint32_t min, uint8_t sec){
  uint32_t time;
  time = ((min*60) + sec)*ESP8266_sec;
  ESP.deepSleep(time);
}

/**
* @brief Sets testdata
* @retuns None
* @note Temp test function
*/
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