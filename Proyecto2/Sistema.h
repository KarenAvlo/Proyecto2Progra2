#pragma once
#include "Interfaz.h"

class Interfaz;

class Sistema{
public:
	// Creaci�n y liberaci�n de la interfaz:
	Sistema();
	~Sistema();

	static void visualMenuPrincipal();
	static void visualGenerarAleatorio();
	static void visualMenuCrearPersonalizado();
	static void visualsubmenuReportes();
	static void visualsubmenuPersistenciaDeDatos();

	// L�gica de los submen�s:
	void mostrarMenuPrincipal();
	void mostrarSubmenuAleatorio();
	void mostrarMenuCrearPersonalizado();
	void mostrarSubmenuRegistroDatos();
	void mostrarSubmenuReportes();
	void mostrarSubmenuEntornoyInteracciones();
	void mostrarSubmenuPersistenciaDeDatos();

private:
	shared_ptr<Interfaz> i;
};

