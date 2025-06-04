#pragma once
#include "memory"
#include <typeinfo>
#include "Objeto.h"
#include <iomanip>

class Objeto;

class Mapa{

public:
	Mapa(int x = 0, int y = 0);
	virtual ~Mapa() = default;

	string mostrarMapa() const;

	int getAncho() const;
	int getAlto() const;

	// Métodos para manipular el mapa
	bool posValida(int, int);
	int espaciosLibres();  //para debug, muestra los espacios libres del mapa

	shared_ptr<Objeto> hayObjetoEnMapa(int x, int y);  //para evitar las colisiones

	/*bool agregarRecurso(int x, int y, shared_ptr<Objeto> recurso);

	bool agregarCreatura(int x, int y, shared_ptr<Objeto> criatura);*/

	bool agregarObjeto(int, int, shared_ptr<Objeto> loquesea);

	void colocarObjeto(int x, int y, shared_ptr<Objeto> obj);  //para el movimiento de las criaturas

	bool eliminarObjeto(int x, int y);

private:
	int ancho;
	int alto;
	unique_ptr<shared_ptr<Objeto>[]> filas;
	unique_ptr<shared_ptr<Objeto>* []>mapa;
};

