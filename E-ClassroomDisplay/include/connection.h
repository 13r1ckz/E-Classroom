#include <Arduino.h>

class Connection
{
  public:
    uint32_t getMin();
    uint8_t getSec();

  protected:
    uint8_t seconds;
    uint32_t minutes;
};