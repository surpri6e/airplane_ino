#include <Strela.h>

#include <Strela.h>
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

int Speed = 255;

void setup(){
    pinMode(9,OUTPUT);
    analogWrite(9,0);
    pinMode(10,OUTPUT);
    analogWrite(10,0);
    
    
}void loop(){
    
    for(int i=0;i<4;i++)
    {
      drive(Speed, Speed);
     delay(600);
     drive (-Speed,Speed);
     delay(450);

    }
    Speed = 0;
    //;0delay(10000);    
}


