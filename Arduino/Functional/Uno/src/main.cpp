#include <Arduino.h>
#include <Motor.hpp>
#include <Stepper.hpp>
#include <Joystick.hpp>
#include <updateFunctions.hpp>
#include <initializeFunctions.hpp>

//#include <Ultrasonic.h>

//Motor FirstLiftMotor(7,9,10,11,12);
Motor SecondLiftMotor(3,8,5,4,6);
Motor LiftMotors[] = {SecondLiftMotor};
Joystick Joystick(A0,A1,2);

void LiftMotors0aUp();

//Stepper ThirdStage(8,4);

void setup() {
  Serial.begin(9600);
  initializeMotors(LiftMotors);

  attachInterrupt(digitalPinToInterrupt(LiftMotors[0].encAPin),LiftMotors0aUp, FALLING);

}

void loop() {

  Serial.println(LiftMotors[0].position);
  delay(100);

  if(Joystick.xHigh){
    LiftMotors[0].setVelocity(250);
  }
  else if(Joystick.xLow){
    LiftMotors[0].setVelocity(-250);
  }
  else{
    LiftMotors[0].setVelocity(0);
  }

  updateMotors(LiftMotors);
  Joystick.updateJoystick();

}

void LiftMotors0aUp(){
  LiftMotors[0].aUp();
}
