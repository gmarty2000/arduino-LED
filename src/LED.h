#ifndef __LED_h
#define __LED_h

#include "Arduino.h"
#include "utility/Morse.h"

class LED {
    public:     LED(int);
                void begin(int);
                void on();
                void off();
                void brightness(int);
                void on(int, int);
                void off(int, int);
                void brightness(int, int, int);
                void blink(int, int);
                void flash(int, int);
                void fadeIn(int, int);
                void fadeOut(int, int);
                void sendMorseCode(int, int, Morse);
                String toString();
    private:    int pin;
                int time;
};

#endif