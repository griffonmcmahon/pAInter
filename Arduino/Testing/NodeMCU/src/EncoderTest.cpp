#include <Arduino.h>

int EncAPin = D1;
int EncBPin = D2;

bool EncB = false;

long position = 0;

void ICACHE_RAM_ATTR aLow();
//void bLow();
//void bHigh();

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
    if (digitalRead(EncBPin)){
        position++;
    }
    else{
        position--;
    }
}
/*
void bLow(){
    Serial.println("LOW");
    EncB=false;
}
void bHigh(){
    Serial.println("HIGH");
    EncB=true;
}
*/
