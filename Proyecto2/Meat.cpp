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
#include "Meat.h"

Meat::Meat(int xx, int yy, int ee) 
	:Recursos(xx, yy, ee) {}


string Meat::getEtiqueta() const 
{
	return "Carne";
}


string Meat::toString() const 
{
	stringstream s;

	s << "M(" << x << "," << y << ") E:" << EnergyValue; // M de Meat, sus coordenadas y respectiva energía

	return s.str();
}

void Meat::guardarDatos(ofstream& archivo) const 
{ 
	archivo << "Meat," << x << "," << y << "," << EnergyValue << "\n"; 
}