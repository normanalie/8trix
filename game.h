#ifndef GAME_H
#define GAME_H

#include "Arduino.h"

class Game{
  public:
    Game();
    void loop();
    void frame_update();
    void game_update();
};

#endif