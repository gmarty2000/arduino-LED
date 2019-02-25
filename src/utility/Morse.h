#ifndef __Morse_h
#define __Morse_h

#include "Arduino.h"

enum class Signal {
    DOT,
    DASH,
    SPACE
};

class Morse {
    public:     Morse();
                void addSignal(Signal);
                void removeSignal(int);
                char getSignal(int);
                int length();
                void translate(String);
                String toString();
    private:    String message;
};

#endif
