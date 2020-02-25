//This library is for functions to control lift motors

class LiftMotor{
    char name [];
    char encAPin, encBPin, enPin, in1Pin, in2Pin;
    int encPerInch;
} LMotor;

void FirstDistance(int distance, int& position, double speed);
void SecondDistance(int distance, int& position, double speed);
