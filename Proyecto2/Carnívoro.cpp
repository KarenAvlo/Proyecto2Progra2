#include "Carnívoro.h"

Carnívoro::Carnívoro(int x, int y, int energia, int edad, shared_ptr<EstrategiaMovimiento> em,
	shared_ptr<EstrategiaReproducción> er)
	: Creatura(x, y, energia, edad, em, er) {
}


string Carnívoro::toString() const {
	stringstream s;
	s << "Soy Canívoro" << endl;
	s << "Posicion:" << x << "," << y << endl;
	s << "Tengo una energia de:" << energía << endl;
	return s.str();
}

string Carnívoro::getEtiqueta() const {
	return "Carnivoro";
}