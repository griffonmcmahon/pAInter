#ifndef SOME_STRING_Z
#define SOME_STRING_Z
//This library is for functions to control ultrasonic sensors
#include <Arduino.h>

class Ultrasonic{
    char sigPin;

    public:
      int distance;
        Ultrasonic(char sigPin){
            this->sigPin = sigPin;
        }

    void setPinTypes();
    void findDistance();
    char getSigPin(){
        return this->sigPin;
    }
};

#endif
