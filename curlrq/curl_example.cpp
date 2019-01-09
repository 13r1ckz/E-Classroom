#include <iostream>
#include <string>
#include <curl/curl.h>


static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main(void)
{


  CURL *curl = curl_easy_init();
  struct curl_slist *headers = NULL;
  std::string readBuffer;

if(curl){
curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
curl_easy_setopt(curl, CURLOPT_URL, "https://roostertest.windesheim.nl/WebUntis/Timetable.do?request.preventCache=1543327601812&ajaxCommand=getWeeklyTimetable&elementType=4&date=20181127&departmentId=0&filterId=2&elementId=328");

curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

headers = curl_slist_append(headers, "cache-control: no-cache");
headers = curl_slist_append(headers, "schoolname='_d2luZGVzaGVpbQ==***'");

curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

 CURLcode res = curl_easy_perform(curl);

std::cout << res << std::endl;

curl_easy_cleanup(curl);  
}

  return 0;
}
