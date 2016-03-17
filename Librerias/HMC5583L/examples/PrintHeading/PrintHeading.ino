#include <Wire.h>
#include <HMC5583L.h>
HMC5583L compass=HMC5583L(HMC5583L_DEFAULT_ADDRESS);
void setup() {
  Serial.begin(9600);
  Wire.begin();
  compass.initialize();
  compass.setStartingAngle();
}

void loop() {
  float currentAngle=compass.getAngle();
  Serial.println(currentAngle);
}
