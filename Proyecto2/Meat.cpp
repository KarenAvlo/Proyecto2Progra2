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
	s << "Soy Planta" << endl;
	s << "Posicion:" << x << "," << y << endl;
	s << "Brindo una energía de:" << EnergyValue << endl;
	return s.str();
}