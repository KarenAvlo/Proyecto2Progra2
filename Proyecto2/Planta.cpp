#include "Planta.h"


Planta::Planta(int xx, int yy, int ee):Recursos(xx,yy,ee){}

void Planta::regenerarse() {
	if (Enviroment::getInstancia()->getClima() == "Soleado") {// falta si hay agua cerca
		disponible = true;
	}
}
string Planta::toString() const {
	stringstream s;
	s << "Soy Planta" << endl;
	s << "Posicion:" << posX << "," << posY << endl;
	s << "Brindo una energía de:" << EnergyValue << endl;
	return s.str();
}

string Planta::getEtiqueta() const
{
	return "Planta";
}
