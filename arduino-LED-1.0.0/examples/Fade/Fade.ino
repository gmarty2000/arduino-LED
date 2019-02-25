#include <LED.h>

LED led(11);

void setup() {}

void loop() {
  int time = 1000;
  led.fadeIn(time);
  led.fadeOut(time);
}
