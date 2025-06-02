#include "Carnívoro.h"

Carnívoro::Carnívoro(int x, int y, int energia, int edad, shared_ptr<EstrategiaMovimiento> em,
	shared_ptr<EstrategiaReproduccion> er, shared_ptr<EstrategiaAlimentacion> ea)
	: Creatura(x, y, energia, edad, em, er,ea) {

	//se debe cambiar la estrategia para los carnívoros
	setEstrategiaAlimentacion(make_shared < EstrategiaAlimentacionC>());
}


string Carnívoro::toString() const {
	stringstream s;
	s << "C(" << x << "," << y << ") E:" << energia; // C de carnivoro, sus coordenadas y respectiva energía
	return s.str();
}

string Carnívoro::getEtiqueta() const {
	return "Carnivoro";
}


void Carnívoro::alimentarse() {
	if (ea) {
		ea->EjecutarEstrategia(shared_from_this());
	}
}