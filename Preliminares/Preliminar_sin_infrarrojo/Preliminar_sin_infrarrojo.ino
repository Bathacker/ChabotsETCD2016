#include <Adafruit_HMC5883_U.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Omnidireccional.h>
#include <VNH5019.h>

Omnidireccional robot = Omnidireccional();
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);

int c_actual, c_inicio, brujula;
int LDR1_1, LDR1_2, LDR1_3, LDRValue1_1, LDRValue1_2, LDRValue1_3;
int LDR2_1, LDR2_2, LDR2_3, LDRValue2_1, LDRValue2_2, LDRValue2_3;
int LDR3_1, LDR3_2, LDR3_3, LDRValue3_1, LDRValue3_2, LDRValue3_3;
int LDR4_1, LDR4_2, LDR4_3, LDRValue4_1, LDRValue4_2, LDRValue4_3;
int LDRValue1, LDRValue2, LDRValue3;

void setup()
{
  
  Serial.begin(9600);
  Wire.begin();
  
  robot.setM1puente1(6,7,8,9);
  robot.setM2puente1(2,17,16,15);
  robot.setM2puente2(3,14,4,5);
  robot.setM1puente2(10,11,12,13);
  
  robot.encenderPuente1();
  robot.encenderPuente2();
  
  c_inicio = obtenerGrados();
  
}

void loop()
{
  
  leerDatos();
  
  LDRValue1 = promedio1();
  LDRValue2 = promedio2();
  LDRValue3 = promedio3();
  
  c_actual = obtenerGrados();
  brujula = arreglarCompas();
  
  Serial.print("Compas: ");
  Serial.println(brujula);
  /*Serial.print(" luz 1: ");
  Serial.print(LDRValue1);
  Serial.print(" luz 2: ");
  Serial.print(LDRValue2);
  Serial.print(" luz 3: ");
  Serial.println(LDRValue3);*/
  //followball();

}

void leerDatos()
{

  LDRValue1_1 = analogRead(LDR1_1);
  LDRValue1_2 = analogRead(LDR1_2);
  LDRValue1_3 = analogRead(LDR1_3);
  LDRValue2_1 = analogRead(LDR2_1);
  LDRValue2_2 = analogRead(LDR2_2);
  LDRValue2_3 = analogRead(LDR2_3);
  LDRValue3_1 = analogRead(LDR3_1);
  LDRValue3_2 = analogRead(LDR3_2);
  LDRValue3_3 = analogRead(LDR3_3);
  LDRValue4_1 = analogRead(LDR4_1);
  LDRValue4_2 = analogRead(LDR4_2);
  LDRValue4_3 = analogRead(LDR4_3);

}

int promedio1()
{

  return (LDRValue1_1, LDRValue1_2, LDRValue1_3)/3;

}

int promedio2()
{

  return (LDRValue2_1, LDRValue2_2, LDRValue2_3)/3;

}

int promedio3()
{

  return (LDRValue3_1, LDRValue3_2, LDRValue3_3)/3;

}

int obtenerGrados()
{
  
  sensors_event_t event;
  mag.getEvent(&event);
  
  float heading = atan2(event.magnetic.y, event.magnetic.x);
  
  if(heading < 0)
    heading += 2*PI;
    
  if(heading > 2*PI)
    heading -= 2*PI;
    
  float headingDegrees = heading * 180/M_PI;

  return headingDegrees;

}

int arreglarCompas()
{

  int b;
  b = c_actual - c_inicio;
  if(b < 0)
  {
  
    b+=360;
  
  }
  
  return b;

}

void followball()
{

  if (brujula >= 20 &&  brujula <= 345)
  {
  
    Serial.println("No alineado");
    if (brujula >= 183)
    {
    
      robot.alto();
      
      do
      {
      
        robot.alinearDer(80);
      
      }while(brujula > 350);
    
    }

    else
    {
    
      robot.alto();
      
      do
      {
      
        robot.alinearIzq(80);
      
      }while(brujula < 10);
    
    }    
  
  }
  
  else
  {
  
     Serial.println("Alineado");
  
  }

}
