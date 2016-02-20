#ifndef HTInfraredSeeker_h
#define HTInfraredSeeker_h
#include "Arduino.h"
	
	struct InfraredInput //Sirve como un arreglo para guardar
	{
	
	  	byte Direction;
	  	byte Strength;
	
	};

	struct InfraredInput2 //Sirve como un arreglo para guardar
	{
	
	  	byte Direction2;
	  	byte Strength2;
	
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

	class InfraredSeeker2
	{

		public:

			static void Initialize2(); //Metodo que inicia la comunicacion con el I2C
			static void ReadACRaw2(byte* buffer); //Metodo para leer valores
			static InfraredInput2 ReadAC2(); //Recibe todos los metodos de lectura

		private:

			static InfraredInput2 PopulateValues2(byte* buffer); //Obtiene la direccion de la pelota y la intensidad
			static void ReadValues2(byte OffsetAddress2, byte* buffer);
			static const int Address2 = 0x10 / 2; //Divide by two as 8bit-I2C address is provided

	};
#endif
