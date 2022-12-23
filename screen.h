#ifndef SCREEN_H
#define SCREEN_H

#include "Arduino.h"
#include "LedControl.h"

class Screen : public LedControl {
  public:
    Screen(int din, int clk, int cs) : LedControl(din, clk, cs, 1){}
    void test_pattern();
};

#endif