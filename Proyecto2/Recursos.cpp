#include "Recursos.h"

Recursos::Recursos(int xx, int yy, int ee):EnergyValue(ee),disponible(true){
	posX = xx;
	posY = yy;
}

void Recursos::update(){
	regenerarse();
}

void Recursos::consumir(){
	// falta modificarlo, es decir, que entre por par�metro una Creatura, de modo que le haga un crecimeinto de su energ�a
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