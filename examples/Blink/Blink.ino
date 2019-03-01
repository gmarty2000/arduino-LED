#include <LED.h>

LED led(11);

void setup() {
  led.begin(1000);
}

void loop() {
  led.blink(0, 1000);
}
