#include <Arduino.h>
#include <Motor.hpp>
#include <updateFunctions.hpp>
//#include <Ultrasonic.h>


Motor FirstLiftMotor(2,8,3,5,6,1000);
//Motor SecondLiftMotor(7,8,9,10,11,250);

Motor LiftMotors[] = {FirstLiftMotor};

void setup() {
  Serial.begin(9600);
}

void loop() {
  LiftMotors[0].setVelocity(0);
  updateMotors(LiftMotors);
  delay(1000);
  LiftMotors[0].setVelocity(100);
  updateMotors(LiftMotors);
  delay(2000);
  LiftMotors[0].setVelocity(0);
  updateMotors(LiftMotors);
  delay(1000);
  LiftMotors[0].setVelocity(-255);
  updateMotors(LiftMotors);
  delay(2000);
}
