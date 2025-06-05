#include "Sistema.h"

Sistema::Sistema(){
	i= make_shared<Interfaz>();
}
Sistema::~Sistema(){
// la memoria se libera sola :)
}

void Sistema::visualMenuPrincipal(){
	cout << ("   ---[ Menu Principal ]---   ") << endl;
	cout << "[1] - Generar entorno aleatorio." << endl;
	cout << "[2] - Generar Entorno personalidado." << endl;
	cout << "[3] - Entorno Actual..." << endl;
	//aqui pienso que como solo hay un entorno a la vez, no se deberia modificar,
	//si se quiere modificar pienso que lo ideal seria matar el entorno actual y crear uno nuevo
	//para mantener la coerencia de un entorno por vez
	cout << "[4] - Submenu Reporte de Datos" << endl;
	cout << "[5] - Submenu Persistencia De Datos" << endl;

	cout << "[0] - Salir del sistema" << endl << endl;
}
void Sistema::visualGenerarAleatorio() {
	cout << ("   ---[ Generar aleatorio ]---   ") << endl;
	cout << "(1) - Generar." << endl;
	cout << "(2) - Ver entorno." << endl;
	cout << "[0] - Volver a Menu Principal" << endl << endl;
}

void Sistema::visualMenuCrearPersonalizado(){
	cout<<("   ---[ Submenu Generar Entorno Personalizado ]---   ")<<endl;
	cout << "(1) - Generar Creatura(s)" << endl;
	cout << "(2) - Generar niveles: AGUA/SOL (afecta a la regeneracion de recursos) " << endl;
	cout << "[0] - Volver a Menu Principal" << endl << endl;
	cout << "Ingrese la opcion: " << endl;
}

void Sistema::mostrarEntorno()
{
	i->mostrarEntorno();
}

void Sistema::ejecutarSimulacion(int tickTiempo)
{
	if (tickTiempo <= 0) {
		cerr << "El tick de tiempo debe ser un numero positivo." << endl;
		return;
	}
	Enviroment::getInstancia()->simularTickTiempo(tickTiempo);
	cout << "Simulacion ejecutada por " << tickTiempo << " ticks de tiempo." << endl;
	cout << "Mostrando el entorno actual:" << endl;
	cout << Enviroment::getInstancia()->getMapa()->mostrarMapa() << endl;
}

 void Sistema::visualsubmenuReportes(){
	 cout << ("   ---[ Submenu Reporte de Datos ]---   ") << endl;

	cout << "(1) - Reporte de Creaturas" << endl;
	cout << "(2) - Reporte de Recursos" << endl;
	cout << "[0] - Volver a Menu Principal" << endl << endl;
}

void Sistema::visualsubmenuPersistenciaDeDatos() {
	cout << ("   ---[ Submenu Persistencia De Datos ]---   ") << endl;
	
	 cout << "1 - Guardar Creaturas" << endl;
	 cout << "2 - Cargar Creaturas" << endl << endl;

	 cout << "3 - Guardar Recursos" << endl;
	 cout << "4 - Cargar Recursos" << endl << endl;

	 cout << "[0] - Volver a Menu Principal" << endl << endl;
}

// Lógica de los submenús:
void Sistema::mostrarMenuPrincipal() {
	int opcion = -1;
	int tickTiempo = 0;
	int iniciarSimulacion = 0;

	do {
		system("cls");
		visualMenuPrincipal();

		// Validar entrada
		while (!(cin >> opcion) || opcion < 0 || opcion > 5) {
			cin.clear();
			cin.ignore(1000, '\n');
			cerr << "Opcion invalida. Ingrese un numero entre 1 y 5 o 0: ";
		}

		system("cls");

		switch (opcion) {
		case 0:
			cout << "Salida exitosa..." << endl;
			break;

		case 1:
			// Generar entorno aleatorio
			visualGenerarAleatorio();
			cout << "\nPresione Enter para continuar...";
			cin.ignore();
			cin.get();
			break;

		case 2: {
			// Generar entorno personalizado
			int subopcion = -1;
			visualMenuCrearPersonalizado();
			while (!(cin >> subopcion) || subopcion < 0 || subopcion > 2) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Opcion invalida, ingrese 0 a 2: ";
			}

			if (subopcion == 1) {
				int tipo = 0;
				i->ingresarCreatura(tipo);
			}
			else if (subopcion == 2) {
				int sol = 0, agua = 0;
				i->ingresarRecurso(sol, agua);
			}

			cout << "\nPresione Enter para continuar...";
			cin.ignore();
			cin.get();
			break;
		}

		case 3: {
			//mostrar simulacion
			mostrarEntorno();
			cout << "Desea iniciar la simulacion? (1: Si, 0: No): " << endl;
			while (!(cin >> iniciarSimulacion) || (iniciarSimulacion != 0 && iniciarSimulacion != 1)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cerr << "Entrada invalida. Ingrese 0 o 1: ";
			}if (iniciarSimulacion == 1) {
				cout << "Ingrese los ticks de tiempo para ejecutar la simulacion: " << endl;
				while (!(cin >> tickTiempo) || tickTiempo < 0) {
					cin.clear();
					cin.ignore(1000, '\n');
					cerr << "Entrada invalida. Ingrese un numero positivo: ";
				}
				ejecutarSimulacion(tickTiempo);
				cout << "\nPresione Enter para continuar...";
				cin.ignore();
				cin.get();
			}
			else {
				cout << "Simulacion no iniciada, regresando..." << endl;
				cout << "\nPresione Enter para continuar...";
				cin.ignore();
				cin.get();
			}
		}break;

		case 4: {
			//reporte de datos
			mostrarSubmenuPersistenciaDeDatos();
			cout << "\nPresione Enter para continuar...";
			cin.ignore();
			cin.get();
		}break;

		case 5: {
			//persistencia de datos
			mostrarSubmenuReportes();
			cout << "\nPresione Enter para continuar...";
			cin.ignore();
			cin.get();
		}break;

		default: {
			cerr << "Opcion invalida. Ingrese un numero entre 0 y 5." << endl;
			cout << "\nPresione Enter para continuar...";
			cin.ignore();
			cin.get();
		}break;
		}
		} while (opcion != 0);
}

//por hacer, primero tengo que hacer cosas antes
void Sistema::mostrarSubmenuAleatorio() {
	int opcion;
	do {
		system("cls");
		visualGenerarAleatorio();

		while (!(cin >> opcion) || opcion < 0 || opcion > 2) {
			cin.clear();
			cin.ignore(1000, '\n');
			cerr << "Opcion invalida. Ingrese 0, 1 o 2: ";
		}
		system("cls");
		switch (opcion) {
		case 0:
			break;
		case 1:
			system("cls");
			i->generarAleatorio();
			/*cout << "\nPresione Enter para continuar...";
			cin.ignore();
			cin.get();*/
			break;
		case 2:
			system("cls");
			i->MostrarEntornoAndInteractions();
			/*cout << "\nPresione Enter para continuar...";
			cin.ignore();
			cin.get();*/
			break;
		}
	} while (opcion != 0);
}

void Sistema::mostrarMenuCrearPersonalizado()
{
	int opcion;
	int tipo = 0;
	int sol = 0;
	int agua = 0;
	do {
		system("cls");
		mostrarMenuCrearPersonalizado();

		while (!(cin >> opcion) || opcion < 0 || opcion > 2) {
			cin.clear();
			cin.ignore(1000, '\n');
			cerr << "Opcion invalida. Ingrese 0, 1 o 2: ";
		}
		switch (opcion) {
		case 1:
			cout << "Generar criaturas" << endl;
			while (!(cin >> tipo) || opcion < 1 || opcion >3)
			{
				i->ingresarCreatura(tipo);
			}
			break;
		case 2:
			cout << "Generar recursos" << endl;
			while (!(cin >> sol, agua) || agua < 0 || agua > 2 && sol < 0 || sol > 2)
			{
				i->ingresarRecurso(sol, agua);
			}
			cout << "\nPresione Enter para continuar...";
			cin.ignore();
			cin.get();
			break;
		}
	} while (opcion != 0);
}




void Sistema::mostrarSubmenuRegistroDatos(){
	int opcion;

	do {

		system("cls");
		visualMenuCrearPersonalizado();

		while (!(cin >> opcion) || opcion < 0 || opcion > 2) {
			cin.clear();
			cin.ignore(1000, '\n');
			cerr << "Opcion invalida. Ingrese 0, 1 o 2: ";
		}

		system("cls");

		switch (opcion) {

		case 0:
			break;

		case 1:
			system("cls");
			/*i->ingresarCreatura();*/
			break;

		case 2:
			system("cls");
			/*i->ingresarRecurso();*/
			break;
		}
	}   while (opcion != 0);
}

void Sistema::mostrarSubmenuReportes(){

	int opcion;

	do {

		system("cls");
		visualsubmenuReportes();

		while (!(cin >> opcion) || opcion < 0 || opcion > 2) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Opcion invalida. Ingrese 0, 1 o 2: ";
		}
	

		switch (opcion) {

		case 0:
			break;

		case 1:
			system("cls");
			i->MostrarReporteCreaturas();
			cout << "\nPresione Enter para continuar...";
			cin.ignore();
			cin.get();
			break;

		case 2:
			system("cls");
			i->MostrarReporteRecursos();
			cout << "\nPresione Enter para continuar...";
			cin.ignore();
			cin.get();
			break;
		}

	} while (opcion != 0);
}

void Sistema::mostrarSubmenuEntornoyInteracciones(){


}

void Sistema::mostrarSubmenuPersistenciaDeDatos() {
	int opcion;

	do {
		system("cls");
		visualsubmenuPersistenciaDeDatos();

		while (!(cin >> opcion) || opcion < 0 || opcion > 4) {  
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Opcion invalida, ingrese 0 a 4: ";
		}

		switch (opcion) {
		case 0: break;
		case 1:
			system("cls");
			i->GuardarCreaturas(); // no dejar que guarde si no hay creaturas
			system("pause");
			break;
		case 2:
			system("cls");
			i->CargarCreaturas(); // no cargar creaturas si esta vacio // carga raro, arreglar
			system("pause");
			break;
		case 3:
			system("cls");
			i->GuardarRecursos(); // falta implementar esto
			system("pause");
			break;
		case 4:
			system("cls");
			i->CargarRecursos(); // falta implementar esto
			system("pause");
			break;
		}
	} while (opcion != 0);
}
