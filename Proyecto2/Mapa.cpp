#include "Mapa.h"

Mapa::Mapa(int x, int y) : ancho(x), alto(y) {
	// Crear array de filas (punteros a columnas)
	filas =make_unique<shared_ptr<Objeto>[]>(alto * ancho);

	// Crear array de punteros a filas
	mapa = make_unique<shared_ptr<Objeto>*[]>(alto);

	// Inicializar punteros a filas
	for (int i = 0; i < alto; ++i) {
		mapa[i] = &filas[i * ancho];
	}
}

string Mapa::mostrarMapa() const {
	stringstream ss;
	const int anchoCelda = 15;

	for (int i = 0; i < alto; ++i) {
		for (int j = 0; j < ancho; ++j) {
			string contenido = " ";

			if (mapa[i][j]) {
				contenido = mapa[i][j]->toString();
			}

			// Asegurar que el contenido tenga siempre el mismo ancho
			ss << "[ " << setw(anchoCelda - 2) << left << contenido << "]";
		}
		ss << "\n";
	}

	return ss.str();
}


bool Mapa::posValida()
{
	if (ancho <= 0 || alto <= 0) {
		std::cerr << "El mapa no tiene dimensiones válidas.\n";
		return false;
	}
	return true; // Retorna true si las dimensiones del mapa son válidas
}

shared_ptr<Objeto> Mapa::hayObjetoEnMapa(int x, int y)
{
	if (x < 0 || x >= ancho || y < 0 || y >= alto) {
		std::cerr << "Coordenadas fuera de los limites.\n";
		return nullptr;
	}
	return mapa[y][x]; // Retorna true si hay un objeto en las coordenadas dadas
}

bool Mapa::agregarRecurso(int x, int y, std::shared_ptr<Objeto> recurso) {
	if (x < 0 || x >= ancho || y < 0 || y >= alto) {
		std::cerr << "Coordenadas fuera de los límites del mapa.\n";
		return false;
	}
	if (mapa[y][x]) {
		std::cerr << "Ya hay un objeto en estas coordenadas.\n";
		return false;
	}

	mapa[y][x] = recurso;
	recurso->setX(x);
	recurso->setY(y);
	return true;
}

bool Mapa::agregarCreatura(int x, int y, shared_ptr<Objeto> criatura){
	if (x < 0 || x >= ancho || y < 0 || y >= alto) {
		cout << "Coordenadas fuera de los limites del mapa." << endl;
		return false;
	}
	if (mapa[y][x]) {
		cout << "Ya hay un recurso o criatura en estas coordenadas." << endl;
		return false;
	}
	mapa[y][x] = criatura;
	criatura->setX(x);
	criatura->setY(y);
	return true;
}

bool Mapa::eliminarCreatura(int x, int y) {
	if (x < 0 || x >= ancho || y < 0 || y >= alto) {
		cout << "Coordenadas fuera de los limites del mapa." << endl;
		return false;
	}
	if (!mapa[y][x]) {
		cout << "No hay criatura en esas coordenadas para eliminar." << endl;
		return false;
	}
	mapa[y][x] = nullptr;  // Eliminar la criatura (shared_ptr queda en nullptr)
	return true;
}

