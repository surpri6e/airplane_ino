#include <Wire.h>
#include <Strela.h>


void setup() {
  Serial.begin(9600);

}

void loop() {
  Serial.print(typeid(S1).name(), S1);
  for(uint8_t i = S1 + 1; i <= S4; i++) {
    uDigitalWrite(L1 + (i - S1), uDigitalRead(i));
  }
}
