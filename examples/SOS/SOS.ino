#include <LED.h>

LED led(11);
Morse morse;

void setup() {
  morse.translate("SOS");
  led.sendMorseCode(morse, 200);
}

void loop() {}
