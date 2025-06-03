#include "Factory.h"


shared_ptr<Recursos> FactoryResources::crearInstancia(int t){
	shared_ptr<Recursos> re = nullptr;

	//Se crean nuevas variables x y y, random;
	int newX = rand() % 10;
	int newY = rand() % 10;

	switch (t) {
	case 1:
		re = make_shared<Agua>(newX,newY,100);
		break;
	case 2:
		re = make_shared<Planta>(newX, newY, 100);
		break;
	case 3:
		re = make_shared<Meat>(newX, newY, 100);
		break;
	default:
		throw invalid_argument("Tipo de recurso desconocido: ");
		break;
	}
	return re;
}

shared_ptr<Creatura> FactoryCreature::crearInstancia(int t) {
	shared_ptr<Creatura> creatura = nullptr;

	shared_ptr<Estrategia> e1= make_shared<EstrategiaMovimiento>();
	

	//Se crean nuevas variables x y y, random;
	int newX = rand() % 10;
	int newY = rand() % 10;
	int edad = rand() % 10;

	switch (t) {
	case 1:

		creatura = make_shared<Hervivoro>(newX, newY, 100,edad,e1);
		break;
	case 2:
		creatura = make_shared<Carnívoro>(newX, newY, 100, edad, e1);
		break;
	case 3:
		creatura = make_shared<Omnivoro>(newX, newY, 100, edad, e1);
		break;

	default:
		throw invalid_argument("Tipo de creatura desconocido: ");
		break;
	}
	return creatura;
}

int FactoryCreature::etiquetaToTipo(const string& etiqueta) {
	if (etiqueta == "Hervivoro") return 1;
	if (etiqueta == "Carnivoro") return 2;
	if (etiqueta == "Omnivoro")return 3;

	throw std::invalid_argument("Etiqueta desconocida");

}

