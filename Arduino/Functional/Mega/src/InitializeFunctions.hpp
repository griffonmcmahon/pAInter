#include <Arduino.h>
#include <DriveMotor.hpp>
#include <LiftMotor.hpp>
#include <Ultrasonic.hpp>
#include <Stepper.hpp>

void initializeMotors(LiftMotor MotorArray[]){
    for (int i=0;i<2;i++){
      MotorArray[i].setPinTypes();
    }
}
void initializeMotors(DriveMotor MotorArray[]){
    for (int i=0;i<3;i++){
      MotorArray[i].setPinTypes();
    }
}

void initializeUltrasonics(Ultrasonic UltrasonicArray[]){
    for (int i=0;i<6;i++){
        UltrasonicArray[i].setPinTypes();
    }
}

void initializeStepper(Stepper Stepper){
    for (int i=0;i<1;i++){
        Stepper.setPinTypes();
    }
}
