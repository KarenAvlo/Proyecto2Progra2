#include "Interfaz.h"
#include "visuales.h"
#include "utilitarios.h"


Interfaz::Interfaz(){}
Interfaz::~Interfaz(){}

void Interfaz::ingresarCreatura(){
	int opcion = 0;
	int regresar = 0;
	int tipo = 0;

	do {
		cout << "=============Ingresar Creatura================" << endl;

		cout << "Digite 0 para regresar o 1 para continuar." << endl;
		cin>> regresar;
		/*int regresar = obtenerOpcion(0, 1);*/

		if (regresar == 0) {
			break;  // Si elige regresar, salimos del ciclo
		}

		cout << "Seleccione el tipo de Creatura (1:Hervivoro , 2: Carnivoro, 3:Omnivoro). ";
		cin >> tipo;

	/*	int tipo = obtenerOpcion(1, 3); cout << endl;*/

		cout << "Digite 0 para regresar o 1 para continuar." << endl;
		cin >> regresar;
		/*regresar = obtenerOpcion(0, 1);*/

		if (regresar == 0) {
			break;  // Si elige regresar, salimos del ciclo
		}

		//creamos una instancia con el factory
		shared_ptr<Creatura> nueva = FactoryCreature::crearInstancia(tipo);

		Enviroment::getInstancia()->agregarCreatura(nueva);

		cout<<"Creatura agregada exitosamente(" << nueva->getX() << ", " << nueva->getY() << ")." << endl;

		cout << "Desea agregar otra creatura? (1: Sí, 0: No): ";
		opcion = obtenerOpcion(0, 1);

	} while (opcion != 0); // si el usuario marca 0 sale del ciclo

}
void Interfaz::ingresarRecurso(){}

void Interfaz::MostrarEntornoAndInteractions(){}

void Interfaz::MostrarReporteCreaturas(){}
void Interfaz::MostrarReporteRecursos(){}

void Interfaz::GuardarCreaturas(){}
void Interfaz::GuardarRecursos(){}

void Interfaz::CargarCreaturas(){}
void Interfaz::CargarRecursos(){}