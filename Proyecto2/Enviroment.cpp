#include "Enviroment.h"

unique_ptr<Enviroment> Enviroment::instancia = nullptr;

Enviroment::Enviroment() :clima("Lluvioso"), estacion("Primavera"), energia(100) {
	observers = make_shared<lista<shared_ptr<Observer>>>();
}

Enviroment* Enviroment::getInstancia(){
	if (!instancia) {
		instancia = unique_ptr<Enviroment>(new Enviroment());
	}
	return instancia.get();
}

//metodos derivados de subject
void Enviroment::eliminar(shared_ptr<Observer> obj) {
	observers->eliminar(obj);
}

void Enviroment::add(shared_ptr<Observer> obj){
	observers->agregar(obj);
}

void Enviroment::notifyObservers() {
	for (auto& o : *observers) {
		o->update();
	}
}

//setters
void Enviroment::setClima(string cli) { clima = cli; }

void Enviroment::setEstacion(string est) { estacion = est; }

void Enviroment::setEnergia(int Energy) { energia = Energy; }

//getters
string Enviroment::getClima() { return clima; }

string Enviroment::getEstaci�n() { return estacion; }

int Enviroment::getEnergia() { return energia; }