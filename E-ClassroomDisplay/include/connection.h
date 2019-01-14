/******************************************************************************
 * File : Connection.h
 ******************************************************************************/
#ifndef CONNECTION_H
#define CONNECTION_H

/* Defines ------------------------------------------------------------------*/
#define PI_SERVER 0
#define WIFI_CONNECTION_TIMEOUT 20
#define NUMBER_OF_DISPLAY_ELEMENTS 9
#define MAX_TCP_MSG_SIZE 255
#define LONG_SLEEP 3
#define TCP_CONNECTION_TIMEOUT_ERROR -1
#define WIFI_CONNECTION_TIMEOUT_ERROR -2
#define TCP_END_OF_TRANSMISSION '\3'
#define TCP_SLEEP_COMMAND '\4'
#define DEBUG 0
#define YES 1
#define NO 0

/* Includes ------------------------------------------------------------------*/
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "display.h"
#include "battery.h"

/* Classes -------------------------------------------------------------------*/
class Connection{
  public:
    uint32_t getMin();
    uint8_t getSec();
    int8_t WiFi_innit(Display display);
    int getBatteryStatus();
  protected:
    uint8_t seconds = 0;
    uint32_t minutes = 15;
    int8_t TCPConnect(Display display);
    void TCPsendRequest(String string, WiFiClient client);
    void TCPcloseConnection(WiFiClient client);
    String TCPreceivePacket(WiFiClient client);
    void parsePacket(String string);
    void setAllScreenData(Display display);
};
#endif
