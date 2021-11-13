
#include <Strela.h>
#include <Wire.h> 
#include <Ultrasonic.h>
int speed = 100;
int var = 0; // Номер случая
int noml = 7; // Номер ангара слева
int nomr = 3; // Номер ангара справа
int schetl = 0; // Подсчёт примыканий слева
int schetr = 1; // Подсчёт примыканий справа
int S = 1; // Флаг движения вперёд-назад

Ultrasonic ultrasonic(P6, P7);

void Forward() 
{
    speed = 65 * S;
    drive (speed, speed);
}

void Right()
{
    speed = 70 * S;
    drive (speed, -speed);
}

void Left() 
{
    speed = 70 * S;
    drive (-speed, speed);
}

void Perl() 
{
    speed = 70;
    drive (speed, -speed);
    delay (250);
    schetl++;
}

void Perr() 
{
    speed = 70;
    drive (-speed, speed);
    delay (250);
    schetr++;
}
void Stop()
{
    speed = 0;
    drive (speed, speed);
    delay (3000);
    S = -1;
    speed = 70;
    drive (speed * S, speed * S);
    delay (300);
    //var = 0;
}

void setup() 

{
  Serial1.begin(9600);
  motorConnection(0, 0);
  uPinMode(P1, INPUT);   // Пин P1 настроим  на ввод данных
  uPinMode(P2, INPUT);   // Пин P2 настроим  на ввод данных
  uPinMode(P3, INPUT);   // Пин P3 настроим  на ввод данных
  uPinMode(P4, INPUT);   // Пин P4 настроим  на ввод данных
  uPinMode(P5, INPUT);   // Пин P5 настроим  на ввод данных
  Forward(); // Сразу едем вперёд
} 

void loop() 
{ 
    float D = ultrasonic.Ranging(CM); //измеряем расстояние
    boolean L = !uDigitalRead(P2);
    boolean C = !uDigitalRead(P3);    //читаем значение центрального датчика
    boolean R = !uDigitalRead(P1);
    boolean RL = !uDigitalRead(P4);
    boolean RR = !uDigitalRead(P5);
    
    
    
    
    if (L == R) {var = 0;}
    else if (L == HIGH && RL == LOW) {var = 1;}
    else if (R == HIGH && RR == LOW) {var = 2;}
    else if (RR == HIGH && (schetr == 1 || schetr == nomr || schetr == 4)) {var = 3;}
    else if (RL == HIGH && (schetl == noml || schetl == 4 || schetl == 5)) {var = 4;}
    else if (L == C == R) {S = 1; var = 3;}
    if (D > 15 && D < 20) {var = 5;}                       
    
    switch (var) {
        case 0:
             Forward();
             break;
        case 1:
             Left();
             break;
        case 2:
             Right();
             break;
        case 3:
             Perr();
             break;
        case 4:
             Perl();
             break;
        case 5:
             Stop();
             break;
        
        //case STATE_PERR:
        //    steerPerr();
        //    break;
        
        //case STATE_STOP:
        //    runStop();
        //    break;
    
    //int targetState;  // В какое состояние нужно перейти?

    //if (schet == nom) {
      // нужный въезд (у нас 5-й)
    //  targetState = STATE_PERL;
    //}
    
          
     
    
   // else if (L == HIGH && RL == LOW) {
   //     targetState = STATE_LEFT;
   // } 
   // else if (R == HIGH && RR == LOW) {
   //     targetState = STATE_RIGHT;
   // }
   // if (RL == HIGH) {
   //     schetl++;
   //    targetState = STATE_FORWARD;
   // } 
   // else if (RR == HIGH) {
   //     schetr++;
   //    targetState = STATE_FORWARD;
   // } 
    //else if ((RL == HIGH) && (C == HIGH) && (schetl == noml || schetl == 3 || schetl == 4)) {
    //  targetState = STATE_PERL;
    //}
    //else if ((RR == HIGH) && (C == HIGH) && (schetr == 0 || schetr == nomr || schetr == 3)) {
    //  targetState = STATE_PERR;
    //}
    //if (D > 10 && D < 12) {
      // въезд в ангар
    //  S = -1;
    //  targetState = STATE_STOP;}
    //if (L == HIGH && C == HIGH && R == HIGH) {
    //   S = 1;
    //   targetState = STATE_PERR;
    //}
    //if (state == targetState) {
        // мы уже делаём всё что нужно,
        // делаем измерения заново
    
    }

    

        //case STATE_BACKWARD:
        //    runForward();
        //    break;

        //case STATE_LEVPRAV:
        //    runLevprav();
        //    break;
    return;
    }

    // не позволяем сильно вилять на прямой
    //delay(50);
//}
