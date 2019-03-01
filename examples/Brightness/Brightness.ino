#include <LED.h>

LED led(11);

void setup() {
  led.begin(1000);
}

void loop() {
  led.brightness(0, 500, 63);
  led.brightness(500, 1000, 255);
}
