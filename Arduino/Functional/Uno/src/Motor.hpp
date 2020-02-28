//This library is for functions to control motors
#ifndef SOME_STRING_H
#define SOME_STRING_H

#include <Arduino.h>

class Motor{
    char encAPin, encBPin, enPin, in1Pin, in2Pin;
    int encPerInch;
    long position;
    int velocity;
    public:

        Motor(char encAPin, char encBPin, char enPin,char in1Pin, char in2Pin, int encPerInch);
        char getencAPin();
        void setVelocity(int velocity);
        void MoveVelocity();
        void aUp();
        void setPinTypes();


};



#endif
