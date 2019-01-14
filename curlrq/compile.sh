#!/bin/bash
gcc curlrq.cpp -o curlrq -lcurl -lstdc++ -ljsoncpp && ./curlrq
