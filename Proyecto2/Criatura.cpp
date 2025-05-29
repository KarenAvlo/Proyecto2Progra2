#include "Criatura.h"

Criatura::Criatura(int x, int y, int energia) 
	: posX(x), posY(y), energia(energia) {}

Criatura::~Criatura() {}

void Criatura::update() {}

int Criatura::getEnergia() const {
	return energia;
}

void Criatura::setEnergia(int e) {
	if (e >= 0 && e <= MAX_ENERGIA) {
		energia = e;
	}
	else {
		throw std::out_of_range("Energía fuera de rango");
	}
}

int Criatura::getPosX() const {
	return posX;
}

int Criatura::getPosY() const {
	return posY;
}

void Criatura::setPosX(int x) {
	posX = x;
}

void Criatura::setPosY(int y) {
	posY = y;
}

string Criatura::toString() const {
	stringstream ss;
	ss << "Criatura en posición (" << posX << ", " << posY << ") con energia: " << energia << endl;
	return ss.str();
}



