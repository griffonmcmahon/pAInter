#include <Arduino.h>
#include <Motor.h>
#include <Ultrasonic.h>

int i;

void initializeMotors(){
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
