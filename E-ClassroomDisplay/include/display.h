
/******************************************************************************
 * File : Display.h
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#ifndef DISPLAY_H
#define DISPLAY_H
#include <Arduino.h>
//display libs
#include <GxEPD.h>
#include <GxGDEW0583Z21/GxGDEW0583Z21.h> // b/w/r diplay
//#include <GxGDEW0583T7/GxGDEW0583T7.h> // b/w Display
#include <GxFont_GFX.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>
//fonts libs
#include <Fonts/Roboto_24.h>
#include <Fonts/Roboto_Mono_26.h>
#include <Fonts/Roboto_Mono_Bold_48.h>
#include <Fonts/Roboto_Mono_Bold_100.h>
//bitmap libs
#include <imglib/logov2.h>

/* Defines -------------------------------------------------------------------*/
#define CS_PIN      2   /*CS-D4-GPIO2*/
#define DC_PIN      4   /*DC-D2-GPIO4*/
#define RST_PIN     5   /*RST-D1-GPIO5*/
#define BUSY_PIN    12  /*BUSY-D6-GPIO12*/
#define BAUDRATE    115200
#define X_OFFSET_LINE 0
#define X_OFFSET_TEXT 10
#define Y_OFFSET_TIME 50
#define Y_OFFSET_TEXT 30
#define LINE_WIDTH   600
#define LINE_HEIGHT  3
#define Y_LOGO       0
#define X_LOGO       500
#define Y_LINE1      135
#define Y_LINE2      273
#define Y_LINE3      411
#define Y_LECTURE1   140
#define Y_LECTURE2   278
#define Y_ROOM_NUM    90
#define Y_ROOM_NAME   Y_ROOM_NUM  + Y_OFFSET_TEXT
#define Y_L1_TIME     Y_LECTURE1 + Y_OFFSET_TIME
#define Y_L1_NAME     Y_L1_TIME   + Y_OFFSET_TEXT
#define Y_L1_TEACHER  Y_L1_NAME   + Y_OFFSET_TEXT
#define Y_L2_TIME     Y_LECTURE2 + Y_OFFSET_TIME
#define Y_L2_NAME     Y_L2_TIME   + Y_OFFSET_TEXT
#define Y_L2_TEACHER  Y_L2_NAME   + Y_OFFSET_TEXT
#define Y_TIME_FREE 441

/* Classes -------------------------------------------------------------------*/
class Display{
  public:
    void initDisplay();
    void updateDisplay();
    void setClassroom(String s);
    void setClassroomText(String s);
    void setTime1(String s);
    void setTime2(String s);
    void setLecture1(String s);
    void setLecture2(String s);
    void setTeacher1(String s);
    void setTeacher2(String s);
    void setTimeFree(String s);
    void drawDisplay();
  protected:
    void drawLines();
    void drawLogo();
    void drawClassroom();
    void drawLecture1();
    void drawLecture2();
    void drawFreeFrom();
};

void drawDisplayCallback();

#endif
