#include <iostream>
#include <sstream>
#include "clases.h"

using namespace std;


int main() {
  /*  shared_ptr<EstrategiaMovimiento> em = make_shared<EstrategiaMovimiento>();
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


    cout << Enviroment::getInstancia()->getMapa()->mostrarMapa();*/

	/*Enviroment& env = *Enviroment::getInstancia();

    shared_ptr<EstrategiaMovimiento> em = make_shared<EstrategiaMovimiento>();
    shared_ptr<EstrategiaReproduccion> er = make_shared<EstrategiaReproduccion>();
    shared_ptr<EstrategiaAlimentacion> ea = make_shared<EstrategiaAlimentacionC>();
    shared_ptr<EstrategiaAlimentacion> ea1 = make_shared<EstrategiaAlimentacionC>();

    shared_ptr<Carnívoro> ca = make_shared<Carnívoro>(5, 5, 50, 13, em, er, ea);
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

    env.setClima(1);
    env.setEstacion("Primavera");


    int segundos;
    cout << "Ingrese la cantidad de segundos a simular: ";
    cin >> segundos;

    env.simularTiempo(segundos);*/


	//PROBLEMA CON LAS POSICIONES DE LAS CRIATURAS
        Enviroment& env = *Enviroment::getInstancia();

        // Crear estrategias
        shared_ptr<EstrategiaMovimiento> em = make_shared<EstrategiaMovimiento>();
        shared_ptr<EstrategiaReproduccion> er = make_shared<EstrategiaReproduccion>();
        shared_ptr<EstrategiaAlimentacion> ea = make_shared<EstrategiaAlimentacionC>();
        shared_ptr<EstrategiaAlimentacion> ea1 = make_shared<EstrategiaAlimentacionC>();

        // Crear criaturas
        shared_ptr<Carnívoro> ca = make_shared<Carnívoro>(5, 5, 50, 13, em, er, ea);
        shared_ptr<Hervivoro> her = make_shared<Hervivoro>(5, 6, 20, 2, em, er, ea1);

        cout << *ca << endl;
        cout << *her << endl;

        // Agregar al ambiente
        env.agregarCreatura(ca);
        env.agregarCreatura(her);

        // Configurar entorno
        env.setClima(1);
        env.setEstacion("Primavera");

        // Mostrar estado inicial
        cout << "MAPA INICIAL:" << endl;
        cout << env.getMapa()->mostrarMapa();
        cout << "---------------------------------------" << endl;

        // Ciclos de simulación
        int segundos;
        cout << "Ingrese la cantidad de segundos a simular: ";
        cin >> segundos;

        for (int i = 0; i < segundos; i++) {
            env.simularTiempo(1); // un ciclo por segundo
            cout << "MAPA TRAS SEGUNDO " << (i + 1) << ":\n";
            cout << env.getMapa()->mostrarMapa();
            cout << "---------------------------------------" << endl;
        }

    return 0;
}
