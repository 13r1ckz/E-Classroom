#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "display.h"
#include "connection.h"

class Main
{
  public:
    void setSleep(uint32_t min, uint8_t sec);
};