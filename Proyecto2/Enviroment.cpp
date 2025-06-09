#include "clases.h"

unique_ptr<Enviroment> Enviroment::instancia = nullptr;

Enviroment::Enviroment() :clima("Lluvioso"), estacion("Primavera") {
	
	mapa = make_shared<Mapa>(10, 10); 
	nivelAguita=0;
	nivelSol=0;

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

	if (mapa->agregarObjeto(x, y, recurso)) {
		objetos.agregar(recurso);
	}
	else {
		cerr << "No se pudo agregar la creatura en (" << x << ", " << y << "), posición ocupada o inválida." << endl;
	}
}

void Enviroment::agregarCreatura(shared_ptr<Objeto>creatura ){
	int x = creatura->getX();
	int y = creatura->getY();

	//cout << "Intentando agregar criatura en (" << x << ", " << y << ")" << endl;

	if (mapa->posValida(x, y) && !mapa->hayObjetoEnMapa(x, y)) {
		if (mapa->agregarObjeto(x, y, creatura)) {
			objetos.agregar(creatura);
			//cout << "Criatura agregada correctamente." << endl;
		}
		else {
			cerr << "Fallo al agregar la creatura en el mapa, posiblemente un error interno." << endl;
		}
	}
	else {
		cerr << " No se pudo agregar la Creatura en (" << x << "," << y << ") , posicion invalida o ocupada" << endl;
	}
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

void Enviroment::setNivelAgua(int nivel)
{
	if (nivel >= 0 && nivel <= 2) {
		nivelAguita = nivel;
	}
	else {
		cerr << "Nivel de agua invalido. Debe estar entre 0 y 2." << endl;
	}
}

void Enviroment::setNivelSol(int nivel)
{
	if (nivel >= 0 && nivel <= 2) {
		nivelSol = nivel;
	}
	else {
		cerr << "Nivel de sol invalido. Debe estar entre 0 y 2." << endl;
	}
}

int Enviroment::getNivelAgua() const { return nivelAguita; }
int Enviroment::getNivelSol() const { return nivelSol; }

int Enviroment::getAnchoMapa() const
{
	return mapa->getAncho();
}
int Enviroment::getAltoMapa() const
{
	return mapa->getAlto();
}


string Enviroment::getClima() { return clima; }

string Enviroment::getEstacion() { return estacion; }

const lista<shared_ptr<Objeto>>* Enviroment::getLista() const{
	return &objetos;
}

shared_ptr<lista<shared_ptr<Creatura>>> Enviroment::mostrarCreaturas() const {
	auto listaCreaturas = make_shared<lista<shared_ptr<Creatura>>>();

	for (auto it = objetos.begin(); it != objetos.end(); ++it) {
		shared_ptr<Objeto> obj = *it;
		shared_ptr<Creatura> c = dynamic_pointer_cast<Creatura>(obj);
		if (c != nullptr) {
			listaCreaturas->agregar(c);
		}
	}
	return listaCreaturas;

}

shared_ptr<lista<shared_ptr<Recursos>>> Enviroment::mostrarRecursos() const {
	auto listaRecursos = make_shared<lista<shared_ptr<Recursos>>>();

	for (auto it = objetos.begin(); it != objetos.end(); ++it) {
		shared_ptr<Objeto> obj = *it;
		shared_ptr<Recursos> c = dynamic_pointer_cast<Recursos>(obj);
		if (c != nullptr) {
			listaRecursos->agregar(c);
		}
	}
	return listaRecursos;

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

 int Enviroment::generarIntervaloDeRegeneracionRecursos()const {
 //los niveles de agua y sol son 0, 1 o 2
// y el numero que retorna son los ticks de tiempo que tarda en regenerarse el recurso
	 if (nivelSol == 2 && nivelAguita == 2) return 2;
	 if (nivelSol == 1 && nivelAguita == 1) return 4;
	 if (nivelSol == 2 && nivelAguita == 1) return 3;
	 if (nivelSol == 1 && nivelAguita == 2) return 3;
	 if (nivelSol == 0 && nivelAguita == 2) return 7;
	 if (nivelSol == 2 && nivelAguita == 0) return 7;
	 if (nivelSol == 0 && nivelAguita == 1) return 9;
	 if (nivelSol == 1 && nivelAguita == 0) return 9;
	 if (nivelSol == 0 && nivelAguita == 0) return 15;

	 //este No se mueve a factory
 }

 void Enviroment::ticksDeRecursos()
 {
	 tickGlobal++;
	 int canRecurso = generarIntervaloDeRegeneracionRecursos();

	 if (tickGlobal >= canRecurso) {
		 int cantidad = rand() % 3 + 1; 

		 for (int i = 0; i < cantidad; i++) {
			 int tipo = rand() % 3 + 1; 
			 try {
				 shared_ptr<Recursos> recurso = FactoryResources::crearInstancia(tipo);
				 agregarRecurso(recurso);
			 }
			 catch (const std::exception& e) {
				 cerr << "Error generando recurso: " << e.what() << endl;
			 }
		 }
		 tickGlobal = 0;
	 }
 }


 bool Enviroment::hayPlantaCerca(Herbivoro* her) const {
	 if (!her) return false;

	 for (const auto& obj : objetos) {
		 // PlantaFlor
		 shared_ptr<PlantaFlor> flor = dynamic_pointer_cast<PlantaFlor>(obj);
		 if (flor) {
			 double dist = hypot(flor->getX() - her->getX(), flor->getY() - her->getY());
			 if (dist <= 3.0) return true;
		 }

		 // PlantaRosa
		 shared_ptr<PlantaRosa> rosa = dynamic_pointer_cast<PlantaRosa>(obj);
		 if (rosa) {
			 double dist = hypot(rosa->getX() - her->getX(), rosa->getY() - her->getY());
			 if (dist <= 3.0) return true;
		 }
	 }

	 return false;
 }

 shared_ptr<Recursos> Enviroment::getPlantaCerca(shared_ptr<Creatura> herbivoro) {
	 if (!herbivoro) return nullptr;

	 shared_ptr<Recursos> plantaMasCercana = nullptr;
	 double distanciaMinima = std::numeric_limits<double>::max();

	 for (const auto& obj : objetos) {
		 // PlantaFlor
		 shared_ptr<PlantaFlor> flor = dynamic_pointer_cast<PlantaFlor>(obj);
		 if (flor) {
			 double dist = hypot(flor->getX() - herbivoro->getX(), flor->getY() - herbivoro->getY());
			 if (dist <= 1.0 && dist < distanciaMinima) {
				 plantaMasCercana = flor;
				 distanciaMinima = dist;
			 }
		 }

		 // PlantaRosa
		 shared_ptr<PlantaRosa> rosa = dynamic_pointer_cast<PlantaRosa>(obj);
		 if (rosa) {
			 double dist = hypot(rosa->getX() - herbivoro->getX(), rosa->getY() - herbivoro->getY());
			 if (dist <= 1.0 && dist < distanciaMinima) {
				 plantaMasCercana = rosa;
				 distanciaMinima = dist;
			 }
		 }
	 }

	 return plantaMasCercana;
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
		 shared_ptr<Herbivoro> her = dynamic_pointer_cast<Herbivoro>(obj);
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

 shared_ptr<Creatura> Enviroment::getCreaturaFuerteCerca(shared_ptr<Creatura> depredador)
 {
	 if (!depredador) return nullptr;
	 shared_ptr<Creatura> presaMasCercana = nullptr;
	 double distanciaPresa = 0;
	 for (auto it = objetos.begin(); it != objetos.end(); ++it) {
		 shared_ptr<Objeto> obj = *it;
		 // Carnívoro
		 shared_ptr<Carnivoro> car = dynamic_pointer_cast<Carnivoro>(obj);
		 if (car && car.get() != depredador.get()) {
			 double dist = hypot(car->getX() - depredador->getX(), car->getY() - depredador->getY());
			 if (dist <= 1.0 && (presaMasCercana == nullptr || dist < distanciaPresa)) {
				 presaMasCercana = car;
				 distanciaPresa = dist;
			 }
		 }
	 }
	 return presaMasCercana;
 }

 
 bool Enviroment::hayHerviroroCerca(shared_ptr<Creatura> cre) const {
	 for (auto it = objetos.begin(); it != objetos.end(); ++it) {

		 shared_ptr<Objeto> obj = *it;

		 //el hypot calcula la formula de la distancia


		// Intenta convertir a Herbivoro
		 shared_ptr<Herbivoro> her = dynamic_pointer_cast<Herbivoro>(obj);
		 if (her && her!= cre) {
			 double dist = hypot(her->getX() - cre->getX(), her->getY() - cre->getY());
			 if (dist <= 1.5) return true;
		 }
	 }
	 return false;
 }

 bool Enviroment::hayCarnivoroCerca(shared_ptr<Creatura> cre) const {

	 for (auto it = objetos.begin(); it != objetos.end(); ++it) {
		 shared_ptr<Objeto> obj = *it;
		 //el hypot calcula la formula de la distancia

		 // Intenta convertir a Omnivoro
		 shared_ptr<Carnivoro> car = dynamic_pointer_cast<Carnivoro>(obj);
		 if (car && car != cre) {
			 double dist = hypot(car->getX() - cre->getX(), car->getY() - cre->getY());
			 if (dist <= 1.5) return true;
		 }
	 }
	 return false;
 }

 bool Enviroment::hayOmnivoroCerca(shared_ptr<Creatura> cre) const {
	 for (auto it = objetos.begin(); it != objetos.end(); ++it) {

		 shared_ptr<Objeto> obj = *it;

		 //el hypot calcula la formula de la distancia

		 // Intenta convertir a Omnivoro
		 shared_ptr<Omnivoro> om = dynamic_pointer_cast<Omnivoro>(obj);
		 if (om && om != cre) {
			 double dist = hypot(om->getX() - cre->getX(), om->getY() - cre->getY());
			 if (dist <= 1.5) return true;
		 }
	 }
	 return false;

 }




 void Enviroment::isDeadtoMeat() {

	 // Recorremos la lista de objetos
	 for (auto it = objetos.begin(); it != objetos.end(); ++it) {

		 shared_ptr<Objeto> obj = *it;

		 // Intentamos convertir a Creatura
		 shared_ptr<Creatura> criatura = dynamic_pointer_cast<Creatura>(obj);

		 // Si es una criatura y está muerta
		 if (criatura && criatura->isDead()) {
			 // Eliminamos la criatura del entorno
			 eliminarCreatura(criatura);

			 // Creamos carne en su lugar
			 shared_ptr<Meat> carne = make_shared<Meat>(criatura->getX(), criatura->getY(), 50);

			 // Agregamos el recurso carne al entorno
			 Enviroment::getInstancia()->agregarRecurso(carne);
		 }
	 }
 }


 void Enviroment::eliminarTodo() {
	 objetos.eliminarTodos();
	 mapa->limpiarCeldas();
 }

 //void Enviroment::verAtaques()
 //{
	// cout << "--- Simulacion de ataques ---" << endl;

	// for (int i = 0; i < objetos.getCan; ++i) {
	//	 for (int j = 0; j < objetos.getCantidad(); ++j) {
	//		 if (i == j) continue;

	//		 shared_ptr<Creatura> atacante = dynamic_pointer_cast<Creatura>(objetos.getObjeto(i));
	//		 shared_ptr<Creatura> objetivo = dynamic_pointer_cast<Creatura>(objetos.getObjeto(j));

	//		 if (atacante && objetivo && atacante->getEnergia() && objetivo->estaViva()) {
	//			 cout << atacante->getNombre() << " va a atacar a " << objetivo->getNombre() << endl;
	//			 cout << "Energia antes: " << objetivo->getEnergia() << endl;

	//			 atacante->atacar(*objetivo);

	//			 cout << "Energia despues: " << objetivo->getEnergia() << endl;
	//			 cout << "-----------------------------" << endl;
	//		 }
	//	 }
	// }
 //}

 void Enviroment::simularTickTiempo(int maxTick)
 {
	 int ticksPorDia = 10;
	 int tickGlobal = 0;
	 int maxTicks = maxTick;
	 char continuar = 's';

	 int ticksDesdeUltimoRecurso = 0; // contador individual

	 while (continuar == 's' || continuar == 'S') {

		 for (int tick = 0; tick < maxTicks; ++tick, ++tickGlobal) {

			 cout << "\nTick: " << tickGlobal + 1 << endl;
			 cout << "Clima actual: " << clima << endl;
			 cout << "Estacion actual: " << estacion << endl;
	

			 // Cambio de clima y estación
			 if (tickGlobal % ticksPorDia == 0) {
				 int nuevoClima = rand() % 3 + 1;
				 setClima(nuevoClima);

				 if (estacion == "Primavera") estacion = "Verano";
				 else if (estacion == "Verano") estacion = "Otonio";
				 else if (estacion == "Otonio") estacion = "Invierno";
				 else estacion = "Primavera";
			 }
			 // Acciones de criaturas
			 for (auto& obj : objetos) {
				 shared_ptr<Creatura> criatura = dynamic_pointer_cast<Creatura>(obj);
				 if (criatura) {
					 criatura->AumentarEdad();
					 criatura->moverse();
					 criatura->atacar();
					 criatura->alimentarse();
					 criatura->reproducirse();
					
				 }
			 }
			 //convertir a las creaturas muertas en carnitas asadas
			 isDeadtoMeat();

			 // Simulación de recursos (por intervalo)
			 ticksDesdeUltimoRecurso++;
			 int interRegeneracion = generarIntervaloDeRegeneracionRecursos();

			 if (ticksDesdeUltimoRecurso >= interRegeneracion) {
				 FactoryResources::crearRecursos();
				 ticksDesdeUltimoRecurso = 0;
			 }
			 // Mostrar mapa
			 cout << mapa->mostrarMapa() << endl;
			 std::this_thread::sleep_for(std::chrono::seconds(1));
		 }

		 cout << "\n¿Desea continuar la simulacion por mas segundos? (s/n): ";
		 cin >> continuar;

		 if (continuar == 's' || continuar == 'S') {
			 cout << "¿Cuantos segundos quiere?: ";
			 cin >> maxTicks;
		 }
	 }
 }

 

 void Enviroment::guardarCreaturasEnArchivo(const string& nombreArchivo) const 
 {
	 ofstream archivo(nombreArchivo);

	 if (!archivo.is_open()) { 
		 cerr << "Error al abrir el archivo para guardar.\n"; 
		 return;
	 }

	 for (const auto& obj : objetos) {   
		 auto criatura = std::dynamic_pointer_cast<Creatura>(obj); 
		 if (criatura && !criatura->isDead()) {  // Solo guardamos si NO está muerta 
			 criatura->guardarDatos(archivo); 
		 }
	 }

	 archivo.close(); 
 }

 