#include "Enviroment.h"

//unique_ptr<Enviroment> Enviroment::instancia = nullptr;
//
//Enviroment::Enviroment() :clima("Lluvioso"), estacion("Primavera") {
//	
//	mapa = make_shared<Mapa>(20, 20); //creamos un mapa de 20x20 por defecto
//	//hay que hacer algo para poder rotar entre lluvioso, soleado, ventoso.... igual con las estaciones
//
//}
//
//Enviroment* Enviroment::getInstancia(){
//	if (!instancia) {
//		instancia = unique_ptr<Enviroment>(new Enviroment());
//	}
//	return instancia.get();
//}
//
//
//
//void Enviroment::agregarRecurso( shared_ptr<Objeto> recurso){
//	int x = recurso->getX();
//	int y = recurso->getY();
//	mapa->agregarRecurso(x, y, recurso);
//}
//
//void Enviroment::agregarCreatura(shared_ptr<Objeto>creatura )
//{
//	int x = creatura->getX();
//	int y = creatura->getY();
//	mapa->agregarCriatura(x, y, creatura);
//}
//
////setters
//void Enviroment::setClima(int cli) {
//	if (cli == 1) {
//		clima = "Soleado";
//	}
//	else if (cli == 2) {
//		clima = "Lluvioso";
//	}
//	else if (cli == 3) {
//		clima = "Nublado";
//	}
//	else {
//		clima = "Desconocido"; 
//	}
//}
//
//void Enviroment::setEstacion(string est) { estacion = est; }
//
////getters
//string Enviroment::getClima() { return clima; }
//
//string Enviroment::getEstación() { return estacion; }
//
//shared_ptr<Mapa> Enviroment::getMapa() const
//{
//	return mapa; 
//}
//
//
// //string Enviroment::toString() const{
//	// stringstream s;
//	// s << "Clima: " << clima << endl;
//	// s << "Estacion:" << estacion << endl;
//	// s << "Energia: " << energia << endl;
//	// return s.str();
// //}

 