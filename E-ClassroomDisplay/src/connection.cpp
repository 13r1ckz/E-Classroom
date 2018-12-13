#include "connection.h"

uint32_t Connection::getMin(){
    return minutes*60;
}
uint8_t Connection::getSec(){
    return seconds;
}
