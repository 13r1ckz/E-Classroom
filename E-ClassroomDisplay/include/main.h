#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>
#include "display.h"
#include "connection.h"
#include "battery.h"
unsigned char MOSFET = D3;

class Main
{
  public:
    void setSleep(uint32_t min, uint8_t sec);
    void setTestData();
};
#endif
