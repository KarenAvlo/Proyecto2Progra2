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



void EstrategiaAlimentacionC::EjecutarEstrategia(shared_ptr<Creatura> c) {
	if (!c) return;

	shared_ptr<Meat> carne = Enviroment::getInstancia()->getCarneCerca(c);

	if (!carne) return;

	c->AumentarEnergia(20); //comer da 20pts de energía

	Enviroment::getInstancia()->eliminarCreatura(carne);

}

void EstrategiaAlimentacionH::EjecutarEstrategia(shared_ptr<Creatura> c) {

	shared_ptr<Recursos> alimento = Enviroment::getInstancia()->getPlantaCerca(c);

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


	shared_ptr<Recursos> alimento = Enviroment::getInstancia()->getPlantaCerca(c);

	if (alimento) { //alguna planta

		c->AumentarEnergia(20);

		Enviroment::getInstancia()->eliminarRecurso(static_pointer_cast<Objeto>(alimento));

		return;
	}


}
//-------------------------------------HERVIVORO--------------------------------------------
void EstrategiaAtaqueH::EjecutarEstrategia(shared_ptr<Creatura> c) {
	if (!c) return;

	shared_ptr<Creatura> presa = Enviroment::getInstancia()->getCreaturaFuerteCerca(c);
	if (!presa || presa == c) return;

	c->ReducirEnergia(10); 

	if (!presa->isDead()) {
		int d = rand() % (15) + 10;
		presa->ReducirEnergia(d);

		string tipoAtaque;

		if (d > 10) { tipoAtaque = " Fuerte"; }
		else { tipoAtaque = " Debil"; }
		
		cout << "H(" << c->getX() << "," << c->getY() << ")";
		cout << "::Se DEFENDIO de(" << presa->getX() << ", " << presa->getY() << ")" << endl;
		cout << "Ataque" << tipoAtaque << ", Inflige " << d << "% de danio." << endl;
		
	}

	if (presa->isDead()) {
		Enviroment::getInstancia()->eliminarCreatura(presa);
		shared_ptr<Meat> carne = make_shared<Meat>(presa->getX(), presa->getY(), 50);
		Enviroment::getInstancia()->agregarRecurso(carne);
	}
}



//-------------------------------------CARNIVORO--------------------------------------------
void EstrategiaAtaqueC::EjecutarEstrategia(shared_ptr<Creatura> c){

	if (!c) return;
	shared_ptr<Creatura> presa = Enviroment::getInstancia()->getCreaturaDebilCerca(c);

	if (!presa || presa == c) return;

	c->ReducirEnergia(15);

	if (!presa->isDead()) {

			int d = rand() % (50 - 25 + 1) + 25;

			presa->ReducirEnergia(d);

			string tipoAtaque;
			if (d > 30) { tipoAtaque = " Fuerte"; }
			else { tipoAtaque = " Debil"; }

			cout << "C(" << c->getX() << "," << c->getY() << ")";
			cout << "::ATACO a la creatura" << "(" << presa->getX() << ", " << presa->getY() << ")" << endl;
			cout << "Ataque" << tipoAtaque
				<< ", Inflige " << d << "% de danio." << endl;
			
	}

	if (presa->isDead()) { 

		Enviroment::getInstancia()->eliminarCreatura(presa); //eliminamos la creatura y luego se convierte a recurso Meat

		shared_ptr<Meat> carne = make_shared<Meat>(presa->getX(), presa->getY(), 50);

		Enviroment::getInstancia()->agregarRecurso(carne);
	}
}


//-------------------------------------OMNIVORO--------------------------------------------
void EstrategiaAtaqueO::EjecutarEstrategia(shared_ptr<Creatura> c){

	if (!c) return;
	shared_ptr<Creatura> presa = Enviroment::getInstancia()->getCreaturaDebilCerca(c);

	if (!presa || presa == c) return;

	c->ReducirEnergia(15);

	if (!presa->isDead()) {

	   int d= rand() % (25 - 15 + 1) + 15; // reduce entre un 15 a 25%

		presa->ReducirEnergia(d);

		string tipoAtaque;
		if (d > 20) { tipoAtaque = " Fuerte"; }
		else { tipoAtaque = " Debil"; }

		
		cout << "O(" << c->getX() << "," << c->getY() << ")";
		cout << "::ATACO a la creatura" << "(" << presa->getX() << ", " << presa->getY() << ")" << endl;
		cout << "Ataque" << tipoAtaque
			<< ", Inflige " << d << "% de danio." << endl;

	}

	if (presa->isDead()) {

		Enviroment::getInstancia()->eliminarCreatura(presa); //eliminamos la creatura y luego se convierte a recurso Meat

		shared_ptr<Meat> carne = make_shared<Meat>(presa->getX(), presa->getY(), 50);

		Enviroment::getInstancia()->agregarRecurso(carne);
	}
}


