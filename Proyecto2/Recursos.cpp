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

//void Recursos::consumir(Creatura* c) {
//	if (disponible) {
//		c->AumentarEnergia(c->getEnergia());
//		disponible = false;
//	}
//}

string Recursos::formatear(){
//falta;
	return "";
}
