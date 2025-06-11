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

#include "Recursos.h"
#include "Creature.h"

Recursos::Recursos(int xx, int yy, int ee)
	:Objeto(xx, yy), EnergyValue(ee) {
}

Recursos::~Recursos(){}

string Recursos::getEtiqueta() const{
	return "_*_";
}

string Recursos::toString() const{
	return "_*_";
}


