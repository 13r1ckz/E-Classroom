// class GxGDEW0583Z21 : Display class for GDEW0583Z21 e-Paper from Dalian Good Display Co., Ltd.: www.good-display.com
//
// based on Demo Example from Good Display, available here: http://www.e-paper-display.com/download_detail/downloadsId=580.html
// Controller: IL0371 : http://www.good-display.com/download_detail/downloadsId=536.html
//
// Author : J-M Zingg
//
// Version : see library.properties
//
// License: GNU GENERAL PUBLIC LICENSE V3, see LICENSE
//
// Library: https://github.com/ZinggJM/GxEPD

#ifndef _GxGDEW0583Z21_H_
#define _GxGDEW0583Z21_H_

#include "../GxEPD.h"

#define GxGDEW0583Z21_WIDTH 600
#define GxGDEW0583Z21_HEIGHT 448

// pixel number expressed in bytes; this is neither the buffer size nor the size of the buffer in the controller
#define GxGDEW0583Z21_BYTE_SIZE (uint32_t(GxGDEW0583Z21_WIDTH) * uint32_t(GxGDEW0583Z21_HEIGHT) / 8)

// divisor for AVR or limited RAM, should be factor of GxGDEW0583Z21_HEIGHT
// add conditional case if the compiler complains for your target
#if defined(__AVR)
//#define GxGDEW0583Z21_PAGES 48
#define GxGDEW0583Z21_PAGES 64
#elif defined(ESP8266)
#define GxGDEW0583Z21_PAGES 2
#elif defined(ARDUINO_ARCH_STM32F1)
#define GxGDEW0583Z21_PAGES 7
#else
#define GxGDEW0583Z21_PAGES 1 // e.g. ESP32
#endif

#define GxGDEW0583Z21_PAGE_HEIGHT (GxGDEW0583Z21_HEIGHT / GxGDEW0583Z21_PAGES)
#define GxGDEW0583Z21_PAGE_SIZE (GxGDEW0583Z21_BYTE_SIZE / GxGDEW0583Z21_PAGES)
#define GxGDEW0583Z21_BUFFER_SIZE GxGDEW0583Z21_PAGE_SIZE

class GxGDEW0583Z21 : public GxEPD
{
  public:
#if defined(ESP8266)
    GxGDEW0583Z21(GxIO& io, int8_t rst = 2, int8_t busy = 4);
#else
    GxGDEW0583Z21(GxIO& io, int8_t rst = 9, int8_t busy = 7);
#endif
    void drawPixel(int16_t x, int16_t y, uint16_t color);
    void init(uint32_t serial_diag_bitrate = 0); // = 0 : disabled
    void fillScreen(uint16_t color); // 0x0 black, >0x0 white, to buffer
    void update(void);
    // to buffer, may be cropped, drawPixel() used, update needed
    void  drawBitmap(const uint8_t *bitmap, uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color, int16_t mode = bm_normal);
    // to full screen, filled with white if size is less, no update needed, black  /white / red, for example bitmaps
    void drawExamplePicture(const uint8_t* black_bitmap, const uint8_t* red_bitmap, uint32_t black_size, uint32_t red_size);
    // to full screen, filled with white if size is less, no update needed, black  /white / red, general version
    void drawPicture(const uint8_t* black_bitmap, const uint8_t* red_bitmap, uint32_t black_size, uint32_t red_size, int16_t mode = bm_normal);
    // to full screen, filled with white if size is less, for 3-color example bitmaps
    void drawExamplePicture_3C(const uint8_t* bitmap_3C, uint32_t size_3C, int16_t mode = bm_normal);
    // to full screen, filled with white if size is less, no update needed
    void drawBitmap(const uint8_t *bitmap, uint32_t size, int16_t mode = bm_normal); // only bm_normal, bm_invert, bm_partial_update modes implemented
    void eraseDisplay(bool using_partial_update = false);
    // partial update of rectangle from buffer to screen, does not power off
    // note: on this display, partial update to display RAM works, but refresh is full screen
    void updateWindow(uint16_t x, uint16_t y, uint16_t w, uint16_t h, bool using_rotation = true);
    // partial update of rectangle at (xs,ys) from buffer to screen at (xd,yd), does not power off
    void updateToWindow(uint16_t xs, uint16_t ys, uint16_t xd, uint16_t yd, uint16_t w, uint16_t h, bool using_rotation = true);
    // terminate cleanly updateWindow or updateToWindow before removing power or long delays
    void powerDown();
    // paged drawing, for limited RAM, drawCallback() is called GxGDEW0583Z21_PAGES times
    // each call of drawCallback() should draw the same
    void drawPaged(void (*drawCallback)(void));
    void drawPaged(void (*drawCallback)(uint32_t), uint32_t);
    void drawPaged(void (*drawCallback)(const void*), const void*);
    void drawPaged(void (*drawCallback)(const void*, const void*), const void*, const void*);
    // paged drawing to screen rectangle at (x,y) using partial update
    void drawPagedToWindow(void (*drawCallback)(void), uint16_t x, uint16_t y, uint16_t w, uint16_t h);
    void drawPagedToWindow(void (*drawCallback)(uint32_t), uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint32_t);
    void drawPagedToWindow(void (*drawCallback)(const void*), uint16_t x, uint16_t y, uint16_t w, uint16_t h, const void*);
    void drawPagedToWindow(void (*drawCallback)(const void*, const void*), uint16_t x, uint16_t y, uint16_t w, uint16_t h, const void*, const void*);
    void drawCornerTest(uint8_t em = 0x01);
  private:
    template <typename T> static inline void
    swap(T& a, T& b)
    {
      T t = a;
      a = b;
      b = t;
    }
    void _writeToWindow(uint16_t xs, uint16_t ys, uint16_t xd, uint16_t yd, uint16_t w, uint16_t h, bool using_rotation = true);
    uint16_t _setPartialRamArea(uint16_t x, uint16_t y, uint16_t xe, uint16_t ye);
    void _wakeUp();
    void _sleep();
    void _waitWhileBusy(const char* comment = 0);
    void _send8pixel(uint8_t black_data, uint8_t red_data);
    void _rotate(uint16_t& x, uint16_t& y, uint16_t& w, uint16_t& h);
  private:
    uint8_t _black_buffer[GxGDEW0583Z21_BUFFER_SIZE];
    uint8_t _red_buffer[GxGDEW0583Z21_BUFFER_SIZE];
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
#define GxEPD_Class GxGDEW0583Z21
#define GxEPD_WIDTH GxGDEW0583Z21_WIDTH
#define GxEPD_HEIGHT GxGDEW0583Z21_HEIGHT
#define GxEPD_BitmapExamples <GxGDEW0583Z21/BitmapExamples.h>
#define GxEPD_BitmapExamplesQ "GxGDEW0583Z21/BitmapExamples.h"
#endif

#endif

