#include <Strela.h>
#include <Servo.h>
#include <Wire.h>

Servo wingLeft;
Servo wingRight;

void setup() {
  wingLeft.attach(P1);
  wingRight.attach(P2);
}

void loop() {
  uint8_t tmp = 160;
  wingLeft.write(111);
  wingRight.write(66);
  delay(1000);
  
  for(uint8_t i = 20; i <= 135; i += 5) {
    wingLeft.write(i);
    wingRight.write(tmp);
    tmp -= 5;
    delay(80);
  }
  delay(1000);
  
  for(uint8_t i = 135; i >= 20; i -= 5) {
    wingLeft.write(i);
    wingRight.write(tmp);
    tmp += 5;
    delay(80);   
  }
  tmp = 135;
  for(uint8_t i = 20; i <= 111; i += 2) {
    wingLeft.write(i);
    wingRight.write(tmp);
    if(tmp >= 68) {
      tmp -= 2;
    }
    delay(20);
  }
  // Частота 100 - самая лучшая
  tone(BUZZER, 100, 1000);
  delay(2000);
  
  /*
  for(uint8_t i = 20; i <= 135; i++) {
    wingLeft.write(i);
    wingRight.write(i);
    delay(30);
  }
  */
  

  while(true) {}
}

