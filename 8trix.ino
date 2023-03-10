#include "config.h"
#include "screen.h"
#include "power.h"
#include "io.h"
#include "menu.h"

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

Game* gm = NULL;
gm = dynamic_cast<Menu*>(gm);
gm = &Menu(&sc);


unsigned long prev_tick = millis();
unsigned long prev_frame = millis();

void update_game();
void update_screen();

void setup() {
  Serial.begin(9600);
  digitalWrite(LED_BUILTIN, HIGH);

  Serial.println("prout");
  sc.test_pattern();
  
  gm->setup(&sc);
}

void loop() {
  if(start.long_press()){  //On/Off
    pwr.shutdown(&sc);
    digitalWrite(LED_BUILTIN, HIGH);
  }

  gm->loop();

  if(millis() - prev_frame >= 1000/FPS){
    sc.update();
    prev_frame = millis();
  }
  
  if(millis() - prev_tick >= 1000/TPS){
    gm->game_update();
    prev_tick = millis();
  }
}
