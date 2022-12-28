#ifndef IO_H
#define IO_H

#include "Arduino.h"

const uint16_t long_time = 500;

class Button{
  public:
    Button(uint8_t gpio, uint8_t mode, bool inverted);
    bool down();
    bool press();
    bool long_press();
    uint8_t gpio;
    bool inverted;
  private:
    uint16_t last_pressed;
    bool active;
};




#endif