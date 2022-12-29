#ifndef MENU_H
#define MENU_H

#include "game.h"

class Menu : public Game{
  public:
    Menu();
    void loop();
    void frame_update();
    void game_update();
};

#endif