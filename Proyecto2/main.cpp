#include <iostream>
#include <sstream>
#include "clases.h"

using namespace std;


int main() {
  
        // Obtener la instancia singleton del entorno
        Enviroment* env = Enviroment::getInstancia();

        // Crear una planta en (5, 5)
        shared_ptr<Planta> planta1 = make_shared<Planta>(5, 5);

        // Crear un hervivoro en (7, 6) - a una distancia ~2.24 de la planta (dentro de 3)
        shared_ptr<Hervivoro> herv1 = make_shared<Hervivoro>(7, 6, 10, 1, nullptr);

        // Agregar la planta al entorno
        env->agregarRecurso(planta1);

        // Agregar el hervivoro al entorno (aunque no es necesario para esta prueba)
        env->agregarCreatura(herv1);

        cout << *planta1 << endl;
        cout << "----------------" << endl;

        cout << env->getLista()->toString() << endl;


        // Probar si hay planta cerca del hervivoro
       /* bool hayPlanta = env->hayPlantaCerca(herv1.get());

        cout << "¿Hay planta cerca del hervivoro? " << (hayPlanta ? "Sí" : "No") << endl;*/

    return 0;
}
