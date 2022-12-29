#ifndef MENU_H
#define MENU_H

#include "game.h"
#include "screen.h"

class Menu : public Game{
  public:
    Menu();
    void setup(bool disp[SCREEN_SIZE][SCREEN_SIZE]);
    void loop(bool disp[SCREEN_SIZE][SCREEN_SIZE]);
    void game_update(bool disp[SCREEN_SIZE][SCREEN_SIZE]);
};

#endif