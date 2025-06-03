#include "Hervivoro.h"


Hervivoro::Hervivoro(int x, int  y , int energia , int edad , shared_ptr<Estrategia> E):
	Creatura(x, y, energia, edad, E){}



string Hervivoro::toString() const{
	stringstream s;
	s << "H(" << x << "," << y << ") E:" << energia; // H de Hervivoro, sus coordenadas y respectiva energía
	return s.str();
}

string Hervivoro::getEtiqueta() const{
	return "Hervivoro";
}

void Hervivoro::alimentarse() {
	setEstrategia(make_shared<EstrategiaAlimentacionH>());
	if (E) {
		E->EjecutarEstrategia(shared_from_this());
	}
}

void Hervivoro::atacar() {
	// los hervivoros no atacan

}