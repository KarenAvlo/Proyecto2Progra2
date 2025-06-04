#include "Planta.h"


Planta::Planta(int xx, int yy, int ee)
	:Recursos(xx, yy, ee)
{}

void Planta::regenerarse() {
	if (Enviroment::getInstancia()->getClima() == "Soleado") {// falta si hay agua cerca
		disponible = true;
	}
}

string Planta::toString() const {
	stringstream s;
	s << "P(" << x << "," << y << ") E:" << EnergyValue; // P de Planta, sus coordenadas y respectiva energía
	return s.str();
}

string Planta::getEtiqueta() const
{
	return "Planta";
}
