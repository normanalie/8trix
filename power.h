#ifndef POWER_H
#define POWER_H

#include <avr/sleep.h>
#include "screen.h"

class Power{
  public:
    Power(int interrupt_pin);
    void shutdown(Screen *screen);
    static int pin;
    static void boot();
};

#endif