#include "power.h"

int Power::pin = 3;

Power::Power(int interrupt_pin){
  this->pin = interrupt_pin;
}

void Power::shutdown(Screen *screen){
  delay(200); //Realease time
  screen->shutdown(0, true);
  digitalWrite(LED_BUILTIN, LOW);
  attachInterrupt(digitalPinToInterrupt(this->pin), this->boot, FALLING);

  sleep_enable();
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  delay(100);
  sleep_cpu();
}

void Power::boot(){
  sleep_disable();
  detachInterrupt(pin);
  return;
}