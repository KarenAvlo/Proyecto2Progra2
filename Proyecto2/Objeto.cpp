#include "Objeto.h"

Objeto::Objeto(int xx, int yy):x(xx),y(yy){}

int Objeto::getX() const { return x; }
int Objeto::getY() const { return y; }
void Objeto::setX(int xx) { x = xx; }
void Objeto::setY(int yy) { y = yy; }

bool Objeto:: operator==(const Objeto& otro) const {
	return x == otro.x && y == otro.y && getEtiqueta() == otro.getEtiqueta();

}

ostream& operator<<(ostream& out, const Objeto& obj) {
	out << obj.toString();
	return out;
}