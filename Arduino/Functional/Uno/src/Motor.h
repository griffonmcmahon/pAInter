//This library is for functions to control lift motors
#include <Arduino.h>
class Motor{
    char encAPin, encBPin, enPin, in1Pin, in2Pin;
    int encPerInch;
    long position;
    double velocity;
    public:
        Motor(char encAPin, char encBPin, char enPin,char in1Pin, char in2Pin, int encPerInch){
            this->encAPin=encAPin;
            this->encBPin=encBPin;
            this->enPin=enPin;
            this->in1Pin=in1Pin;
            this->in2Pin=in2Pin;
            this->encPerInch=encPerInch;
    }

    void MoveVelocity();
    void aUp();
    char getencAPin(){
        return this->encAPin;
    }
};

void Motor::MoveVelocity(){
    velocity=velocity;
    digitalWrite(enPin, (velocity!=0));
    digitalWrite(in1Pin, (velocity>0));
    digitalWrite(in2Pin, (velocity<0));
}

void Motor::aUp(){
    if (digitalRead(this->encBPin)){
        this->position++;
    }
    else{
        this->position--;
    }
}







Motor FirstLiftMotor(2,3,4,5,6,1000);
//Motor SecondLiftMotor(7,8,9,10,11,250);

Motor MotorArray[] = {FirstLiftMotor};
