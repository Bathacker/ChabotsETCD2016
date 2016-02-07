#ifndef HCSR04_h
#define HCSR04_h

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#define CM 1
#define INC 0

class HCSR04
{
  
  public:

    //Metodos
    HCSR04(int TP, int EP);
	  HCSR04(int TP, int EP, long TO);
    long Timing();
    long Ranging(int sys);
    void imprimirValores();

  private:
    
    //Variables
    int cm;
    int Trig_pin;
    int Echo_pin;
	  long Time_out;
    long duration,distacne_cm,distance_inc;

};

#endif