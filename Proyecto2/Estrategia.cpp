#include "Factory.h"

void EstrategiaReproduccion::EjecutarEstrategia(shared_ptr<Creatura> c) {

		//la creatura debe de tener una edad de 5 y energía de 50 para reproducirse
    if (c->getEdad() > 5 && c->getEnergia() >50){ 
	
		//se crea una creatura por defecto..
		int tipo = FactoryCreature::etiquetaToTipo(c->getEtiqueta());

		//llamamos a factory para crear una creatura
		shared_ptr<Creatura>cre = FactoryCreature::crearInstancia(tipo);

		// luego se introduce al ambiente...
		//pues lo que se hace es crear una creatura de su mismo tipo

		cout << "Criatura creada por reproduccion en (" << cre->getX() << "," << cre->getY() << ")\n";

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


void EstrategiaAlimentacionC::EjecutarEstrategia(shared_ptr<Creatura> c) {
	if (!c) return;

	// si hay carne cerca, bríndela
	shared_ptr<Meat> carne = Enviroment::getInstancia()->getCarneCerca(c);

	//Sino, no haga nada
	if (!carne) return;

	c->AumentarEnergia(20); //comer da 50pts de energía, puesto que eso brinda cada carne

	Enviroment::getInstancia()->eliminarRecurso(carne); // la eliminamos pues ya ha sido consumida

}

void EstrategiaAlimentacionH::EjecutarEstrategia(shared_ptr<Creatura> c) {

	// si hay planta cerca, bríndela
	shared_ptr<Recursos> alimento = Enviroment::getInstancia()->getPlantaCerca(c);

	//Sino, no haga nada
	if (!alimento) return;

	c->AumentarEnergia(20); //comer da 20pts de energía, puesto que eso brinda cada recurso

	Enviroment::getInstancia()->eliminarRecurso(alimento);

	cout << "H(" << c->getX() << "," << c->getY() << "), devore a Planta(" << alimento->getX() << "," << alimento->getY() << ")" << endl;
}

void EstrategiaAlimentacionO::EjecutarEstrategia(shared_ptr<Creatura> c) {

	
	//el Omnivoro come ambas cosas carne y plantas

	shared_ptr<Meat> presa = Enviroment::getInstancia()->getCarneCerca(c);


	if (presa) { // el caso de alguna carne

		c->AumentarEnergia(20); //comer carne 20pts de energía

		Enviroment::getInstancia()->eliminarRecurso(presa); //eliminamos el recurso del mapa y la lista del enviroment

		cout << "0(" << c->getX() << "," << c->getY() << "), devore a M(" << presa->getX() << "," << presa->getY() << ")"<<endl;

		return;
	}


	shared_ptr<Recursos> alimento = Enviroment::getInstancia()->getPlantaCerca(c);

	if (alimento) { //alguna planta

		c->AumentarEnergia(20); //comer plantas da 20pts de energía

		Enviroment::getInstancia()->eliminarRecurso(static_pointer_cast<Objeto>(alimento));  //eliminamos el recurso del mapa y la lista del enviroment

		cout << "0(" << c->getX() << "," << c->getY() << "), devore a Planta(" << alimento->getX() << "," << alimento->getY() << ")"<<endl;

		return;
	}


}
//-------------------------------------HERVIVORO--------------------------------------------
void EstrategiaAtaqueH::EjecutarEstrategia(shared_ptr<Creatura> c) {
	if (!c) return;

	//la idea de esta estrategia, es que si una creatura fuerte ataca a un hervivoro, entonces que el hervivoro se defienda

	shared_ptr<Creatura> presa = Enviroment::getInstancia()->getCreaturaFuerteCerca(c);
	if (!presa || presa == c) return;

	c->ReducirEnergia(10); 

	if (!presa->isDead()) {
		int d = rand() % (15) + 10; // el daño va de %10-%15 por ser hervivoro
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

			int d = rand() % (50 - 25 + 1) + 25; // el daño del carnivoro es el mas fuerte de %25-%50

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
	//buscamos la presa cerca
	shared_ptr<Creatura> presa = Enviroment::getInstancia()->getCreaturaDebilCerca(c);

	if (!presa || presa == c) return;

	c->ReducirEnergia(15); // esta accion baja un 15 de energía

	if (!presa->isDead()) { // si la presa sigue vivan

	   int d= rand() % (25 - 15 + 1) + 15; // reduce entre un 15 a 25%

		presa->ReducirEnergia(d);

		//definimos el ataque con respecto a la cantidad de daño
		string tipoAtaque;
		if (d > 20) { tipoAtaque = " Fuerte"; }
		else { tipoAtaque = " Debil"; }

		//Mensaje de confimacion de la accion
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


