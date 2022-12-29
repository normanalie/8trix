#ifndef SCREEN_H
#define SCREEN_H

#include "Arduino.h"
#include "LedControl.h"
#include "font.h"

#define SCREEN_SIZE 8
#define SCREEN_ADDR 0

class Screen : public LedControl {
  public:
    Screen(int din, int clk, int cs, int brightness);
    void test_pattern();
    void update();
    void off();
    void on();
    bool display[SCREEN_SIZE][SCREEN_SIZE];
  private:
    bool buffer[SCREEN_SIZE][SCREEN_SIZE];
};

#endif