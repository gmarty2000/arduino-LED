#include <LED.h>

LED led(11);

void setup() {}

void loop() {
  led.brightness(63, 500);
  led.brightness(255, 500);
}
