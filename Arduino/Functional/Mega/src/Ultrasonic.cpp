#include <Arduino.h>
#include <Ultrasonic.hpp>

void Ultrasonic::setPinTypes(){
    pinMode(this->sigPin, INPUT);
}

void Ultrasonic::findDistance(){
  pinMode(this->sigPin, OUTPUT);
    digitalWrite(this->sigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(this->sigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(this->sigPin, LOW);
    pinMode(this->sigPin, INPUT);
    this->distance = pulseIn(this->sigPin, HIGH) * (0.034 / 2) / 2.54;
}
