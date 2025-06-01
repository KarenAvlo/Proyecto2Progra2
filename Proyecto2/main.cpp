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
    cout << endl;

    shared_ptr<Hervivoro> her = make_shared<Hervivoro>(5, 6, 20, 2, em, er, ea1);
    cout << *her;
    cout << endl;

    Enviroment::getInstancia()->agregarCreatura(ca);
    Enviroment::getInstancia()->agregarCreatura(her);

    cout << Enviroment::getInstancia()->getMapa()->mostrarMapa();
    cout << endl;
    cout << "---------------------------------------" << endl;

    ca->alimentarse();


    cout << *ca;
    cout << endl;

    ca->moverse();


    cout << Enviroment::getInstancia()->getMapa()->mostrarMapa();

    system("cls");

	//primeras pruebas
	/*cout << "---------------------------------------" << endl;

	cout << "Simulando el entorno..." << endl;
	Enviroment::getInstancia()->simularTiempo(10);
	cout << "---------------------------------------" << endl;
	cout << Enviroment::getInstancia()->getMapa()->mostrarMapa();
	cout << endl;
	cout << "---------------------------------------" << endl;
	cout << "Estado final de las criaturas:" << endl;
	for (auto it = Enviroment::getInstancia()->getLista()->begin(); it != Enviroment::getInstancia()->getLista()->end(); ++it) {
		shared_ptr<Objeto> obj = *it;
		shared_ptr<Creatura> criatura = dynamic_pointer_cast<Creatura>(obj);
		if (criatura) {
			cout << *criatura << endl;
		}
	}
	cout << "---------------------------------------" << endl;
	cout << "Estado final del entorno:" << endl;
	cout << Enviroment::getInstancia()->toString() << endl;
	cout << "---------------------------------------" << endl;
	cout << "Estado final del mapa:" << endl;
	cout << Enviroment::getInstancia()->getMapa()->mostrarMapa() << endl;

	cout << "---------------------------------------" << endl;
	cout << "Fin de la simulacion." << endl;*/

    return 0;
}
