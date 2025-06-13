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
* versión 1.0.0, 09 - 06 - 2025                                       |
*                                                                     |
* --------------------------------------------------------------------+
*/


#include "Carnivoro.h"

Carnivoro::Carnivoro(int x, int  y, int energia, int edad, shared_ptr<Estrategia> E):
	Creatura(x, y, energia, edad,E) {}


string Carnivoro::toString() const 
{
	stringstream s;
	s << "C(" << x << "," << y << ") E:" << energia; // C de carnivoro, sus coordenadas y respectiva energía
	return s.str();
}

string Carnivoro::getEtiqueta() const 
{
	return "Carnivoro";
}

void Carnivoro::atacar() 
{
	//si hay creatura debil cerca, entonces ataque

	if (Enviroment::getInstancia()->getCreaturaDebilCerca(shared_from_this())) {
		setEstrategia(make_shared<EstrategiaAtaqueC>());

		if (E) {
			E->EjecutarEstrategia(shared_from_this());
		}
	}
}

void Carnivoro::reproducirse() 
{

	if (Enviroment::getInstancia()->hayCarnivoroCerca(shared_from_this()) && !Enviroment::getInstancia()->getMapa()->estaLleno()) {
		setEstrategia(make_shared<EstrategiaReproduccion>());
		if (E) {
			E->EjecutarEstrategia(shared_from_this());
		}
	}
}

void Carnivoro::alimentarse() 
{
	setEstrategia(make_shared <EstrategiaAlimentacionC>());

	//si hay carne cerca, comasela
	if (Enviroment::getInstancia()->hayCarneCerca(shared_from_this())) {
		if (E) {
			E->EjecutarEstrategia(shared_from_this());
		}
	}
}

void Carnivoro::guardarDatos(ofstream& archivo) const 
{
	archivo << "Carnivoro," << x << "," << y << "," << energia << "," << edad << "\n";
}