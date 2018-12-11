// scherm.h
#ifndef _SCHERM_h
#define _SCHERM_h

//defines
#define xPosition 10

//libs
#include <Display/gfxfont.h>
#include <Display/GxEPD.h>
#include <Display/GxGDEW0583T7/GxGDEW0583T7.h>
#include <Display/GxFont_GFX.h>
#include <Display/GxIO/GxIO_SPI/GxIO_SPI.h>
#include <Display/GxIO/GxIO.h>
#include <Display/Adafruit_GFX.h>
#include <Display/Adafruit_SPITFT.h>
#include <Display/Adafruit_SPITFT_Macros.h>
#include <Display/Fonts/Roboto_Mono_26.h>
#include <Display/Fonts/Roboto_Mono_Bold_48.h>
#include <Display/Fonts/Roboto_Mono_Bold_100.h>

//class GxEPD : public Adafruit_GFX
class Scherm {
  public:
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
};

#endif

