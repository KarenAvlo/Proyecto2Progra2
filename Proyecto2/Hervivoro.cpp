#include "Hervivoro.h"

Hervivoro::Hervivoro(int x, int y, int energia,int edad, shared_ptr<EstrategiaMovimiento> em,
	shared_ptr<EstrategiaReproducción> er) 
	: Creatura(x, y, energia,edad,em ,er){}


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
