#include "Planta.h"


Planta::Planta(int xx, int yy, int ee, string eti)
	:Recursos(xx, yy, ee), etiqueta(eti) 
{}

void Planta::regenerarse() {
	if (Enviroment::getInstancia()->getClima() == "Soleado") {// falta si hay agua cerca
		disponible = true;
	}
}

string Planta::toString() const {
	stringstream s;
	s << "🌱(" << x << "," << y << ") E:" << EnergyValue; // P de Planta, sus coordenadas y respectiva energía
	return s.str();
}

string Planta::getEtiqueta() const
{
	return "Planta";
}
