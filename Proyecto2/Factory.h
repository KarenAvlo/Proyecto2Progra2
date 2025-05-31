#pragma once
#include "Recursos.h"
#include "Creature.h"
#include "Hervivoro.h"
#include "Estrategia.h"
#include <memory>
using namespace std;

class FactoryResources{
public:
	static shared_ptr<Recursos> crearInstancia(int); 
};

class FactoryCreature {
public:
	static shared_ptr<Creatura> crearInstancia(int);
	static int etiquetaToTipo(const string& etiqueta);


};



