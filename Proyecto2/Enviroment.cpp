/* -------------------------------------------------------------------+
*                                                                     |
* (c) 2025                                                            |
* EIF204 - Programaci�n 2                                             |
* 1er ciclo 2025                                                      |
* NRC 41371 � Grupo 01                                                |
* Proyecto 2                                                          |
*                                                                     |
* 2-0816-0954; Avil�s�L�pez, Karen Minards                            |
* 1-1709-0658; Elizondo�Cascante, Cristhian                           |
* 1-19560437; S�nchez Berm�dez, Juan Pablo                            |
*                                                                     |
* versi�n 1.0.0, 12 - 06 - 2025                                       |
*                                                                     |
* --------------------------------------------------------------------+
*/

#include "clases.h"
#include <iostream>

unique_ptr<Enviroment> Enviroment::instancia = nullptr;

Enviroment::Enviroment() :clima("Lluvioso"), estacion("Primavera") 
{
	// creamos un mapa por defecto
	mapa = make_shared<Mapa>(10, 10); 

	nivelAguita = 1;

	nivelSol = 1;
}

Enviroment* Enviroment::getInstancia()
{
	if (!instancia) {

		instancia = unique_ptr<Enviroment>(new Enviroment());
	}

	return instancia.get();
}

void Enviroment::agregarRecurso(shared_ptr<Objeto> recurso)
{
	int x = recurso->getX();
	int y = recurso->getY();

	if (mapa->agregarObjeto(x, y, recurso)) {

		objetos.agregar(recurso);
	}

	else {

		cerr << "No se pudo agregar la creatura en (" << x << ", " << y << "), posici�n ocupada o inv�lida." << endl;
	}
}

bool Enviroment::agregarCreatura(shared_ptr<Objeto>creatura )
{
	int x = creatura->getX();
	int y = creatura->getY();

	//cout << "Intentando agregar criatura en (" << x << ", " << y << ")" << endl;

	if (mapa->posValida(x, y) && !mapa->hayObjetoEnMapa(x, y)) {

		if (mapa->agregarObjeto(x, y, creatura)) {

			objetos.agregar(creatura);

			return true;
		}

		else {

			cerr << "Fallo al agregar la creatura en el mapa, posiblemente un error interno." << endl;

			return false;
		}
	}

	else {

		cerr << " No se pudo agregar la Creatura en (" << x << "," << y << ") , posicion invalida o ocupada" << endl;

		return false;
	}
}

void Enviroment::eliminarCreatura(shared_ptr<Objeto> creatura) 
{
	//Se debe eliminar de la lista de objetos y del mapa
	mapa->eliminarObjeto(creatura->getX(), creatura->getY());

	objetos.eliminar(creatura);
}

void Enviroment::eliminarRecurso(shared_ptr<Objeto> recurso) 
{
	mapa->eliminarObjeto(recurso->getX(), recurso->getY());

	objetos.eliminar(recurso);
}


//setters
void Enviroment::setClima(int cli) 
{
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

string Enviroment::getClima() { return clima; }

string Enviroment::getEstacion() { return estacion; }

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


const lista<shared_ptr<Objeto>>* Enviroment::getLista() const
{
	return &objetos;
}

shared_ptr<lista<shared_ptr<Creatura>>> Enviroment::mostrarCreaturas() const 
{
	//lista especificamente para creaturas

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

shared_ptr<lista<shared_ptr<Recursos>>> Enviroment::mostrarRecursos() const 
{
	//lista especificamente para creaturas

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

shared_ptr<Mapa> Enviroment::getMapa() const 
{
	return mapa;
}


 string Enviroment::toString() const
 {
	 stringstream s;

	 s << "Clima: " << clima << endl;
	 s << "Estacion:" << estacion << endl;
	
	 return s.str();
 }

 int Enviroment::generarIntervaloDeRegeneracionRecursos()const 
 {
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

	 cerr << "Advertencia: combinaci�n inesperada de nivelSol = " << nivelSol
		 << ", nivelAguita = " << nivelAguita << endl;

	 return 10; // valor por defecto razonable
 }

 bool Enviroment::hayPlantaCerca(shared_ptr<Creatura> cre) const 
 {
	 if (!cre) return false;

	 for (const auto& obj : objetos) {

		 // PlantaFlor
		 shared_ptr<PlantaFlor> flor = dynamic_pointer_cast<PlantaFlor>(obj);

		 if (flor) {

			 double dist = hypot(flor->getX() - cre->getX(), flor->getY() - cre->getY());

			 if (dist <= 3.0) return true;
		 }

		 // PlantaRosa
		 shared_ptr<PlantaRosa> rosa = dynamic_pointer_cast<PlantaRosa>(obj);

		 if (rosa) {

			 double dist = hypot(rosa->getX() - cre->getX(), rosa->getY() - cre->getY());

			 if (dist <= 3.0) return true;
		 }
	 }

	 return false;
 }

 bool Enviroment::hayHerviroroCerca(shared_ptr<Creatura> cre) const 
 {
	 for (auto it = objetos.begin(); it != objetos.end(); ++it) {

		 shared_ptr<Objeto> obj = *it;

		 //el hypot calcula la formula de la distancia


		// Intenta convertir a Herbivoro
		 shared_ptr<Herbivoro> her = dynamic_pointer_cast<Herbivoro>(obj);
		 if (her && her != cre) {

			 double dist = hypot(her->getX() - cre->getX(), her->getY() - cre->getY());

			 if (dist <= 1.5) return true;
		 }
	 }

	 return false;
 }

 bool Enviroment::hayCarnivoroCerca(shared_ptr<Creatura> cre) const 
 {
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

 bool Enviroment::hayOmnivoroCerca(shared_ptr<Creatura> cre) const 
 {
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

 bool Enviroment::hayCarneCerca(shared_ptr<Creatura> cre) const 
 {
	 if (!cre) return false;

	 for (const auto& obj : objetos) {

		 // Intentamos convertir el objeto a tipo Carne
		 shared_ptr<Meat> carne = dynamic_pointer_cast<Meat>(obj);

		 if (carne) {

			 double dist = hypot(carne->getX() - cre->getX(), carne->getY() - cre->getY());

			 if (dist <= 3.0) return true;
		 }
	 }

	 return false;
 }

 shared_ptr<Recursos> Enviroment::getPlantaCerca(shared_ptr<Creatura> herbivoro) 
 {
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


 shared_ptr<Meat> Enviroment::getCarneCerca(shared_ptr<Creatura> depredador) 
 {
	 if (!depredador) return nullptr;

	 shared_ptr<Meat> presaMasCercana = nullptr;

	 double distanciaPresa = 0.0;

	 for (const auto& obj : objetos) {

		 // Intentar convertir el objeto a una Planta
		 shared_ptr<Meat> carnita = dynamic_pointer_cast<Meat>(obj);

		 // Si es una planta v�lida y no es el mismo objeto que el herv�voro
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


 shared_ptr<Creatura> Enviroment::getCreaturaDebilCerca(shared_ptr<Creatura> depredador) 
 {
	 if (!depredador) return nullptr;

	 shared_ptr<Creatura> presaMasCercana = nullptr;

	 double distanciaPresa = 0;

	 for (auto it = objetos.begin(); it != objetos.end(); ++it) {

		 shared_ptr<Objeto> obj = *it;

		 // Herb�voro
		 shared_ptr<Herbivoro> her = dynamic_pointer_cast<Herbivoro>(obj);

		 if (her && her.get() != depredador.get()) {

			 double dist = hypot(her->getX() - depredador->getX(), her->getY() - depredador->getY());

			 if (dist <= 3.0 && (presaMasCercana == nullptr || dist < distanciaPresa)) {

				 presaMasCercana = her;

				 distanciaPresa = dist;
			 }
		 }

		 // Omn�voro
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

		 // Carn�voro
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

 void Enviroment::isDeadtoMeat() 
 { //metodo para revisar estan muertas y convertirlas en carne

	 // Recorremos la lista de objetos
	 for (auto it = objetos.begin(); it != objetos.end(); ++it) {

		 shared_ptr<Objeto> obj = *it;

		 // Intentamos convertir a Creatura
		 shared_ptr<Creatura> criatura = dynamic_pointer_cast<Creatura>(obj);

		 // Si es una criatura y est� muerta
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


 void Enviroment::eliminarTodo() 
 {
	 objetos.eliminarTodos();

	 mapa->limpiarCeldas();
 }

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
	

			 // Cambio de clima y estaci�n
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

			 // Simulaci�n de recursos (por intervalo)
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

		 cout << "\n�Desea continuar la simulacion por mas segundos? (s/n): ";

		 cin >> continuar;

		 if (continuar == 's' || continuar == 'S') {

			 cout << "�Cuantos segundos quiere?: ";

			 cin >> maxTicks;
		 }
	 }
 }

 void Enviroment::guardarDatosCreaturas(const string& nombreArchivo) 
 {
	 if (getLista()->estaVacia()) {

		 cout << "No hay elementos a guardar" << std::endl;
		 return;
	 }

	 ofstream archivo(nombreArchivo);

	 if (!archivo.is_open()) {

		 cerr << "Error al abrir archivo para guardar criaturas\n";
		 return;
	 }

	 auto listaCreaturas = mostrarCreaturas(); 

	 for (const auto& c : *listaCreaturas) {

		 if (!c->isDead()) {

			 c->guardarDatos(archivo);
		 }
	 }

	 archivo.close();

	 cout << "Creaturas guardadas correctamente.\n";
 }

 void Enviroment::guardarDatosRecursos(const string& nombreArchivo) 
 {
	 if (getLista()->estaVacia()) {

		 cout << "No hay elementos a guardar" << std::endl;
		 return;
	 }

	 ofstream archivo(nombreArchivo);

	 if (!archivo.is_open()) {

		 cerr << "Error al abrir archivo para guardar criaturas\n";
		 return;
	 }

	 auto listaRecursos = mostrarRecursos();  // Devuelve shared_ptr a lista/colecci�n de recursos

	 for (const auto& r : *listaRecursos) {

		 r->guardarDatos(archivo);
	 }

	 archivo.close();

	 cout << "Recursos guardados correctamente.\n";
 }

 void Enviroment::cargarDatosCreaturas(const string& nombreArchivo) 
 {
	 ifstream archivo(nombreArchivo);

	 if (!archivo.is_open()) {

		 cerr << "Error al abrir archivo para cargar criaturas\n";
		 return;
	 }

	 auto env = Enviroment::getInstancia();

	 string linea;

	 while (getline(archivo, linea)) {

		 stringstream ss(linea);

		 string tipo;

		 getline(ss, tipo, ',');

		 int x, y, energia, edad;

		 bool fueHerido = false; // solo se usa si es herb�voro

		 char coma;

		 // Leer los valores comunes
		 if (!(ss >> x >> coma >> y >> coma >> energia >> coma >> edad)) { 

			 cerr << "Error en formato de l�nea: " << linea << "\n";  
			 continue;
		 }

		 shared_ptr<Creatura> nuevaCreatura; 

		 if (tipo == "Herbivoro") {

			 if (!(ss >> coma >> fueHerido)) {
				 cerr << "Advertencia: Herb�voro sin informaci�n de 'fueHerido', usando false por defecto.\n";
			 }

			 auto nueva = make_shared<Herbivoro>(x, y, energia, edad, make_shared<EstrategiaAtaqueH>()); 

			 nueva->setFueHerido(fueHerido); 

			 nuevaCreatura = nueva; 
		 }

		 else if (tipo == "Carnivoro") {

			 nuevaCreatura = make_shared<Carnivoro>(x, y, energia, edad, make_shared<EstrategiaAtaqueC>());
		 }

		 else if (tipo == "Omnivoro") {

			 nuevaCreatura = make_shared<Omnivoro>(x, y, energia, edad, make_shared<EstrategiaAtaqueO>());
		 }

		 else {

			 cerr << "Tipo desconocido: " << tipo << "\n";
			 continue;
		 }

		 env->agregarCreatura(nuevaCreatura);
	 }

	 archivo.close();

	 cout << "Creaturas cargadas correctamente.\n";
 }

 void Enviroment::cargarDatosRecursos(const string& nombreArchivo) 
 {
	 ifstream archivo(nombreArchivo);

	 if (!archivo.is_open()) {

		 cerr << "Error al abrir archivo para cargar recursos\n";
		 return;
	 }

	 // Asumimos singleton Enviroment con m�todo agregarRecurso(shared_ptr<Recursos>)
	 auto env = Enviroment::getInstancia();

	 string linea;

	 while (getline(archivo, linea)) {

		 stringstream ss(linea);

		 string tipo;

		 getline(ss, tipo, ',');

		 int x, y, energia;

		 char coma;
 
		 if (!(ss >> x >> coma >> y >> coma >> energia)) {

			 cerr << "Error en formato de l�nea: " << linea << "\n";
			 continue;
		 }

		 shared_ptr<Recursos> nuevoRecurso;

		 if (tipo == "Meat") {

			 nuevoRecurso = make_shared<Meat>(x, y, energia);
		 }

		 else if (tipo == "PlantaFlor") {

			 nuevoRecurso = make_shared<PlantaFlor>(x, y, energia);
		 }

		 else if (tipo == "PlantaRosa") {

			 nuevoRecurso = make_shared<PlantaRosa>(x, y, energia);
		 }

		 else {

			 cerr << "Tipo desconocido: " << tipo << "\n";
			 continue;
		 }

		 env->agregarRecurso(nuevoRecurso);
	 }

	 archivo.close();
	 cout << "Recursos cargados correctamente.\n";
 }

 