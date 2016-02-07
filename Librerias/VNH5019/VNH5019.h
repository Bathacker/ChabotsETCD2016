#ifndef VNH5019_h
#define VNH5019_h

class VNH5019 //En esta libreria se usan dos motores
{
  public:	
   
   //Constructor
   VNH5019();
   //Metodos
   void setM1(int M1PWM, int M1INB, int M1INA, int M1EN);  //Metodo que declara los pines del M1
   void setM2(int M2PWM, int M2INB, int M2INA, int M2EN);  //Metodo que declara los pines del M2
   void encenderM1();
   void apagarM1();
   void encenderM2();
   void apagarM2();
   void adelante1(int vel);
   void atras1(int vel);
   void alto1();
   void adelante2(int vel);
   void atras2(int vel);
   void alto2();
  
  private:
  
    int M2PWM; //Pin de velocidad del M2
    int M2INB; //Pin entrada B del M2
    int M2INA; //Pin entrada A del M2
    int M2EN;  //Pin para encender/apagar el M1
    int M1PWM; //Pin de velocidad del M1
    int M1INB; //Pin entrada B del M1
    int M1INA; //Pin entrada A del M1
    int M1EN;  //Pin para encender/apagar el M1

};
#endif