#include "Carnívoro.h"

Carnívoro::Carnívoro(int x, int  y , int energia , int edad , shared_ptr<Estrategia> E):
	Creatura(x, y, energia, edad,E){}


string Carnívoro::toString() const {
	stringstream s;
	s << "C(" << x << "," << y << ") E:" << energia; // C de carnivoro, sus coordenadas y respectiva energía
	return s.str();
}

string Carnívoro::getEtiqueta() const {
	return "Carnivoro";
}


void Carnívoro::alimentarse() {
	setEstrategia(make_shared <EstrategiaAlimentacionC>());

	if (E) {
		E->EjecutarEstrategia(shared_from_this());
	}
}

void Carnívoro::atacar() {
	setEstrategia(make_shared <EstrategiaAtaque>());

	if (E) {
		E->EjecutarEstrategia(shared_from_this());
	}

}