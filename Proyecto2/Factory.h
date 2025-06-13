#pragma once

#include "clases.h"
#include <memory>

using namespace std;

class FactoryResources {

	public:

		static shared_ptr<Recursos> crearInstancia(int);  
		static shared_ptr<Recursos> crearRecursos();
		static shared_ptr<Recursos> crearRecursosPorCan(int n);
};

class FactoryCreature {

	public:

		static shared_ptr<Creatura> crearInstancia(int);
		static int etiquetaToTipo(const string& etiqueta);
};



