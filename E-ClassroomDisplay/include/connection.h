#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

class Connection
{
  public:
    uint32_t getMin();
    uint8_t getSec();
    void WiFi_innit();

  protected:
    uint8_t seconds;
    uint32_t minutes;
};