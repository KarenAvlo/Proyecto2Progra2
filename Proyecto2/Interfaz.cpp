#include "Interfaz.h"

Interfaz::Interfaz(){}
Interfaz::~Interfaz(){}

void Interfaz::ingresarCreatura(){
	int opcion = 0;
	int tipo = 0;

	do {
		cout << "   ---Ingresar Creatura---   " << endl;

		cout << "Seleccione el tipo de Creatura (1:Hervivoro , 2: Carnivoro, 3:Omnivoro). ";
		cin >> tipo;

		if (cin.fail()) {
			cin.clear();                // Limpia el error
			cin.ignore(1000, '\n');     // Ignora entrada inválida hasta el salto de línea
			cout << "Entrada invalida, por favor ingrese un numero." << endl;
			continue;
		}

		if (tipo < 1 || tipo > 3) {
			cout << "Tipo inválido. Intente de nuevo." << endl;
			continue;
		}

		try {
			shared_ptr<Creatura> nueva = FactoryCreature::crearInstancia(tipo);
			Enviroment::getInstancia()->agregarCreatura(nueva);
			cout << "Creatura agregada exitosamente " << nueva->toString() << endl;
		}
		catch (const std::exception& e) {
			cout << "Error al crear la creatura: " << e.what() << endl;
			continue;
		}

		cout << endl;
		cout << "Mostrando los objetos del entorno" << endl;
		cout<<Enviroment::getInstancia()->getLista()->toString();

	
			cout << "Desea agregar otra creatura? (1: Sí, 0: No): ";
			cin >> opcion;

			while (cin.fail() || (opcion != 0 && opcion != 1)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Opcion invalida, ingrese 0 o 1: ";
				cin >> opcion;
			}

	} while (opcion != 0); // si el usuario marca 0 sale del ciclo

}
void Interfaz::ingresarRecurso() {
	int opcion = 0;
	int tipo = 0;


	do {
		cout << "   ---Ingresar Recurso---   " << endl;

		cout << "Seleccione el tipo de Recurso (1: Agua , 2: Planta, 3: Meat). ";
		cin >> tipo;

		if (cin.fail()) {
			cin.clear();                // Limpia el error
			cin.ignore(1000, '\n');     // Ignora entrada inválida hasta el salto de línea
			cout << "Entrada invalida, por favor ingrese un numero." << endl;
			continue;
		}

		if (tipo < 1 || tipo > 3) {
			cout << "Tipo inválido. Intente de nuevo." << endl;
			continue;
		}

		try {
			shared_ptr<Recursos> nueva = FactoryResources::crearInstancia(tipo);
			Enviroment::getInstancia()->agregarRecurso(nueva);
			cout << "Recurso agregado exitosamente " << nueva->toString() << endl;
		}
		catch (const std::exception& e) {
			cout << "Error al crear el Recurso: " << e.what() << endl;
			continue;
		}

		cout << endl;
		cout << "Mostrando los objetos del entorno" << endl;
		cout << Enviroment::getInstancia()->getLista()->toString();


		cout << "Desea agregar otro Recurso? (1: Sí, 0: No): ";
		cin >> opcion;

		while (cin.fail() || (opcion != 0 && opcion != 1)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Opcion invalida, ingrese 0 o 1: ";
			cin >> opcion;
		}

	} while (opcion != 0); // si el usuario marca 0 sale del ciclo
}


void Interfaz::MostrarEntornoAndInteractions(){}

void Interfaz::MostrarReporteCreaturas(){
	

	cout<< Enviroment::getInstancia()->mostrarCreaturas()->toString() << endl;
}
void Interfaz::MostrarReporteRecursos(){
	cout << Enviroment::getInstancia()->mostrarCreaturas() << endl;
}

void Interfaz::GuardarCreaturas(){}
void Interfaz::GuardarRecursos(){}

void Interfaz::CargarCreaturas(){}
void Interfaz::CargarRecursos(){}