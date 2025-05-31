#include <iostream>
#include <sstream>
#include "clases.h"

using namespace std;


int main() {
  
    // Crear una criatura que cumple con los requisitos de reproducción
    shared_ptr<EstrategiaMovimiento> estrategiaMovimiento = make_shared<EstrategiaMovimiento>();
    shared_ptr<EstrategiaReproducción> estrategiaRepro = make_shared<EstrategiaReproducción>();


    shared_ptr<Creatura> hervivoro = make_shared<Hervivoro>(1, 1, 50, 25, estrategiaMovimiento, estrategiaRepro);

    Enviroment::getInstancia()->agregarCreatura(hervivoro);
    cout << "--------------Antes de reproducirse-----------" << endl;
   cout<< Enviroment::getInstancia()->getLista()->toString();

   hervivoro->reproducirse();

   cout << "--------------Despues de reproducirse-----------" << endl;

   cout << Enviroment::getInstancia()->getLista()->toString();

   cout << Enviroment::getInstancia()->getMapa()->mostrarMapa();

   Enviroment::getInstancia()->eliminarCreatura(hervivoro);
   cout << "----------después de la eliminación --------------" << endl;

   cout << Enviroment::getInstancia()->getLista()->toString();

   cout << Enviroment::getInstancia()->getMapa()->mostrarMapa();


    return 0;
}
