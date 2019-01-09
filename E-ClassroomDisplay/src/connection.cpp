/******************************************************************************
 * File : Connection.cpp
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "connection.h"
#include "display.h"

/* Defines ------------------------------------------------------------------*/
#define PI_SERVER 1

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
            i++;
            endPos = i;
            temp = string.substring(beginPos, endPos);
            #if DEBUG
                Serial.println("Parsepacket function");
                Serial.println(temp);
            #endif
            addStrToList(data, (char *)temp.c_str());
            addNodeListToNodeListList(dataList ,data);
        }
        i++;
        beginPos = endPos;
    }
}

void setAllScreenData(Display display){
    String temp;
    NodeList *tempList = (struct NodeList*) malloc(sizeof(nodeList));
    if(dataList->head == NULL){
        Serial.println("ERROR");
        return;
    }
    tempList = dataList->head;
    listToStr(tempList, (char *)temp.c_str(), 0, tempList->size);
    Serial.println("Printing temp");
    Serial.println(temp);
    display.setClassroom(temp);
    #if DEBUG
        Serial.println(temp);
    #endif
    tempList = (NodeList*) tempList->next;
    
    listToStr(tempList, (char *)temp.c_str(), 0, tempList->size);
    display.setClassroomText(temp);
    #if DEBUG
        Serial.println(temp);
    #endif
    tempList = (NodeList*) tempList->next;

    listToStr(tempList, (char *)temp.c_str(), 0, tempList->size);
    display.setTime1(temp);
    #if DEBUG
        Serial.println(temp);
    #endif
    tempList = (NodeList*) tempList->next;
    
    listToStr(tempList, (char *)temp.c_str(), 0, tempList->size);
    display.setTime2(temp);
    #if DEBUG
        Serial.println(temp);
    #endif
    tempList = (NodeList*) tempList->next;

    listToStr(tempList, (char *)temp.c_str(), 0, tempList->size);
    display.setLecture1(temp);
    #if DEBUG
        Serial.println(temp);
    #endif
    tempList = (NodeList*) tempList->next;

    listToStr(tempList, (char *)temp.c_str(), 0, tempList->size);
    display.setLecture2(temp);
    #if DEBUG
        Serial.println(temp);
    #endif
    tempList = (NodeList*) tempList->next;

    listToStr(tempList, (char *)temp.c_str(), 0, tempList->size);
    display.setTeacher1(temp);
    #if DEBUG
        Serial.println(temp);
    #endif
    tempList = (NodeList*) tempList->next;

    listToStr(tempList, (char *)temp.c_str(), 0, tempList->size);
    display.setTeacher2(temp);
    #if DEBUG
        Serial.println(temp);
    #endif
    tempList = (NodeList*) tempList->next;
}