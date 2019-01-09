	 /******************************************************************************
 * File : Display.cpp
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "display.h"

GxIO_Class io(SPI, CS_pin, DC_pin, RST_pin);
GxEPD_Class ePaper(io, RST_pin, BUSY_pin);

// ----------------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------------
String classroom;
String classroomText;
String time1;
String time2;
String lecture1;
String lecture2;
String teacher1;
String teacher2;
String timeFree;

// ----------------------------------------------------------------------------
// Functions
// ----------------------------------------------------------------------------
void Display::initDisplay(){
	ePaper.init(baudrate);
}

void Display::updateDisplay(){
	ePaper.drawPaged(drawDisplayCallback);
}

void Display::setClassroom(String s){
	classroom = s;
}

void Display::setClassroomText(String s){
	classroomText = s;
}

void Display::setTime1(String s){
	time1 = s;
}

void Display::setTime2(String s){
	time2 = s;
}

void Display::setLecture1(String s){
	lecture1 = s;
}

void Display::setLecture2(String s){
	lecture2 = s;
}

void Display::setTeacher1(String s){
	teacher1 = s;
}

void Display::setTeacher2(String s){
	teacher2 = s;
}

void Display::setTimeFree(String s){
	timeFree = s;
}

void Display::drawLogo(){
	ePaper.drawBitmap(gImage_Logo, xLogo, yLogo, logo_width, logo_height, GxEPD_BLACK);
}

void Display::drawLines(){
	ePaper.fillRect(xOffSetLine, yLine1, lineWidth, lineHeight, GxEPD_BLACK);
	ePaper.fillRect(xOffSetLine, yLine2, lineWidth, lineHeight, GxEPD_BLACK);
	ePaper.fillRect(xOffSetLine, yLine3, lineWidth, lineHeight, GxEPD_BLACK);
}

void Display::drawClassroom(){
	ePaper.setTextColor(GxEPD_BLACK);
	//Room Number
	ePaper.setFont(&Roboto_Mono_Bold_100);
	ePaper.setCursor(xOffSetText, yRoomNum);
	ePaper.print(classroom);
	//Room name
	ePaper.setFont(&Roboto_Mono_26);
	ePaper.setCursor(xOffSetText, yRoomName);
	ePaper.print(classroomText);
}

void Display::drawLecture1(){
	ePaper.setTextColor(GxEPD_BLACK);
	// Time
	ePaper.setFont(&Roboto_Mono_Bold_48);
	ePaper.setCursor(xOffSetText, yL1Time);
	ePaper.print(time1);
	// Lecture
	ePaper.setFont(&Roboto_Mono_26);
	ePaper.setCursor(xOffSetText, yL1Name);
	ePaper.print(lecture1);
	// Teacher
	ePaper.setCursor(xOffSetText, yL1Teacher);
	ePaper.print(teacher1);
}

void Display::drawLecture2(){
	ePaper.setTextColor(GxEPD_BLACK);
	// Time
	ePaper.setFont(&Roboto_Mono_Bold_48);
	ePaper.setCursor(xOffSetText, yL2Time);
	ePaper.print(time2);
	// Lecture
	ePaper.setFont(&Roboto_Mono_26);
	ePaper.setCursor(xOffSetText, yL2Name);
	ePaper.print(lecture2);
	// Teacher
	ePaper.setCursor(xOffSetText, yL2Teacher);
	ePaper.print(teacher2);
}

void Display::drawFreeFrom(){
	if(timeFree != NULL){
		ePaper.setTextColor(GxEPD_BLACK);
		ePaper.setFont(&Roboto_Mono_26);
		ePaper.setCursor(xOffSetText, yTimeFree);
		ePaper.print("Vrij van ");
		ePaper.print(timeFree);
	}
}

void Display::drawDisplay(){
	this->drawLogo();
	this->drawLines();
	this->drawClassroom();
	this->drawLecture1();
	this->drawLecture2();
	this->drawFreeFrom();
}

void drawDisplayCallback(){
	Display display;
	display.drawDisplay();
}

	