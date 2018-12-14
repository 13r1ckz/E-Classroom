/******************************************************************************
 * File : Display.h
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include <Arduino.h>
//display libs
#include <GxEPD.h>
//if b/w/r:
#include <GxGDEW0583Z00/GxGDEW0583Z00.h>
//if b/w:
//#include <GxGDEW0583T7/GxGDEW0583T7.h>
#include <GxFont_GFX.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>
//draw libs
#include <gfxfont.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
//fonts libs
#include <Fonts/Roboto_Mono_26.h>
#include <Fonts/Roboto_Mono_Bold_48.h>
#include <Fonts/Roboto_Mono_Bold_100.h>
//bitmap libs
#include <imglib/windesheim.h>
/* Defines -------------------------------------------------------------------*/
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
    void setTecher1(String name);
    void setTecher2(String name);
    void drawDisplay();
  //protected:
    void drawLines();
    void drawClassroom();
    void drawLecture1();
    void drawLecture2();
};

void drawDisplayCallback();