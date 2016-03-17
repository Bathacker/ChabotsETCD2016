#include <HMC5583L.h>
#include <Wire.h>
#include <Omnidireccional.h>
#include <VNH5019.h>
#include <HTInfraredSeeker.h>

HMC5583L mag = HMC5583L(HMC5583L_DEFAULT_ADDRESS);
Omnidireccional robot = Omnidireccional();
HTInfraredSeeker seeker = HTInfraredSeeker();
InfraredInput seekerInput;
float c_inicio, c_actual, brujula;
 
byte ir, intensidad;

void setup()
{
  
  Serial.begin(9600);
  Wire.begin();
  robot.setM1puente1(10,11,12,13);
  robot.setM2puente1(6,7,8,9);
  robot.setM1puente2(3,14,4,5);
  robot.setM2puente2(2,17,16,15);
  mag.initialize();
  seeker.init();
  
  robot.encenderPuente1();
  robot.encenderPuente2();

  c_inicio = mag.getAngle();
  
}


void loop()
{
  seekerInput = seeker.readSensorValues();
  c_actual = mag.getAngle();
  brujula = arreglarCompas();
  
  ir = seekerInput.direction;
  
  intensidad = seekerInput.strengthAll; 
  /*
  Serial.print("Infra: ");
  Serial.print(ir);
  Serial.print(" compas: ");
  Serial.println(brujula);*/
  followball();

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

void followball()
{
  
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
  {   
     switch(ir)
     {
  
      case 0:

          robot.alto();
        
         break;

      
      case 1:
      
          robot.alto();
          robot.eIDer(50);
        
         break;
       
      case 2:
    
          robot.alto();
          robot.eIDer(50);
        
         break;
       
      case 3:
      
          robot.alto();
          robot.eIDer(50);
        
         break;
       
      case 4:
      
          robot.alto();
          robot.eIIzq(50);
                  
         break;
       
      case 5:
    
          robot.alto();
          robot.adelante();
        
         break;
       
      case 6:
    
          robot.alto();
          robot.eIDer(50);
        
         break;
       
      case 7:
        
          robot.alto();
          robot.eIIzq(50);
        
         break;
       
      case 8:
    
          robot.alto();
          robot.eIIzq(50);
        
         break;
       
      case 9:
        
          robot.alto();
          robot.eIIzq(50);
        
         break;
  
    }
  
  }

}

