#include "Recursos.h"
#include "Creature.h"

Recursos::Recursos(int xx, int yy, int ee)
	:Objeto(xx, yy), EnergyValue(ee) {
}

Recursos::~Recursos(){}

string Recursos::getEtiqueta() const{
	return "_*_";
}


string Recursos::toString() const{
	return "_*_";
}


