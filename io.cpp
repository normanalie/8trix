#include "io.h"

Button::Button(uint8_t gpio, uint8_t mode, bool inverted){
  this->gpio = gpio;
  this->inverted = inverted;
  this->active = false;
  this->last_pressed = 0;
  pinMode(this->gpio, mode);
}

bool Button::down(){
  bool down = digitalRead(this->gpio);
  if(this->inverted) down = !down;

  return down;
}

bool Button::press(){
  bool down = this->down();

  if(down && !this->active){
    this->last_pressed = (uint16_t)millis();
    this->active = true;
    return false;
  }else if(!down && this->active){ //Active but released == Not aknowledge yet
    this->active = false;
    return true;
  }
  return false;
}


bool Button::long_press(){
  bool down = this->down();

  if(down && !this->active){
    this->last_pressed = (uint16_t)millis();
    this->active = true;
    return false;
  }else if(down && this->active){
    if((uint16_t)millis() - this->last_pressed >= long_time){
      this->active = false;
      this->last_pressed = (uint16_t)millis();
      return true;
    }
  }else{
    this->active = false;
  }
  return false;
}