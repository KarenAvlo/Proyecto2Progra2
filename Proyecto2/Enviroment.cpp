#include "clases.h"

unique_ptr<Enviroment> Enviroment::instancia = nullptr;

Enviroment::Enviroment() :clima("Lluvioso"), estacion("Primavera") {
	
	mapa = make_shared<Mapa>(10, 10); 

}

Enviroment* Enviroment::getInstancia(){
	if (!instancia) {
		instancia = unique_ptr<Enviroment>(new Enviroment());
	}
	return instancia.get();
}

void Enviroment::agregarRecurso(shared_ptr<Objeto> recurso){
	int x = recurso->getX();
	int y = recurso->getY();
	objetos.agregar(recurso);
	mapa->agregarObjeto(x, y, recurso);
}

void Enviroment::agregarCreatura(shared_ptr<Objeto>creatura ){
	int x = creatura->getX();
	int y = creatura->getY();
	objetos.agregar(creatura);
	mapa->agregarObjeto(x, y, creatura);
}

void Enviroment::eliminarCreatura(shared_ptr<Objeto> creatura) {
	mapa->eliminarObjeto(creatura->getX(), creatura->getY());
	objetos.eliminar(creatura);
	
}

void Enviroment::eliminarRecurso(shared_ptr<Objeto> recurso) {
	mapa->eliminarObjeto(recurso->getX(), recurso->getY());
	objetos.eliminar(recurso);
}


//setters
void Enviroment::setClima(int cli) {
	if (cli == 1) {
		clima = "Soleado";
	}
	else if (cli == 2) {
		clima = "Lluvioso";
	}
	else if (cli == 3) {
		clima = "Nublado";
	}
	else {
		clima = "Desconocido"; 
	}
}

void Enviroment::setEstacion(string est) { estacion = est; }

string Enviroment::getClima() { return clima; }

string Enviroment::getEstacion() { return estacion; }

const lista<shared_ptr<Objeto>>* Enviroment::getLista() const{
	return &objetos;
}

shared_ptr<Mapa> Enviroment::getMapa() const{
	return mapa; 
}


 string Enviroment::toString() const{
	 stringstream s;
	 s << "Clima: " << clima << endl;
	 s << "Estacion:" << estacion << endl;
	 return s.str();
 }

 bool Enviroment::hayPlantaCerca(Hervivoro* her) const { //creo que no se está necesitando

	 for (auto it = objetos.begin(); it != objetos.end(); ++it) {

		 shared_ptr<Objeto> obj = *it;

		 shared_ptr<Planta> planta = std::dynamic_pointer_cast<Planta>(obj);

		 if (planta) {
			 double dist = std::hypot(planta->getX() - her->getX(), planta->getY() - her->getY());
			 if (dist <= 3.0) return true;
		 }
	 }
	 return false;
 }

 shared_ptr<Planta> Enviroment::getPlantaCerca(shared_ptr<Creatura> hervivoro) {
	 if (!hervivoro) return nullptr;

	 shared_ptr<Planta> presaMasCercana = nullptr;
	 double distanciaPresa = 0.0;

	 for (const auto& obj : objetos) {
		 // Intentar convertir el objeto a una Planta
		 shared_ptr<Planta> planta = dynamic_pointer_cast<Planta>(obj);

		 // Si es una planta válida y no es el mismo objeto que el hervívoro
		 if (planta && obj != hervivoro) {
			 double dist = hypot(planta->getX() - hervivoro->getX(),
				 planta->getY() - hervivoro->getY());

			 if (dist <= 1.0 && (!presaMasCercana || dist < distanciaPresa)) {
				 presaMasCercana = planta;
				 distanciaPresa = dist;
			 }
		 }
	 }

	 return presaMasCercana;
 }


 shared_ptr<Meat> Enviroment::getCarneCerca(shared_ptr<Creatura> depredador) {
	 if (!depredador) return nullptr;

	 shared_ptr<Meat> presaMasCercana = nullptr;
	 double distanciaPresa = 0.0;

	 for (const auto& obj : objetos) {
		 // Intentar convertir el objeto a una Planta
		 shared_ptr<Meat> carnita = dynamic_pointer_cast<Meat>(obj);

		 // Si es una planta válida y no es el mismo objeto que el hervívoro
		 if (carnita && obj != depredador) {
			 double dist = hypot(carnita->getX() - depredador->getX(),
				 carnita->getY() - depredador->getY());

			 if (dist <= 1.0 && (!presaMasCercana || dist < distanciaPresa)) {
				 presaMasCercana = carnita;
				 distanciaPresa = dist;
			 }
		 }
	 }

	 return presaMasCercana;
 }




 shared_ptr<Creatura> Enviroment::getCreaturaDebilCerca(shared_ptr<Creatura> depredador) {
	 if (!depredador) return nullptr;
	 shared_ptr<Creatura> presaMasCercana = nullptr;

	 double distanciaPresa = 0;

	 for (auto it = objetos.begin(); it != objetos.end(); ++it) {
		 shared_ptr<Objeto> obj = *it;

		 // Herbívoro
		 shared_ptr<Hervivoro> her = dynamic_pointer_cast<Hervivoro>(obj);
		 if (her && her.get() != depredador.get()) {
			 double dist = hypot(her->getX() - depredador->getX(), her->getY() - depredador->getY());
			 if (dist <= 3.0 && (presaMasCercana == nullptr || dist < distanciaPresa)) {
				 presaMasCercana = her;
				 distanciaPresa = dist;
			 }
		 }

		 // Omnívoro
		 shared_ptr<Omnivoro> om = dynamic_pointer_cast<Omnivoro>(obj);
		 if (om && om.get() != depredador.get()) {
			 double dist = hypot(om->getX() - depredador->getX(), om->getY() - depredador->getY());
			 if (dist <= 1.0 && (presaMasCercana == nullptr || dist < distanciaPresa)) {
				 presaMasCercana = om;
				 distanciaPresa = dist;
			 }
		 }
	 }
	 return presaMasCercana;

 }

 bool Enviroment::hayCreaturaDebilCerca(Creatura* cre) const{

	 for (auto it = objetos.begin(); it != objetos.end(); ++it) {

		 shared_ptr<Objeto> obj = *it;

		 //el hypot calcula la formula de la distancia


		// Intenta convertir a Hervivoro
		 shared_ptr<Hervivoro> her = dynamic_pointer_cast<Hervivoro>(obj);
		 if (her && her.get() != cre) {
			 double dist = hypot(her->getX() - cre->getX(), her->getY() - cre->getY());
			 if (dist <= 3.0) return true;
		 }

		 // Intenta convertir a Omnivoro
		 shared_ptr<Omnivoro> om = dynamic_pointer_cast<Omnivoro>(obj);
		 if (om && om.get() != cre) {
			 double dist = hypot(om->getX() - cre->getX(), om->getY() - cre->getY());
			 if (dist <= 3.0) return true;
		 }
	 }
	 return false;
 }

 //void Enviroment::simularTiempo(int maxTicks)
 //{
	// int tick = 0;
	// int ticksPorDia = 10; // Definir cuántos ticks son un día
	// int op = -1;

	// do {
	//	 int tick = 0;

	//	 while (tick < maxTicks) {

	//		 cout << "Tick: " << tick + 1 << endl;
	//		 cout << "Clima actual: " << clima << endl;
	//		 cout << "Estación actual: " << estacion << endl;

	//		 // Simular el clima y la estación
	//		 if (tick % ticksPorDia == 0) {
	//			 // Cambiar el clima aleatoriamente
	//			 int nuevoClima = rand() % 3 + 1; // 1 a 3

	//			 setClima(nuevoClima);
	//			 // Cambiar la estación aleatoriamente
	//			 if (estacion == "Primavera") estacion = "Verano";
	//			 else if (estacion == "Verano") estacion = "Otonio";
	//			 else if (estacion == "Otonio")  estacion = "Invierno";
	//			 else  estacion = "Primavera";
	//		 }

	//		 // Simular las criaturas
	//		 for (auto& obj : objetos) {
	//			 shared_ptr<Creatura> criatura = dynamic_pointer_cast<Creatura>(obj);
	//			 if (criatura) {
	//				 criatura->moverse();
	//				 criatura->alimentarse();
	//				 criatura->reproducirse();
	//			 }
	//		 }
	//		 cout << mapa->mostrarMapa() << endl;
	//		 tick++;
	//		 std::this_thread::sleep_for(chrono::milliseconds(1)); // Simular un pequeño retraso para la visualización

	//		 cout << "\n¿Deseas continuar la simulacion? (1 = Si, 0 = No): ";
	//		 cin >> op;

	//		 if (op == 0) {
	//			 cout << "Simulacion finalizada." << endl;
	//			 break;
	//		 }
	//	 }
	// } while (op != 0);
 //}

 void Enviroment::simularTickTiempo(int maxTick)
 {

	 int ticksPorDia = 10; // Cada 10 ticks cambia clima/estación
	 int tickGlobal = 0;
	 int maxTicks = maxTick;
	 char continuar = 's';

	 while (continuar == 's' || continuar == 'S') {

		 for (int tick = 0; tick < maxTicks; ++tick, ++tickGlobal) {

			 cout << endl;
			 cout << "Tick: " << tickGlobal + 1 << endl;
			 cout << "Clima actual: " << clima << endl;
			 cout << "Estacion actual: " << estacion << endl;

			 // Cambios al clima 
			 if (tickGlobal % ticksPorDia == 0) {
				 int nuevoClima = rand() % 3 + 1;
				 setClima(nuevoClima);
				 if (estacion == "Primavera") estacion = "Verano";
				 else if (estacion == "Verano") estacion = "Otonio";
				 else if (estacion == "Otonio") estacion = "Invierno";
				 else estacion = "Primavera";
			 }

			 // criaturas
			 for (auto& obj : objetos) {
				 shared_ptr<Creatura> criatura = dynamic_pointer_cast<Creatura>(obj);
				 if (criatura) {
					 criatura->moverse();
					 criatura->alimentarse();
					 criatura->reproducirse();
					 criatura->atacar();

				 }
			 }		

			 //falta simular recursos

			 cout << mapa->mostrarMapa() << endl;
			 std::this_thread::sleep_for(std::chrono::seconds(1)); // para simular los segundos
		 }

		
		 cout << "\n¿Desea continuar la simulacion por mas segundos? (s/n): ";
		 cin >> continuar;
		 if (continuar == 'n') {
			 break;
		 }else if (continuar == 's' || continuar == 'S') {
			 cout << "¿Cuantos segundos quiere?: ";
			 cin >> maxTicks;
		 }
	 }
 }
 
 