#include "menu.h"

Menu::Menu(Screen *screen) : Game(){
  this->screen = screen;
}

void Menu::setup(Screen *screen){
  //Game::setup();
  Serial.println("setup");
  screen->print_chr('b');
  return;
}

void Menu::loop(){
  return;
}


uint8_t count = 0;
char str[] = "Hello World";
void Menu::game_update(){

  //if(str[count] == '\0') count = 0;
  //this->screen->print_chr(str[count]);
  return;
}