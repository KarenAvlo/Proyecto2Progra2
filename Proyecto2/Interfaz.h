#pragma once
#include "clases.h"

class Interfaz {

	public:

		Interfaz();
		~Interfaz();

		void ingresarCreatura();
		void ingresarRecurso();
		void ingresarRecursoAleatorios();
		void mostrarEntorno();

		void ejecutarSimulacion(int tickTiempo);
		void entornoPersonalizado();
		void iniciarSimulacion();
		void limpiarEntorno();

		void MostrarReporteCreaturas();
		void MostrarReporteRecursos();

		void GuardarCreaturas();
		void GuardarRecursos();

		void CargarCreaturas();
		void CargarRecursos();

};

