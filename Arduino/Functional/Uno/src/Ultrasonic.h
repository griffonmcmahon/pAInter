//This library is for functions to control ultrasonic sensors
#include <Arduino.h>

class Ultrasonic{
    char echoPin, trigPin;
    bool threePin;

    public:
        Ultrasonic(char echoPin, char trigPin, bool threePin){
            this->trigPin = trigPin;
            this->echoPin = echoPin;
            this->threePin = threePin;
        }

    void setPinTypes();
    int getDistance();
    char getechoPin(){
        return this->echoPin;
    }
};

void Ultrasonic::setPinTypes(){
    pinMode(this->echoPin, INPUT);
    pinMode(this->trigPin, OUTPUT);
}

int Ultrasonic::getDistance(){
    digitalWrite(this->trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(this->trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(this->trigPin, LOW);
    return  pulseIn(this->echoPin, HIGH) * (0.034 / 2) / 2.54;
}




Ultrasonic UltrasonicTop(12,13,false);

Ultrasonic UltrasonicArray[] = {UltrasonicTop};
