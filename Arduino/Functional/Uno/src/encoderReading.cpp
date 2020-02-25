#include <Arduino.h>

int EncAPin = 1;
int EncBPin = 2;

bool EncB = false;

long position = 0;

void aChange();

void setup() {
    Serial.begin(9600);

    //create interrupts
    attachInterrupt(digitalPinToInterrupt(EncAPin), aChange, CHANGE);
    //attachInterrupt(digitalPinToInterrupt(EncAPin), aHIGH, RISING);
    //attachInterrupt(digitalPinToInterrupt(EncBPin), bLow, FALLING);
    //attachInterrupt(digitalPinToInterrupt(EncBPin), bHigh, RISING);
}

void loop() {
  Serial.println(position);
}

void aChange(){
    if (digitalRead(EncBPin)==digitalRead(EncAPin)){
        position++;
    }
    else{
        position--;
    }
}
