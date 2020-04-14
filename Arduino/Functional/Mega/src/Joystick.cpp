#include <Arduino.h>
#include <Joystick.hpp>

Joystick::Joystick(char xPin, char yPin, char swPin){
    this->xPin = xPin;
    this->yPin = yPin;
    this->swPin = swPin;
}

void Joystick::updateJoystick(){
  this->xHigh = analogRead(this->xPin)>600;
  this->xLow = analogRead(this->xPin)<450;
  this->yHigh = analogRead(this->yPin)>600;
  this->yLow = analogRead(this->yPin)<450;
  this->sw = digitalRead(this->swPin)==HIGH;
}

void Joystick::setPinTypes(){
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(swPin, INPUT);
}
