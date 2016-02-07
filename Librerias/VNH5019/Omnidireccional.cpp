#include "Omnidireccional.h"
#include <VNH5019.h>

Omnidireccional::Omnidireccional()
{



}

void Omnidireccional::setM1puente1(int M1PWM, int M1INB, int M1INA, int M1EN)
{

	puente1.setM1(M1PWM, M1INB, M1INA, M1EN);

}

void Omnidireccional::setM2puente1(int M2PWM, int M2INB, int M2INA, int M2EN)
{

	puente1.setM2(M2PWM, M2INB, M2INA, M2EN);

}

void Omnidireccional::encenderPuente1()
{

	puente1.encenderM1();
	puente1.encenderM2();

}

void Omnidireccional::apagarPuente1()
{

	puente1.apagarM1();
	puente1.apagarM2();

}

void Omnidireccional::setM1puente2(int M2PWM, int M2INB, int M2INA, int M2EN)
{

	puente2.setM2(M2PWM, M2INB, M2INA, M2EN);

}

void Omnidireccional::setM2puente2(int M1PWM, int M1INB, int M1INA, int M1EN)
{

	puente2.setM1(M1PWM, M1INB, M1INA, M1EN);

}

void Omnidireccional::encenderPuente2()
{

	puente2.encenderM1();
	puente2.encenderM2();

}

void Omnidireccional::apagarPuente2()
{

	puente2.apagarM1();
	puente2.apagarM2();

}

void Omnidireccional::Aadelante(int vel1, int vel2, int vel3, int vel4)
{

	puente1.adelante1(vel1);
	puente1.adelante2(vel4);
	puente2.adelante1(vel2);
	puente2.adelante2(vel3);
}

void Omnidireccional::adelante(int vel)
{

	puente1.adelante1(vel);
	puente1.adelante2(vel);
	puente2.adelante1(vel);
	puente2.adelante2(vel);

}

void Omnidireccional::adelante()
{

	puente1.adelante1(255);
	puente1.adelante2(255);
	puente2.adelante1(255);
	puente2.adelante2(255);

}

void Omnidireccional::Aatras(int vel1, int vel2, int vel3, int vel4)
{

	puente1.atras1(vel1);
	puente1.atras2(vel4);
	puente2.atras1(vel2);
	puente2.atras2(vel3);

}

void Omnidireccional::atras(int vel)
{

	puente1.atras1(vel);
	puente1.atras2(vel);
	puente2.atras1(vel);
	puente2.atras2(vel);

}

void Omnidireccional::atras()
{

	puente1.atras1(255);
	puente1.atras2(255);
	puente2.atras1(255);
	puente2.atras2(255);

}

void Omnidireccional::Aizquierda(int vel1, int vel2, int vel3, int vel4)
{

	puente1.atras1(vel1);
	puente1.adelante2(vel4);
	puente2.atras1(vel2);
	puente2.adelante2(vel3);
	
}

void Omnidireccional::izquierda(int vel)
{

	puente1.atras1(vel);
	puente1.adelante2(vel);
	puente2.atras1(vel);
	puente2.adelante2(vel);

}

void Omnidireccional::izquierda()
{

	puente1.atras1(255);
	puente1.adelante2(255);
	puente2.atras1(255);
	puente2.adelante2(255);

}

void Omnidireccional::Aderecha(int vel1, int vel2, int vel3, int vel4)
{

	puente1.adelante1(vel1);
	puente1.atras2(vel4);
	puente2.adelante1(vel2);
	puente2.atras2(vel3);

}

void Omnidireccional::derecha(int vel)
{

	puente1.adelante1(vel);
	puente1.atras2(vel);
	puente2.adelante1(vel);
	puente2.atras2(vel);

}

void Omnidireccional::derecha()
{

	puente1.adelante1(255);
	puente1.atras2(255);
	puente2.adelante1(255);
	puente2.atras2(255);
}

void Omnidireccional::AeSDer(int vel2, int vel4)
{

	puente1.alto1();
	puente1.adelante2(vel2);
	puente2.alto1();
	puente2.adelante2(vel4);

}

void Omnidireccional::eSDer(int vel)
{

	puente1.alto1();
	puente1.adelante2(vel);
	puente2.alto1();
	puente2.adelante2(vel);
}

void Omnidireccional::eSDer()
{

	puente1.alto1();
	puente1.adelante2(255);
	puente2.alto1();
	puente2.adelante2(255);
}

void Omnidireccional::AeSIzq(int vel1, int vel3)
{

	puente1.adelante1(vel1);
	puente1.alto2();
	puente2.adelante1(vel3);
	puente2.alto2();

}

void Omnidireccional::eSIzq(int vel)
{

	puente1.adelante1(vel);
	puente1.alto2();
	puente2.adelante1(vel);
	puente2.alto2();

}

void Omnidireccional::eSIzq()
{

	puente1.adelante1(255);
	puente1.alto2();
	puente2.adelante1(255);
	puente2.alto2();

}

void Omnidireccional::AeIIzq(int vel2, int vel4)
{

	puente1.alto1();
	puente1.atras2(vel2);
	puente2.alto1();
	puente2.atras2(vel4);

}

void Omnidireccional::eIIzq(int vel)
{

	puente1.alto1();
	puente1.atras2(vel);
	puente2.alto1();
	puente2.atras2(vel);

}

void Omnidireccional::eIIzq()
{

	puente1.alto1();
	puente1.atras2(255);
	puente2.alto1();
	puente2.atras2(255);

}

void Omnidireccional::AeIDer(int vel2, int vel4)
{

	puente1.atras1(vel2);
	puente1.alto2();
	puente2.atras1(vel4);
	puente2.alto2();

}

void Omnidireccional::eIDer(int vel)
{

	puente1.atras1(vel);
	puente1.alto2();
	puente2.atras1(vel);
	puente2.alto2();

}

void Omnidireccional::eIDer()
{

	puente1.atras1(255);
	puente1.alto2();
	puente2.atras1(255);
	puente2.alto2();
}

void Omnidireccional::alinearDer(int vel)
{

	puente1.atras1(vel);
	puente1.atras2(vel);
	puente2.adelante1(vel);
	puente2.adelante2(vel);

}

void Omnidireccional::alinearIzq(int vel)
{

	puente1.adelante1(vel);
	puente1.adelante2(vel);
	puente2.atras1(vel);
	puente2.atras2(vel);

}

void Omnidireccional::alto()
{

	puente1.alto1();
	puente1.alto2();
	puente2.alto1();
	puente2.alto2();

}

void Omnidireccional::Motor1adel(int vel)
{

	puente1.adelante1(vel);

}

void Omnidireccional::Motor1atras(int vel)
{

	puente1.atras1(vel);

}

void Omnidireccional::Motor1alto()
{
	
	puente1.alto1();

}

void Omnidireccional::Motor2adel(int vel)
{

	puente1.adelante2(vel);

}

void Omnidireccional::Motor2atras(int vel)
{

	puente1.atras2(vel);

}

void Omnidireccional::Motor2alto()
{

	puente1.alto2();

}

void Omnidireccional::Motor3adel(int vel)
{

	puente2.adelante1(vel);

}

void Omnidireccional::Motor3atras(int vel)
{

	puente2.atras1(vel);

}

void Omnidireccional::Motor3alto()
{

	puente2.alto1();

}

void Omnidireccional::Motor4adel(int vel)
{

	puente2.adelante2(vel);

}

void Omnidireccional::Motor4atras(int vel)
{

	puente2.atras2(vel);

}

void Omnidireccional::Motor4alto()
{

	puente2.alto2();

}
