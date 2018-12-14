/******************************************************************************
 * File : Display.cpp
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "display.h"

GxIO_Class io(SPI, /*CS-D16*/ 2, /* DC-D4*/ 4, /*RST-D5*/ 5);
GxEPD_Class ePaper(io, 5, 12 /*RST-D5*/ /*BUSY-D12*/);

// ----------------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------------
String classroom = "NON";
String classroomText = "NON";
String time1 = "NON";
String time2 = "NON";
String lecture1 = "NON";
String lecture2 = "NON";
String teacher1 = "NON";
String teacher2 = "NON";

// ----------------------------------------------------------------------------
// Functions
// ----------------------------------------------------------------------------
void Display::initDisplay(){
	ePaper.init(115200);
}

void Display::updateDisplay(){
	ePaper.drawPaged(drawDisplayCallback);
}

void Display::setClassroom(String name){
	classroom= name;
}

void Display::setClassroomText(String name){
	classroomText = name;
}

void Display::setTime1(String name){
	time1 = name;
}

void Display::setTime2(String name){
	time2 = name;
}

void Display::setLecture1(String name){
	lecture1 = name;
}

void Display::setLecture2(String name){
	lecture2 = name;
}

void Display::setTecher1(String name){
	teacher1 = name;
}

void Display::setTecher2(String name){
	teacher2 = name;
}

void Display::drawLines(){
	ePaper.drawBitmap(gImage_windesheim, 440, 0, 160, 160, GxEPD_BLACK);
	ePaper.drawRect(0, 149, 600, 3, GxEPD_BLACK);
	ePaper.drawFastHLine(0, 150, 600, GxEPD_BLACK);
	ePaper.drawRect(0, 299, 600, 3, GxEPD_BLACK);
	ePaper.drawFastHLine(0, 300, 600, GxEPD_BLACK);
}

void Display::drawClassroom(){
	//Room Number
	ePaper.setTextColor(GxEPD_BLACK);
	ePaper.setFont(&Roboto_Mono_Bold_100);
	ePaper.setCursor(xOffSet, firstLine);
	ePaper.println(classroom);
	//Room name
	ePaper.setFont(&Roboto_Mono_26);
	ePaper.setCursor(xOffSet, secondLine);
	ePaper.println(classroomText);
}

void Display::drawLecture1(){
	ePaper.setTextColor(GxEPD_BLACK);
	ePaper.setFont(&Roboto_Mono_Bold_48);
	ePaper.setCursor(xOffSet, thirdLine);
	ePaper.println(time1);
	ePaper.setFont(&Roboto_Mono_26);
	ePaper.setCursor(xOffSet, fourthLine);
	ePaper.println(lecture1);
	ePaper.setCursor(xOffSet, eigthLine);
	ePaper.println(teacher2);
}

void Display::drawLecture2(){
	ePaper.setTextColor(GxEPD_BLACK);
	ePaper.setFont(&Roboto_Mono_Bold_48);
	ePaper.setCursor(xOffSet, sixthLine);
	ePaper.println(time2);
	ePaper.setFont(&Roboto_Mono_26);
	ePaper.setCursor(xOffSet, seventhLine);
	ePaper.println(lecture2);
	ePaper.setCursor(xOffSet, fifthLine);
	ePaper.println(teacher1);
}

void Display::drawDisplay(){
	this->drawLines();
	this->drawClassroom();
	this->drawLecture1();
	this->drawLecture2();
}

void drawDisplayCallback(){
	Display display;
	display.drawDisplay();
}