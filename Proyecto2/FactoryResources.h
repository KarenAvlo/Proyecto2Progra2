#pragma once
#include "Recursos.h"
#include "Criatura.h"
#include "Observer.h"
#include <memory>

class FactoryResources{
public:
	static shared_ptr<Observer> crearInstancia(int, int, int, int); //para pasarle coordenadas y nivel de agua

	static shared_ptr<Observer> crearInstancia(int, int, int); //para pasarle coordenadas y energia
};

