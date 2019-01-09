
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
#include <imglib/logo.h>

/* Defines -------------------------------------------------------------------*/
#define CS_pin      2   /*CS-D4-GPIO2*/
#define DC_pin      4   /*DC-D2-GPIO4*/
#define RST_pin     5   /*RST-D1-GPIO5*/
#define BUSY_pin    12  /*BUSY-D6-GPIO12*/
#define baudrate    115200
#define xOffSetLine 0
#define xOffSetText 10
#define yOffSetTime 50
#define yOffSetText 30
#define lineWidth   600
#define lineHeight  3
#define yLogo       0
#define xLogo       500
#define yLine1      135
#define yLine2      273
#define yLine3      411
#define yLecture1   140
#define yLecture2   278
#define yRoomNum    90
#define yRoomName   yRoomNum  + yOffSetText
#define yL1Time     yLecture1 + yOffSetTime
#define yL1Name     yL1Time   + yOffSetText
#define yL1Teacher  yL1Name   + yOffSetText
#define yL2Time     yLecture2 + yOffSetTime
#define yL2Name     yL2Time   + yOffSetText
#define yL2Teacher  yL2Name   + yOffSetText
#define yTimeFree   441

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
