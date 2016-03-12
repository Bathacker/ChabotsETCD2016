#include <Wire.h>
#include <Omnidireccional.h>
#include <VNH5019.h>
#include <HTInfraredSeeker.h>

Omnidireccional robot = Omnidireccional();
InfraredSeeker seeker = InfraredSeeker();
InfraredInput seekerInput;

byte ir, intensidad;
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
  
}

void loop()
{
  
  leerDatos();
  
  LDRValue1 = promedio1();
  LDRValue2 = promedio2();
  LDRValue3 = promedio3();
  
  seekerInput = seeker.ReadAC();
  
  ir = seekerInput.Direction;
  intensidad = seekerInput.Strength;
  
  Serial.print("Infra: ");
  Serial.println(ir);
  Serial.print(" luz 1: ");
  Serial.print(LDRValue1);
  Serial.print(" luz 2: ");
  Serial.print(LDRValue2);
  Serial.print(" luz 3: ");
  Serial.println(LDRValue3);
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
void followball()
{
     
     switch(ir)
     {
  
      case 0:
    
          robot.alto();
          robot.eIDer();
        
         break;
       
      case 1:
    
          robot.alto();
          robot.eIDer();
        
         break;
       
      case 2:
    
          robot.alto();
          robot.eIDer();
        
         break;
       
      case 3:
    
          robot.alto();
          robot.eIDer();
        
         break;
       
      case 4:
    
          robot.alto();
          robot.eIIzq();
        
         break;
       
      case 5:
    
          robot.alto();
          robot.adelante();
        
         break;
       
      case 6:
    
          robot.alto();
          robot.eIDer();
        
         break;
       
      case 7:
    
          robot.alto();
          robot.eIIzq();
        
         break;
       
      case 8:
    
          robot.alto();
          robot.eIIzq();
        
         break;
       
      case 9:
    
          robot.alto();
          robot.eIIzq();
        
         break;
  
    }

}
