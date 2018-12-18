#ifndef DISPLAY_H
#define DISPLAY_H
#include <Arduino.h>
//display libs
#include <GxEPD.h>
#include <GxGDEW0583T7/GxGDEW0583T7.h>
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

//defines
#define xOffSet 10
#define firstLine 90
#define secondLine 120
#define thirdLine 200
#define fourthLine 240
#define fifthLine 270
#define sixthLine 350
#define seventhLine 390
#define eigthLine 420

class Display
{
  public:
    void initDisplay();
    void updateDisplay();
    void setLokaal(String name);
    void setLokaalText(String name);
    void setTime1(String name);
    void setTime2(String name);
    void setLecture1(String name);
    void setLecture2(String name);
    void setTecher1(String name);
    void setTecher2(String name);
    String getLokaal();
    String getLokaalText();
};

void drawDisplay();
#endif