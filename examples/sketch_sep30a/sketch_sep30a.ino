#include <Strela.h>
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

int Speed = 175;

void setup(){
    pinMode(9,OUTPUT);
    analogWrite(9,0);
    pinMode(10,OUTPUT);
    analogWrite(10,0);22
    
    
}
void loop(){
    
    drive(Speed, Speed/4); 
    delay(10000);
    Speed = 0;
}


