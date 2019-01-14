/******************************************************************************
 * File : Connection.cpp
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "connection.h"

// ----------------------------------------------------------------------------
// Functions
// ----------------------------------------------------------------------------
#if PI_SERVER
    const char *ssid = "devices";
    const char *password = "toitoitoi";
    const uint16_t port = 420;
    const char* host=  "145.44.187.11";
    IPAddress static_ip(145,44,187,14);
    IPAddress gateway(145,44,187,1);
    IPAddress subnet(255,255,255,128);
#else
    const char *ssid = "Rick's test netwerk";
    const char *password = "stuff123";
    const uint16_t port = 420;
    const char* host=  "192.168.0.100";
    IPAddress static_ip(192,168,0,105);
    IPAddress gateway(192,168,0,1);
    IPAddress subnet(255,255,255,0);
#endif


String dataStrings[NUMBER_OF_DISPLAY_ELEMENTS];
uint8_t evening  = NO;

uint32_t Connection::getMin(){
    return minutes;
}

uint8_t Connection::getSec(){
    return seconds;
}

int8_t Connection::WiFi_innit(Display display){
    int8_t error;
    uint8_t WiFiCount = 0;
    uint8_t maxTCPRequest = 0;

    WiFi.begin(ssid, password);
    WiFi.config(static_ip, gateway, subnet);
    while(WiFi.status()!=WL_CONNECTED){
        if(WiFiCount > WIFI_CONNECTION_TIMEOUT){
            #if DEBUG
                Serial.println("WiFi connect timeout");
            #endif
            error = -2;
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
    while((dataStrings[0] == "") && (maxTCPRequest < 5)){
        #if DEBUG
            Serial.println("TCP message incomplete");
        #endif
        error = TCPConnect(display);
        maxTCPRequest++;
    }
    if(evening == YES){
        error = 3;
        return error;
    }
    else if(!(dataStrings[0] == "")){
        WiFi.forceSleepBegin();
        delay(1);
        setAllScreenData(display); 
        return error;
    }  
    else {
        error = -1;
        return error;
    }
}

int8_t Connection::TCPConnect(Display display){
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
    TCPsendRequest(WiFi.macAddress() + ";" + getBatteryPercentage() + '\3', client);
    parsePacket((TCPreceivePacket(client)));
    TCPcloseConnection(client);
    return 1;
}

void Connection::TCPsendRequest(String string, WiFiClient client){
    client.println(string);
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

void Connection::parsePacket(String string){
    uint8_t stringPosition = 0;
    uint16_t i = 0;
    const char delimiter = ';';
    uint16_t beginPos = 0;
    uint16_t endPos = 0;
    String temp;
    while(i < MAX_TCP_MSG_SIZE && string[i] != '\3' && string[i] != '\4'){
        if(string[i] == delimiter){
            endPos = i;
            temp = string.substring(beginPos, endPos);
            dataStrings[stringPosition] = temp;
            stringPosition++;
            beginPos = endPos + 1;
        }
        if(string[i] == '\4'){
            evening = YES;
            break;
        }
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