#include <Arduino.h>
#include "display.h"
#include "connection.h"

class Main
{
  public:
    void setSleep(uint32_t min, uint8_t sec);
    void setTestData();
};