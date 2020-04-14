#include <Arduino.h>
#include <LiftMotor.hpp>
#include <Stepper.hpp>
#include <updateFunctions.hpp>
#include <initializeFunctions.hpp>
#include <Ultrasonic.hpp>
#include <Switch.hpp>

LiftMotor FirstLiftMotor();
LiftMotor SecondLiftMotor();
LiftMotor LiftMotors[] = {FirstLiftMotor, SecondLiftMotor};

void LiftMotors0EncUp();
void LiftMotors1EncUp();

DriveMotor LeftDriveMotor();
DriveMotor RightDriveMotor();
DriveMotor MidDriveMotor();
DriveMotor DriveMotors[] = {LeftDriveMotor, RightDriveMotor, MidDriveMotor};

void DriveMotors0EncUp();
void DriveMotors1EncUp();
void DriveMotors2EncUp();

Stepper ThirdStage();

Ultrasonic UltraTop();
Ultrasonic UltraOut();
Ultrasonic UltraSL();
Ultrasonic UltraWL();
Ultrasonic UltraWR();
Ultrasonic UltraSR();
Ultrasonic Ultrasonics[] = {UltraTop, UltraOut, UltraSL, UltraWL, UltraWR, UltraSR};


Switch bot1Switch();
Switch top1Switch();
Switch bot2Switch();
Switch top2Switch();
Switch Switches[] = {bot1Switch, top1Switch, bot2Switch, top2Switch};

void setup() {
  Serial.begin(9600);
  initializeLiftMotors(LiftMotors);
  initialiseDriveMotors(DriveMotors);
  initializeStepper(ThirdStage);
  initializeUltrasonics(Ultrasonics);
  attachInterrupt(digitalPinToInterrupt(LiftMotors[0].encAPin),LiftMotors0EncUp, FALLING);
  attachInterrupt(digitalPinToInterrupt(LiftMotors[1].encAPin),LiftMotors1EncUp, FALLING);
  attachInterrupt(digitalPinToInterrupt(DriveMotors[0].encAPin),DriveMotors0EncUp, FALLING);
  attachInterrupt(digitalPinToInterrupt(DriveMotors[1].encAPin),DriveMotors1EncUp, FALLING);
  attachInterrupt(digitalPinToInterrupt(DriveMotors[2].encAPin),DriveMotors2EncUp, FALLING);

}

void loop() {
    //update loop
    updateLiftMotors(LiftMotors);
    updateDriveMotors(DriveMotors);
    updateUltrasonics(Ultrasonics);
    //update switches



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
