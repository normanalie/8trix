#include "screen.h"

Screen::Screen(int din, int clk, int cs, int brightness) : LedControl(din, clk, cs, 1){
  this->clearDisplay(0);
  this->shutdown(0, false);
  this->setIntensity(0, brightness);
}

void Screen::test_pattern(){
  for(int j = 0; j < 8; j++){
    for(int i = 0; i < 8; i++){
      this->setLed(0, i, j, HIGH);
      delay(15);
    }
  }
  for(int j = 0; j < 8; j++){
    for(int i = 0; i < 8; i++){
      this->setLed(0, i, j, LOW);
      delay(15);
    }
  }
  return;
}
