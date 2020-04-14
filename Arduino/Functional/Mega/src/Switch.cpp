#include <Arduino.h>
#include <Switch.hpp>

void Switch::setPinTypes(){
    pinMode(this->sigPin, INPUT);
}
void Switch::updateState(){
    this->state = digitalRead(this->sigPin);
}
