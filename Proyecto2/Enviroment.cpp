#include "Enviroment.h"

unique_ptr<Enviroment> Enviroment::instancia = nullptr;

Enviroment::Enviroment() :clima("Lluvioso"), estacion("Primavera"), energia(100) {
	observers = make_shared<lista<shared_ptr<Observer>>>();
	mapa = make_shared<Mapa>(20, 20); //creamos un mapa de 20x20 por defecto
	//hay que hacer algo para poder rotar entre lluvioso, soleado, ventoso.... igual con las estaciones

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

void Enviroment::agregarRecurso(shared_ptr<Mapa> m, shared_ptr<Observer> recurso)
{
	if (m->agregarRecurso(recurso->getPosX(), recurso->getPosY(), recurso)) {
		observers->agregar(recurso);
		cout << "Recurso agregado al mapa." << endl;
	}
	else {
		cout << "No se pudo agregar el recurso al mapa." << endl;
	}
}

void Enviroment::agregarCriatura(shared_ptr<Mapa> m, shared_ptr<Observer> criatura)
{
	if (m->agregarCriatura(criatura->getPosX(), criatura->getPosY(), criatura)) {
		observers->agregar(criatura);
		cout << "Criatura agregada al mapa." << endl;
	}
	else {
		cout << "No se pudo agregar la criatura al mapa." << endl;
	}
}

//setters
void Enviroment::setClima(int cli) {
	if (cli == 1) {
		clima = "Soleado";
	}
	else if (cli == 2) {
		clima = "Lluvioso";
	}
	else if (cli == 3) {
		clima = "Nublado";
	}
	else {
		clima = "Desconocido"; 
	}
}

void Enviroment::setEstacion(string est) { estacion = est; }

void Enviroment::setEnergia(int Energy) { energia = Energy; }

//getters
string Enviroment::getClima() { return clima; }

string Enviroment::getEstación() { return estacion; }

int Enviroment::getEnergia() { return energia; }

shared_ptr<lista<shared_ptr<Observer>>> Enviroment::getLista() { return observers; }

shared_ptr<Mapa> Enviroment::getMapa() const
{
	return mapa; 
}


 string Enviroment::toString() const{
	 stringstream s;
	 s << "Clima: " << clima << endl;
	 s << "Estacion:" << estacion << endl;
	 s << "Energia: " << energia << endl;
	 return s.str();
 }

 