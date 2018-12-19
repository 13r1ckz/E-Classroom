#ifndef CONNECTION_H
#define CONNECTION_H

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "display.h"
extern "C"{
	#include <node.h>
}

class Connection
{
  public:
    uint32_t getMin();
    uint8_t getSec();
    void WiFi_innit(Display display);
    int getBatteryStatus();

  protected:
    uint8_t seconds;
    uint32_t minutes;
    void TCPConnect(Display display);
    void TCPsendRequest(String string, WiFiClient client);
    void TCPcloseConnection(WiFiClient client);
    String TCPreceivePacket(WiFiClient client);
    void parsePacket(String string);
    void setAllScreenData(NodeList nodelist);
};
#endif