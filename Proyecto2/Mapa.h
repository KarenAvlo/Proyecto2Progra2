#pragma once
#include "objectBase.h"
#include "Observer.h"
#include <typeinfo>

class Observer;

class Mapa
{
public:
	Mapa(int x = 0, int y = 0);
	virtual ~Mapa();

	string mostrarMapa() const;
	// Métodos para manipular el mapa
	bool agregarRecurso(int x, int y, shared_ptr<Observer> recurso);
	bool agregarCriatura(int x, int y, shared_ptr<Observer> criatura);

private:
	int ancho;
	int alto;
	shared_ptr<Observer>** mapa; 
};

