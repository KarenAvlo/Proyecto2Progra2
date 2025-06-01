#include "Carn�voro.h"

Carn�voro::Carn�voro(int x, int y, int energia, int edad, shared_ptr<EstrategiaMovimiento> em,
	shared_ptr<EstrategiaReproducci�n> er, shared_ptr<EstrategiaAlimentacion> ea)
	: Creatura(x, y, energia, edad, em, er,ea) {

	//se debe cambiar la estrategia para los carn�voros
	setEstrategiaAlimentacion(make_shared < EstrategiaAlimentacionC>());
}


string Carn�voro::toString() const {
	stringstream s;
	s << "Soy Carnivoro" << endl;
	s << "Posicion:" << x << "," << y << endl;
	s << "Tengo una energia de:" << energ�a << endl;
	return s.str();
}

string Carn�voro::getEtiqueta() const {
	return "Carnivoro";
}


void Carn�voro::alimentarse() {
	if (ea) {
		ea->EjecutarEstrategia(this);
	}
}