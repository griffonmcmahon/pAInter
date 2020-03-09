#include <Arduino.h>
#include <Stepper.hpp>

Stepper::Stepper(char stepPin, char dirPin){
  this->stepPin=stepPin;
  this->dirPin=dirPin;
}

void Stepper::setDirection(char direction){
  this->direction = direction;
}

void Stepper::MoveStepper(int numSteps){
  digitalWrite(this->dirPin,this->direction);
  for(int x = 0; x < numSteps ; x++) {
    digitalWrite(this->stepPin,HIGH);
    delayMicroseconds(600);
    digitalWrite(this->stepPin,LOW);
    delayMicroseconds(600);
  }
}

void Stepper::setPinTypes(){
    pinMode(this->stepPin, OUTPUT);
    pinMode(this->dirPin, OUTPUT);
}
