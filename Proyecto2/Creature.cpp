#include "Creature.h"

Creatura::Creatura(){
	x = 0;
	y = 0;
	energ�a = MAX_ENERGIA;
	edad = 10;
	em = nullptr;
}

Creatura::Creatura(int xx, int yy, int ener, int age, shared_ptr<EstrategiaMovimiento> e1, 
	shared_ptr<EstrategiaReproducci�n> e2) :Objeto(xx, yy),
energ�a(ener), edad(age), em(e1),er(e2) {
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

void Creatura::reproducirse() {
	if (energ�a > 10) {
		energ�a -= 10;
		er->EjecutarEstrategia(this);
	}
}

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

void Creatura::ReducirEnerg�a(int e) {
	if (e >= 0 && e <= MAX_ENERGIA) {
		energ�a -= e;
	}
	else {
		throw std::out_of_range("Energ�a fuera de rango");
	}

}

void Creatura::setEdad(int age) { edad = age; }

void Creatura::setEstrategiaMovimiento(shared_ptr<EstrategiaMovimiento> move) {
	em = move;
}
void Creatura::setEstrategiaReproduccion(shared_ptr<EstrategiaReproducci�n> repro) {
	er = repro;
}


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



