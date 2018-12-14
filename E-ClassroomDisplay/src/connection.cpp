/******************************************************************************
 * File : Connection.cpp
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "connection.h"

// ----------------------------------------------------------------------------
// Functions
// ----------------------------------------------------------------------------
uint32_t Connection::getMin(){
    return minutes * 60;
}

uint8_t Connection::getSec(){
    return seconds;
}

void Connection::WiFi_innit(){
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}