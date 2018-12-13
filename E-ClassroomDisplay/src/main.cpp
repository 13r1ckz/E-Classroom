#include "main.h"

Display display;
Connection connection;
Main main;

void setup() {
  Serial.begin(115200);
  display.initDisplay();
  while(!Serial);
  display.updateDisplay();
  main.setSleep(connection.getMin(), connection.getSec());
}

void Main::setSleep(uint32_t min, uint8_t sec){
  uint32_t time;
  time = (min + sec)*10^6;
  ESP.deepSleep(time);
}
void loop() {
  //do nothing
}