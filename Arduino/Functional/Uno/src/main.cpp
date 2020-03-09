#include <Arduino.h>
#include <Motor.hpp>
#include <Stepper.hpp>
#include <Joystick.hpp>
#include <updateFunctions.hpp>
#include <initializeFunctions.hpp>
#include <Ultrasonic.hpp>

//Motor FirstLiftMotor(7,9,10,11,12);
Motor SecondLiftMotor(3,2,5,4,6);
Motor LiftMotors[] = {SecondLiftMotor};
Joystick Joystick(A0,A1,2);

void LiftMotors0aUp();

Stepper ThirdStage(8,7);

Ultrasonic UltraTop(12,12);

Ultrasonic Ultrasonics[] = {UltraTop};

void setup() {
  Serial.begin(9600);
  initializeMotors(LiftMotors);
  initializeStepper(ThirdStage);
  initializeUltrasonics(Ultrasonics);
  attachInterrupt(digitalPinToInterrupt(LiftMotors[0].encAPin),LiftMotors0aUp, FALLING);

}

void loop() {

  Ultrasonics[0].findDistance();
  Serial.println(Ultrasonics[0].distance);

  if(Joystick.xHigh){
    Serial.println("Up");
    ThirdStage.setDirection(0);
    ThirdStage.MoveStepper(20);
  }
  else if(Joystick.xLow){
    Serial.println("Down");
    ThirdStage.setDirection(1);
    ThirdStage.MoveStepper(20);
  }
  else{

  }

  updateMotors(LiftMotors);
  Joystick.updateJoystick();

}

void LiftMotors0aUp(){
  LiftMotors[0].aUp();
}
