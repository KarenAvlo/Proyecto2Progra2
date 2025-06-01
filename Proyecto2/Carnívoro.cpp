#include "Carnívoro.h"

Carnívoro::Carnívoro(int x, int y, int energia, int edad, shared_ptr<EstrategiaMovimiento> em,
	shared_ptr<EstrategiaReproducción> er, shared_ptr<EstrategiaAlimentacion> ea)
	: Creatura(x, y, energia, edad, em, er,ea) {

	//se debe cambiar la estrategia para los carnívoros
	setEstrategiaAlimentacion(make_shared < EstrategiaAlimentacionC>());
}


string Carnívoro::toString() const {
	stringstream s;
	s << "Soy Carnivoro" << endl;
	s << "Posicion:" << x << "," << y << endl;
	s << "Tengo una energia de:" << energía << endl;
	return s.str();
}

string Carnívoro::getEtiqueta() const {
	return "Carnivoro";
}


void Carnívoro::alimentarse() {
	if (ea) {
		ea->EjecutarEstrategia(this);
	}
}