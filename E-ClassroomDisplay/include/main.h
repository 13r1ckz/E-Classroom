#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>
#include "display.h"
#include "connection.h"
#include "battery.h"


/* Defines -------------------------------------------------------------------*/
#define SLEEP 0
#define ESP8266_sec 1000000

class Main
{
  public:
    void setSleep(uint32_t min, uint8_t sec);
    void setTestData();
};
#endif
