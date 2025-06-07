#pragma once
#include "Interfaz.h"

class Interfaz;

class Sistema{
public:
	// Creación y liberación de la interfaz:
	Sistema();
	~Sistema();

	static void visualMenuPrincipal();
	static void visualGenerarAleatorio();
	static void visualMenuCrearPersonalizado();
	static void visualsubmenuReportes();
	static void visualsubmenuPersistenciaDeDatos();

	// Lógica de los submenús:
	void mostrarMenuPrincipal();
	void mostrarSubmenuAleatorio();
	void mostrarEntorno();
	
	//void mostrarSubmenuRegistroDatos();
	void mostrarSubmenuReportes();
	void mostrarSubmenuPersistenciaDeDatos();

	//otro

    void ejecutarSimulacion(int tickTiempo);

private:
	shared_ptr<Interfaz> i;
};

