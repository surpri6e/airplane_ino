#include <Strela.h>
#include <Wire.h>
#include <VarSpeedServo.h>

// Ошибка библиотеки и таймеры, дело не в коде

// Чтобы создать массив char, нужно оставить пустым первый элемент(индекс 0)
// arrayOfSimbol[0]?
char arrayOfSimbol[7] = {'F', 'B', 'L', 'R', 't', 'f',};
int16_t currentSpeed = 100;

VarSpeedServo Servo_LeftWing;
VarSpeedServo Servo_RightWing;
VarSpeedServo Servo_RudderRoute;
VarSpeedServo Servo_RudderHeight;

// Для начала реализовать похожую функцию в основном файле
void rudderRouteUsing(int16_t rec) {
}

void wingsUsing(char isWing, int16_t rec) {
}

// Наверно повороты будут реализовываться в каком-то соотношении, функция вычисляет это
void mathCounting() {
}

void trafficControl() {
  char currentSimbol = Serial.read();

  if (currentSimbol == arrayOfSimbol[0]) { 
    drive(currentSpeed, currentSpeed);
  } else if (currentSimbol == arrayOfSimbol[1]) {
    drive(-currentSpeed, -currentSpeed);
  } else if (currentSimbol == arrayOfSimbol[2]) {
    drive(-currentSpeed, currentSpeed);
  } else if (currentSimbol == arrayOfSimbol[3]) {
    drive(currentSpeed, -currentSpeed);
  } else if (currentSimbol == arrayOfSimbol[4]) {
    currentSpeed = 0;
    drive(currentSpeed, currentSpeed);
  } else if (currentSimbol == arrayOfSimbol[5]){
    currentSpeed = 100;
  }
}

void setup() {
  motorConnection(0, 1);
  Serial.begin(9600);
  
  Servo_LeftWing.attach(P1); // Предположим, что это - левое крыло
  Servo_RightWing.attach(P2); // Предположим, что это - правое крыло
  Servo_RudderRoute.attach(P3); // Предроложим, что это - руль направления
  Servo_RudderHeight.attach(P4); // Предположим, что это - рули высоты
}
void loop() {
  if (Serial.available() > 0) {
    trafficControl();
  }
}
