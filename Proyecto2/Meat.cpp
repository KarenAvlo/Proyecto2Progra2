#include "Meat.h"


Meat::Meat(int xx, int yy, int ee) :Recursos(xx, yy, ee) {}

void Meat::regenerarse() {
	//la carne no se regenera xd
}

string Meat::getEtiqueta() const {
	return "Carne";
}



string Meat::toString() const {
	stringstream s;
	s << "M(" << x << "," << y << ") E:" << EnergyValue; // M de Meat, sus coordenadas y respectiva energía
	return s.str();
}