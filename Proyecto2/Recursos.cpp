#include "Recursos.h"
#include "Creature.h"

Recursos::Recursos(int xx, int yy, int ee):Objeto(xx,yy),EnergyValue(ee),disponible(true){
	
}

Recursos::~Recursos(){}


void Recursos::consumir(Creatura* c) {
	if (disponible) {
		c->AumentarEnergia(c->getEnergia());
		disponible = false;
	}
}

string Recursos::formatear(){
//falta;
	return "";
}
void Recursos::cargar(){
// falta
}