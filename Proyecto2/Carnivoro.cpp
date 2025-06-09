#include "Carnivoro.h"

Carnivoro::Carnivoro(int x, int  y, int energia, int edad, shared_ptr<Estrategia> E):
	Creatura(x, y, energia, edad,E) {
}


string Carnivoro::toString() const {
	stringstream s;
	s << "C(" << x << "," << y << ") E:" << energia; // C de carnivoro, sus coordenadas y respectiva energía
	return s.str();
}

string Carnivoro::getEtiqueta() const {
	return "Carnivoro";
}


void Carnivoro::reproducirse() {

	if (Enviroment::getInstancia()->hayCarnivoroCerca(shared_from_this())) {
		setEstrategia(make_shared<EstrategiaReproduccion>());
		if (E) {
			E->EjecutarEstrategia(shared_from_this());
		}
	}
}

void Carnivoro::alimentarse() {
	setEstrategia(make_shared <EstrategiaAlimentacionC>());

	if (E) {
		E->EjecutarEstrategia(shared_from_this());
	}
}

void Carnivoro::atacar() {
	
	if (Enviroment::getInstancia()->getCreaturaDebilCerca(shared_from_this())) {
		setEstrategia(make_shared<EstrategiaAtaqueC>());

		if (E) {
			E->EjecutarEstrategia(shared_from_this());
		}
	}
}

void Carnivoro::guardarDatos(ofstream& archivo) const {
	archivo << "Carnivoro, " << "Posicion en el eje X: " << getX() << ", " << "Posicion en el eje Y: " << getY() << ", " << "Energia del Carnivoro: " << energia << " , " << "Edad del Carnivoro: " << edad << endl;
}