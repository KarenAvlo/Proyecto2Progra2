#include "Omnivoro.h"


Omnivoro::Omnivoro(int x, int y, int energia, int edad, shared_ptr<Estrategia> E) :
	Creatura(x, y, energia, edad, E) {

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
	setEstrategia(make_shared<EstrategiaAlimentacionO>());

	if (Enviroment::getInstancia()->hayCarneCerca(shared_from_this()) || Enviroment::getInstancia()->hayPlantaCerca(shared_from_this())) {
		if (E) {
			E->EjecutarEstrategia(shared_from_this());
		}
	}
}

void Omnivoro::atacar() {

	if (Enviroment::getInstancia()->getCreaturaDebilCerca(shared_from_this())) {
		setEstrategia(make_shared<EstrategiaAtaqueO>());

		if (E) {
			E->EjecutarEstrategia(shared_from_this());
		}
	}
}

void Omnivoro::reproducirse() {

	if (Enviroment::getInstancia()->hayOmnivoroCerca(shared_from_this())) {
		setEstrategia(make_shared<EstrategiaReproduccion>());

		if (E) {
			E->EjecutarEstrategia(shared_from_this());
		}
	}

}

void Omnivoro::guardarDatos(ofstream& archivo) const {
	archivo << "Omnivoro," << x << "," << y << "," << energia << "," << edad << "\n";
}