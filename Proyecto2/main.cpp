#include <iostream>
#include <sstream>
#include "clases.h"

using namespace std;


int main() {

        // Obtener instancia del entorno
        Enviroment* env = Enviroment::getInstancia();

        // Crear un recurso manualmente
        shared_ptr<Observer> recurso1 = make_shared<Planta>(3, 4, 15); // x=3, y=4, energia=15

        // Agregar al mapa desde el entorno
        env->agregarRecurso(env->getMapa(), recurso1);

        // Mostrar el mapa (si implementaste mostrarMapa)
        cout << env->getMapa()->mostrarMapa();


	

    return 0;
}
