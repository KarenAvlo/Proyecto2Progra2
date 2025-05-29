#include "Mapa.h"

Mapa::Mapa(int x, int y) : ancho(x), alto(y) {
	mapa = new shared_ptr<Observer>* [alto];
	for (int i = 0; i < alto; i++) {
		mapa[i] = new shared_ptr<Observer>[ancho];
	}
}

Mapa::~Mapa() {
	for (int i = 0; i < alto; i++) {
		delete[] mapa[i];
	}
	delete[] mapa;
}

string Mapa::mostrarMapa() const
{
	stringstream ss;
	for (int i = 0; i < alto; i++) {
		for (int j = 0; j < ancho; j++) {
			if (mapa[i][j]) {
				ss << "[ X ]"; 
			}
			else {
				ss << "[   ]"; 
			}
		}
		ss << endl;
	}
	return ss.str();
}

bool Mapa::agregarRecurso(int x, int y, shared_ptr<Observer> recurso)
{
	if (x < 0 || x >= ancho || y < 0 || y >= alto) {
		cout << "Coordenadas fuera de los limites del mapa." << endl;
		return false;
	}
	if (mapa[y][x]) {
		cout << "Ya hay un recurso o criatura en estas coordenadas." << endl;
		return false;
	}
	mapa[y][x] = recurso;
	recurso->setPosX(x);
	recurso->setPosY(y);
	return true;
}

bool Mapa::agregarCriatura(int x, int y, shared_ptr<Observer> criatura)
{
	if (x < 0 || x >= ancho || y < 0 || y >= alto) {
		cout << "Coordenadas fuera de los limites del mapa." << endl;
		return false;
	}
	if (mapa[y][x]) {
		cout << "Ya hay un recurso o criatura en estas coordenadas." << endl;
		return false;
	}
	mapa[y][x] = criatura;
	criatura->setPosX(x);
	criatura->setPosY(y);
	return true;
}

