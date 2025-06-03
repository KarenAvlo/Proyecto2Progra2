#pragma once
#include "Interfaz.h"

class Interfaz;

class Sistema{
public:
	// Creación y liberación de la interfaz:
	Sistema();
	~Sistema();

	// Lógica de los submenús:
	void mostrarMenuPrincipal();
	void mostrarSubmenuRegistroDatos();
	void mostrarSubmenuModificacionDatos();
	void mostrarSubmenuReportes();
	void mostrarSubmenuPersistenciaDeDatos();

private:
	shared_ptr<Interfaz> i;
};

