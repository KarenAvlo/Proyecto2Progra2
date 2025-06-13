/* -------------------------------------------------------------------+
*                                                                     |
* (c) 2025                                                            |
* EIF204 - Programación 2                                             |
* 1er ciclo 2025                                                      |
* NRC 41371 – Grupo 01                                                |
* Proyecto 2                                                          |
*                                                                     |
* 2-0816-0954; Avilés López, Karen Minards                            |
* 1-1709-0658; Elizondo Cascante, Cristhian                           |
* 1-19560437; Sánchez Bermúdez, Juan Pablo                            |
*                                                                     |
* versión 1.0.0, 12 - 06 - 2025                                       |
*                                                                     |
* --------------------------------------------------------------------+
*/
#include "Omnivoro.h"

Omnivoro::Omnivoro(int x, int y, int energia, int edad, shared_ptr<Estrategia> E)
	: Creatura(x, y, energia, edad, E) {}

string Omnivoro::toString() const 
{
	stringstream s;

	s << "O(" << x << "," << y << ") E:" << energia; // O de Omnivoro, sus coordenadas y respectiva energía

	return s.str();
}

string Omnivoro::getEtiqueta() const 
{
	return "Omnivoro";
}

void Omnivoro::alimentarse() 
{
	setEstrategia(make_shared<EstrategiaAlimentacionO>());

	if (Enviroment::getInstancia()->hayCarneCerca(shared_from_this()) || Enviroment::getInstancia()->hayPlantaCerca(shared_from_this())) {

		if (E) {

			E->EjecutarEstrategia(shared_from_this());
		}
	}
}

void Omnivoro::atacar() 
{
	if (Enviroment::getInstancia()->getCreaturaDebilCerca(shared_from_this())) {

		setEstrategia(make_shared<EstrategiaAtaqueO>());

		if (E) {

			E->EjecutarEstrategia(shared_from_this());
		}
	}
}

void Omnivoro::reproducirse() 
{
	if (Enviroment::getInstancia()->hayOmnivoroCerca(shared_from_this()) && !Enviroment::getInstancia()->getMapa()->estaLleno()) {

		setEstrategia(make_shared<EstrategiaReproduccion>());

		if (E) {

			E->EjecutarEstrategia(shared_from_this());
		}
	}
}

void Omnivoro::guardarDatos(ofstream& archivo) const 
{
	archivo << "Omnivoro," << x << "," << y << "," << energia << "," << edad << "\n";
}