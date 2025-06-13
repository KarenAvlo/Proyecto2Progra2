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

#include "Objeto.h"

Objeto::Objeto(int xx, int yy):x(xx),y(yy){}

int Objeto::getX() const { return x; }

int Objeto::getY() const { return y; }

void Objeto::setX(int xx) { x = xx; }

void Objeto::setY(int yy) { y = yy; }

bool Objeto:: operator==(const Objeto& otro) const 
{
	return x == otro.x && y == otro.y && getEtiqueta() == otro.getEtiqueta();
}

ostream& operator<<(ostream& out, const Objeto& obj) 
{
	out << obj.toString();

	return out;
}