#include <iostream>
#include <sstream>
#include "clases.h"

using namespace std;


int main() {
  
    // Crear una criatura que cumple con los requisitos de reproducci�n
    shared_ptr<EstrategiaMovimiento> estrategiaMovimiento = make_shared<EstrategiaMovimiento>();
    shared_ptr<EstrategiaReproducci�n> estrategiaRepro = make_shared<EstrategiaReproducci�n>();


    shared_ptr<Creatura> hervivoro = make_shared<Hervivoro>(1, 1, 50, 25, estrategiaMovimiento, estrategiaRepro);

    Enviroment::getInstancia()->agregarCreatura(hervivoro);
   cout<< Enviroment::getInstancia()->getLista()->toString();

   hervivoro->reproducirse();

   cout << Enviroment::getInstancia()->getLista()->toString();






    return 0;
}
