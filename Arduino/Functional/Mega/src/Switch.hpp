#ifndef SOME_STRING_O
#define SOME_STRING_O
//This library is for functions to control ultrasonic sensors
#include <Arduino.h>

class Switch{
    char sigPin;

    public:
      bool state;
        Switch(char sigPin){
            this->sigPin = sigPin;
        }

    void setPinTypes();
    void updateState();
};

#endif
