#include <iostream>
#include <sstream>
#include "clases.h"

using namespace std;


int main() {
    shared_ptr<EstrategiaMovimiento> em = make_shared<EstrategiaMovimiento>();
    shared_ptr<EstrategiaReproducción> er = make_shared<EstrategiaReproducción>();
    shared_ptr<EstrategiaAlimentacion> ea = make_shared<EstrategiaAlimentacionC>();

    shared_ptr<EstrategiaAlimentacion> ea1 = make_shared<EstrategiaAlimentacionC>();

    shared_ptr<Carnívoro> ca = make_shared<Carnívoro>(5, 5, 50, 13, em, er,ea);
    cout << *ca;


    shared_ptr<Hervivoro> her = make_shared<Hervivoro>(5, 6, 20, 2, em, er, ea1);
    cout << *her;

    Enviroment::getInstancia()->agregarCreatura(ca);
    Enviroment::getInstancia()->agregarCreatura(her);

    cout << Enviroment::getInstancia()->getMapa()->mostrarMapa();

    ca->alimentarse();

    cout << *ca;

    cout << Enviroment::getInstancia()->getMapa()->mostrarMapa();

    return 0;
}
