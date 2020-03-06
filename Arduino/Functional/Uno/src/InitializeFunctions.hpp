#include <Arduino.h>
#include <Motor.hpp>
#include <Ultrasonic.h>

void initializeMotors(Motor MotorArray[]){
    for (int i=0;i<1;i++){
      MotorArray[i].setPinTypes();
    }
}

void initializeUltrasonics(Ultrasonic UltrasonicArray[]){
    for (int i=0;i<1;i++){
        UltrasonicArray[i].setPinTypes();
    }
}

void initializeSteppers(){
    for (int i=0;i<1;i++){

    }
}
