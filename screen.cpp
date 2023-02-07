#include "screen.h"
#include "font.h"

Screen::Screen(int din, int clk, int cs, int brightness) : LedControl(din, clk, cs, 1){
  this->clearDisplay(SCREEN_ADDR);
  this->on();
  this->setIntensity(0, brightness);
  for(int i = 0; i<SCREEN_SIZE; i++){
    for(int j = 0; i<SCREEN_SIZE; i++){
      this->display[i][j] = LOW;
      this->buffer[i][j] = LOW;
    }
  }
}

void Screen::test_pattern(){
  for(int j = 0; j < 8; j++){
    for(int i = 0; i < 8; i++){
      this->setLed(SCREEN_ADDR, i, j, HIGH);
      delay(5);
    }
  }
  for(int j = 0; j < 8; j++){
    for(int i = 0; i < 8; i++){
      this->setLed(SCREEN_ADDR, i, j, LOW);
      delay(5);
    }
  }
  return;
}

void Screen::update(){
  for(int i = 0; i<SCREEN_SIZE; i++){
    for(int j = 0; i<SCREEN_SIZE; i++){
      if(this->display[i][j] != this->buffer[i][j]){
        this->buffer[i][j] = this->display[i][j];
        this->setLed(SCREEN_ADDR, i, j, this->buffer[i][j]);
      }
    }
  }
}

void Screen::off(){
  this->shutdown(SCREEN_ADDR, true);
}

void Screen::on(){
  this->shutdown(SCREEN_ADDR, false);
}

void Screen::print_chr(char chr){
  char *character = NULL;
  if(chr >= 'a' && chr <= 'z'){
    character = Font::chr[chr-'a'];
  }else if(chr >= 'A' && chr <= 'Z'){
    character = Font::chr[chr-'A'];
  } 

  if(character){
    for(int i=SCREEN_SIZE; i>(SCREEN_SIZE-FONT_SIZE); i--){
      this->setColumn(0, i-1, character[SCREEN_SIZE-i]<<3);
    }
  }
}
