#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <stdio.h>
#include <ctime>
#include <iomanip>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>

void curlRequest(std::string* buffer, int ID);
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
std::string getCurlURL(int ID);
std::string getDateField();
std::string getIdField(int ID);

std::string BaseURL = "https://roostertest.windesheim.nl/WebUntis/Timetable.do?request.preventCache=1543327601812&";
std::string RequestClassData = "ajaxCommand=getWeeklyTimetable&elementType=4&departmentId=0&filterId=2&";


int main(void){
    std::string readBuffer;
    curlRequest(&readBuffer, 328);

    Json::Reader reader;
    Json::Value obj;
    reader.parse(readBuffer, obj); // reader can also read strings
    const Json::Value& characters = obj["result"]["data"]["elementPeriods"]["328"]; // array of characters
    for (int i = 0; i < characters.size(); i++){
        std::cout << " " <<std::endl;
	std::cout << "      Name: " << characters[i]["lessonText"] << std::endl;
        std::cout << "start Time: " << characters[i]["startTime"]  << std::endl;
        std::cout << "  end Time: " << characters[i]["endTime"]    << std::endl;
	
	const Json::Value& teatcherid = characters[i]["elements"];
	for (int j =0; j < teatcherid.size(); j++){
		//if(teatcherid[j]["type"].asUInt() = 2){
			std::cout << " teatcher ID" << teatcherid[j]["id"] << std::endl;
		//}
	}
    }
std::cout << "yeet" << std::endl;

}

/**
* @brief This function requests Room data from roostertest.windesheim.nl by RoomID.
* @retuns none
* @note needs a pointer to a string buffer & RoomID int
*/
void curlRequest(std::string* buffer, int ID){
    CURL *curl;
    CURLcode res;
    std::string URLString = getCurlURL(ID);
    //String to Char array
    char * URL = new char [URLString.length()+1];
    strcpy (URL, URLString.c_str());
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, buffer);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_COOKIE, "schoolname=\"Windesheim\"");
        res = curl_easy_perform(curl);
        /* Check for errors */
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

/**
* @brief This function is used by curlRequest as WriteCallback
* @retuns
* @note
*/
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp){
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

/**
* @brief This function creates the curl request URL with Date & RoomID.
* @retuns String of URL
* @note Needs a RoomID
*/
std::string getCurlURL(int ID){
    std::string Date = getDateField();
    std::string RoomID = getIdField(ID);
    std::string URL = BaseURL + RequestClassData + Date + RoomID;
    return URL;
}

/**
* @brief This function creates Date part of the curl request URL.
* @retuns String with date in following format: data=YYYYMMDD&
* @note
*/
std::string getDateField(){
    time_t t = time(NULL);
	tm* timePtr = localtime(&t);
    std::ostringstream streamDate;
    streamDate << "date=" << (timePtr->tm_year + 1900) << std::setw(2) << std::setfill('0') << (timePtr->tm_mon + 1) << std::setw(2) << std::setfill('0') << timePtr->tm_mday << "&";
    std::string Date(streamDate.str());
    return Date;
}

/**
* @brief This function creates RoomID part of the curl request URL.
* @retuns String with RoomID in following format: elementId=RoomID.
* @note Needs a RoomID
*/
std::string getIdField(int ID){
    std::ostringstream streamID;
    streamID << "elementId=" << ID;
    std::string RoomID(streamID.str());
    return RoomID;
}
