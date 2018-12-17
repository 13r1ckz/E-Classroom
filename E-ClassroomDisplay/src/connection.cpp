#include "connection.h"

#define DEBUG 1

const char* ssid = "devices";
const char* password = "toitoitoi";
const uint16_t port = 420.;
const char* host=  "145.44.187.11";
IPAddress ip(145,44,187,12);
IPAddress gateway(145,44,187,1);
IPAddress subnet(255,255,255,128);

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
    TCPConnect();
}

void Connection::TCPConnect(){
    WiFiClient client;
    if(!client.connect(host, port)){
        Serial.println("Connection failed");
        return;
    } else {
        #if DEBUG
            Serial.print("Connection established on port: ");
            Serial.println(port);
        #endif
    }
    TCPsendRequest("Gentstudent42.2", client);
    #if DEBUG
        Serial.println(TCPreceivePacket(client));
    #endif

    TCPcloseConnection(client);
}

void Connection::TCPsendRequest(char* string, WiFiClient client){
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
    packet = client.readStringUntil('\n');
    return packet;
}

int getBatteryStatus(){
    #if DEBUG
        Serial.println("Batterij is kanker vol");
    #endif

}