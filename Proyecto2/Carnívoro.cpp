#include "Carn�voro.h"

Carn�voro::Carn�voro(int x, int y, int energia, int edad, shared_ptr<EstrategiaMovimiento> em,
	shared_ptr<EstrategiaReproducci�n> er)
	: Creatura(x, y, energia, edad, em, er) {
}


string Carn�voro::toString() const {
	stringstream s;
	s << "Soy Can�voro" << endl;
	s << "Posicion:" << x << "," << y << endl;
	s << "Tengo una energia de:" << energ�a << endl;
	return s.str();
}

string Carn�voro::getEtiqueta() const {
	return "Carnivoro";
}