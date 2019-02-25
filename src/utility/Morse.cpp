#include "Morse.h"

Morse::Morse() {}

void Morse::addSignal(Signal signal) {
    char c;

    switch (signal) {
        case Signal::DOT:   c = '.';
                            break;
        case Signal::DASH:  c = '-';
                            break;
        case Signal::SPACE: c = ' ';
                            break;
    }

    this->message.concat(c);
}

void Morse::removeSignal(int position) {
    this->message.remove(position);
}

char Morse::getSignal(int position) {
    return this->message.charAt(position);
}

int Morse::length() {
    return this->message.length();
}

void Morse::translate(String str) {
    str.toLowerCase();

    for (int i = 0; i < str.length(); i++) {
        char c = str.charAt(i);

        switch (c) {
            case 'a':   this->message.concat(".-");
                        break;

            case 'b':   this->message.concat("-...");
                        break;

            case 'c':   this->message.concat("-.-.");
                        break;

            case 'd':   this->message.concat("-..");
                        break;

            case 'e':   this->message.concat(".");
                        break;

            case 'f':   this->message.concat("..-.");
                        break;

            case 'g':   this->message.concat("--.");
                        break;

            case 'h':   this->message.concat("....");
                        break;

            case 'i':   this->message.concat("..");
                        break;

            case 'j':   this->message.concat(".---");
                        break;
                        
            case 'k':   this->message.concat("-.-");
                        break;

            case 'l':   this->message.concat(".---");
                        break;

            case 'm':   this->message.concat("--");
                        break;

            case 'n':   this->message.concat("-.");
                        break;

            case 'o':   this->message.concat("---");
                        break;

            case 'p':   this->message.concat(".--.");
                        break;

            case 'q':   this->message.concat("--.-");
                        break;

            case 'r':   this->message.concat(".-.");
                        break;

            case 's':   this->message.concat("...");
                        break;

            case 't':   this->message.concat("-");
                        break;

            case 'u':   this->message.concat("..-");
                        break;

            case 'v':   this->message.concat("...-");
                        break;

            case 'w':   this->message.concat(".--");
                        break;

            case 'x':   this->message.concat("-..-");
                        break;

            case 'y':   this->message.concat("-.--");
                        break;

            case 'z':   this->message.concat("--..");
                        break;

            case '1':   this->message.concat(".----");
                        break;

            case '2':   this->message.concat("..---");
                        break;

            case '3':   this->message.concat("...--");
                        break;

            case '4':   this->message.concat("....-");
                        break;

            case '5':   this->message.concat(".....");
                        break;

            case '6':   this->message.concat("-....");
                        break;

            case '7':   this->message.concat("--...");
                        break;

            case '8':   this->message.concat("---..");
                        break;

            case '9':   this->message.concat("----.");
                        break;

            case '0':   this->message.concat("-----");
                        break;
        }

        this->addSignal(Signal::SPACE);
    }
}

String Morse::toString() {
    String ret = String("Morse: {");
    ret.concat("message=\"");
    ret.concat(this->message);
    ret.concat("\"}");
    
    return ret;
}
