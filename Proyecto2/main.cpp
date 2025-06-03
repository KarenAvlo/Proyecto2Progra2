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



	//PROBLEMA CON LAS POSICIONES DE LAS CRIATURAS
        Enviroment& env = *Enviroment::getInstancia();

        // Crear estrategias
        shared_ptr<Estrategia> em = make_shared<EstrategiaMovimiento>();
        

        // Crear criaturas
        shared_ptr<Carnívoro> ca = make_shared<Carnívoro>(1, 1, 100, 13, em);
        shared_ptr<Hervivoro> her = make_shared<Hervivoro>(0, 4, 100, 2, em);

        shared_ptr<Hervivoro> her2 = make_shared<Hervivoro>(4, 2, 100, 2, em);//este hervivoro desaparece xd
		shared_ptr<Planta> planta = make_shared<Planta>(5, 3, 10); // Crear una planta para el entorno

        shared_ptr<Carnívoro> ca2 = make_shared<Carnívoro>(7,9, 100, 13, em);
        shared_ptr<Omnivoro> omn = make_shared<Omnivoro>(6,8, 100, 2, em);


        cout << *ca << endl;
        cout << *her << endl;

        // Agregar al ambiente
        env.agregarCreatura(ca);
        env.agregarCreatura(her);
        env.agregarCreatura(her2);

		env.agregarRecurso(planta); // Agregar la planta al entorno

        env.agregarCreatura(ca2);
        env.agregarCreatura(omn);

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

       
		env.simularTickTiempo(1); // Simular un tick de tiempo
        cout << env.getMapa()->mostrarMapa();
        cout << "---------------------------------------" << endl;
      

    return 0;
}
