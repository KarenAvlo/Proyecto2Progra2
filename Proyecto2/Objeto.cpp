#include "Objeto.h"

Objeto::Objeto(int xx, int yy):x(xx),y(yy){}

int Objeto::getX() { return x; }
int Objeto::getY() { return y; }
void Objeto::setX(int xx) { x = xx; }
void Objeto::setY(int yy) { y = yy; }

ostream& operator<<(ostream& out, const Objeto& obj) {
	out << obj.toString();
	return out;
}