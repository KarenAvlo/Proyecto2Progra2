#include <iostream>
#include "visuales.h"

using namespace std;

static void generarTitulos(string submenu, string tipo){
	if (!tipo.empty()) {
		cout << '\t' << submenu << " - " << tipo;
	}

	else {
		cout << '\t' << "- " << submenu << " -";
	}

	cout << endl << endl;
}

static void visualMenuPrincipal()
{
	generarTitulos("---[ Menu Principal ]---", "");

	cout << "[1] - Submenu Registro de Datos" << endl;
	cout << "[2] - Submenu Modificacion de Datos" << endl;

	cout << "[3] - Submenu Reporte de Datos" << endl;
	cout << "[4] - Submenu Persistencia De Datos" << endl;

	cout << "[0] - Salir del sistema" << endl << endl;
}

static void visualsubmenuRegistro()
{
	generarTitulos("Submenu Registro de Datos", "");

	cout << "(1) - Ingresar Material" << endl;
	cout << "(2) - Ingresar Usuarios" << endl;
	cout << "(3) - Ingresar Solicitud Prestamo" << endl;
	cout << "(4) - Devolver Prestamo" << endl;

	cout << "[0] - Volver a Menu Principal" << endl << endl;
}

static void visualsubmenuModificacion()
{
	generarTitulos("Submenu Modificacion Datos", "");

	cout << "(1) - Modificar Datos Material" << endl;
	cout << "(2) - Modificar Datos Usuario" << endl;

	cout << "[0] - Volver a Menu Principal" << endl << endl;
}

static void visualsubmenuReportes()
{
	generarTitulos("Submenu Reporte de Datos", "");

	cout << "(1) - Reporte de Inventario Materiales" << endl;
	cout << "(2) - Reporte de Usuarios" << endl;
	cout << "(3) - Reporte de Materiales en Prestamo (general)" << endl;
	cout << "(4) - Reporte de Materiales en Prestamo (por tipo)" << endl;
	cout << "(5) - Reporte de Materiales en Prestamo (por usuario)" << endl;

	cout << "[0] - Volver a Menu Principal" << endl << endl;
}

static void visualsubmenuPersistenciaDeDatos()
{
	generarTitulos("Submenu Persistencia De Datos", "");

	cout << "1 - Guardar Materiales" << endl;
	cout << "2 - Cargar Materiales" << endl << endl;

	cout << "3 - Guardar Usuarios" << endl;
	cout << "4 - Cargar Usuarios" << endl << endl;

	cout << "5 - Guardar Prestamos" << endl;
	cout << "6 - Cargar Prestamos" << endl << endl;

	cout << "[0] - Volver a Menu Principal" << endl << endl;
}