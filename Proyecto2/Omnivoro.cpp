#include "Omnivoro.h"


Omnivoro::Omnivoro(int x, int y, int energia, int edad, shared_ptr<Estrategia> E, shared_ptr<EstrategiaAtaque> E2) :
	Creatura(x, y, energia, edad, E, E2) {
	E2 = make_shared<EstrategiaAtaqueO>(); // Estrategia de ataque loli
}

string Omnivoro::toString() const {
	stringstream s;
	s << "O(" << x << "," << y << ") E:" << energia; // O de Omnivoro, sus coordenadas y respectiva energía
	return s.str();
}

string Omnivoro::getEtiqueta() const {
	return "Omnivoro";
}

void Omnivoro::alimentarse() {
	setEstrategia(make_shared<EstrategiaAlimentacionO>());

	if (E) {
		E->EjecutarEstrategia(shared_from_this());
	}
}

void Omnivoro::atacar(Creatura& objetivo) {
	// los omnívoros pueden atacar a cualquier criatura
	if (E2 && !objetivo.isDead()) {
		for (int i = 0; i < 2 && !objetivo.isDead(); i++) {
			int d = E2->calcularDanio();
			objetivo.recibirDanio(d);
			cout << "Ataque " << (i + 1) << " con " << E2->getTipoAtaque()
				<< " inflige " << d << " de danio." << endl;
		}
	}
}

void Omnivoro::setEstrategiaAtaque(shared_ptr<EstrategiaAtaque> estrategia)
{
	E2 = estrategia;
}

void Omnivoro::recibirDanio(int danio) {
	energia -= danio;
	if (energia < 0) energia = 0; // Evitar energía negativa
}

void Omnivoro::guardarDatos(std::ofstream& archivo) const {
	archivo << "Carnivoro," << getX() << "," << getY() << "," << energia << "," << edad << "\n";
}