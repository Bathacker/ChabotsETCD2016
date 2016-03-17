#include <HMC5583L.h>
#include <Wire.h>
#include <Omnidireccional.h>
#include <VNH5019.h>
#include <HTInfraredSeeker.h>

HMC5583L mag = HMC5583L(HMC5583L_DEFAULT_ADDRESS);
Omnidireccional robot = Omnidireccional();
HTInfraredSeeker seeker = HTInfraredSeeker();
InfraredInput seekerInput;
float brujula;
 
byte ir, intensidad;

int LDRValue1_1, LDRValue1_2, LDRValue1_3;
int LDRValue1;
int luz;

void setup()
{
  
  Serial.begin(9600);
  Wire.begin();
  robot.setM1puente1(6,7,8,9);
  robot.setM2puente1(2,17,16,15);
  robot.setM2puente2(3,14,4,5);
  robot.setM1puente2(10,11,12,13);
  mag.initialize();
  seeker.init();
  
  robot.encenderPuente1();
  robot.encenderPuente2();
  
}

void loop()
{
  seekerInput = seeker.readSensorValues();
  brujula = mag.getAngle();
  
  ir = seekerInput.direction;

  leerDatos();
  
  LDRValue1 = promedio1(); 
  
  intensidad = seekerInput.strengthAll; 
  
  Serial.print("Infra: ");
  Serial.print(ir);
  Serial.print(" compas: ");
  Serial.print(brujula);
  Serial.print(" luz 1: ");
  Serial.print(LDRValue1);
  //followball();

}

void leerDatos()
{

  LDRValue1_1 = analogRead(A6);
  LDRValue1_2 = analogRead(A7);
  LDRValue1_3 = analogRead(A8);
  
}

int promedio1()
{

  return (LDRValue1_1, LDRValue1_2, LDRValue1_3)/3;

}

void followball()
{

  if (brujula >= 20 &&  brujula <= 345)
  {
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
  
     switch(ir)
     {
  
      case 0:

          if(LDRValue1 >= luz)
          {

            robot.alto();
            robot.eSIzq();
            
          }   
          
          else
          {
          
            robot.alto();
            robot.eIDer();
          
          }
        
         break;
       
      case 1:
    
          if(LDRValue1 >= luz)
          {

            robot.alto();
            robot.eSIzq();
          
          } 
          
          else
          {
            
            robot.alto();
            robot.eIDer();

          }
        
         break;
       
      case 2:
    
          if(LDRValue1 >= luz)
          {

            robot.alto();
            robot.eSIzq();
                      
          }
          
          else
          {
          
            robot.alto();
            robot.eIDer();
          
          }
        
         break;
       
      case 3:
    
          if(LDRValue1 >= luz)}
          {

            robot.alto();
            robot.eSIzq();
            
          }
          
          else
          {
            
            robot.alto();
            robot.eIDer();

          }
        
         break;
       
      case 4:
    
          if(LDRValue1 >= luz)
          {

            robot.alto();
            robot.eSDer();

          }
          
          else
          {
            
            robot.alto();
            robot.eIIzq();

          }
                  
         break;
       
      case 5:
    
          if(LDRValue1 >= luz)
          {

            robot.alto();
            robot.atras();

          }

          else
          {
            
            robot.alto();
            robot.adelante();

          }
        
         break;
       
      case 6:
    
          if(LDRValue1 >= luz)
          {

            robot.alto();
            robot.eSIzq();

          }

          else
          {
          
            robot.alto();
            robot.eIDer();

          }
        
         break;
       
      case 7:
    
          if(LDRValue1 >= luz)
          {

            robot.alto();
            robo.eSDer();

          }

          else
          {
            
            robot.alto();
            robot.eIIzq();

          }
        
         break;
       
      case 8:
    
          if(LDRValue1 >= luz)
          {

            robot.alto();
            robot.eSDer();

          }

          else
          {
            
            robot.alto();
            robot.eIIzq();

          }
        
         break;
       
      case 9:
    
          if(LDRValue1 >= luz)
          {

            robot.alto();
            robot.eSDer();

          }

          else
          {
            
            robot.alto();
            robot.eIIzq();

          }
        
         break;
  
    }
  
  }

}

