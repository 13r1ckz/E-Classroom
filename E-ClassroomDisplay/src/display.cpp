/******************************************************************************
 * File : Display.cpp
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "display.h"

GxIO_Class io(SPI, CS_PIN, DC_PIN, RST_PIN);
GxEPD_Class ePaper(io, RST_PIN, BUSY_PIN);

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
/**
* @brief Initializes display at defined baudrate.
* @retuns None
* @note
*/
void Display::initDisplay(){
	ePaper.init(BAUDRATE);
}

/**
* @brief Updates display with data created in drawDisplayCallback.
* @retuns None
* @note
*/
void Display::updateDisplay(){
	ePaper.drawPaged(drawDisplayCallback);
}

/**
* @brief Sets Classroom to given string.
* @retuns None 
* @note
*/
void Display::setClassroom(String s){
	classroom = s;
}

/**
* @brief Sets ClassroomText to given string.
* @retuns None 
* @note
*/
void Display::setClassroomText(String s){
	classroomText = s;
}

/**
* @brief Sets Time for field 1 to given string.
* @retuns None 
* @note
*/
void Display::setTime1(String s){
	time1 = s;
}

/**
* @brief Sets Time for field 2 to given string.
* @retuns None 
* @note
*/
void Display::setTime2(String s){
	time2 = s;
}

/**
* @brief Sets Lecture for field 1 to given string.
* @retuns None 
* @note
*/
void Display::setLecture1(String s){
	lecture1 = s;
}

/**
* @brief Sets Lecture for field 2 to given string.
* @retuns None 
* @note
*/
void Display::setLecture2(String s){
	lecture2 = s;
}

/**
* @brief Sets Teacher for field 1 to given string.
* @retuns None 
* @note
*/
void Display::setTeacher1(String s){
	teacher1 = s;
}

/**
* @brief Sets Teacher for field 2 to given string.
* @retuns None 
* @note
*/
void Display::setTeacher2(String s){
	teacher2 = s;
}

/**
* @brief Sets TimeFree field to given string.
* @retuns None 
* @note
*/
void Display::setTimeFree(String s){
	timeFree = s;
}

/**
* @brief Draws logo on defined location.
* @retuns None 
* @note
*/
void Display::drawLogo(){
	ePaper.drawBitmap(gImage_Logov2, X_LOGO, Y_LOGO, logo_width, logo_height, GxEPD_BLACK);
}

/**
* @brief Draws lines at defined locations.
* @retuns None 
* @note
*/
void Display::drawLines(){
	ePaper.fillRect(X_OFFSET_LINE, Y_LINE1, LINE_WIDTH, LINE_HEIGHT, GxEPD_BLACK);
	ePaper.fillRect(X_OFFSET_LINE, Y_LINE2, LINE_WIDTH, LINE_HEIGHT, GxEPD_BLACK);
	ePaper.fillRect(X_OFFSET_LINE, Y_LINE3, LINE_WIDTH, LINE_HEIGHT, GxEPD_BLACK);
}

/**
* @brief Draws Room number and name at defined location.
* @retuns None 
* @note
*/
void Display::drawClassroom(){
	ePaper.setTextColor(GxEPD_BLACK);
	//Room Number
	ePaper.setFont(&Roboto_Mono_Bold_100);
	ePaper.setCursor(X_OFFSET_TEXT, Y_ROOM_NUM);
	ePaper.print(classroom);
	//Room name
	ePaper.setFont(&Roboto_Mono_26);
	ePaper.setCursor(X_OFFSET_TEXT, Y_ROOM_NAME);
	ePaper.print(classroomText);
}

/**
* @brief Draws lecture field 1 to defined location.
* @retuns None 
* @note
*/
void Display::drawLecture1(){
	ePaper.setTextColor(GxEPD_BLACK);
	// Time
	ePaper.setFont(&Roboto_Mono_Bold_48);
	ePaper.setCursor(X_OFFSET_TEXT, Y_L1_TIME);
	ePaper.print(time1);
	// Lecture
	ePaper.setFont(&Roboto_Mono_26);
	ePaper.setCursor(X_OFFSET_TEXT, Y_L1_NAME);
	ePaper.print(lecture1);
	// Teacher
	ePaper.setCursor(X_OFFSET_TEXT, Y_L1_TEACHER);
	ePaper.print(teacher1);
}

/**
* @brief Draws lecture field 2 to defined location.
* @retuns None 
* @note
*/
void Display::drawLecture2(){
	ePaper.setTextColor(GxEPD_BLACK);
	// Time
	ePaper.setFont(&Roboto_Mono_Bold_48);
	ePaper.setCursor(X_OFFSET_TEXT, Y_L2_TIME);
	ePaper.print(time2);
	// Lecture
	ePaper.setFont(&Roboto_Mono_26);
	ePaper.setCursor(X_OFFSET_TEXT, Y_L2_NAME);
	ePaper.print(lecture2);
	// Teacher
	ePaper.setCursor(X_OFFSET_TEXT, Y_L2_TEACHER);
	ePaper.print(teacher2);
}

/**
* @brief Draws FreeFrom field to defined location.
* @retuns None 
* @note
*/
void Display::drawFreeFrom(){
	if(timeFree != NULL){
		ePaper.setTextColor(GxEPD_BLACK);
		ePaper.setFont(&Roboto_Mono_26);
		ePaper.setCursor(X_OFFSET_TEXT, Y_TIME_FREE);
		ePaper.print(timeFree);
	}
}

/**
* @brief Executes drawfunctions for layout.
* @retuns None 
* @note
*/
void Display::drawDisplay(){
	this->drawLogo();
	this->drawLines();
	this->drawClassroom();
	this->drawLecture1();
	this->drawLecture2();
	this->drawFreeFrom();
}

/**
* @brief Callback function to connect display library to drawDisplay function.
* @retuns None 
* @note
*/
void drawDisplayCallback(){
	Display display;
	display.drawDisplay();
}

	