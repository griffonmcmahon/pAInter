#include <Arduino.h>
#include <Ultrasonic.hpp>

void Ultrasonic::setPinTypes(){
    pinMode(this->echoPin, INPUT);
    pinMode(this->trigPin, OUTPUT);
}

void Ultrasonic::findDistance(){
  pinMode(this->echoPin, OUTPUT);
    digitalWrite(this->trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(this->trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(this->trigPin, LOW);
    pinMode(this->echoPin, INPUT);
    this->distance = pulseIn(this->echoPin, HIGH) * (0.034 / 2) / 2.54;
}
