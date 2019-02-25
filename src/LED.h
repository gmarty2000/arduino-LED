#ifndef __LED_h
#define __LED_h

#include "Arduino.h"
#include "utility/Morse.h"

class LED {
    public:     LED(int);
                void on(int);
                void off(int);
                void brightness(int, int);
                void blink(int);
                void fadeIn(int);
                void fadeOut(int);
                void sendMorseCode(Morse, int);
                String toString();
    private:    int pin;
};

#endif