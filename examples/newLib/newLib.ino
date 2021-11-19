// Необходимо скачать самую верхнюю библиотеку на компьютер

#include <VarSpeedServo.h>
#include <Strela.h>
#include <Wire.h>

VarSpeedServo ServoL;
VarSpeedServo ServoR;

void setup() {
  ServoL.attach(P1);
  ServoR.attach(P2); 
  ServoL.write(111, 30);
  ServoR.write(67, 30);
}


void loop() {}
