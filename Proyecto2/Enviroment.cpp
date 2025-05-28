#include "Enviroment.h"

unique_ptr<Enviroment> Enviroment::instancia = nullptr;

Enviroment::Enviroment() :clima("Lluvioso"), estacion("Primavera"), energia(100),agua(20) {
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

string Enviroment::getEstación() { return estacion; }

int Enviroment::getEnergia() { return energia; }

shared_ptr<lista<shared_ptr<Observer>>> Enviroment::getLista() { return observers; }


 string Enviroment::toString() const{
	 stringstream s;
	 s << "Clima: " << clima << endl;
	 s << "Estacion:" << estacion << endl;
	 s << "Energia: " << energia << endl;
	 return s.str();
 }

 bool Enviroment::hayAgua() {
	 if (agua > 0) { // si hay más de 0% sí hay agua
		 return true;
	 }
	 return false;
 }