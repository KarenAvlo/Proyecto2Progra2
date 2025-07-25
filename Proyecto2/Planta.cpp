﻿/* -------------------------------------------------------------------+
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

#include "Planta.h"

PlantaFlor::PlantaFlor(int xx, int yy, int ee)
	:Recursos(xx, yy, ee)
{}

string PlantaFlor::toString() const 
{
	stringstream s;

	s << "_+_  E:" << EnergyValue; 

	return s.str();
}

string PlantaFlor::getEtiqueta() const
{ 
	return "Planta";
}

void PlantaFlor::guardarDatos(ofstream& archivo) const
{
	archivo << "PlantaFlor," << x << "," << y << "," << EnergyValue << "\n";
}

//-----Planta Rosa------
PlantaRosa::PlantaRosa(int xx, int yy, int ee)
	:Recursos(xx, yy, ee) {}


string PlantaRosa::toString() const 
{
	stringstream s;

	s << "_@_  E:" << EnergyValue;

	return s.str();
}

string PlantaRosa::getEtiqueta() const 
{ 
	return "Planta";
}

void PlantaRosa::guardarDatos(ofstream& archivo) const 
{
	archivo << "PlantaRosa," << x << "," << y << "," << EnergyValue << "\n"; 
}
