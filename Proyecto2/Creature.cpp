#include "Creature.h"

Creatura::Creatura(){
	x = 0;
	y = 0;
	energia = MAX_ENERGIA;
	edad = 10;
	em = nullptr;
}

Creatura::Creatura(int xx, int yy, int ener, int age, shared_ptr<EstrategiaMovimiento> e1, 
	shared_ptr<EstrategiaReproduccion> e2, shared_ptr<EstrategiaAlimentacion> e3) :
	Objeto(xx, yy),energia(ener), edad(age), em(e1),er(e2),ea(e3) {
}

Creatura::~Creatura() {}

void Creatura::moverse() {
	//el moverse utiliza 5 de energia
	if (energia >= 5) {
		Reducirenergia(5);
		em->EjecutarEstrategia(shared_from_this());
	}
}

void Creatura::reproducirse() {
	if (energia > 10) {
		Reducirenergia(10);
		er->EjecutarEstrategia(shared_from_this());
	}
}

int Creatura::getEnergia() { return energia; }

int Creatura::getEdad() { return edad; }

void Creatura::AumentarEnergia(int e){
	if (e >= 0 && e <= MAX_ENERGIA) {
		energia += e;
	}
	else {
		throw std::out_of_range("energia negativa");
	}
}

void Creatura::Reducirenergia(int e) {
	if (e >= 0 && e <= MAX_ENERGIA) {
		energia -= e;
	}
	else {
		throw std::out_of_range("energia fuera de rango");
	}
}

void Creatura::setEdad(int age) { edad = age; }

void Creatura::setEstrategiaMovimiento(shared_ptr<EstrategiaMovimiento> move) {
	em = move;
}
void Creatura::setEstrategiaReproduccion(shared_ptr<EstrategiaReproduccion> repro) {
	er = repro;
}

void Creatura::setEstrategiaAlimentacion(shared_ptr<EstrategiaAlimentacion> alimento) {
	ea = alimento;
}

string Creatura::toString() const {
	stringstream s;
	s << "( " << x <<", " << y <<")" << endl;
	s << "Energia: " << energia<<endl;
	s << "Edad: " << edad<<endl;
	return s.str();
}

string Creatura::getEtiqueta() const {
	return "Creatura";
}

bool Creatura::isDead() { //lo ideal es poner algo en enviroment para sacar las creaturas muertas
	if (energia < 0) {
		return true;
	}
	return false;
}



