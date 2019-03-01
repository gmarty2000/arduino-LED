#include "LED.h"

/* ------------------------------ CONSTRUCTOR CODE ------------------------------ */

/* Constructor - It saves the pin number and sets it in OUTPUT mode */
LED::LED(int pin) {
    this->pin = pin;
    this->time = 0;

    pinMode(pin, OUTPUT);
}

/* ------------------------------ SIMPLE APIs ------------------------------ */

/* Method - It sets the total time to complete one cycle */
void LED::begin(int time) {
    this->time = time;
}

/* Method - It turns the LED on */
void LED::on() {
    digitalWrite(this->pin, HIGH);
}

/* Method - It turns the LED off */
void LED::off() {
    digitalWrite(this->pin, LOW);
}

/* Method - It sets the brightness of the LED */
void LED::brightness(int light) {
    analogWrite(this->pin, light);
}

/* ------------------------------ NON-BLOCKING APIs ------------------------------ */

/* Method - It turns the LED on (with the variation of time) */
void LED::on(int beginTime, int endTime) {
    int currentTime = millis() % this->time;

    if (currentTime >= beginTime && currentTime <= endTime)
        this->on();
}

/* Method - It turns the LED off (with the variation of time) */
void LED::off(int beginTime, int endTime) {
    int currentTime = millis() % this->time;

    if (currentTime >= beginTime && currentTime <= endTime)
        this->off();
}

/* Method - It sets the brightness of the LED (with the variation of time) */
void LED::brightness(int beginTime, int endTime, int light) {
    int currentTime = millis() % this->time;

    if (currentTime >= beginTime && currentTime <= endTime)
        this->brightness(light);
}

/* ------------------------------ OTHER METHOD ------------------------------ */

/* Method - It blinks the LED */
void LED::blink(int beginTime, int endTime) {
    int middleTime = (endTime + beginTime) / 2;

    this->on(beginTime, middleTime);
    this->off(middleTime, endTime);
}

/* Method - It makes fade-in effect */
void LED::fadeIn(int beginTime, int endTime) {
    int max_light = 256;

    for (int light = 0; light < max_light; light++) {
        int duration = endTime - beginTime;

        this->brightness(   beginTime,
                            beginTime + (duration / (max_light - light)),
                            light);

        beginTime += duration / (max_light - light);
    }
}

/* Method - It makes fade-out effect */
void LED::fadeOut(int beginTime, int endTime) {
    int max_light = 256;

    for (int light = 0; light < max_light; light++) {
        int duration = endTime - beginTime;

        this->brightness(   beginTime,
                            beginTime + (duration / (max_light - light)),
                            max_light - light - 1);

        beginTime += duration / (max_light - light);
    }
}

/* Method - It sends the Morse Code to the LED */
void LED::sendMorseCode(int beginTime, int endTime, Morse morse) {
    int units = 0;
    int totalTime = endTime - beginTime;
    int timeBreak;

    for (int i = 0; i < morse.length(); i++) {
        char c = morse.getSignal(i);

        switch (c) {
            case '.':   units += 5;
                        break;

            case '-':   units += 9;
                        break;

            case ' ':   units += 2;
                        break;
        }
    }

    timeBreak = totalTime / units;

    for (int i = 0; i < morse.length(); i++) {
        char c = morse.getSignal(i);

        switch (c) {
            case '.':   this->on(beginTime, beginTime + (timeBreak * 4));
                        beginTime += timeBreak * 4;

                        this->off(beginTime, beginTime + timeBreak);
                        beginTime += timeBreak;
                        break;


            case '-':   this->on(beginTime, beginTime + (timeBreak * 8));
                        beginTime += timeBreak * 8;

                        this->off(beginTime, beginTime + timeBreak);
                        beginTime += timeBreak;
                        break;

                        
            case ' ':   this->off(beginTime, beginTime + (timeBreak * 2));
                        beginTime += timeBreak * 2;
                        break;
        }
    }
}

/* ------------------------------ toString() METHOD ------------------------------ */

/* Method - It returns the LED informations */
String LED::toString() {
    String ret = String("LED: {");
    ret.concat("pin=");
    ret.concat(this->pin);
    ret.concat(", time=");
    ret.concat(this->time);
    ret.concat("}");
    
    return ret;
}
