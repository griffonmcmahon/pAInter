#include <Arduino.h>
#include <Motor.hpp>
#include <Stepper.hpp>
#include <updateFunctions.hpp>

//#include <Ultrasonic.h>


Motor FirstLiftMotor(1,2,3,5,6);
Motor SecondLiftMotor(7,8,9,10,11);
Motor LiftMotors[] = {FirstLiftMotor, SecondLiftMotor};

Stepper ThirdStage(8,4);

//for joystick demo
int VRx = A0;
int VRy = A1;
int switchPin = 2;

int x = 0;
int y = 0;
int sw = 0;

void setup() {
  Serial.begin(9600);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
}

void loop() {
  x = analogRead(VRx)/2.05-255;
  delay(25);
  y = analogRead(VRy)/2.05-255;
  Serial.println(x);
  sw=digitalRead(switchPin);
  ThirdStage.MoveStepper(10);
  LiftMotors[1].setVelocity(0);
  LiftMotors[0].setVelocity(0);
  /*
  if(abs(x)>20){
    LiftMotors[0].setVelocity(x);
  }
  else{
    LiftMotors[0].setVelocity(0);
  }
  if (abs(y)>20){
    LiftMotors[1].setVelocity(y);
  }
  else{
    LiftMotors[1].setVelocity(0);
  }
  */
  updateMotors(LiftMotors);
}
