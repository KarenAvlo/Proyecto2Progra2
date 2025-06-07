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
	cout << "[2] - Generar Entorno personalizado." << endl;
	cout << "[3] - Mostrar Entorno Actual" << endl;


	//aqui pienso que como solo hay un entorno a la vez, no se deberia modificar,
	//si se quiere modificar pienso que lo ideal seria matar el entorno actual y crear uno nuevo
	//para mantener la coerencia de un entorno por vez


	cout << "[4] - Submenu Reporte de Datos" << endl;
	cout << "[5] - Submenu Persistencia De Datos" << endl;
	cout << "[0] - Salir del sistema" << endl << endl;
	cout << "Ingrese la opcion: " << endl;
}
void Sistema::visualGenerarAleatorio() {
	cout << ("   ---[ Generar aleatorio ]---   ") << endl;
	cout << "(1) - Generar." << endl;
	cout << "[0] - Volver a Menu Principal" << endl << endl;
	cout << "Ingrese la opcion: " << endl;
}

void Sistema::visualMenuCrearPersonalizado(){
	cout<<("   ---[ Submenu Generar Entorno Personalizado ]---   ")<<endl;
	cout << "(1) - Generar Creaturas" << endl;
	cout << "(2) - Generar Recursos" << endl;
	cout << "(3) - Generar Recursos Aleatorios " << endl;
	cout << "[0] - Volver a Menu Principal" << endl << endl;
	cout << "Ingrese la opcion: " << endl;
}

void Sistema::mostrarEntorno(){
	i->mostrarEntorno();
}

void Sistema::ejecutarSimulacion(int tickTiempo){
	i->ejecutarSimulacion(tickTiempo);
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


				//porfavor esto, ponerlo dentro de la interfaz, no aqui
				cout << "\nPresione Enter para continuar...";
				cin.ignore();
				cin.get();
				break;

			case 2: {
				// Generar entorno personalizado
				visualMenuCrearPersonalizado();
				i->entornoPersonalizado();
				break;
			}

			case 3: {
				//mostrar simulacion
				mostrarEntorno();
				i->iniciarSimulacion();
				break;
			}

			case 4: {
				//reporte de datos
				mostrarSubmenuReportes();
				break;
			}

			case 5: {
				//persistencia de datos
				mostrarSubmenuPersistenciaDeDatos();
				break;
			}

			default: {
				cerr << "Opcion invalida. Ingrese un numero entre 0 y 5." << endl;
				cout << "\nPresione Enter para continuar...";
				cin.ignore();
				cin.get();
				break;
			}
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
		}
	} while (opcion != 0);
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
			break;

		case 2:
			system("cls");
			i->MostrarReporteRecursos();
			break;
		}

	} while (opcion != 0);
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
