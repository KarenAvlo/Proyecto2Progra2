#include "Hervivoro.h"


Herbivoro::Herbivoro(int x, int  y, int energia, int edad, shared_ptr<Estrategia> estrategia):
	Creatura(x, y, energia, edad, estrategia), fueHerido(false){
	E = make_shared<EstrategiaAtaqueH>(); // 
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
	
	if (Enviroment::getInstancia()->hayPlantaCerca(shared_from_this())) {
		//si hay planta cerca entonces cómasela

		setEstrategia(make_shared<EstrategiaAlimentacionH>());

		if (E) {
			E->EjecutarEstrategia(shared_from_this());
		}
	}
}

void Herbivoro::atacar() {

	if (Enviroment::getInstancia()->getCreaturaFuerteCerca(shared_from_this())) {
		//si creatura fuerte está cerca y me ataca, entonces realizo la estrategia contra-ataque

		setEstrategia(make_shared<EstrategiaAtaqueH>());

		if (E) {
			E->EjecutarEstrategia(shared_from_this());
			fueHerido = false; // Reseteamos el estado de herida después de atacar
		}
		else {
			cout << "No hay estrategia de ataque definida." << endl;
		}
	}
}

void Herbivoro::ReducirEnergia(int danio){
	this->energia -= danio;
	if (energia < 0) energia = 0;
	fueHerido = true;
}
 
void Herbivoro::guardarDatos(ofstream& archivo) const { 
	archivo << "Herbivoro," << x << "," << y << "," << energia << "," << edad << "," << fueHerido << "\n"; 
}

void Herbivoro::setFueHerido(bool valor) {
	fueHerido = valor;
}