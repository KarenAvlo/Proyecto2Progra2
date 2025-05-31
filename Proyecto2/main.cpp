#include <iostream>
#include <sstream>
#include "clases.h"

using namespace std;


int main() {
    EstrategiaMovimiento* em = new EstrategiaMovimiento();
    Creatura* cre = new Creatura(1, 2, 20, 20, em);

    cout << "Estado inicial: " << cre->toString() << endl;

   

    return 0;
}
