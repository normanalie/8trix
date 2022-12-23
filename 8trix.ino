#include "config.h"
#include "screen.h"
#include "power.h"

//Init display OK
//Turn on/Shutdown
//Menu
//Settings
//Games list
//Transitions


Screen sc = Screen(MATRIX_DIN, MATRIX_CLK, MATRIX_CS, BRIGHTNESS);
Power pwr = Power(START);

void setup() {
  sc.test_pattern();
  pinMode(SELECT, INPUT_PULLUP);
  pinMode(START, INPUT_PULLUP);
}

void loop() {
  sc.setLed(0, 2, 2, HIGH);
  if (!digitalRead(SELECT)) {
    pwr.shutdown(&sc);
  }
}
