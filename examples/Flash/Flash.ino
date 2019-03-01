#include <LED.h>

LED led(11);

void setup() {
  led.begin(2000);
}

void loop() {
  led.flash(0, 1000);
}
