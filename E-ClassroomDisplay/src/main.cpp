#include "main.h"

#define SLEEP 0

Display display;
Connection connection;
Main main;

void setup() {
  Serial.begin(115200);
  display.initDisplay();
  while(!Serial);
  display.updateDisplay();
  connection.WiFi_innit(display);
  // Serial.println(display.getLokaalText());
  // Serial.println(display.getLokaal());
  #if SLEEP
    main.setSleep(connection.getMin(), connection.getSec());
  #else
    Serial.println("Running without sleep mode.");
  #endif
}

void Main::setSleep(uint32_t min, uint8_t sec){
  uint32_t time;
  time = (min + sec)*10^6;
  ESP.deepSleep(time);
}
void loop() {
  //do nothing
}