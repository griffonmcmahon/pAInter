#include <Arduino.h>
#include <Motor.hpp>
#include <Ultrasonic.h>

int i;

void initializeMotors(Motor MotorArray[]){
    for (i=0;i<1;i++){
        attachInterrupt(digitalPinToInterrupt(MotorArray[i].getencAPin), MotorArray[i].aUp(), FALLING);
    }
    MotorArray[i].setPinTypes();
}

void initializeUltrasonics(){
    for (i=0;i<1;i++){
        UltrasonicArray[i].setPinTypes();
    }
}

void initializeSteppers(){
    for (i=0;i<1;i++){

    }
}
