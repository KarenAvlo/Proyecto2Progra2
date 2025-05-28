#include "Agua.h"


Agua::Agua(int xx, int yy, int ee): Recursos(xx,yy,ee){}


void Agua::regenerarse() {
	if (Enviroment::getInstancia()->getClima() == "lluvioso") {
		disponible = true;
	}
}
string Agua::toString() const {
	stringstream s;
	s << "Soy Agua" << endl;
	s << "Posicion:" << x << "," << y << endl;
	s << "Brindo una energía de:" << EnergyValue << endl;
	return s.str();
}