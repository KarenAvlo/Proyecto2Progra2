#pragma once
#include "memory"
#include <typeinfo>
#include "Objeto.h"

class Objeto;

class Mapa{

public:
	Mapa(int x = 0, int y = 0);
	virtual ~Mapa() = default;

	string mostrarMapa() const;

	// Métodos para manipular el mapa

	bool agregarRecurso(int x, int y, shared_ptr<Objeto> recurso);

	bool agregarCreatura(int x, int y, shared_ptr<Objeto> criatura);

private:
	int ancho;
	int alto;
	unique_ptr<shared_ptr<Objeto>[]> filas;
	unique_ptr<shared_ptr<Objeto>* []>mapa;
};

