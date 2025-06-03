#include "Factory.h"


shared_ptr<Recursos> FactoryResources::crearInstancia(int t){
	const int maxIntentos = 100;
	int newX, newY;

	for (int intentos = 0; intentos < maxIntentos; ++intentos) {
		newX = rand() % 10;  // o mapa->getAncho()
		newY = rand() % 10;

		if (Enviroment::getInstancia()->getMapa()->posValida(newX, newY)) {  // solo si la posición está libre
			shared_ptr<Recursos> re = nullptr;

			switch (t) {
			case 1:
				re = make_shared<Agua>(newX, newY, 20);
				break;
			case 2:
				re = make_shared<Planta>(newX, newY, 20);
				break;
			case 3:
				re = make_shared<Meat>(newX, newY, 20);
				break;
			default:
				throw invalid_argument("Tipo de recurso desconocido: ");
				break;
			}
			return re;
		}
	}
	throw runtime_error("No se encontró posición válida para crear recurso.");
}

shared_ptr<Creatura> FactoryCreature::crearInstancia(int t) {
	const int maxIntentos = 100;
	int newX, newY,edad;
	shared_ptr<Estrategia> e1 = make_shared<EstrategiaMovimiento>();

	for (int intentos = 0; intentos < maxIntentos; ++intentos) {
		newX = rand() % 10;  // o mapa->getAncho()
		newY = rand() % 10;
		edad = rand() % 100;

		if (Enviroment::getInstancia()->getMapa()->posValida(newX, newY)) {
			shared_ptr<Creatura> creatura = nullptr;
		

			switch (t) {
			case 1:

				creatura = make_shared<Hervivoro>(newX, newY, 100, edad, e1);
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
	}
	throw runtime_error("No se encontró posición válida para crear criatura.");
}

int FactoryCreature::etiquetaToTipo(const string& etiqueta) {
	if (etiqueta == "Hervivoro") return 1;
	if (etiqueta == "Carnivoro") return 2;
	if (etiqueta == "Omnivoro")return 3;

	throw std::invalid_argument("Etiqueta desconocida");

}

