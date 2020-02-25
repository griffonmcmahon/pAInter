#include <Arduino.h>
#include <Motor.h>

int i;

void updateMotors(){
    for (i=0;i<1;i++){
        MotorArray[i].MoveVelocity();
    }
}

void updateUltrasonics(){
    for (i=0;i<1;i++){
        UltrasonicArray[i].MoveVelocity();
    }

}
