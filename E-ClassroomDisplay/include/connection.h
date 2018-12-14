/******************************************************************************
 * File : Connection.h
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
/* Classes -------------------------------------------------------------------*/
class Connection{
  public:
    void WiFi_innit();
    uint32_t getMin();
    uint8_t getSec();
    
  private:
    uint8_t seconds;
    uint32_t minutes;
    const char* ssid;
    const char* password;
};