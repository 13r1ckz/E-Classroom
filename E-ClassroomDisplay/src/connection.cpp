/******************************************************************************
 * File : Connection.cpp
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "connection.h"

// ----------------------------------------------------------------------------
// Functions
// ----------------------------------------------------------------------------
#define MAX_TCP_MSG_SIZE 65535
#define DEBUG 1

const char *ssid = "devices";
const char *password = "toitoitoi";
const uint16_t port = 420;
const char* host=  "145.44.187.11";
IPAddress static_ip(145,44,187,12);
IPAddress gateway(145,44,187,1);
IPAddress subnet(255,255,255,128);

nodeList *data = (struct NodeList*) malloc(sizeof(nodeList));


uint32_t Connection::getMin(){
    return minutes * 60;
}

uint8_t Connection::getSec(){
    return seconds;
}

void Connection::WiFi_innit(Display display){
    
    WiFi.begin(ssid, password);
    WiFi.config(static_ip, gateway, subnet);
    while(WiFi.status()!=WL_CONNECTED){
        delay(500);
        #if DEBUG
            Serial.print(".");
        #endif
    }
    #if DEBUG
        Serial.println("");
        Serial.println("WiFi connected");  
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
    #endif
    TCPConnect(display);
}

void Connection::TCPConnect(Display display){
    WiFiClient client;
    if(!client.connect(host, port)){
        #if DEBUG
            Serial.println("TCP connection failed");
        #endif
        return;
    } else {
        #if DEBUG
            Serial.print("Connection established on port: ");
            Serial.println(port);
        #endif
    }
    TCPsendRequest("Gentstudent42.2", client);
    parsePacket((TCPreceivePacket(client)));
    //client.println(TCPreceivePacket(client));
    #if DEBUG
        // display.setLokaal(TCPreceivePacket(client));
        // display.setLokaalText(TCPreceivePacket(client));
        //Serial.println(TCPreceivePacket(client));

    #endif

    TCPcloseConnection(client);
}

void Connection::TCPsendRequest(String string, WiFiClient client){
    client.println(string);
    client.println(WiFi.macAddress());
}

void Connection::TCPcloseConnection(WiFiClient client){
    client.println("Closing connection");
    client.flush();
    client.stop();
}

String Connection::TCPreceivePacket(WiFiClient client){
    String packet;
    client.println("Reading from TCP connection");
    packet = client.readStringUntil('\0');
    #if DEBUG
        Serial.println("Packet end received");
    #endif
    return packet;
}

int Connection::getBatteryStatus(){
    //analogRead();
    #if DEBUG
        Serial.println("Batterij is kanker vol");
    #endif
    return 1;
}

void Connection::parsePacket(String string){
    
    uint16_t i = 0;
    const char delimiter = ';';
    uint16_t beginPos = 0;
    uint16_t endPos = 0;
    String temp;
    while(string[i] != MAX_TCP_MSG_SIZE && string[i] != '\3'){
        if(string[i] == delimiter){
            endPos = i;
            temp = string.substring(beginPos, endPos);
            Serial.println(temp);
            addStrToList(data, (char *)temp.c_str());
            i++;
        }
        i++;
        beginPos = endPos;
    }
    // string = string.substring(0,2);
    // Serial.println(string);
}