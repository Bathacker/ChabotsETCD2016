#ifndef HTInfraredSeeker_h
#define HTInfraredSeeker_h
#include "Arduino.h"
	
	struct InfraredInput //Sirve como un arreglo para guardar
	{
	
	  	byte Direction;
	  	byte Strength;
	
	};
	
	class InfraredSeeker
	{
		
		public:
		
			static void Initialize(); //Metodo que inicia la comunicacion con el I2C
			static void ReadACRaw(byte* buffer); //Metodo para leer valores
			static InfraredInput ReadAC(); //Recibe todos los metodos de lectura
	  	
	  	private:
		
			static InfraredInput PopulateValues(byte* buffer); //Obtiene la direccion de la pelota y la intensidad
			static void ReadValues(byte OffsetAddress, byte* buffer);
			static const int Address = 0x10 / 2; //Divide by two as 8bit-I2C address is provided
	
	};
#endif