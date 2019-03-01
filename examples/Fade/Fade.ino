#include <LED.h>

LED led(11);

void setup() {
  led.begin(1000);
}

void loop() {
  led.fadeIn(0, 250);
  led.fadeOut(250, 1000);
}
