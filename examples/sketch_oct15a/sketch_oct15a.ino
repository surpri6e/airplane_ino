#include <Strela.h>

#include <Wire.h> 
int speed = 0; 
void setup()
{
  Serial1.begin(9600);  
  motorConnection(1, 1);  
}
void loop()  //выполняется циклически
{
  if (Serial1.available() > 0) //Если пришли данные от Bluetooth
  {
    robot();                  //управляем роботом
  }
}
void robot()  //функция управления роботом
{
  char simvol = Serial1.read();  //Читаем символ от Bluetooth
  if (simvol == 'F')         //Если пришло F едем вперед
    drive(speed, speed);   
  else if (simvol == 'B')    //или если пришло B едем назад
    drive(-speed, -speed); 
  else if (simvol == 'L')    //или если пришло L поворот налево
    drive(-speed, speed);
  else if (simvol == 'R')    //или если пришло R поворот направо
    drive(speed, -speed);
  else if (simvol == '0')     //стоп
  {
    speed = 0;
    drive(speed, speed);  
  }
  else if (simvol == '1')     //едем
    speed = 120;
}

