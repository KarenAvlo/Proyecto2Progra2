#include "Carnivoro.h"

Carnivoro::Carnivoro(int x, int  y , int energia , int edad , shared_ptr<Estrategia> E, shared_ptr<EstrategiaAtaque> E2):
	Creatura(x, y, energia, edad,E, E2) {
	E2 = make_shared<EstrategiaAtaqueC>(); // Estrategia de ataque por defecto
}


string Carnivoro::toString() const {
	stringstream s;
	s << "C(" << x << "," << y << ") E:" << energia; // C de carnivoro, sus coordenadas y respectiva energía
	return s.str();
}

string Carnivoro::getEtiqueta() const {
	return "Carnivoro";
}


void Carnivoro::reproducirse() {
	if (Enviroment::getInstancia()->hayCarnivoroCerca(shared_from_this())) {
		//si hay un animal de su mismo tipo, entonces reproduzcase


		setEstrategia(make_shared<EstrategiaReproduccion>());
		if (E) {
			E->EjecutarEstrategia(shared_from_this());
		}
	}

}

void Carnivoro::alimentarse() {
	setEstrategia(make_shared <EstrategiaAlimentacionC>());

	if (E) {
		E->EjecutarEstrategia(shared_from_this());
	}
}


///*setEstrategia(make_shared <EstrategiaAtaque>());
//if (energia >= 15) {
//	if (E) {
//		E->EjecutarEstrategia(shared_from_this());
//	}
//}*/
void Carnivoro::atacar(Creatura& objetivo) {

	if (E2 && !objetivo.isDead()) {
		for (int i = 0; i < 2 && !objetivo.isDead(); i++) {
			int d = E2->calcularDanio();
			objetivo.recibirDanio(d);
			cout << "Ataque " << (i + 1) << " con " << E2->getTipoAtaque()
				<< " inflige " << d << " de danio." << endl;
		}
	}
}

void Carnivoro::setEstrategiaAtaque(shared_ptr<EstrategiaAtaque> estrategia)
{
	E2 = estrategia;
}

void Carnivoro::recibirDanio(int danio) {
	energia -= danio;
	if (energia < 0) energia = 0; // Evitar energía negativa
}

void Carnivoro::guardarDatos(ofstream& archivo) const {
	archivo << "Carnivoro," << getX() << "," << getY() << "," << energia << "," << edad << "\n";
}