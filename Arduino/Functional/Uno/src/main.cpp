#include <Arduino.h>
#include <Motor.h>
#include <updateFunctions.h>
//#include <Ultrasonic.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  MotorArray[0].setVelocity(1);
  updateMotors();
  delay(1);
  MotorArray[0].setVelocity(.5);
  updateMotors();
  delay(1);
  MotorArray[0].setVelocity(0);
  updateMotors();
  delay(1);
  MotorArray[0].setVelocity(-.5);
  updateMotors();
  delay(1);
  MotorArray[0].setVelocity(-1);
  updateMotors();
  delay(1);
  MotorArray[0].setVelocity(0);
  updateMotors();
  delay(1);
}
