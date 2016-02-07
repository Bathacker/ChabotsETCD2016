//Este programa no es definitivo solo es una prueba con 2 infrarrojos
#include <Omnidireccional.h>
#include <VNH5019.h>
#include <Wire.h>
#include <HTInfraredSeeker.h>
//infrarrojo 1
InfraredSeeker seeker = InfraredSeeker();
InfraredInput seekerInput;
//infrarrojo 2
InfraredSeeker seeker2 = InfraredSeeker();
InfraredInput seeker2Input;
//robot
Omnidireccional robot = Omnidireccional();

byte ir, intensidad;
byte ir2, intensidad2;

void setup()
{
  
  Wire.begin();
  robot.setM1puente2(6,7,8,9);//Pines de motor 1 en puente h segundo
  robot.setM2puente1(2,17,16,15); //Pines de motor 2 en puentte h primero
  robot.setM2puente2(3,14,4,5); //Pines de motor 2 en puente h segundo
  robot.setM1puente1(10,11,12,13);//Pines de motor 1 en puentte h primero 
  
  robot.encenderPuente1();
  robot.encenderPuente2();

}

void loop()
{
  
  seekerInput = seeker.ReadAC();
  seeker2Input = seeker2.ReadAC();
  
  ir=seekerInput.Direction;
  intensidad=seekerInput.Strength;
  ir2=seeker2Input.Direction;
  intensidad2=seeker2Input.Strength;
  
  followball();

}

void followball()
{

  switch (ir)
  {
      
    case 3:
    
       robot.eIIzq();
       
      break;
    
    case 4:
    
       robot.eIDer();
        
      break;
       
    case 5:
    
       robot.adelante();
        
      break;
       
    case 6:
    
       robot.eIIzq();
        
      break;
       
    case 7:
    
       robot.eIDer();
        
      break;
  
  }
  
  switch (ir2)
  {
  
    case 3:
    
       robot.eIDer();
       
      break;
    
    case 4:
    
       robot.eIDer();
        
      break;
       
    case 5:
    
       robot.eIDer();
        
      break;
       
    case 6:
    
       robot.eIIzq();
        
      break;
       
    case 7:
    
       robot.eIIzq();
        
      break;
  
  }
  
}
