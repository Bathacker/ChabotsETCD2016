#include <Omnidireccional.h>
#include <VNH5019.h>

Omnidireccional robot = Omnidireccional();

void setup()
{

  robot.setM1puente1(10,11,12,13);
  robot.setM2puente1(6,7,8,9);
  robot.setM1puente2(3,14,4,5);
  robot.setM2puente2(2,17,16,15);

  robot.encenderPuente1();
  robot.encenderPuente2();

}

void loop()
{

  robot.Motor1adel(255);
  delay(500);
  robot.Motor2adel(255);
  delay(500);
  robot.Motor3adel(255);
  delay(500);
  robot.Motor4adel(255);
  //robot.adelante();
  /*delay(1000);
  robot.alto();
  delay(300);
  robot.atras();
  delay(1000);
  robot.alto();
  delay(300);
  robot.derecha();
  delay(1000);
  robot.alto();
  delay(300);
  robot.izquierda();
  delay(1000);
  robot.alto();
  delay(300);
  robot.eSDer();
  delay(1000);
  robot.alto();
  delay(300);
  robot.eSIzq();
  delay(1000);
  robot.alto();
  delay(300);
  robot.eIDer();
  delay(1000);
  robot.alto();
  delay(300);
  robot.eIIzq();
  delay(1000);
  robot.alto();
  delay(300);*/

}

