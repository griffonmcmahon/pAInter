#ifndef SOME_STRING_Z
#define SOME_STRING_Z
//This library is for functions to control ultrasonic sensors
#include <Arduino.h>

class Ultrasonic{
    char echoPin, trigPin;

    public:
      int distance;
        Ultrasonic(char echoPin, char trigPin){
            this->trigPin = trigPin;
            this->echoPin = echoPin;
        }

    void setPinTypes();
    void findDistance();
    char getechoPin(){
        return this->echoPin;
    }
};

#endif
