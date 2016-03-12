#include <Omnidireccional.h>
#include <VNH5019.h>

Omnidireccional robot = Omnidireccional();

void setup()
{
  
  robot.setM1puente1(6,7,8,9);
  robot.setM2puente1(2,17,16,15);
  robot.setM2puente2(3,14,4,5);
  robot.setM1puente2(10,11,12,13);
  
  robot.encenderPuente1();
  robot.encenderPuente2();

}

void loop()
{

  robot.adelante();
  delay(1000);
  robot.atras();
  delay(1000);
  robot.izquierda();
  delay(1000);
  robot.derecha();
  delay(1000);
  robot.eSDer();
  delay(1000);
  robot.eSIzq();
  delay(1000);
  robot.eIIzq();
  delay(1000);
  robot.eIDer();
  delay(1000);
  robot.alto();
  delay(1000);

}
