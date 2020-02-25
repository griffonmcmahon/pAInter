#include <Arduino.h>
#include <Motor.h>

int i;

void attachInterrupts(){
    for (i=0;i<1;i++){
        attachInterrupt(digitalPinToInterrupt(MotorArray[i].getencAPin), MotorArray[i].aUp(), FALLING);
    }
}
