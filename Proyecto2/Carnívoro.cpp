#include "Carn�voro.h"

Carn�voro::Carn�voro(int x, int  y , int energia , int edad , shared_ptr<Estrategia> E):
	Creatura(x, y, energia, edad,E){}


string Carn�voro::toString() const {
	stringstream s;
	s << "C(" << x << "," << y << ") E:" << energia; // C de carnivoro, sus coordenadas y respectiva energ�a
	return s.str();
}

string Carn�voro::getEtiqueta() const {
	return "Carnivoro";
}


void Carn�voro::reproducirse() {
	if (Enviroment::getInstancia()->hayCarnivoroCerca(shared_from_this())) {
		//si hay un animal de su mismo tipo, entonces reproduzcase


		setEstrategia(make_shared<EstrategiaReproduccion>());
		if (E) {
			E->EjecutarEstrategia(shared_from_this());
		}
	}

}

void Carn�voro::alimentarse() {
	setEstrategia(make_shared <EstrategiaAlimentacionC>());

	if (E) {
		E->EjecutarEstrategia(shared_from_this());
	}
}

void Carn�voro::atacar() {
	setEstrategia(make_shared <EstrategiaAtaque>());
	if (energia >= 15) {
		if (E) {
			E->EjecutarEstrategia(shared_from_this());
		}
	}

}

void Carn�voro::guardarDatos(std::ofstream& archivo) const {
	archivo << "Carnivoro," << getX() << "," << getY() << "," << energia << "," << edad << "\n";
}