#include "Planta.h"


Planta::Planta(int xx, int yy, int ee)
	:Recursos(xx, yy, ee), etiqueta("_+_")
{}

void Planta::regenerarse() {
	if (Enviroment::getInstancia()->getClima() == "Soleado") {// falta si hay agua cerca
		disponible = true;
	}
}

string Planta::toString() const {
	stringstream s;
	s << "_+_ (" << x << "," << y << ") E:" << EnergyValue; // P de Planta, sus coordenadas y respectiva energía
	return s.str();
}

string Planta::getEtiqueta() const
{
	return "Planta";
}
