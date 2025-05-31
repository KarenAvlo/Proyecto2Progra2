#include "Mapa.h"

//Mapa::Mapa(int x, int y) : ancho(x), alto(y) {
//	// Crear array de filas (punteros a columnas)
//	filas =make_unique<shared_ptr<Objeto>[]>(alto * ancho);
//
//	// Crear array de punteros a filas
//	mapa = make_unique<shared_ptr<Objeto>*[]>(alto);
//
//	// Inicializar punteros a filas
//	for (int i = 0; i < alto; ++i) {
//		mapa[i] = &filas[i * ancho];
//	}
//}
//
//Mapa::~Mapa() {}
//
//string Mapa::mostrarMapa() const {
//	stringstream ss;
//	for (int i = 0; i < alto; ++i) {
//		for (int j = 0; j < ancho; ++j) {
//			if (mapa[i][j]) {
//				ss << "[ " << mapa[i][j]->getEtiqueta() << " ]";
//			}
//			else {
//				ss << "[   ]";
//			}
//		}
//		ss << '\n';
//	}
//	return ss.str();
//}
//
//
//bool Mapa::agregarRecurso(int x, int y, std::shared_ptr<Objeto> recurso) {
//	if (x < 0 || x >= ancho || y < 0 || y >= alto) {
//		std::cerr << "Coordenadas fuera de los límites del mapa.\n";
//		return false;
//	}
//	if (mapa[y][x]) {
//		std::cerr << "Ya hay un objeto en estas coordenadas.\n";
//		return false;
//	}
//
//	mapa[y][x] = recurso;
//	recurso->setX(x);
//	recurso->setY(y);
//	return true;
//}
//
//bool Mapa::agregarCriatura(int x, int y, shared_ptr<Objeto> criatura)
//{
//	if (x < 0 || x >= ancho || y < 0 || y >= alto) {
//		cout << "Coordenadas fuera de los limites del mapa." << endl;
//		return false;
//	}
//	if (mapa[y][x]) {
//		cout << "Ya hay un recurso o criatura en estas coordenadas." << endl;
//		return false;
//	}
//	mapa[y][x] = criatura;
//	criatura->setX(x);
//	criatura->setY(y);
//	return true;
//}

