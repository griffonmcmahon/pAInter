//This library is for functions to control motors
#ifndef SOME_STRING_H
#define SOME_STRING_H

#include <Arduino.h>

class Motor{
public:
    char encAPin, encBPin, enPin, in1Pin, in2Pin;
    int encPerInch;

    int velocity;
    public:
        long position;
        Motor(char encAPin, char encBPin, char enPin,char in1Pin, char in2Pin);
        char getencAPin();
        void setVelocity(int velocity);
        void moveVelocity();
        void aUp();
        void setPinTypes();


};



#endif
