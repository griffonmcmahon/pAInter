#include <Arduino.h>
#include <Motor.hpp>
#include <Stepper.hpp>
#include <Joystick.hpp>
#include <updateFunctions.hpp>
#include <initializeFunctions.hpp>
#include <Ultrasonic.hpp>

Stepper ThirdStage(8,7);
Motor FirstLiftMotor();
Motor SecondLiftMotor();
Motor LiftMotors[] = {FirstLiftMotor, SecondLiftMotor};

void LiftMotors0aUp();



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
