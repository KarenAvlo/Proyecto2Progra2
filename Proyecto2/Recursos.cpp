#include "Recursos.h"

Recursos::Recursos(int xx, int yy, int ee):x(xx),y(yy),EnergyValue(ee),disponible(true){}

void Recursos::update(){
	regenerarse();
}

void Recursos::consumir(){
	// falta modificarlo, es decir, que entre por parámetro una Creatura, de modo que le haga un crecimeinto de su energía
	if (disponible) {
		disponible = false;
		cout << "Recurso Consumido" << endl;
    }

	//virtual void consumir(Creature * criatura) {
	//	if (disponible) {
	//		criatura->aumentarEnergia(energyValue);
	//		disponible = false;
	//	}
	//}
}
string Recursos::formatear(){
//falta;
	return "";
}
void Recursos::cargar(){
// falta
}