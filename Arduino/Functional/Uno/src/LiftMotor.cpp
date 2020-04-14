#include <Arduino.h>
#include <LiftMotor.hpp>

LiftMotor::LiftMotor(char encAPin, char encBPin, char enPin,char in1Pin, char in2Pin, char topLimitPin, char botLimitPin){
    this->encAPin=encAPin;
    this->encBPin=encBPin;
    this->enPin=enPin;
    this->in1Pin=in1Pin;
    this->in2Pin=in2Pin;
    this->topLimitPin=topLimitPin;
    this->botLimitPin=botLimitPin;
}

char LiftMotor::getencAPin(){
    return this->encAPin;
}

void LiftMotor::setVelocity(int velocity){
  this->velocity = velocity;
}

void LiftMotor::moveVelocity(){
    analogWrite(this->enPin, abs(this->velocity));//(int)(this->velocity*255.0)
    digitalWrite(this->in1Pin, (this->velocity>0));
    digitalWrite(this->in2Pin, (this->velocity<0)); //(this->velocity>0)
}

void LiftMotor::aUp(){
    if (digitalRead(this->encBPin)){
        this->position++;
    }
    else{
        this->position--;
    }
}

void LiftMotor::setPinTypes(){
    pinMode(this->encAPin, INPUT);
    pinMode(this->encBPin, INPUT);
    pinMode(this->enPin, OUTPUT);
    pinMode(this->in1Pin, OUTPUT);
    pinMode(this->in2Pin, OUTPUT);
}
