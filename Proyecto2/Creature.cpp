#include "Creature.h"


Creatura::Creatura(int xx, int yy, int ener, int age, EstrategiaMovimiento* e1) :Objeto(xx, yy),
energ�a(ener), edad(age), em(e1) {
}

Creatura::~Creatura() {}

void Creatura::moverse() {
	//el moverse utiliza 5 de energ�a
	if (energ�a >= 5) {
		energ�a -= 5;
		em->EjecutarEstrategia(this);
	}
}
void Creatura::alimentarse() {}

void Creatura::reproducirse() {}

int Creatura::getEnergia() { return energ�a; }

int Creatura::getEdad() { return edad; }

void Creatura::AumentarEnergia(int e) {
	if (e >= 0 && e <= MAX_ENERGIA) {
		energ�a += e;
	}
	else {
		throw std::out_of_range("Energ�a fuera de rango");
	}
}
void Creatura::setEdad(int age) { edad = age; }


string Creatura::toString() const {
	stringstream s;
	s << "( " << x <<", " << y <<")" << endl;
	s << "Energy: " << energ�a<<endl;
	s << "Edad: " << edad<<endl;
	return s.str();
}

string Creatura::getEtiqueta() const {
	return "Creatura";
}



