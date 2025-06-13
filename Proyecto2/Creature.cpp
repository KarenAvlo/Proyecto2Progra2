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
#include "Creature.h"

Creatura::Creatura()
{
	x = 0;
	y = 0;
	energia = MAX_ENERGIA;
	edad = 10;
	E = nullptr;
}

Creatura::Creatura(int xx, int yy, int ener, int age, shared_ptr<Estrategia> e):
	Objeto(xx, yy), energia(ener), edad(age),E(e){}


Creatura::~Creatura() {}


void Creatura::atacar() 
{
	cout << "ATACANDO" << endl;
}

void Creatura::reproducirse() 
{

	setEstrategia(make_shared <EstrategiaReproduccion>());

	if (E) {
		E->EjecutarEstrategia(shared_from_this());
	}
}

void Creatura::AumentarEnergia(int e) 
{
	if (e >= 0 && e <= MAX_ENERGIA) {
		energia += e;
	}

	else {
		throw std::out_of_range("energia negativa");
	}
}

void Creatura::ReducirEnergia(int e) 
{
	if (e >= 0 && e <= MAX_ENERGIA) {
		energia -= e;
	}

	else {
		throw std::out_of_range("energia fuera de rango");
	}
}

string Creatura::toString() const 
{
	stringstream s;

	s << "( " << x << ", " << y << ")" << endl;
	s << "Energia: " << energia << endl;
	s << "Edad: " << edad << endl;

	return s.str();
}

string Creatura::getEtiqueta() const 
{
	return "Criatura";
}

bool Creatura::isDead() const 
{
	if (energia <= 0) {
		return true;
	}

	return false;
}

void Creatura::AumentarEdad() 
{
	edad++;
}

void Creatura::moverse() 
{
	//se cambia la estrategia para cada cosa
	setEstrategia(make_shared < EstrategiaMovimiento>());
	
	//el moverse utiliza 5 de energia
	if (energia >= 5) {
		ReducirEnergia(5);
		E->EjecutarEstrategia(shared_from_this());
	}
}


void Creatura::setEstrategia(shared_ptr<Estrategia> ee) 
{
	E = ee;
}

int Creatura::getEnergia() { return energia; }

int Creatura::getEdad() { return edad; }










