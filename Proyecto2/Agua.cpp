#include "Agua.h"


Agua::Agua(int xx, int yy, int ee, int nive): Recursos(xx,yy,ee), nivel(nive){}


//void Agua::regenerarse() {
//	if (Enviroment::getInstancia()->getClima() == "lluvioso") {
//		disponible = true;
//	}
//}

string Agua::getEtiqueta() const{return "Agua";}

void Agua::nivelAgual(int n){
	//modificar despues
	if (n == 0) {
		nivel = 0; // sin agua
	}
	else if (n == 1) {
		nivel = 1; // poca agua
	}
	else if (n == 2) {
		nivel = 2; // mucha agua
	}
	else {
		throw std::out_of_range("Nivel de agua fuera de rango");
	}
}

string Agua::toString() const {
	stringstream s;
	s << "Soy Agua" << endl;
	s << "Posicion:" << x << "," << y << endl;
	s << "Brindo una energía de:" << EnergyValue << endl;
	s << "Nivel de agua: " << nivel << endl;
	return s.str();
}