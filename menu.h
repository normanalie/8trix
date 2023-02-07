#ifndef MENU_H
#define MENU_H

#include "game.h"
#include "screen.h"

class Menu : virtual public Game{
  public:
    Menu(Screen *screen);
    virtual void setup(Screen *screen);
    virtual void loop();
    virtual void game_update();
    Screen *screen;
};

#endif