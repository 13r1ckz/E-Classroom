// class GxGDEW0583T7 : Display class for GDEW0583T7 e-Paper from Dalian Good Display Co., Ltd.: www.good-display.com
//
// based on Demo Example from Good Display, available here: http://www.good-display.com/download_detail/downloadsId=515.html
// Controller: IL0371 : http://www.good-display.com/download_detail/downloadsId=536.html
//
// Author : J-M Zingg
//
// Version : see library.properties
//
// License: GNU GENERAL PUBLIC LICENSE V3, see LICENSE
//
// Library: https://github.com/ZinggJM/GxEPD

#ifndef _GxGDEW0583T7_H_
#define _GxGDEW0583T7_H_

#include "../GxEPD.h"

#define GxGDEW0583T7_WIDTH 600
#define GxGDEW0583T7_HEIGHT 448

#define GxGDEW0583T7_BUFFER_SIZE (uint32_t(GxGDEW0583T7_WIDTH) * uint32_t(GxGDEW0583T7_HEIGHT) / 8)

// divisor for AVR, should be factor of GxGDEW0583T7_HEIGHT
#define GxGDEW0583T7_PAGES 28

#define GxGDEW0583T7_PAGE_HEIGHT (GxGDEW0583T7_HEIGHT / GxGDEW0583T7_PAGES)
#define GxGDEW0583T7_PAGE_SIZE (GxGDEW0583T7_BUFFER_SIZE / GxGDEW0583T7_PAGES)

class GxGDEW0583T7 : public GxEPD
{
  public:
#if defined(ESP8266)
    //GxGDEW0583T7(GxIO& io, int8_t rst = D4, int8_t busy = D2);
    // use pin numbers, other ESP8266 than Wemos may not use Dx names
    GxGDEW0583T7(GxIO& io, int8_t rst = 2, int8_t busy = 4);
#else
    GxGDEW0583T7(GxIO& io, int8_t rst = 9, int8_t busy = 7);
#endif
    void drawPixel(int16_t x, int16_t y, uint16_t color);
    void init(uint32_t serial_diag_bitrate = 0); // = 0 : disabled
    void fillScreen(uint16_t color); // 0x0 black, >0x0 white, to buffer
    void update(void);
    // to buffer, may be cropped, drawPixel() used, update needed
    void  drawBitmap(const uint8_t *bitmap, uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color, int16_t mode = bm_normal);
    // to full screen, filled with white if size is less, no update needed
    void drawBitmap(const uint8_t *bitmap, uint32_t size, int16_t mode = bm_normal); // only bm_normal, bm_invert, bm_partial_update modes implemented
    void eraseDisplay(bool using_partial_update = false);
    // partial update of rectangle from buffer to screen, does not power off
    // note: on this display, partial update to display RAM works, but refresh is full screen
    // terminate cleanly updateWindow or updateToWindow before removing power or long delays
    void powerDown();
    // paged drawing, for limited RAM, drawCallback() is called GxGDEW0583T7_PAGES times
    // each call of drawCallback() should draw the same
    void drawPaged(void (*drawCallback)(void));
  private:
    template <typename T> static inline void
    swap(T& a, T& b)
    {
      T t = a;
      a = b;
      b = t;
    }
    uint16_t _setPartialRamArea(uint16_t x, uint16_t y, uint16_t xe, uint16_t ye);
    void _wakeUp();
    void _sleep();
    void _waitWhileBusy(const char* comment = 0);
    void _send8pixel(uint8_t data);
  private:
#if defined(__AVR)
    uint8_t _buffer[GxGDEW0583T7_PAGE_SIZE];
#else
    uint8_t _buffer[GxGDEW0583T7_BUFFER_SIZE];
#endif
    GxIO& IO;
    int16_t _current_page;
    bool _using_partial_mode;
    bool _diag_enabled;
    int8_t _rst;
    int8_t _busy;
#if defined(ESP8266) || defined(ESP32)
  public:
    // the compiler of these packages has a problem with signature matching to base classes
    void drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h, uint16_t color)
    {
      Adafruit_GFX::drawBitmap(x, y, bitmap, w, h, color);
    };
#endif
};

#ifndef GxEPD_Class
#define GxEPD_Class GxGDEW0583T7
#define GxEPD_WIDTH GxGDEW0583T7_WIDTH
#define GxEPD_HEIGHT GxGDEW0583T7_HEIGHT
#define GxEPD_BitmapExamples <GxGDEW0583T7/BitmapExamples.h>
#define GxEPD_BitmapExamplesQ "GxGDEW0583T7/BitmapExamples.h"
#endif

#endif

