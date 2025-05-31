#include "Creature.h"


Creatura::Creatura(int xx, int yy, int ener, int age, EstrategiaMovimiento* e1) :Objeto(xx, yy),
energía(ener), edad(age), em(e1) {
}

Creatura::~Creatura() {}

void Creatura::moverse() {
	//el moverse utiliza 5 de energía
	if (energía >= 5) {
		energía -= 5;
		em->EjecutarEstrategia(this);
	}
}
void Creatura::alimentarse() {}

void Creatura::reproducirse() {}

int Creatura::getEnergia() { return energía; }

int Creatura::getEdad() { return edad; }

void Creatura::AumentarEnergia(int e) {
	if (e >= 0 && e <= MAX_ENERGIA) {
		energía += e;
	}
	else {
		throw std::out_of_range("Energía fuera de rango");
	}
}
void Creatura::setEdad(int age) { edad = age; }


string Creatura::toString() const {
	stringstream s;
	s << "( " << x <<", " << y <<")" << endl;
	s << "Energy: " << energía<<endl;
	s << "Edad: " << edad<<endl;
	return s.str();
}

string Creatura::getEtiqueta() const {
	return "Creatura";
}



