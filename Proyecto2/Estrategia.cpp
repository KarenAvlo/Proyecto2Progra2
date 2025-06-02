#include "Factory.h"

void EstrategiaReproduccion::EjecutarEstrategia(shared_ptr<Creatura> c) {

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

void EstrategiaMovimiento::EjecutarEstrategia(shared_ptr<Creatura> c) {
	shared_ptr<Mapa> destino = Enviroment::getInstancia()->getMapa();
    int dx = (rand() % 3) - 1; // -1, 0 o 1
    int dy = (rand() % 3) - 1;
    int nuevaX = c->getX() + dx;
    int nuevaY = c->getY() + dy;

    if (destino->posValida(nuevaX, nuevaY) && destino->hayObjetoEnMapa(nuevaX, nuevaY) == nullptr) {
        //para mover la criatura de pos
		destino->eliminarObjeto(c->getX(), c->getY()); // Eliminar la criatura de su posición actual
		c->setX(nuevaX);
		c->setY(nuevaY);
		destino->colocarObjeto(nuevaX, nuevaY, c); // Colocar la criatura en la nueva posición
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

//
//void EstrategiaAlimentacionC::EjecutarEstrategia(Creatura* c) {
//    if (Enviroment::getInstancia()->hayCreaturaDebilCerca(c)) {
//
//        shared_ptr<Creatura> presa = Enviroment::getInstancia()->getCreaturaDebilCerca(c);
//
//        c->AumentarEnergia(20); //comer da 20pts de energía
//
//        Enviroment::getInstancia()->eliminarCreatura(presa);
//    }
//}
//
//
//void EstrategiaAlimentacionH::EjecutarEstrategia(Creatura* c) {
//
//}

void EstrategiaAlimentacionC::EjecutarEstrategia(shared_ptr<Creatura> c)
{
            shared_ptr<Creatura> presa = Enviroment::getInstancia()->getCreaturaDebilCerca(c);

            if (!presa) return;
    
            c->AumentarEnergia(20); //comer da 20pts de energía
    
            Enviroment::getInstancia()->eliminarCreatura(presa);

}

void EstrategiaAlimentacionH::EjecutarEstrategia(shared_ptr<Creatura> c)
{

}
