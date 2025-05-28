#include "FactoryResources.h"
#include "Agua.h"
#include "Planta.h"
#include "Meat.h"
// se podría hacer con punteros inteligentes

Recursos* FactoryResources::crearInstancia(int t) {
	Recursos* re = nullptr;
	switch (t) {
	case 1:
		re = new Agua();
		break;
	case 2:
		re = new Planta();
		break;
	case 3:
		re = new Meat();
		break;
	default:
		std::cerr << "Tipo desconocido: " << t << std::endl;
		break;

	}
	return re;
}