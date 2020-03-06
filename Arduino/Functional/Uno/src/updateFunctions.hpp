#include <Arduino.h>
#include <Motor.hpp>
#include <Ultrasonic.h>
#include <Joystick.hpp>

int i;

void updateMotors(Motor MotorArray[]){
    for (i=0;i<1;i++){
        MotorArray[i].moveVelocity();
    }
}

/*
void updateUltrasonics(){
    for (i=0;i<1;i++){
        UltrasonicArray[i].findDistance();
    }

}
*/
