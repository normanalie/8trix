#ifndef GAME_H
#define GAME_H

#include "Arduino.h"
#include "screen.h"

class Game{
  public:
    Game();
    virtual void setup();
    virtual void loop();
    virtual void game_update();
};

#endif