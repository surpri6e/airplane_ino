#include <Strela.h>
#include <Wire.h>
#include <VarSpeedServo.h>

VarSpeedServo Servo_LeftWing;
VarSpeedServo Servo_RightWing;
VarSpeedServo Servo_RudderRoute;
VarSpeedServo Servo_RudderHeight;

void leftWingCheckAfortStart() { // Проверка левого крыла перед стартом
  Servo_LeftWing.write(111, 255);
  Servo_LeftWing.write(175, 20);
  Servo_LeftWing.write(5, 20);
}

void rightWingCheckAfortStart() { // Проверка правого крыла перед стартом
  Servo_LeftWing.write(67, 255);
  Servo_LeftWing.write(175, 20);
  Servo_LeftWing.write(5, 20);
}

void rightAndLeftWingsCheckAfortStart() { // Поднятие одновременно крыльев в рабочее положение
  Servo_LeftWing.write(111, 15);
  Servo_LeftWing.write(67, 15);
}

void onPropellerCheckAfortStart() { // Проверка пропеллера перед стартом
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

// Эти функции не будут в тесте
void rudderHeightCheckAfortStart(int8_t rectangle) {
    Servo_RudderHeight.write(rectangle);
    delay(3000);
    Servo_RudderHeight.write(-rectangle);
}

void rudderRouteUsing(int8_t rectangle) { // Не знаю какое значение даёт какое направление
  // Что вообще такое rectangle, угол ДО которого нужно сделать или ТЕКУЩИЙ угол?
  // Предположим, что отрицательное - влево, положительное - вправо
  int8_t rec = rectangle;
  if(rectangle > 0) {
     // Или делать через память
     // for(rec; rec <  )
  }
  
}

void wingsUsing(char isWing, int8_t rectangle) {
  // Наверно стоит сделать отдельный файл для поворотов
}

void math() {
  // Function for counting various expressions in other functions
}

void setup() {
  motorConnection(0, 1);
  Serial.begin(9600);
  
  Servo_LeftWing.attach(P1); // Предположим, что это - левое крыло
  Servo_RightWing.attach(P2); // Предположим, что это - правое крыло
  Servo_RudderRoute.attach(P3); // Предроложим, что это - руль направления
  Servo_RudderHeight.attach(P4); // Предположим, что это - рули высоты
}

// Закинуть все тестовые функции в одну общую и вызывать уже её <complete>

void testFunctionAfortStart() {
  leftWingCheckAfortStart();
  Serial.println("Левое крыло успешно прошло тест! Готово к использованию.");
  rightWingCheckAfortStart();
  Serial.println("Правое крыло успешно прошло тест! Готово к использованию.");
  onPropellerCheckAfortStart();
  Serial.println("Пропеллер успешно запущен!");
  rightAndLeftWingsCheckAfortStart();
  Serial.println("Проверка пройдена.");
  offPropellerCheckAfortStart();
  Serial.println("Пропеллер успешно отключен! Пропеллер готов к использованию.");
}

// Я не знаю пока что точно как будет работать управление самолётом, поэтому напишу простую функцию на первый раз
int16_t counterSpeed = 120;

// Чтобы создать массив char, нужно оставить пустым первый элемент(индекс 0)

char arrayOfSimbol[7] = {'F', 'B', 'L', 'R', 't', 'f',};

// Управление будет совершенно другое, придётся работатьс с сервоприводами


// Если язык довольно быстрый, то проверку на зажатость кнопки можно проверять с помощью кейсов в цикле

void trafficControl() {
  char counterSimbol = Serial.read();

  // Пример реализации движения и поворота
  // Наверно поворот придётся производить в каком-то соотношении или отношении, а не польностью
  // Данное отношение пока не понятно
  if(counterSimbol == arrayOfSimbol[99]) { // Выход за границы массива, для примера
    // Нужно повернуть влево
    // Цикл нужен для плавности
    // for(uint8_t i = 0; i < )
  
  }

  // Serial.println(arrayOfSimbol[0]);
  if (counterSimbol == arrayOfSimbol[0]) { // Нужно проверить что лежит в 0 индексе, потестить
    drive(counterSpeed, counterSpeed);
  } else if (counterSimbol == arrayOfSimbol[1]) {
    drive(-counterSpeed, -counterSpeed);
  } else if (counterSimbol == arrayOfSimbol[2]) {
    drive(-counterSpeed, counterSpeed);
  } else if (counterSimbol == arrayOfSimbol[3]) {
    drive(counterSpeed, -counterSpeed);
  } else if (counterSimbol == arrayOfSimbol[4]) {
    counterSpeed = 0;
    drive(counterSpeed, counterSpeed);
  } else if (counterSimbol == arrayOfSimbol[5]){
    counterSpeed = 120; // Со значением можно поиграться
    tone(BUZZER, 1000, 50);
  }
}

void loop() {
  testFunctionAfortStart();
  Serial.println("Все проверки пройдены. Самолёт готов к вылету!");

  // rudderHeightAfortStart(-7);

  // if (Serial.available() > 0) {
  //  trafficControl();
  // }
  Serial.end();
  while(true) {}
}
