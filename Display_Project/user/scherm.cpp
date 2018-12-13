#include "driver/scherm.h"

GxIO_Class io(SPI, /*CS-D16*/ 16, /* DC-D4*/ 4, /*RST-D5*/ 5);
GxEPD_Class ePaper(io, 5, 12 /*RST-D5*/ /*BUSY-D12*/);
String lokaal;
String lokaalText;
String time1;
String time2;
String lecture1;
String lecture2;
String teacher1;
String teacher2;


void Scherm::initDisplay(){
	ePaper.init(115200);
	ePaper.eraseDisplay(true);
}
void Scherm::updateDisplay(){
	ePaper.drawPaged(drawDisplay);
}
void Scherm::drawDisplay(){
	Serial.println("hoi");
	ePaper.drawLine(0, 149, 600, 149, GxEPD_BLACK);
	ePaper.drawLine(0, 150, 600, 150, GxEPD_BLACK);
	ePaper.drawLine(0, 151, 600, 151, GxEPD_BLACK);
	ePaper.drawLine(0, 299, 600, 299, GxEPD_BLACK);
	ePaper.drawLine(0, 300, 600, 300, GxEPD_BLACK);
	ePaper.drawLine(0, 301, 600, 301, GxEPD_BLACK);
	ePaper.setTextColor(GxEPD_BLACK);
	ePaper.setFont(&Roboto_Mono_Bold_100);
	ePaper.setCursor(xPosition, 90);
	ePaper.println("T5.44");
	ePaper.setFont(&Roboto_Mono_26);
	ePaper.setCursor(xPosition, 120);
	ePaper.println("CollegeZaal Theorie");
	ePaper.setTextColor(GxEPD_BLACK);
	ePaper.setFont(&Roboto_Mono_Bold_48);
	ePaper.setCursor(xPosition, 200);
	ePaper.println("8:30 - 10:30");
	ePaper.setFont(&Roboto_Mono_26);
	ePaper.setCursor(xPosition, 240);
	ePaper.println("Engels 2");
	ePaper.setCursor(xPosition, 270);
	ePaper.println("Bailey, Marlies");
	ePaper.setTextColor(GxEPD_BLACK);
	ePaper.setFont(&Roboto_Mono_Bold_48);
	ePaper.setCursor(xPosition, 350);
	ePaper.println("11:30 - 14:30");
	ePaper.setFont(&Roboto_Mono_26);
	ePaper.setCursor(xPosition, 390);
	ePaper.println("Microprocessor Architectuur");
	ePaper.setCursor(xPosition, 420);
	ePaper.println("Hakvoort, Gido");
}
void Scherm::setLokaal(String name){
	lokaal = name;
}
void Scherm::setLokaalText(String name){
	lokaalText = name;
}
void Scherm::setTime1(String name){
	time1 = name;
}
void Scherm::setTime2(String name){
	time2 = name;
}
void Scherm::setLecture1(String name){
	lecture1 = name;
}
void Scherm::setLecture2(String name){
	lecture2 = name; 
}
void Scherm::setTecher1(String name){
	teacher1 = name;
}
void Scherm::setTecher2(String name){
	teacher2 = name;
}
