#include "Enviroment.h"
#include "Planta.h"
#include "Hervivoro.h"

unique_ptr<Enviroment> Enviroment::instancia = nullptr;

Enviroment::Enviroment() :clima("Lluvioso"), estacion("Primavera") {
	
	mapa = make_shared<Mapa>(10, 10); 

	//hay que hacer algo para poder rotar entre lluvioso, soleado, ventoso.... igual con las estaciones

}

Enviroment* Enviroment::getInstancia(){
	if (!instancia) {
		instancia = unique_ptr<Enviroment>(new Enviroment());
	}
	return instancia.get();
}

void Enviroment::agregarRecurso(shared_ptr<Objeto> recurso){
	int x = recurso->getX();
	int y = recurso->getY();
	objetos.agregar(recurso);
	mapa->agregarRecurso(x, y, recurso);
}

void Enviroment::agregarCreatura(shared_ptr<Objeto>creatura ){
	int x = creatura->getX();
	int y = creatura->getY();
	objetos.agregar(creatura);
	mapa->agregarCreatura(x, y, creatura);
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

string Enviroment::getClima() { return clima; }

string Enviroment::getEstación() { return estacion; }

const lista<shared_ptr<Objeto>>* Enviroment::getLista() const{
	return &objetos;
}

shared_ptr<Mapa> Enviroment::getMapa() const{
	return mapa; 
}


 string Enviroment::toString() const{
	 stringstream s;
	 s << "Clima: " << clima << endl;
	 s << "Estacion:" << estacion << endl;
	 return s.str();
 }

 bool Enviroment::hayPlantaCerca(Hervivoro* her) const {

	 for (auto it = objetos.begin(); it != objetos.end(); ++it) {

		 shared_ptr<Objeto> obj = *it;

		 shared_ptr<Planta> planta = std::dynamic_pointer_cast<Planta>(obj);

		 if (planta) {
			 double dist = std::hypot(planta->getX() - her->getX(), planta->getY() - her->getY());
			 if (dist <= 3.0) return true;
		 }
	 }
	 return false;
 }

 bool Enviroment::hayCreaturaDebilCerca(Creatura* cre) {
	 return false;
 }
 