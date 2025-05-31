#include "Estrategia.h"
#include "Creature.h"

void EstrategiaReproducción::EjecutarEstrategia(Creatura* c) {




}

void EstrategiaMovimiento::EjecutarEstrategia(Creatura* c) {
    int dx = (std::rand() % 3) - 1; // -1, 0 o 1
    int dy = (std::rand() % 3) - 1;
    int nuevaX = c->getX() + dx;
    int nuevaY = c->getY() + dy;

    c->setX(nuevaX);
    c->setY(nuevaY);
    cout << "Se mueve a (" << nuevaX << ", " << nuevaY << ")\n";
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
//
//}
//
//void EstrategiaAlimentacionH::EjecutarEstrategia(Creatura* c) {
//
//}
