#include "Factory.h"

void EstrategiaReproducción::EjecutarEstrategia(Creatura* c) {

    if (c->getEdad() > 20 && c->getEnergia() > 10) {

        //se crea una creatura por defecto...

        int tipo = FactoryCreature::etiquetaToTipo(c->getEtiqueta());

        //llamamos a factory para crear una creatura
        shared_ptr<Creatura>cre = FactoryCreature::crearInstancia(tipo);

        // luego se introduce al ambiente...
        //pues lo que se hace es crear una creatura de su mismo tipo
        Enviroment::getInstancia()->agregarCreatura(cre);
    }
}

void EstrategiaMovimiento::EjecutarEstrategia(Creatura* c) {
	shared_ptr<Mapa> destino = Enviroment::getInstancia()->getMapa();
    // Verificar si hay objetos en el mapa
    int dx = (rand() % 3) - 1; // -1, 0 o 1
    int dy = (rand() % 3) - 1;
    int nuevaX = c->getX() + dx;
    int nuevaY = c->getY() + dy;

	if (destino->posValida() && !destino->hayObjetoEnMapa(nuevaX, nuevaY)) {
		// Mover la criatura a la nueva posición
		c->setX(nuevaX);
		c->setY(nuevaY);
	}
	else {
		//habira que implementar un mensaje de error con simbologia
		cout << " error (" << nuevaX << ", " << nuevaY << ").\n";
	}
}
   
//void EstrategiaAtaque::EjecutarEstrategia(Creatura* c) {
//
//}
//
//void EstrategiaDefensa ::EjecutarEstrategia(Creatura* c) {
//
//}


void EstrategiaAlimentacionC::EjecutarEstrategia(Creatura* c) {
    if (Enviroment::getInstancia()->hayCreaturaDebilCerca(c)) {

        shared_ptr<Creatura> presa = Enviroment::getInstancia()->getCreaturaDebilCerca(c);

        c->AumentarEnergia(20); //comer da 20pts de energía

        Enviroment::getInstancia()->eliminarCreatura(presa);
    }
}


void EstrategiaAlimentacionH::EjecutarEstrategia(Creatura* c) {

}
