#include "Sistema.h"


Sistema::Sistema(){
	i= make_shared<Interfaz>();
}
Sistema::~Sistema(){
// la memoria se libera sola :)
}


void Sistema::visualMenuPrincipal(){
	cout<<"    ---[ Menu Principal ]---   "<<endl;

	cout << "[1] - Submenu Registro de Datos" << endl;
	cout << "[2] - Entorno e Interacciones" << endl;
	cout << "[3] - Submenu Reporte de Datos" << endl;
	cout << "[4] - Submenu Persistencia De Datos" << endl;

	cout << "[0] - Salir del sistema" << endl << endl;
}

void Sistema::visualsubmenuRegistro(){

	cout<<("   ---[ Submenu Registro de Datos ]---   ")<<endl;

	cout << "(1) - Ingresar Creatura" << endl;
	cout << "(2) - Ingresar Recurso" << endl;

	cout << "[0] - Volver a Menu Principal" << endl << endl;
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
void Sistema::mostrarMenuPrincipal(){
	int opcion;

	do {
		system("cls");
		visualMenuPrincipal();

		while (!(cin >> opcion) || opcion < 0 || opcion > 4) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Opción inválida. Ingrese 0, 1 o 2: ";
		}
		//un try catch por aqui

		system("cls");

		switch (opcion) {

		case 0:
			system("cls");
			cout << "Salida exitosa..." << endl;
			break;

		case 1:
			mostrarSubmenuRegistroDatos();
			break;

		case 2:
			mostrarSubmenuEntornoyInteracciones();
			break;

		case 3:
			mostrarSubmenuReportes();
			break;

		case 4:
			mostrarSubmenuPersistenciaDeDatos();
			break;
		}

	} while (opcion != 0);

}
void Sistema::mostrarSubmenuRegistroDatos(){
	int opcion;

	do {

		system("cls");
		visualsubmenuRegistro();

		while (!(cin >> opcion) || opcion < 0 || opcion > 2) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Opción inválida. Ingrese 0, 1 o 2: ";
		}

		system("cls");

		switch (opcion) {

		case 0:
			break;

		case 1:
			system("cls");
			i->ingresarCreatura();
			break;

		case 2:
			system("cls");
			i->ingresarRecurso();
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
			cout << "Opción inválida. Ingrese 0, 1 o 2: ";
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

void Sistema::mostrarSubmenuPersistenciaDeDatos(){

	int opcion;

	do {

		system("cls");
		visualsubmenuPersistenciaDeDatos();

		while (!(cin >> opcion) || opcion < 0 || opcion > 2) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Opción inválida. Ingrese 0, 1 o 2: ";
		}

		switch (opcion) {
		case 0:
			break;

		case 1:
			system("cls");
			i->GuardarCreaturas();
			break;

		case 2:
			system("cls");
			i->CargarCreaturas();
			break;

		case 3:
			system("cls");
			i->GuardarRecursos();
			break;

		case 4:
			system("cls");
			i->CargarRecursos();
			break;

		} 

	} while (opcion != 0);
}
