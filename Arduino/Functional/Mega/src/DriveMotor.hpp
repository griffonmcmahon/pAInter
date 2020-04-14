//This library is for functions to control motors
#ifndef SOME_STRING_P
#define SOME_STRING_P

#include <Arduino.h>

class DriveMotor{
public:
    char encAPin, encBPin, enPin, in1Pin, in2Pin, topLimitPin, botLimitPin;
    int encPerInch;

    int velocity;
    public:
        long position;
        DriveMotor(char encAPin, char encBPin, char enPin,char in1Pin, char in2Pin, char topLimitPin, char botLimitPin);
        char getencAPin();
        void setVelocity(int velocity);
        void moveVelocity();
        void aUp();
        void setPinTypes();
};



#endif
