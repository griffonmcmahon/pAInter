#include <Arduino.h>
#include <Motor.hpp>

Motor::Motor(char encAPin, char encBPin, char enPin,char in1Pin, char in2Pin, int encPerInch){
    this->encAPin=encAPin;
    this->encBPin=encBPin;
    this->enPin=enPin;
    this->in1Pin=in1Pin;
    this->in2Pin=in2Pin;
    this->encPerInch=encPerInch;
}

char Motor::getencAPin(){
    return this->encAPin;
}

void Motor::setVelocity(int velocity){
  this->velocity = velocity;
}

void Motor::MoveVelocity(){
    analogWrite(this->enPin, abs(this->velocity));//(int)(this->velocity*255.0)
    digitalWrite(this->in1Pin, (this->velocity>0));
    digitalWrite(this->in2Pin, (this->velocity<0)); //(this->velocity>0)
}

void Motor::aUp(){
    if (digitalRead(this->encBPin)){
        this->position++;
    }
    else{
        this->position--;
    }
}

void Motor::setPinTypes(){
    pinMode(this->encAPin, INPUT);
    pinMode(this->encBPin, INPUT);
    pinMode(this->enPin, OUTPUT);
    pinMode(this->in1Pin, OUTPUT);
    pinMode(this->in2Pin, OUTPUT);
}
