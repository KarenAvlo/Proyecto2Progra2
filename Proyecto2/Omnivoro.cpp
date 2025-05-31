#include "Omnivoro.h"

Omnivoro::Omnivoro(int x, int y, int energia, int edad, shared_ptr<EstrategiaMovimiento> em,
	shared_ptr<EstrategiaReproducción> er)
	: Creatura(x, y, energia, edad, em, er) {
}


string Omnivoro::toString() const {
	stringstream s;
	s << "Soy Omnivoro" << endl;
	s << "Posicion:" << x << "," << y << endl;
	s << "Tengo una energia de:" << energía << endl;
	return s.str();
}

string Omnivoro::getEtiqueta() const {
	return "Omnivoro";
}
