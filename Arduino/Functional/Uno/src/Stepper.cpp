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
    while(numSteps>0){
      digitalWrite(this->stepPin, HIGH);
	    delayMicroseconds(5000);
	    digitalWrite(this->stepPin, LOW);
	    delayMicroseconds(5000);
      numSteps--;
    }


}

void Stepper::setPinTypes(){
    pinMode(this->stepPin, OUTPUT);
    pinMode(this->dirPin, OUTPUT);
}
