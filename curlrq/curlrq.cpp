#include <iostream>
#include <string.h>
#include <curl/curl.h>


static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp){
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main(void){
    CURL *curl;
    CURLcode res;
    std::string readBuffer;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(curl, CURLOPT_URL, "https://roostertest.windesheim.nl/WebUntis/Timetable.do?request.preventCache=1543327601812&ajaxCommand=getWeeklyTimetable&elementType=4&date=20190109&departmentId=0&filterId=2&elementId=328");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
       // curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
       // curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_COOKIE, "schoolname=\"Windesheim\"");
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    std::cout << res << std::endl;
    std::cout << readBuffer << std::endl;
	
}
