// scherm.h
#ifndef _SCHERM_h
#define _SCHERM_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

//defines
#define xPosition 10

//libs
#include <gfxfont.h>
#include <GxEPD.h>
#include <GxGDEW0583T7/GxGDEW0583T7.h>
#include <GxFont_GFX.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <Fonts/Roboto_Mono_26.h>
#include <Fonts/Roboto_Mono_Bold_48.h>
#include <Fonts/Roboto_Mono_Bold_100.h>

//functions
void updateDisplay();
void initDisplay();
void drawDisplay();
void setLokaal(String name);
void setLokaalText(String name);
void setTime1(String name);
void setTime2(String name);
void setLecture1(String name);
void setLecture2(String name);
void setTecher1(String name);
void setTecher2(String name);

#endif

