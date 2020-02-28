#include <Arduino.h>
#include <Motor.hpp>
#include <Ultrasonic.h>

int i;

void updateMotors(Motor MotorArray[]){
    for (i=0;i<1;i++){
        MotorArray[i].MoveVelocity();
    }
}

/*
void updateUltrasonics(){
    for (i=0;i<1;i++){
        UltrasonicArray[i].findDistance();
    }

}
*/
