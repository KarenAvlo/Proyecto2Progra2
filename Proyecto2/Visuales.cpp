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

	cout << "[1] - Generar entorno aleatorio." << endl;
	cout << "[2] - Generar Entorno personalidado." << endl;
	cout << "[3] - Modificacion de Datos" << endl;
	//aqui pienso que como solo hay un entorno a la vez, no se deberia modificar,
	//si se quiere modificar pienso que lo ideal seria matar el entorno actual y crear uno nuevo
	//para mantener la coerencia de un entorno por vez
	cout << "[4] - Submenu Reporte de Datos" << endl;
	cout << "[5] - Submenu Persistencia De Datos" << endl;

	cout << "[0] - Salir del sistema" << endl << endl;
}

static void visualGenerarAleatorio()
{
	generarTitulos("Generar aleatorio", "");

	cout << "(1) - Generar." << endl;
	cout << "(2) - Ver entorno." << endl;

	cout << "[0] - Volver a Menu Principal" << endl << endl;
}

static void visualGenerarPersonalizado()
{
	generarTitulos("Generar entorno personalizado", "");

	cout << "(1) - Ingresar tamanio entorno." << endl;
	cout << "(2) - Ingresar Criaturas." << endl;
	cout << "(3) - Nivel de agua." << endl;
	cout << "(4) - Nivel de sol." << endl;

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