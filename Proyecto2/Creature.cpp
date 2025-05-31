#include "Creature.h"

Creatura::Creatura(){
	x = 0;
	y = 0;
	energía = MAX_ENERGIA;
	edad = 10;
	em = nullptr;
}

Creatura::Creatura(int xx, int yy, int ener, int age, shared_ptr<EstrategiaMovimiento> e1, 
	shared_ptr<EstrategiaReproducción> e2) :Objeto(xx, yy),
energía(ener), edad(age), em(e1),er(e2) {
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

void Creatura::reproducirse() {
	if (energía > 10) {
		energía -= 10;
		er->EjecutarEstrategia(this);
	}
}

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

void Creatura::ReducirEnergía(int e) {
	if (e >= 0 && e <= MAX_ENERGIA) {
		energía -= e;
	}
	else {
		throw std::out_of_range("Energía fuera de rango");
	}

}

void Creatura::setEdad(int age) { edad = age; }

void Creatura::setEstrategiaMovimiento(shared_ptr<EstrategiaMovimiento> move) {
	em = move;
}
void Creatura::setEstrategiaReproduccion(shared_ptr<EstrategiaReproducción> repro) {
	er = repro;
}


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



