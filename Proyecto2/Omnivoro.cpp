#include "Omnivoro.h"

Omnivoro::Omnivoro(int x, int y, int energia, int edad, shared_ptr<EstrategiaMovimiento> em,
	shared_ptr<EstrategiaReproduccion> er, shared_ptr<EstrategiaAlimentacion> ea)
	: Creatura(x, y, energia, edad, em, er,ea) {
}


string Omnivoro::toString() const {
	stringstream s;
	s << "O(" << x << "," << y << ") E:" << energia; // O de Omnivoro, sus coordenadas y respectiva energía
	return s.str();
}

string Omnivoro::getEtiqueta() const {
	return "Omnivoro";
}

void Omnivoro::alimentarse() {


}