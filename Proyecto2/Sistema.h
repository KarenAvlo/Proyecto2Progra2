#pragma once
#include "Interfaz.h"

class Interfaz;

class Sistema{
	public:
		// Creaci�n y liberaci�n de la interfaz:
		Sistema();
		~Sistema();

		static void visualMenuPrincipal();
		static void visualMenuCrearPersonalizado();
		static void visualsubmenuReportes();
		static void visualsubmenuPersistenciaDeDatos();

		// L�gica de los submen�s:
		void mostrarMenuPrincipal();
		void mostrarEntorno();
	
		//void mostrarSubmenuRegistroDatos();
		void mostrarSubmenuReportes();
		void mostrarSubmenuPersistenciaDeDatos();

		//otro

		void ejecutarSimulacion(int tickTiempo);

	private:
		shared_ptr<Interfaz> i;
};

