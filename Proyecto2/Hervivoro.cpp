#include "Hervivoro.h"

Hervivoro::Hervivoro(int x, int y, int energia,int edad, shared_ptr<EstrategiaMovimiento> em,
	shared_ptr<EstrategiaReproducción> er,shared_ptr<EstrategiaAlimentacion>ea) 
	: Creatura(x, y, energia,edad,em ,er,ea){}


string Hervivoro::toString() const{
	stringstream s;
	s << "Soy Hervivoro" << endl;
	s << "Posicion:" << x << "," << y << endl;
	s << "Tengo una energia de:" << energía << endl;
	return s.str();
}

string Hervivoro::getEtiqueta() const{
	return "Hervivoro";
}

void Hervivoro::alimentarse() {

}