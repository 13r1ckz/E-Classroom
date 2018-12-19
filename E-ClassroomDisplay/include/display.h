
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
#include <Fonts/Roboto_Mono_26.h>
#include <Fonts/Roboto_Mono_Bold_48.h>
#include <Fonts/Roboto_Mono_Bold_100.h>
//bitmap libs
#include <imglib/windesheim.h>

/* Defines -------------------------------------------------------------------*/
#define CS_pin 2  /*CS-D4-GPIO2*/
#define DC_pin 4  /*DC-D2-GPIO4*/
#define RST_pin 5 /*RST-D1-GPIO5*/
#define BUSY_pin 12 /*BUSY-D6-GPIO12*/
#define xOffSet 10
#define firstLine 90
#define secondLine 120
#define thirdLine 200
#define fourthLine 240
#define fifthLine 270
#define sixthLine 350
#define seventhLine 390
#define eigthLine 420

/* Classes -------------------------------------------------------------------*/
class Display{
  public:
    void initDisplay();
    void updateDisplay();
    void setClassroom(String name);
    void setClassroomText(String name);
    void setTime1(String name);
    void setTime2(String name);
    void setLecture1(String name);
    void setLecture2(String name);
    void setTeacher1(String name);
    void setTeacher2(String name);
    void drawDisplay();
  //protected:
    void drawLines();
    void drawLogo();
    void drawClassroom();
    void drawLecture1();
    void drawLecture2();
};

void drawDisplayCallback();

#endif
