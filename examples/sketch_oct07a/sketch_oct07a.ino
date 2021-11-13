#include <Strela.h>

#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

int Speed = 0;

void setup()
{ 
    Speed=255;
}
void loop(){
    
    for(int i=0;i<4;i++)
    {
     drive(Speed, Speed);
     delay(2000);
     drive (Speed,-Speed);
     delay(350);
    }
    Speed = 0;
    //;0delay(10000);    
}

