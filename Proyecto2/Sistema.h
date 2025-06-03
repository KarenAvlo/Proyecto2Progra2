#pragma once
#include "Interfaz.h"

class Interfaz;

class Sistema{
public:
	// Creaci�n y liberaci�n de la interfaz:
	Sistema();
	~Sistema();

	// L�gica de los submen�s:
	void mostrarMenuPrincipal();
	void mostrarSubmenuRegistroDatos();
	void mostrarSubmenuModificacionDatos();
	void mostrarSubmenuReportes();
	void mostrarSubmenuPersistenciaDeDatos();

private:
	shared_ptr<Interfaz> i;
};

