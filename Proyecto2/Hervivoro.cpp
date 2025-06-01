#include "Hervivoro.h"

Hervivoro::Hervivoro(int x, int y, int energia,int edad, shared_ptr<EstrategiaMovimiento> em,
	shared_ptr<EstrategiaReproducci�n> er,shared_ptr<EstrategiaAlimentacion>ea) 
	: Creatura(x, y, energia,edad,em ,er,ea){}


string Hervivoro::toString() const{
	stringstream s;
	s << "H(" << x << "," << y << ") E:" << energ�a; // H de Hervivoro, sus coordenadas y respectiva energ�a
	return s.str();
}

string Hervivoro::getEtiqueta() const{
	return "Hervivoro";
}

void Hervivoro::alimentarse() {

}