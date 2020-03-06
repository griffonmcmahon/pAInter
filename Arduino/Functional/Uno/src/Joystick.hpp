//This library is for functions to control motors
#ifndef SOME_STRING_L
#define SOME_STRING_L

#include <Arduino.h>

class Joystick{
    char xPin, yPin, swPin;
  public:
    bool xHigh, xLow, yHigh, yLow;
    bool sw;

    public:
      Joystick(char xPin, char yPin, char swPin);
      void updateJoystick();
      void setPinTypes();
};



#endif
