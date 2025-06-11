/* -------------------------------------------------------------------+
*                                                                     |
* (c) 2025                                                            |
* EIF204 - Programación 2                                             |
* 1er ciclo 2025                                                      |
* NRC 41371 – Grupo 01                                                |
* Proyecto 2                                                          |
*                                                                     |
* 2-0816-0954; Avilés López, Karen Minards                            |
* 1-1709-0658; Elizondo Cascante, Cristhian                           |
* 1-19560437; Sánchez Bermúdez, Juan Pablo                            |
*                                                                     |
* versión 1.0.0, 09 - 06 - 2025                                       |
*                                                                     |
* --------------------------------------------------------------------+
*/
#include "Factory.h"

//------------------------Fabrica de Recursos-------------------------------
shared_ptr<Recursos> FactoryResources::crearInstancia(int t) {

	const int maxIntentos = 100;
	auto mapa = Enviroment::getInstancia()->getMapa();
	int newX, newY;

	for (int i = 0; i < maxIntentos; i++) {
		newX = rand() % mapa->getAncho();
		newY = rand() % mapa->getAlto();

		if (mapa->posValida(newX, newY) && !mapa->hayObjetoEnMapa(newX, newY)) {
			switch (t) {
			case 1:
				return make_shared<PlantaFlor>(newX, newY, 20);
			case 2:
				return make_shared<PlantaRosa>(newX, newY, 20);
			case 3:
				return make_shared<Meat>(newX, newY, 20);
			default:
				throw invalid_argument("Tipo de recurso desconocido: " + to_string(t));
			}
		}
	}
	throw runtime_error("No se encontro posicion valida para crear recurso.");
}

shared_ptr<Recursos> FactoryResources::crearRecursos() {

	auto mapa = Enviroment::getInstancia()->getMapa();
	int intentos = 0;
	const int maxIntentos = 50;

	while (intentos < maxIntentos) {
		int x = rand() % mapa->getAncho();
		int y = rand() % mapa->getAlto();

		if (mapa->posValida(x, y) && !mapa->hayObjetoEnMapa(x, y)) {
			int tipo = rand() % 3 + 1;
			shared_ptr<Recursos> recurso = FactoryResources::crearInstancia(tipo);
			recurso->setX(x);
			recurso->setY(y);
			Enviroment::getInstancia()->agregarRecurso(recurso);
			return recurso;
		}
		intentos++;
	}
	return nullptr;
}

shared_ptr<Recursos> FactoryResources::crearRecursosPorCan(int n) {

	auto mapa = Enviroment::getInstancia()->getMapa();
	int agregados = 0;
	int i = 0;
	const int maxIntentos = 100; // para evitar un bucle infinito
	const int maxRecursos = 5;

	if (n < 0 || n > maxRecursos) {
		cerr << "Error: Debe ser entre 0 y " << maxRecursos << "." << endl;
		return nullptr;
	}
	while (agregados < n && i < maxIntentos) {
		int x = rand() % mapa->getAncho();
		int y = rand() % mapa->getAlto();
		if (mapa->posValida(x, y) && !mapa->hayObjetoEnMapa(x, y)) {
			int tipo = rand() % 3 + 1;
			shared_ptr<Recursos> recurso = FactoryResources::crearInstancia(tipo);
			recurso->setX(x);
			recurso->setY(y);
			Enviroment::getInstancia()->agregarRecurso(recurso);
			agregados++;
		}
		i++;
	}
	if (agregados < n) {
		cerr << "Solo se pudieron agregar " << agregados << " recursos despues de " << i << " intentos." << endl;
	}
	return nullptr;
}


//-------------------Fabrica de Creaturas----------------------------

shared_ptr<Creatura> FactoryCreature::crearInstancia(int t) {

	if (Enviroment::getInstancia()->getMapa()->estaLleno()) {
		cerr << "[ERROR] No se puede reproducir: el mapa está lleno.\n";
		return nullptr;
	}

	auto mapa = Enviroment::getInstancia()->getMapa();
	int ancho = mapa->getAncho();
	int alto = mapa->getAlto();

	const int maxIntentos = 100;
	int newX, newY;
	shared_ptr<Estrategia> e1 = make_shared<EstrategiaMovimiento>();

	for (int i = 0; i < maxIntentos; i++) {
		newX = rand() % ancho;
		newY = rand() % alto;
	

		if (mapa->posValida(newX, newY) && !mapa->hayObjetoEnMapa(newX, newY)) {
			shared_ptr<Creatura> creatura = nullptr;

			switch (t) {
			case 1:
				creatura = make_shared<Herbivoro>(newX, newY, 100, 0, e1);
				break;
			case 2:
				creatura = make_shared<Carnivoro>(newX, newY, 100, 0, e1);
				break;
			case 3:
				creatura = make_shared<Omnivoro>(newX, newY, 100, 0, e1);
				break;
			default:
				throw invalid_argument("Tipo de creatura desconocido");
			}
			return creatura;
		}
	}
	//cerr<<("No se encontro posición valida para crear criatura.");
	return nullptr;
}

int FactoryCreature::etiquetaToTipo(const string& etiqueta) {

	if (etiqueta == "Herbivoro") return 1;
	if (etiqueta == "Carnivoro") return 2;
	if (etiqueta == "Omnivoro")return 3;

	throw std::invalid_argument("Etiqueta desconocida");
}

