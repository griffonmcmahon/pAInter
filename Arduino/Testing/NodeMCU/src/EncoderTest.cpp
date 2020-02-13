#include <Arduino.h>

int EncAPin = 2;
int EncBPin = 3;

bool EncA = false;
bool EncB = false;

long position = 0;

void aLow();

void setup() {
    Serial.begin(9600);
    //create interrupts
    attachInterrupt(digitalPinToInterrupt(EncAPin), aLow, FALLING);
    //attachInterrupt(digitalPinToInterrupt(EncAPin), aHIGH, RISING);
    //attachInterrupt(digitalPinToInterrupt(EncBPin), bLow, FALLING);
    //attachInterrupt(digitalPinToInterrupt(EncBPin), bHigh, RISING);
}

void loop() {
  Serial.println(position);
}

void aLow(){
    EncB = digitalRead(EncBPin);
    if (EncB){
        position--;
    }
    else{
        position++;
    }
}
