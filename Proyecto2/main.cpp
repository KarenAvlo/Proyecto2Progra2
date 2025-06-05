#include <iostream>
#include <sstream>
#include "clases.h"
#include <cstdlib>
#include <windows.h>

using namespace std;


int main() {
	SetConsoleOutputCP(CP_UTF8); // intentando que se vean simbolos especiales en la consola

	srand(time(0));
	shared_ptr<Sistema> sistema = make_shared<Sistema>();
	sistema->mostrarMenuPrincipal();
	
    return 0;
}
