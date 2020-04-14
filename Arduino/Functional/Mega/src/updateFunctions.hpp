#include <Arduino.h>
#include <LiftMotor.hpp>
#include <Ultrasonic.hpp>
#include <DriveMotor.hpp>

int i;

void updateLiftMotors(LiftMotor MotorArray[]){
    for (i=0;i<2;i++){
        MotorArray[i].moveVelocity();
    }
}
void updateDriveMotors(DriveMotor MotorArray[]){
    for (i=0;i<3;i++){
        MotorArray[i].moveVelocity();
    }
}


void updateUltrasonics(Ultrasonic UltrasonicArray[]){
    for (i=0;i<1;i++){
        UltrasonicArray[i].findDistance();
    }

}
