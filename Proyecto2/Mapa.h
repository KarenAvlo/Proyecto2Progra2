#pragma once
#include "memory"
#include <typeinfo>
#include "Objeto.h"
#include <iomanip>

class Objeto;

class Mapa {

	public:

		Mapa(int x = 0, int y = 0);
		virtual ~Mapa() = default;

		string mostrarMapa() const;

		int getAncho() const;
		int getAlto() const;

		// M�todos para manipular el mapa
		bool posValida(int, int);

		bool hayObjetoEnMapa(int x, int y) const;

		bool agregarObjeto(int, int, shared_ptr<Objeto> loquesea);  //agrega cualquier tipo al mapa

		bool colocarObjeto(int x, int y, shared_ptr<Objeto> obj);  //para el movimiento de las criaturas

		bool eliminarObjeto(int x, int y);// elimina la pos, anterior de un objeto

		void limpiarCeldas();

		bool estaLleno() const;

	private:

		int ancho;
		int alto;

		unique_ptr<shared_ptr<Objeto>[]> filas;
		unique_ptr<shared_ptr<Objeto>* []>mapa;
};

