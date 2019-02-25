#ifndef __LED_h
#define __LED_h

#include "Arduino.h"

class LED {
    public:     LED(int);
                void on(int);
                void off(int);
                void brightness(int, int);
                void blink(int);
                void fadeIn(int);
                void fadeOut(int);
                String toString();
    private:    int pin;
};

#endif
