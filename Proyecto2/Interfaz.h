#pragma once
#include "clases.h"


class Interfaz{
public:
	Interfaz();
	~Interfaz();

	void generarAleatorio();
	void ingresarCreatura();
	void ingresarRecurso();

	void MostrarEntornoAndInteractions();

	void MostrarReporteCreaturas();
	void MostrarReporteRecursos();

	void GuardarCreaturas();
	void GuardarRecursos();

	void CargarCreaturas();
	void CargarRecursos();

};

