#include "Hervivoro.h"

Hervivoro::Hervivoro(int x, int y, int energia,int edad,EstrategiaMovimiento*em) 
	: Creatura(x, y, energia,edad,em ){}


string Hervivoro::toString() const{
	return "nada";
}

string Hervivoro::getEtiqueta() const
{
	return "Hervivoro";
}
