#include <Wire.h>
#include <Omnidireccional.h>
#include <VNH5019.h>
#include <HMC5583L.h>

Omnidireccional robot = Omnidireccional();
HMC5583L mag = HMC5583L(HMC5583L_DEFAULT_ADDRESS);

float c_inicio, c_actual, brujula;

void setup()
{

  Serial.begin(9600);
  Wire.begin();
  robot.setM1puente1(10,11,12,13);
  robot.setM2puente1(6,7,8,9);
  robot.setM1puente2(3,14,4,5);
  robot.setM2puente2(2,17,16,15);
  mag.initialize();

  robot.encenderPuente1();
  robot.encenderPuente2();

  c_inicio = mag.getAngle();

}

void loop()
{

  c_actual = mag.getAngle();
  brujula = arreglarCompas();

  //Serial.println(brujula);
  if (brujula >= 30 &&  brujula <= 335)
  {
    if (brujula >= 183)
    {
    
      robot.alto();
      
      do
      {
      
        robot.alinearDer(25);
      
      }while(brujula > 350);
    
    }

    else
    {
    
      robot.alto();
      
      do
      {
      
        robot.alinearIzq(25);
      
      }while(brujula < 10);
    
    }    
  
  }

  else
    robot.alto();

}

float arreglarCompas()
{

  float b;

  b = c_actual - c_inicio;

  if(b < 0)
  {

    b += 360;
    
  }

  return b;
  
}

