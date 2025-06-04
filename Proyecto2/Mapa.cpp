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

int Mapa::getAncho() const
{
	return ancho;
}

int Mapa::getAlto() const
{
	return alto;
}

bool Mapa::posValida(int x, int y) {
	
	if (x < 0 || x >= ancho || y < 0 || y >= alto) {
		cerr << "Coordenadas fuera de los límites del mapa: (" << x << ", " << y << ")\n";
		return false;
	}
	return true;
}

shared_ptr<Objeto> Mapa::hayObjetoEnMapa(int x, int y)
{
	if (x < 0 || x >= ancho || y < 0 || y >= alto) {
		cerr << "Coordenadas fuera de los limites.\n";
		return nullptr;
	}
	return mapa[y][x]; // Retorna true si hay un objeto en las coordenadas dadas
}

bool Mapa::agregarObjeto(int x, int y, shared_ptr<Objeto> obj1){

	if (x < 0 || x >= ancho || y < 0 || y >= alto) {
		cerr << "Coordenadas fuera de rango." << endl;
		return false;
	}
	if (mapa[y][x] != nullptr) {
		cerr << "Ya hay un objeto en (" << x << ", " << y << ")." << endl;
		return false;
	}

	mapa[y][x] = obj1;
	return true;
}

void Mapa::colocarObjeto(int x, int y, shared_ptr<Objeto> obj){

		if (posValida(x, y)) {
			mapa[y][x] = obj;
		}
}


bool Mapa::eliminarObjeto(int x, int y) {
	if (posValida(x, y)) {
		if (mapa[y][x]) {
			mapa[y][x] = nullptr; // Elimina el objeto en las coordenadas dadas, pero Ojo no hay que borrar el obj que ya me paso
			return true;
		}
		else {
			cerr << "No hay un objeto en estas coordenadas.\n";
			return false;
		}
	}
	else {
		cerr << "Coordenadas fuera de los límites del mapa.\n";
		return false;
	}
}

