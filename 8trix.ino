#include "config.h"
#include "screen.h"

//Init display OK
//Turn on/Shutdown
//Menu
//Settings
//Games list
//Transitions

Screen sc = Screen(MATRIX_DIN, MATRIX_CLK, MATRIX_CS, BRIGHTNESS);

void setup() {
  sc.test_pattern();

}

void loop() {
  // put your main code here, to run repeatedly:

}
