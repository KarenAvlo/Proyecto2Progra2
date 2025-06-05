#include "Factory.h"

void EstrategiaReproduccion::EjecutarEstrategia(shared_ptr<Creatura> c) {

		//se crea una creatura por defecto...
    if (c->getEdad() > 20 && c->getEnergia() >90) {
		int tipo = FactoryCreature::etiquetaToTipo(c->getEtiqueta());

		//llamamos a factory para crear una creatura
		shared_ptr<Creatura>cre = FactoryCreature::crearInstancia(tipo);

		// luego se introduce al ambiente...
		//pues lo que se hace es crear una creatura de su mismo tipo

		cout << "Criatura creada para reproducción en (" << cre->getX() << "," << cre->getY() << ")\n";

		Enviroment::getInstancia()->agregarCreatura(cre);
	}
	/*else {
		cout << "No cumple requisitos para reproducirse (edad > 20, energía > 90)\n";
	}*/
}

void EstrategiaMovimiento::EjecutarEstrategia(shared_ptr<Creatura> c) {
	shared_ptr<Mapa> mapa = Enviroment::getInstancia()->getMapa();

	// Intentar hasta 10 veces moverse aleatoriamente
	for (int i = 0; i < 10; ++i) {
		int dx = (rand() % 3) - 1; // -1, 0, 1
		int dy = (rand() % 3) - 1;

		// Omitir quedarse en el mismo lugar
		if (dx == 0 && dy == 0) continue;

		int nuevaX = c->getX() + dx;
		int nuevaY = c->getY() + dy;

		// Si es válida y libre, mover
		if (nuevaX >= 0 && nuevaX < Enviroment::getInstancia()->getAnchoMapa() && nuevaY >= 0 && nuevaY < Enviroment::getInstancia()->getAltoMapa()
			&& !mapa->hayObjetoEnMapa(nuevaX, nuevaY)) {

			mapa->eliminarObjeto(c->getX(), c->getY());
			c->setX(nuevaX);
			c->setY(nuevaY);
			mapa->colocarObjeto(nuevaX, nuevaY, c);
			return;
		}
	}

}

void EstrategiaAtaque::EjecutarEstrategia(shared_ptr<Creatura> c) {

	if (!c) return;

	shared_ptr<Creatura> presa = Enviroment::getInstancia()->getCreaturaDebilCerca(c);
	if (!presa || presa == c) return;

	c->ReducirEnergia(15);
	presa->ReducirEnergia(50);

	if (presa->isDead()) { // si la presa está muerta

		Enviroment::getInstancia()->eliminarCreatura(presa); //eliminamos la creatura y luego se convierte a recurso Meat

		shared_ptr<Meat> carne = make_shared<Meat>(presa->getX(), presa->getY(), 50);

		Enviroment::getInstancia()->agregarRecurso(carne);
	}

}

void EstrategiaDefensa::EjecutarEstrategia(shared_ptr<Creatura> c) {
	// me falta

}


void EstrategiaAlimentacionC::EjecutarEstrategia(shared_ptr<Creatura> c) {
	if (!c) return;

	shared_ptr<Meat> carne = Enviroment::getInstancia()->getCarneCerca(c);

	if (!carne) return;

	c->AumentarEnergia(20); //comer da 20pts de energía

	Enviroment::getInstancia()->eliminarCreatura(carne);

}

void EstrategiaAlimentacionH::EjecutarEstrategia(shared_ptr<Creatura> c) {

	shared_ptr<Planta> alimento = Enviroment::getInstancia()->getPlantaCerca(c);

	if (!alimento) return;

	c->AumentarEnergia(20);

	Enviroment::getInstancia()->eliminarRecurso(alimento);

}

void EstrategiaAlimentacionO::EjecutarEstrategia(shared_ptr<Creatura> c) {

	//el Omnivoro come ambas cosas carne y plantas
	shared_ptr<Creatura> presa = Enviroment::getInstancia()->getCreaturaDebilCerca(c);

	//la creatura debil solo son Hervivoros y Omnivoros, por lo cual los carnpivoros ganarían por encima de omnivoros

	if (presa) { // el caso de alguna creatura

		c->AumentarEnergia(20); //comer da 20pts de energía

		Enviroment::getInstancia()->eliminarCreatura(presa);

		return;
	}


	shared_ptr<Planta> alimento = Enviroment::getInstancia()->getPlantaCerca(c);

	if (alimento) { //alguna planta

		c->AumentarEnergia(20);

		Enviroment::getInstancia()->eliminarRecurso(alimento);

		return;
	}


}