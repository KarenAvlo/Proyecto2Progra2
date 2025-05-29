#include "Creature.h"

Creatura::Creatura(int x, int y, int energia) 
	: Observer(x,y), energia(energia) { }

Creatura::~Creatura() {}

void Creatura::update() {}

int Creatura::getEnergia() const {
	return energia;
}

void Creatura::setEnergia(int e) {
	if (e >= 0 && e <= MAX_ENERGIA) {
		energia = e;
	}
	else {
		throw std::out_of_range("Energía fuera de rango");
	}
}

//int Creatura::getPosX() const {
//	return posX;
//}
//
//int Creatura::getPosY() const {
//	return posY;
//}
//
//void Creatura::setPosX(int x) {
//	posX = x;
//}
//
//void Creatura::setPosY(int y) {
//	posY = y;
//}

string Creatura::toString() const {
	stringstream ss;
	ss << "Criatura en posición (" << posX << ", " << posY << ") con energia: " << energia << endl;
	return ss.str();
}



