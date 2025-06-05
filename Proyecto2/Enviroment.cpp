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

	if (mapa->agregarObjeto(x, y, creatura) && mapa->posValida(x,y)) {
		objetos.agregar(creatura);
	}
	else {
		cerr << " No se pudo agregar la Creatura en ( " << x << "," << y << ") , posicion invalida o ocupada" << endl;
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
 }

 void Enviroment::generarRecursos()
 {
	 int maxIntentos = 100; // para evitar un bucle infinito

	 // generar un recurso aleatorio en una posición libre del mapa
	 for (int i = 0; i < maxIntentos; i++) {
		 int x = rand() % mapa->getAncho();
		 int y = rand() % mapa->getAlto();
		 // Verificar si la posicion esta libre
		 if (!mapa->hayObjetoEnMapa(x, y)) {
			 shared_ptr<Recursos> recurs = make_shared<Recursos>(x, y, 100);
			 agregarRecurso(recurs);
			 return; 
		 }
	 }
 }

 //agrega directamente una cantidad de recursos al inicio
 void Enviroment::agregarRecursoPorCan(int n)
 {
	 int agregados = 0;
	 int intentos = 0;
	 int maxIntentos = 100; //evita que quede enclochado
	 const int max = 5;
	 int libres = mapa->espaciosLibres();

	 if (libres < n) {
		 cerr << "No hay suficientes espacios libres en el mapa. Espacios libres: " << libres << endl;
		 return;
	 }
	 if (n < 0 || n > max) {
		 cerr << "Cantidad invalida. Debe ser entre 0 y " << max << "." << endl;
		 return;
	 }

	 while (agregados < n && intentos < maxIntentos) {
		 int x = rand() % mapa->getAncho();
		 int y = rand() % mapa->getAlto();

		 // Verificar si la posicion esta libre
		 if (!mapa->hayObjetoEnMapa(x, y)) {
			 shared_ptr<Recursos> recurs = make_shared<Recursos>(x, y, 100);
			 agregarRecurso(recurs);
			 agregados++;
		 }
		 intentos++;
	 }
	 if (agregados < n) {
		 cerr << "Solo se pudieron agregar " << agregados << " recursos despues de " << intentos << " intentos." << endl;
	 }
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

 void Enviroment::simularTiempoAleatorio()
 {
	 int ticksPorDia = 10; // Cada 10 ticks cambia clima/estación
	 int tickGlobal = 0;
	 srand(time(0)); // Inicializar la semilla aleatoria
	 char continuar = 's';
	 int maxTicks = 30; // Definir un número máximo de ticks para la simulación
	 int interRegeneracion = generarIntervaloDeRegeneracionRecursos();

	 //este va hacer casi todo en el aleatorio
	 if (ticksPorDia % tickGlobal == 0) {

	 }


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
					 criatura->moverse();
					 criatura->alimentarse();
					 criatura->reproducirse();
					 criatura->atacar();
				 }
			 }
			 // Simulación de recursos (por intervalo)
			 ticksDesdeUltimoRecurso++;
			 int interRegeneracion = generarIntervaloDeRegeneracionRecursos();

			 if (ticksDesdeUltimoRecurso >= interRegeneracion) {
				 generarRecursos();
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

 