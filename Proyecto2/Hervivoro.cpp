#include "Hervivoro.h"


Herbivoro::Herbivoro(int x, int  y , int energia , int edad , shared_ptr<Estrategia> E, shared_ptr<EstrategiaAtaque> E2):
	Creatura(x, y, energia, edad, E, E2){
	 // Estrategia de ataque por defecto
	E2 = make_shared<EstrategiaAtaqueH>(); // Estrategia de ataque por defecto
}



string Herbivoro::toString() const{
	stringstream s;
	s << "H(" << x << "," << y << ") E:" << energia; // H de Herbivoro, sus coordenadas y respectiva energía
	return s.str();
}

string Herbivoro::getEtiqueta() const{
	return "Herbivoro";
}

void Herbivoro::reproducirse() {
	
	if (Enviroment::getInstancia()->hayHerviroroCerca(shared_from_this())) {
		//si hay un animal de su mismo tipo, entonces reproduzcase


		setEstrategia(make_shared<EstrategiaReproduccion>());
		if (E) {
			E->EjecutarEstrategia(shared_from_this());

		}
	}
}

void Herbivoro::alimentarse() {
	setEstrategia(make_shared<EstrategiaAlimentacionH>());
	if (E) {
		E->EjecutarEstrategia(shared_from_this());
	}
}

void Herbivoro::atacar(Creatura& obj) {
	
	if (E2 && !obj.isDead()) {
		for (int i = 0; i < 2 && !obj.isDead(); i++) {
			int d = E2->calcularDanio();
			obj.recibirDanio(d);
			cout << "Ataque " << (i + 1) << " con " << E2->getTipoAtaque()
				<< " inflige " << d << " de danio." << endl;
		}
	}
}

void Herbivoro::setEstrategiaAtaque(shared_ptr<EstrategiaAtaque> estrategia)
{
	E2 = estrategia; 
}

void Herbivoro::recibirDanio(int danio) {
	energia -= danio;
	if (energia < 0) energia = 0; // Evitar energía negativa
}

void Herbivoro::guardarDatos(std::ofstream& archivo) const {
	archivo << "Herbivoro," << getX() << "," << getY() << "," << energia << "," << edad << "\n";
}