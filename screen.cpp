#include "screen.h"

Screen::Screen(int din, int clk, int cs);

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
