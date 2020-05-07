#include <Arduino.h>
#include <LiftMotor.hpp>
#include <Stepper.hpp>
#include <updateFunctions.hpp>
#include <initializeFunctions.hpp>
#include <Ultrasonic.hpp>
#include <Switch.hpp>

LiftMotor FirstLiftMotor(1,2,3,4,5,6,7);
LiftMotor SecondLiftMotor(1,2,3,4,5,6,7);
LiftMotor LiftMotors[] = {FirstLiftMotor, SecondLiftMotor};

void LiftMotors0EncUp();
void LiftMotors1EncUp();

DriveMotor LeftDriveMotor(1,2,3,4,5,6,7);
DriveMotor RightDriveMotor(1,2,3,4,5,6,7);
DriveMotor MidDriveMotor(1,2,3,4,5,6,7);
DriveMotor DriveMotors[] = {LeftDriveMotor, RightDriveMotor, MidDriveMotor};

void DriveMotors0EncUp();
void DriveMotors1EncUp();
void DriveMotors2EncUp();

Stepper ThirdStage(1,2);

Ultrasonic UltraTop(1);
Ultrasonic UltraOut(1);
Ultrasonic UltraSL(1);
Ultrasonic UltraWL(1);
Ultrasonic UltraWR(1);
Ultrasonic UltraSR(1);
Ultrasonic Ultrasonics[] = {UltraTop, UltraOut, UltraSL, UltraWL, UltraWR, UltraSR};


Switch bot1Switch(1);
Switch top1Switch(1);
Switch bot2Switch(1);
Switch top2Switch(1);
Switch saturateSwitch(1);
Switch Switches[] = {bot1Switch, top1Switch, bot2Switch, top2Switch, saturateSwitch};

char mainPhase = 'o';
void saturate();
void paint();
void nextColumn();
void neutral();

int subPhase = 0;

long curTime = 0;
long time1 = 0;
long time2 = 0;

void setup() {
  Serial.begin(9600);
  initializeLiftMotors(LiftMotors);
  initializeDriveMotors(DriveMotors);
  initializeStepper(ThirdStage);
  initializeUltrasonics(Ultrasonics);
  attachInterrupt(digitalPinToInterrupt(LiftMotors[0].encAPin),LiftMotors0EncUp, FALLING);
  attachInterrupt(digitalPinToInterrupt(LiftMotors[1].encAPin),LiftMotors1EncUp, FALLING);
  attachInterrupt(digitalPinToInterrupt(DriveMotors[0].encAPin),DriveMotors0EncUp, FALLING);
  attachInterrupt(digitalPinToInterrupt(DriveMotors[1].encAPin),DriveMotors1EncUp, FALLING);
  attachInterrupt(digitalPinToInterrupt(DriveMotors[2].encAPin),DriveMotors2EncUp, FALLING);

}

void loop() {

    curTime = millis();

    //update loop
        updateLiftMotors(LiftMotors);
        updateDriveMotors(DriveMotors);
        updateUltrasonics(Ultrasonics);
        //update switches



    switch(mainPhase){
        case 's':
            saturate();
            break;
        case 'p':
            paint();
            break;
        case 'n':
            nextColumn();
            break;
        case 'o':
            neutral();
            break;
    }


}

void LiftMotors0EncUp(){
  LiftMotors[0].aUp();
}
void LiftMotors1EncUp(){
  LiftMotors[1].aUp();
}
void DriveMotors0EncUp(){
  DriveMotors[0].aUp();
}
void DriveMotors1EncUp(){
  DriveMotors[1].aUp();
}
void DriveMotors2EncUp(){
  DriveMotors[2].aUp();
}




void saturate(){
    switch(subPhase){
        case 0:
            ThirdStage.setDirection(0);
            ThirdStage.MoveStepper(20);
            if(saturateSwitch.state){
                 subPhase=1;
             };
             break;
        case 1:
            if(time1==0){
                time1=curTime;
            }
            if(curTime-time1>5000){ //5 second saturate
                subPhase = 2;
                time1 = 0;
            }
            break;
        case 2:
            ThirdStage.setDirection(1);
            ThirdStage.MoveStepper(20);
            if(UltraOut.distance < 3){
                subPhase=0;
                mainPhase = 'p';
            };
            break;
    }
}
void paint(){
    //roller pulled in not to button
    //roller lfited up to top1Switch
    //roller applied to wall
    //roller rolled down wall
    //possibly up and down motion

    switch(subPhase){
        case 0:
            ThirdStage.setDirection(0);
            ThirdStage.MoveStepper(20);
            if(saturateSwitch.state){
                 subPhase=1;
             };
             break;
        case 1:
            ThirdStage.setDirection(1);
            ThirdStage.MoveStepper(40);
            subPhase=2;
            break;
        case 2:
            if(!top1Switch.state){
                FirstLiftMotor.setVelocity(255);
            }
            else{
                FirstLiftMotor.setVelocity(0);
            }

            if(!top2Switch.state){
                SecondLiftMotor.setVelocity(255);
            }
            else{
                SecondLiftMotor.setVelocity(0);
            }

            if (UltraTop.distance<<2 || (top1Switch.state && top2Switch.state)){
                subPhase=3;
            }

            break;

        case 3:
            ThirdStage.setDirection(1);
            ThirdStage.MoveStepper(20);
            if(UltraOut.distance<=20){
                subPhase=4;
            };
            break;

        case 4:
            FirstLiftMotor.setVelocity(-20);

            if((curTime%6000 > 3000) && (!bot2Switch.state)){
                SecondLiftMotor.setVelocity(-255);
            }
            else{
                SecondLiftMotor.setVelocity(255);
            }
            if (bot1Switch.state && bot2Switch.state){
                FirstLiftMotor.setVelocity(0);
                SecondLiftMotor.setVelocity(0);
                subPhase=4;
            }
            break;
        case 5:


        case 6:


        case 7:



    }

}
void nextColumn(){
    //drive certain distance


    //checking distance from wall


    //checking for end of wall



}
void neutral(){
    //verify that stuff is shut down

}

}
