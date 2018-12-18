#include "display.h"

GxIO_Class io(SPI, /*CS-D16*/ 2, /* DC-D4*/ 4, /*RST-D5*/ 5);
GxEPD_Class ePaper(io, 5, 12 /*RST-D5*/ /*BUSY-D12*/);
String lokaal;
String lokaalText;
String time1;
String time2;
String lecture1;
String lecture2;
String teacher1;
String teacher2;

void Display::initDisplay()
{
	ePaper.init(115200);
}
void Display::updateDisplay()
{
	ePaper.drawPaged(drawDisplay);
}

void Display::setLokaal(String name)
{
	lokaal = name;
}
void Display::setLokaalText(String name)
{
	lokaalText = name;
}
void Display::setTime1(String name)
{
	time1 = name;
}
void Display::setTime2(String name)
{
	time2 = name;
}
void Display::setLecture1(String name)
{
	lecture1 = name;
}
void Display::setLecture2(String name)
{
	lecture2 = name;
}
void Display::setTecher1(String name)
{
	teacher1 = name;
}
void Display::setTecher2(String name)
{
	teacher2 = name;
}

String Display::getLokaal(){
	return lokaal;
}

String Display::getLokaalText(){
	return lokaalText;
}

void drawDisplay()
{
	ePaper.drawLine(0, 149, 600, 149, GxEPD_BLACK);
	ePaper.drawLine(0, 150, 600, 150, GxEPD_BLACK);
	ePaper.drawLine(0, 151, 600, 151, GxEPD_BLACK);
	ePaper.drawLine(0, 299, 600, 299, GxEPD_BLACK);
	ePaper.drawLine(0, 300, 600, 300, GxEPD_BLACK);
	ePaper.drawLine(0, 301, 600, 301, GxEPD_BLACK);
	//Room Location
	ePaper.setTextColor(GxEPD_BLACK);
	ePaper.setFont(&Roboto_Mono_Bold_100);
	ePaper.setCursor(xOffSet, firstLine);
	ePaper.println(lokaal);
	//Time
	ePaper.setTextColor(GxEPD_BLACK);
	ePaper.setFont(&Roboto_Mono_Bold_48);
	ePaper.setCursor(xOffSet, thirdLine);
	ePaper.println(time1);
	ePaper.setCursor(xOffSet, sixthLine);
	ePaper.println(time2);
	//Room name
	ePaper.setFont(&Roboto_Mono_26);
	ePaper.setCursor(xOffSet, secondLine);
	ePaper.println(lokaalText);
	//Lecture
	ePaper.setCursor(xOffSet, fourthLine);
	ePaper.println(lecture1);
	ePaper.setCursor(xOffSet, seventhLine);
	ePaper.println(lecture2);
	//Teacher
	ePaper.setCursor(xOffSet, fifthLine);
	ePaper.println(teacher1);
	ePaper.setTextColor(GxEPD_BLACK);
	ePaper.setCursor(xOffSet, eigthLine);
	ePaper.println(teacher2);
}