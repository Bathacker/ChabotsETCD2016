#include <Wire.h>
#include <HMC5583L.h>
#include <HTInfraredSeeker.h>
HTInfraredSeeker seeker = HTInfraredSeeker();
InfraredInput seekerInput;
HMC5583L compass=HMC5583L(HMC5583L_DEFAULT_ADDRESS);
void setup() {
  Serial.begin(9600);
  Wire.begin();
  compass.initialize();
  compass.setStartingAngle();
  seeker.init();
}

void loop() {
  seekerInput=seeker.readSensorValues();
  float currentAngle=compass.getAngle();
  Serial.println((String)currentAngle+" "+(String)seekerInput.direction);
}
