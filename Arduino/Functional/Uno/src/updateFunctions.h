#include <Arduino.h>
#include <Motor.h>

int i;

void updateVelocities(){
    for (i=0;i<1;i++){
        MotorArray[i].MoveVelocity();
    }
}
