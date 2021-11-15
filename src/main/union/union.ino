#include <Strela.h>
#include <Wire.h>
#include <Servo.h>

Servo Servo_LeftWing;
Servo Servo_RightWing;
Servo Servo_RudderRoute;
Servo Servo_RudderHeight;

void leftWingCheckAfortStart() { // Проверка левого крыла перед стартом
  for(uint8_t i = 0; i <= 90; i++) {
    Servo_LeftWing.write(i);
  }
  delay(1000);
  for(uint8_t i = 90; i <= 180; i++) {
    Servo_LeftWing.write(i);
  }
  delay(1000);
  for(uint8_t i = 180; i >= 0; i--) {
    Servo_LeftWing.write(i);
  }
}

void rightWingCheckAfortStart() { // Проврека правого крыла перед стартом
  for(uint8_t i = 0; i <= 90; i++) {
    Servo_RightWing.write(i);
  }
  delay(1000);
  for(uint8_t i = 90; i <= 180; i++) {
    Servo_RightWing.write(i);
  }
  delay(1000);
  for(uint8_t i = 180; i >= 0; i--) {
    Servo_RightWing.write(i);
  }
}

void unionRightAndLeftWingsCheckAfortStart() { // Поднятие одновременно крыльев в рабочее положение
  for(uint8_t i = 0; i <= 90; i++) {
    Servo_LeftWing.write(i);
    Servo_RightWing.write(i);
  }
}

void onPropellerCheckAfortStart() { // Прверка пропеллера перед стартом
  for(uint8_t i = L1; i <= L4; i++) {
    uDigitalWrite(i, HIGH);
    delay(100);
  }
  for(uint8_t i = 0; i <= 255; i += 5) {
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

// Нужно реализовать вращение руля направления и руля высоты для примеры, я не знаю как они работает в самолёте.

void setup() {
  motorConnection(0, 1);
  Serial.begin(9600);
  
  Servo_LeftWing.attach(P1); // Предположим, что это - левое крыло
  Servo_RightWing.attach(P2); // Предположим, что это - правое крыло
  Servo_RudderRoute.attach(P3); // Предроложим, что это - руль направления
  Servo_RudderHeight.attach(P4); // Предположим, что это - рули высоты
}

// Закинуть все тестовые функции в одну общую и вызывать уже её

void loop() {

  leftWingCheckAfortStart();
  Serial.println("Левое крыло успешно прошло тест! Готово к использованию.");
  rightWingCheckAfortStart();
  Serial.println("Правое крыло успешно прошло тест! Готово к использованию.");
  onPropellerCheckAfortStart();
  Serial.println("Пропеллер успешно запущен!");
  unionRightAndLeftWingsCheckAfortStart();
  Serial.println("Проверка пройдена.");
  offPropellerCheckAfortStart();
  Serial.println("Пропеллер успешно отключен! Пропеллер готов к использованию.");

  Serial.println("Все проверки пройдены. Самолёт готов к вылету!");
  Serial.end();
  while(true) {}
}
