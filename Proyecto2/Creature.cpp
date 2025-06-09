#include "Creature.h"

Creatura::Creatura(){
	x = 0;
	y = 0;
	energia = MAX_ENERGIA;
	edad = 10;
	E = nullptr;
}

Creatura::Creatura(int xx, int yy, int ener, int age, shared_ptr<Estrategia> e):
	Objeto(xx, yy), energia(ener), edad(age),E(e){}


Creatura::~Creatura() {}

void Creatura::moverse() {
	//se cambia la estrategia para cada cosa
	setEstrategia(make_shared < EstrategiaMovimiento>());
	
	//el moverse utiliza 5 de energia
	if (energia >= 5) {
		ReducirEnergia(5);
		E->EjecutarEstrategia(shared_from_this());
	}
}


void Creatura::recibirDanio(int danio) { // esto lo usa el hervivoro nada más
	energia -= danio;
	if (energia < 0) energia = 0; // Evitar energía negativa
}

void Creatura::atacar(){
	cout << "ATACANDO" << endl;
}


void Creatura::reproducirse() {

	setEstrategia(make_shared <EstrategiaReproduccion>());

	if (E) {
		E->EjecutarEstrategia(shared_from_this());
	}
}

int Creatura::getEnergia() { return energia; }

int Creatura::getEdad() { return edad; }


void Creatura::AumentarEdad(){
	edad++;
}

void Creatura::AumentarEnergia(int e){
	if (e >= 0 && e <= MAX_ENERGIA) {
		energia += e;
	}
	else {
		throw std::out_of_range("energia negativa");
	}
}

void Creatura::ReducirEnergia(int e) {
	if (e >= 0 && e <= MAX_ENERGIA) {
		energia -= e;
	}
	else {
		throw std::out_of_range("energia fuera de rango");
	}
}

void Creatura::setEdad(int age) { edad = age; }

void Creatura::setEstrategia(shared_ptr<Estrategia> ee) {
	E = ee;
}

string Creatura::toString() const {
	stringstream s;
	s << "( " << x <<", " << y <<")" << endl;
	s << "Energia: " << energia<<endl;
	s << "Edad: " << edad<<endl;
	return s.str();
}

bool Creatura::isDead() const { 
	if (energia <= 0) {
		return true;
	}
	return false;
}

string Creatura::getEtiqueta() const{
	return "Criatura";
}


