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
  pinMode(8,OUTPUT);
  pinMode(4,OUTPUT);
}

void loop() {
  delay(5000);
  ThirdStage.MoveStepper(4000);
  delay(1000);

  updateMotors(LiftMotors);
}
