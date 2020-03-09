#include <Arduino.h>
#include <Motor.hpp>
#include <Ultrasonic.hpp>
#include <Stepper.hpp>

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

void initializeStepper(Stepper Stepper){
    for (int i=0;i<1;i++){
        Stepper.setPinTypes();
    }
}
