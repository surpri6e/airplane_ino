#include <Wire.h>
#include <Strela.h>
#include <vector>

void setup() {

}

void loop() {
  for(uint8_t i = S1; i <= S4; i++) {
    uDigitalWrite(L1 + (i - S1), uDigitalRead(i));
  }
}
