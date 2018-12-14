#include "connection.h"

const char* ssid = "devices";
const char* password = "toitoitoi";
IPAddress ip(145,44,187,14);
IPAddress gateway(145,44,187,1);
IPAddress subnet(255,255,255,128);
//static IP

uint32_t Connection::getMin(){
    return minutes*60;
}
uint8_t Connection::getSec(){
    return seconds;
}

void Connection::WiFi_innit(){
    WiFi.begin(ssid, password);
    WiFi.config(ip, gateway, subnet);
    while(WiFi.status()!=WL_CONNECTED){
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");  
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}