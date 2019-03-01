#include <LED.h>

LED led(11);
Morse morse;

void setup() {
  morse.translate("SOS");
  led.begin(5000);
}

void loop() {
  led.sendMorseCode(0, 3500, morse);
}
