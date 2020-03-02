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
      digitalWrite(stepPin, HIGH);
	    delayMicroseconds(2000);
	    digitalWrite(stepPin, LOW);
	    delayMicroseconds(2000);
      numSteps--;
    }


}

void Stepper::setPinTypes(){
    pinMode(this->stepPin, OUTPUT);
    pinMode(this->dirPin, OUTPUT);
}
