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

#include "GxGDEW0583T7.h"

//#define DISABLE_DIAGNOSTIC_OUTPUT

#if defined(ESP8266) || defined(ESP32)
#include <pgmspace.h>
#else
#include <avr/pgmspace.h>
#endif

// Partial Update Delay, may have an influence on degradation
#define GxGDEW0583T7_PU_DELAY 500

GxGDEW0583T7::GxGDEW0583T7(GxIO& io, int8_t rst, int8_t busy)
  : GxEPD(GxGDEW0583T7_WIDTH, GxGDEW0583T7_HEIGHT), IO(io),
    _current_page(-1), _using_partial_mode(false), _diag_enabled(false),
    _rst(rst), _busy(busy)
{
}

void GxGDEW0583T7::drawPixel(int16_t x, int16_t y, uint16_t color)
{
  if ((x < 0) || (x >= width()) || (y < 0) || (y >= height())) return;

  // check rotation, move pixel around if necessary
  switch (getRotation())
  {
    case 1:
      swap(x, y);
      x = GxGDEW0583T7_WIDTH - x - 1;
      break;
    case 2:
      x = GxGDEW0583T7_WIDTH - x - 1;
      y = GxGDEW0583T7_HEIGHT - y - 1;
      break;
    case 3:
      swap(x, y);
      y = GxGDEW0583T7_HEIGHT - y - 1;
      break;
  }
  uint16_t i = x / 8 + y * GxGDEW0583T7_WIDTH / 8;
  if (_current_page < 1)
  {
    if (i >= sizeof(_buffer)) return;
  }
  else
  {
    y -= _current_page * GxGDEW0583T7_PAGE_HEIGHT;
    if ((y < 0) || (y >= GxGDEW0583T7_PAGE_HEIGHT)) return;
    i = x / 8 + y * GxGDEW0583T7_WIDTH / 8;
  }

  if (!color)
    _buffer[i] = (_buffer[i] | (1 << (7 - x % 8)));
  else
    _buffer[i] = (_buffer[i] & (0xFF ^ (1 << (7 - x % 8))));
}

void GxGDEW0583T7::init(uint32_t serial_diag_bitrate)
{
  if (serial_diag_bitrate > 0)
  {
    Serial.begin(serial_diag_bitrate);
    _diag_enabled = true;
  }
  IO.init();
  IO.setFrequency(4000000); // 4MHz
  if (_rst >= 0)
  {
    digitalWrite(_rst, HIGH);
    pinMode(_rst, OUTPUT);
  }
  pinMode(_busy, INPUT);
  fillScreen(GxEPD_WHITE);
  _current_page = -1;
  _using_partial_mode = false;
}

void GxGDEW0583T7::fillScreen(uint16_t color)
{
  uint8_t data = (color == GxEPD_BLACK) ? 0xFF : 0x00;
  for (uint16_t x = 0; x < sizeof(_buffer); x++)
  {
    _buffer[x] = data;
  }
}

void GxGDEW0583T7::update(void)
{
  if (_current_page != -1) return;
  _using_partial_mode = false;
  _wakeUp();
  IO.writeCommandTransaction(0x10);
  for (uint32_t i = 0; i < GxGDEW0583T7_BUFFER_SIZE; i++)
  {
#if defined(ESP8266)
    // (10000 * 8bit * (8bits/bit + gap)/ 4MHz = ~ 200ms
    // (31000 * 8bit * (8bits/bit + gap)/ 4MHz = ~ 600ms is safe
    // if ((i % 10000) == 0) yield(); // avoid watchdog reset
#endif
    _send8pixel(i < sizeof(_buffer) ? _buffer[i] : 0x00);
  }
  IO.writeCommandTransaction(0x12);      //display refresh
  _waitWhileBusy("update");
  _sleep();
}

void  GxGDEW0583T7::drawBitmap(const uint8_t *bitmap, uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color, int16_t mode)
{
  if (mode & bm_default) mode |= bm_normal;
  drawBitmapBM(bitmap, x, y, w, h, color, mode);
}

void GxGDEW0583T7::drawBitmap(const uint8_t* bitmap, uint32_t size, int16_t mode)
{
  if (_current_page != -1) return;
  if (mode & bm_partial_update)
  {
    _using_partial_mode = true; // remember
    _wakeUp();
    IO.writeCommandTransaction(0x91); // partial in
    _setPartialRamArea(0, 0, GxGDEW0583T7_WIDTH - 1, GxGDEW0583T7_HEIGHT - 1);
    for (uint32_t i = 0; i < GxGDEW0583T7_BUFFER_SIZE; i++)
    {
      uint8_t data = 0x00; // white is 0x00 on device
      if (i < size)
      {
#if defined(__AVR) || defined(ESP8266) || defined(ESP32)
        data = pgm_read_byte(&bitmap[i]);
#else
        data = bitmap[i];
#endif
        if (mode & bm_invert) data = ~data;
      }
      _send8pixel(data);
    }
    IO.writeCommandTransaction(0x12);      //display refresh
    _waitWhileBusy("drawBitmap");
    IO.writeCommandTransaction(0x92); // partial out
  }
  else
  {
    _using_partial_mode = false; // remember
    _wakeUp();
    IO.writeCommandTransaction(0x10);
    for (uint32_t i = 0; i < GxGDEW0583T7_BUFFER_SIZE; i++)
    {
#if defined(ESP8266)
      // (10000 * 8bit * (8bits/bit + gap)/ 4MHz = ~ 200ms
      // (31000 * 8bit * (8bits/bit + gap)/ 4MHz = ~ 600ms is safe
      // if ((i % 10000) == 0) yield(); // avoid watchdog reset
#endif
      uint8_t data = 0x00; // white is 0x00 on device
      if (i < size)
      {
#if defined(__AVR) || defined(ESP8266) || defined(ESP32)
        data = pgm_read_byte(&bitmap[i]);
#else
        data = bitmap[i];
#endif
        if (mode & bm_invert) data = ~data;
      }
      _send8pixel(data);
    }
    IO.writeCommandTransaction(0x12);      //display refresh
    _waitWhileBusy("drawBitmap");
    _sleep();
  }
}

void GxGDEW0583T7::eraseDisplay(bool using_partial_update)
{
  if (_current_page != -1) return;
  if (using_partial_update)
  {
    if (!_using_partial_mode) _wakeUp();
    _using_partial_mode = true; // remember
    IO.writeCommandTransaction(0x91); // partial in
    _setPartialRamArea(0, 0, GxGDEW0583T7_WIDTH - 1, GxGDEW0583T7_HEIGHT - 1);
    IO.writeCommandTransaction(0x10);
    for (uint32_t i = 0; i < GxGDEW0583T7_BUFFER_SIZE; i++)
    {
      _send8pixel(0x00);
    }
    IO.writeCommandTransaction(0x12);      //display refresh
    _waitWhileBusy("eraseDisplay");
    IO.writeCommandTransaction(0x92); // partial out
  }
  else
  {
    _using_partial_mode = false; // remember
    _wakeUp();
    IO.writeCommandTransaction(0x10);
    for (uint32_t i = 0; i < GxGDEW0583T7_BUFFER_SIZE; i++)
    {
      _send8pixel(0x00);
    }
    IO.writeCommandTransaction(0x12);      //display refresh
    _waitWhileBusy("eraseDisplay");
    _sleep();
  }
}

uint16_t GxGDEW0583T7::_setPartialRamArea(uint16_t x, uint16_t y, uint16_t xe, uint16_t ye)
{
  x &= 0xFFF8; // byte boundary
  xe = (xe - 1) | 0x0007; // byte boundary - 1
  IO.writeCommandTransaction(0x90); // partial window
  IO.writeDataTransaction(x / 256);
  IO.writeDataTransaction(x % 256);
  IO.writeDataTransaction(xe / 256);
  IO.writeDataTransaction(xe % 256);
  IO.writeDataTransaction(y / 256);
  IO.writeDataTransaction(y % 256);
  IO.writeDataTransaction(ye / 256);
  IO.writeDataTransaction(ye % 256);
  //IO.writeDataTransaction(0x01); // don't see any difference
  IO.writeDataTransaction(0x00); // don't see any difference
  return (7 + xe - x) / 8; // number of bytes to transfer per line
}

void GxGDEW0583T7::_waitWhileBusy(const char* comment)
{
  unsigned long start = micros();
  while (1)
  { //=0 BUSY
    if (digitalRead(_busy) == 1) break;
    delay(1);
    if (micros() - start > 40000000)
    {
      if (_diag_enabled) Serial.println("Busy Timeout!");
      break;
    }
  }
  if (comment)
  {
#if !defined(DISABLE_DIAGNOSTIC_OUTPUT)
    if (_diag_enabled)
    {
      unsigned long elapsed = micros() - start;
      Serial.print(comment);
      Serial.print(" : ");
      Serial.println(elapsed);
    }
#endif
  }
  (void) start;
}

void GxGDEW0583T7::_send8pixel(uint8_t data)
{
  for (uint8_t j = 0; j < 8; j++)
  {
    uint8_t t = data & 0x80 ? 0x00 : 0x03;
    t <<= 4;
    data <<= 1;
    j++;
    t |= data & 0x80 ? 0x00 : 0x03;
    data <<= 1;
    IO.writeDataTransaction(t);
  }
}

void GxGDEW0583T7::_wakeUp()
{
  if (_rst >= 0)
  {
    digitalWrite(_rst, 0);
    delay(10);
    digitalWrite(_rst, 1);
    delay(10);
  }
  IO.writeCommandTransaction(0x01); // POWER SETTING
  IO.writeDataTransaction (0x37);
  IO.writeDataTransaction (0x00);
  IO.writeCommandTransaction(0X00); // PANNEL SETTING
  IO.writeDataTransaction(0xCF);
  IO.writeDataTransaction(0x08);
  IO.writeCommandTransaction(0x06); // boost
  IO.writeDataTransaction (0xc7);
  IO.writeDataTransaction (0xcc);
  IO.writeDataTransaction (0x28);
  IO.writeCommandTransaction(0x30); // PLL setting
  IO.writeDataTransaction (0x3a);   // PLL: 15s refresh
  //IO.writeDataTransaction (0x3c); // PLL: 30s refresh
  IO.writeCommandTransaction(0X41); // TEMPERATURE SETTING
  IO.writeDataTransaction(0x00);
  IO.writeCommandTransaction(0X50); // VCOM AND DATA INTERVAL SETTING
  IO.writeDataTransaction(0x77);
  IO.writeCommandTransaction(0X60); // TCON SETTING
  IO.writeDataTransaction(0x22);
  IO.writeCommandTransaction(0x61); // 600*448
  IO.writeDataTransaction (0x02);   // source 600
  IO.writeDataTransaction (0x58);
  IO.writeDataTransaction (0x01);   // gate 448
  IO.writeDataTransaction (0xc0);
  IO.writeCommandTransaction(0X82); // VCOM VOLTAGE SETTING
  IO.writeDataTransaction(0x28);    // all temperature range
  IO.writeCommandTransaction(0xe5); //FLASH MODE
  IO.writeDataTransaction(0x03);
  IO.writeCommandTransaction(0x04); //POWER ON
  //_waitWhileBusy("Power On");
}

void GxGDEW0583T7::_sleep(void)
{
  /**********************************flash sleep**********************************/
  IO.writeCommandTransaction(0X65); //FLASH CONTROL
  IO.writeDataTransaction(0x01);
  IO.writeCommandTransaction(0xB9);
  IO.writeCommandTransaction(0X65); //FLASH CONTROL
  IO.writeDataTransaction(0x00);
  /**********************************flash sleep**********************************/
  IO.writeCommandTransaction(0x02); // POWER OFF
  //_waitWhileBusy("Power Off");
  if (_rst >= 0)
  {
    IO.writeCommandTransaction(0x07); // DEEP SLEEP
    IO.writeDataTransaction(0xa5);
  }
}

void GxGDEW0583T7::drawPaged(void (*drawCallback)(void))
{
  if (_current_page != -1) return;
  _using_partial_mode = false;
  _wakeUp();
  IO.writeCommandTransaction(0x10);
  for (_current_page = 0; _current_page < GxGDEW0583T7_PAGES; _current_page++)
  {
    fillScreen(GxEPD_WHITE);
    drawCallback();
    for (int16_t y1 = 0; y1 < GxGDEW0583T7_PAGE_HEIGHT; y1++)
    {
      for (int16_t x1 = 0; x1 < GxGDEW0583T7_WIDTH / 8; x1++)
      {
        uint16_t idx = y1 * (GxGDEW0583T7_WIDTH / 8) + x1;
        uint8_t data = (idx < sizeof(_buffer)) ? _buffer[idx] : 0x00;
        _send8pixel(data);
      }
    }
#if defined(ESP8266)
    yield();
#endif
  }
  _current_page = -1;
  IO.writeCommandTransaction(0x12);      //display refresh
  //_waitWhileBusy("drawPaged");
  _sleep();
}
