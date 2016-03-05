#include <Adafruit_HMC5883_U.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Omnidireccional.h>
#include <VNH5019.h>
#include <HTInfraredSeeker.h>

Omnidireccional robot = Omnidireccional();
InfraredSeeker seeker = InfraredSeeker();
InfraredInput seekerInput;
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);

byte ir, intensidad;
int c_actual, c_inicio, brujula;

void setup()
{
  
  Serial.begin(9600);
  Wire.begin();
  robot.setM1puente1(6,7,8,9);
  robot.setM2puente1(2,17,16,15);
  robot.setM2puente2(3,14,4,5);
  robot.setM1puente1(10,11,12,13);
  
  robot.encenderPuente1();
  robot.encenderPuente2();
  c_inicio = obtenerGrados();
  
}

void loop()
{
    
  c_actual = obtenerGrados();
  brujula = arreglarCompas();
  
  seekerInput = seeker.ReadAC();
  
  ir = seekerInput.Direction;
  intensidad = seekerInput.Strength;


  
  Serial.print("Infra: ");
  Serial.println(ir);
  Serial.print(" compas: ");
  Serial.println(brujula);
  //followball();

}

float obtenerGrados()
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

}
