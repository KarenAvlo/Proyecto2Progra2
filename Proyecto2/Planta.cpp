#include "Planta.h"


PlantaFlor::PlantaFlor(int xx, int yy, int ee)
	:Recursos(xx, yy, ee)
{}

string PlantaFlor::toString() const {
	stringstream s;
	s << "_+_  E:" << EnergyValue; 
	return s.str();
}

string PlantaFlor::getEtiqueta() const{ // creo que no se está usando
	return "Planta";
}

//-----Planta Rosa------


PlantaRosa::PlantaRosa(int xx, int yy, int ee)
	:Recursos(xx, yy, ee){}


string PlantaRosa::toString() const {
	stringstream s;
	s << "_@_  E:" << EnergyValue;
	return s.str();
}

string PlantaRosa::getEtiqueta() const { // creo que no se está usando
	return "Planta";
}