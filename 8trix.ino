#include "config.h"
#include "screen.h"
#include "power.h"
#include "io.h"

//Init display OK
//Turn on/Shutdown OK
//Menu
//Settings
//Games list
//Transitions


Screen sc = Screen(MATRIX_DIN, MATRIX_CLK, MATRIX_CS, BRIGHTNESS);
Power pwr = Power(START);

Button select = Button(SELECT, INPUT_PULLUP, true);
Button start = Button(START, INPUT_PULLUP, true);
Button up = Button(UP, INPUT_PULLUP, true);
Button down = Button(DOWN, INPUT_PULLUP, true);
Button left = Button(LEFT, INPUT_PULLUP, true);
Button right = Button(RIGHT, INPUT_PULLUP, true);

void setup() {
  Serial.begin(9600);
  digitalWrite(LED_BUILTIN, HIGH);
  sc.test_pattern();
}

void loop() {
  if(start.long_press()){
    pwr.shutdown(&sc);
    digitalWrite(LED_BUILTIN, HIGH);
  }
}
