#include <Strela.h>
#include <Wire.h>
#include <VarSpeedServo.h>

// Выдаёт ошибку библиотке и таймера, дело не в коде.

VarSpeedServo Servo_LeftWing;
VarSpeedServo Servo_RightWing;
VarSpeedServo Servo_RudderRoute;
VarSpeedServo Servo_RudderHeight;

void leftWingCheckAfortStart() { // Проверка левого крыла перед стартом
  Servo_LeftWing.write(111, 255); // Начальное положение
  Servo_LeftWing.write(175, 20);
  Servo_LeftWing.write(5, 20);
}

void rightWingCheckAfortStart() { // Проверка правого крыла перед стартом
  Servo_LeftWing.write(67, 255); // Начальное положение
  Servo_LeftWing.write(175, 20);
  Servo_LeftWing.write(5, 20);
}

void rightAndLeftWingsCheckAfortStart() { // Поднятие одновременно крыльев в рабочее положение
  Servo_LeftWing.write(111, 15);
  Servo_LeftWing.write(67, 15);
}

void rudderHeightCheckAfortStart() {
  // Найти крайнее положение
  Servo_RudderHeight.write();
}

void rudderRouteCheckAfortStart() {
  // Найти крайнее положение и понять как работать с этим сервоприводом
}

void onPropellerCheckAfortStart() { // Проверка пропеллера перед стартом
  for(uint8_t i = L1; i <= L4; i++) {
    uDigitalWrite(i, HIGH);
    delay(100);
  }
  for(uint8_t i = 5; i <= 255; i += 5) {
    drive(i, i);
    delay(80);
  }
  for(uint8_t i = L4; i >= L1; i--) {
    uDigitalWrite(i, LOW);
    delay(100);
  }
}

void offPropellerCheckAfortStart() {
  for(uint8_t i = 250; i >= 0; i--) {
    for(uint8_t j = L1; j <= L4; j++) {
      uDigitalWrite(j, HIGH);
    }
    delay(30);
    
    drive(i, i);
    
    for(uint8_t j = L1; j <= L4; j++) {
      uDigitalWrite(j, LOW);
    }
    delay(30);
  }
  tone(BUZZER, 1000, 50);
}

void testFunctionAfortStart() {
  leftWingCheckAfortStart();
  rightWingCheckAfortStart();
  rightAndLeftWingsCheckAfortStart();
  // rudderHeightCheckAfortStart();
  // rudderRouteCheckAfortStart();
  // onPropellerCheckAfortStart();
  // offPropellerCheckAfortStart();
}

void setup() {
  motorConnection(0, 1);
  Servo_LeftWing.attach(P1); // Предположим, что это - левое крыло
  Servo_RightWing.attach(P2); // Предположим, что это - правое крыло
  Servo_RudderRoute.attach(P3); // Предроложим, что это - руль направления
  Servo_RudderHeight.attach(P4); // Предположим, что это - рули высоты
}
void loop() {
  testFunctionAfortStart();
  tone(BUZZER, 1000, 50);
  while(true) {}
}
