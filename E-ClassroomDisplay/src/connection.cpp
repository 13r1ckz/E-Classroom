/******************************************************************************
 * File : Connection.cpp
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "connection.h"
#include "display.h"

/* Defines ------------------------------------------------------------------*/
#define PI_SERVER 1
#define WIFI_CONNECTION_TIMEOUT 20

// ----------------------------------------------------------------------------
// Functions
// ----------------------------------------------------------------------------
#define MAX_TCP_MSG_SIZE 65535
#define DEBUG 1

#if PI_SERVER
    const char *ssid = "devices";
    const char *password = "toitoitoi";
    const uint16_t port = 420;
    const char* host=  "145.44.187.11";
#else
    const char *ssid = "Rick's test netwerk";
    const char *password = "stuff123";
    const uint16_t port = 420;
    const char* host=  "192.168.0.101";
#endif
IPAddress static_ip(145,44,187,12);
IPAddress gateway(145,44,187,1);
IPAddress subnet(255,255,255,128);
nodeList *data = (struct NodeList*) malloc(sizeof(nodeList));
nodeListList *dataList = (struct NodeListList*) malloc(sizeof(NodeListList));
String dataStrings[9];

uint32_t Connection::getMin(){
    return minutes * 60;
}

uint8_t Connection::getSec(){
    return seconds;
}

int8_t Connection::WiFi_innit(Display display){
    int8_t error;
    uint8_t WiFiCount = 0;
    WiFi.begin(ssid, password);
    WiFi.config(static_ip, gateway, subnet);
    while(WiFi.status()!=WL_CONNECTED){
        if(WiFiCount > WIFI_CONNECTION_TIMEOUT){
            Serial.println("WiFi connect timeout");
            error = -1;
            return error;
        }
        delay(500);
        #if DEBUG
            Serial.print(".");
        #endif
        WiFiCount++;
    }
    #if DEBUG
        Serial.println("");
        Serial.println("WiFi connected");  
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
    #endif
    error = TCPConnect(display);
    return error;
}

int8_t Connection::TCPConnect(Display display){
    String screenData = "T5.50;College Lokaal;11:30 - 13:30;13:30 - 15:30;Engels 2;Engels 1;Gidooooo;Tijntje;17:30;]";
    WiFiClient client;
    if(!client.connect(host, port)){
        #if DEBUG
            Serial.println("TCP connection failed");
        #endif
        return -1;
    } else {
        #if DEBUG
            Serial.print("Connection established on port: ");
            Serial.println(port);
        #endif
    }
    TCPsendRequest("Gentstudent.b", client);
    parsePacket((TCPreceivePacket(client)));

    //parsePacket(screenData);

    setAllScreenData(display);

    TCPcloseConnection(client);
    return 1;
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
    uint8_t stringPosition = 0;
    uint16_t i = 0;
    const char delimiter = ';';
    uint16_t beginPos = 0;
    uint16_t endPos = 0;
    String temp;
    while(string[i] != MAX_TCP_MSG_SIZE && string[i] != ']'){
        if(string[i] == delimiter){
            endPos = i;
            temp = string.substring(beginPos, endPos);
            dataStrings[stringPosition] = temp;
            stringPosition++;
            beginPos = endPos + 1;
        }
        
        //Serial.println(i);
        
        i++;
    }
    #if DEBUG
        Serial.print("0: ");
        Serial.println(dataStrings[0]);
        Serial.print("1: ");
        Serial.println(dataStrings[2]);
        Serial.print("2: ");
        Serial.println(dataStrings[3]);
        Serial.print("3: ");
        Serial.println(dataStrings[4]);
        Serial.print("4: ");
        Serial.println(dataStrings[5]);
        Serial.print("5: ");
        Serial.println(dataStrings[6]);
        Serial.print("7: ");
        Serial.println(dataStrings[7]);
        Serial.print("8: ");
        Serial.println(dataStrings[8]);
    #endif
}

void Connection::setAllScreenData(Display display){
    display.setClassroom(dataStrings[0]);
    display.setClassroomText(dataStrings[1]);
    display.setTime1(dataStrings[2]);
    display.setTime2(dataStrings[3]);
    display.setLecture1(dataStrings[4]);
    display.setLecture2(dataStrings[5]);
    display.setTeacher1(dataStrings[6]);
    display.setTeacher2(dataStrings[7]);
    display.setTimeFree(dataStrings[8]);
 }