#include <Wire.h>
#include <Omnidireccional.h>
#include <VNH5019.h>
#include <HTInfraredSeeker.h>

Omnidireccional robot = Omnidireccional();
InfraredSeeker seeker = InfraredSeeker();
InfraredInput seekerInput;

byte ir, intensidad;

void setup()
{
  
  Wire.begin();
  robot.setM1puente1(6,7,8,9);
  robot.setM2puente1(2,17,16,15);
  robot.setM2puente2(3,14,4,5);
  robot.setM1puente1(10,11,12,13);
  
  robot.encenderPuente1();
  robot.encenderPuente2();
  
}

void loop()
{

  seekerInput = seeker.ReadAC();
  
  ir = seekerInput.Direction;
  intensidad = seekerInput.Strength;
  
  followball();

}

void followball()
{

  switch(ir)
  {
  
    case 0:
    
        robot.eIDer();
        
       break;
       
    case 1:
    
        robot.eIDer();
        
       break;
       
    case 2:
    
        robot.eIDer();
        
       break;
       
    case 3:
    
        robot.eIDer();
        
       break;
       
    case 4:
    
        robot.eIIzq();
        
       break;
       
    case 5:
    
        robot.adelante();
        
       break;
       
    case 6:
    
        robot.eIDer();
        
       break;
       
    case 7:
    
        robot.eIIzq();
        
       break;
       
    case 8:
    
        robot.eIIzq();
        
       break;
       
    case 9:
    
        robot.eIIzq();
        
       break;
  
  }

}

