//This library is for functions to control motors
#ifndef SOME_STRING_G
#define SOME_STRING_G

#include <Arduino.h>

class Stepper{
    char stepPin, dirPin;
    int direction;
    int velocity;
    public:

        Stepper(char stepPin, char dirPin);
        void setDirection(char direction);
        void MoveStepper(int numSteps);
        void setPinTypes();
};



#endif
