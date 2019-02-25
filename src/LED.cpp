#include "LED.h"

/* ------------------------------ CONSTRUCTOR CODE ------------------------------ */

/* Constructor - It saves the pin number and sets it in OUTPUT mode */
LED::LED(int pin) {
    this->pin = pin;
    pinMode(pin, OUTPUT);
}

/* ------------------------------ SIMPLE APIs ------------------------------ */

/* Method - It turns the LED on */
void LED::on(int time) {
    digitalWrite(this->pin, HIGH);
    delay(time);
}

/* Method - It turns the LED on */
void LED::off(int time) {
    digitalWrite(this->pin, LOW);
    delay(time);
}

/* Method - It sets the brightness of the LED */
void LED::brightness(int light, int time) {
    analogWrite(this->pin, light);
    delay(time);
}

/* ------------------------------ OTHER FUNCTIONS ------------------------------ */

/* Method - It blinks the LED */
void LED::blink(int time) {
    this->on(time / 2);
    this->off(time / 2);
}

/* Method - It makes fade-in effect */
void LED::fadeIn(int time) {
    int max_light = 256;

    for (int light = max_light; light > 0; light--) {
        this->brightness(max_light - light, time / light);
        time -= time / light;
    }
}

/* Method - It makes fade-out effect */
void LED::fadeOut(int time) {
    int max_light = 256;

    for (int light = max_light; light > 0; light--) {
        this->brightness(light - 1, time / light);
        time -= time / light;
    }
}

void LED::sendMorseCode(Morse morse, int time) {
    for (int i = 0; i < morse.length(); i++) {
        char c = morse.getSignal(i);

        switch (c) {
            case '.':   this->on(time);
                        this->off(time / 4);
                        break;
            case '-':   this->on(time * 2);
                        this->off(time / 4);
                        break;
            case ' ':   this->off(time / 2);
                        break;
        }
    }
}

/* Method - It returns the LED informations */
String LED::toString() {
    String ret = String("LED: {");
    ret.concat("pin=");
    ret.concat(this->pin);
    ret.concat("}");
    
    return ret;
}
