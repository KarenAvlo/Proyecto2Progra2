#include "Interfaz.h"

Interfaz::Interfaz(){}
Interfaz::~Interfaz(){}


void Interfaz::ingresarCreatura() {
	int opcion = -1;
	int tipo = 0;

	do {
		system("cls"); 
		cout << "   ---[ Generar Creatura ]---   " << endl;

		cout << "Seleccione el tipo de Creatura (1:Herbivoro , 2:Carnivoro, 3:Omnivoro): ";
		cin >> tipo;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cerr << "Entrada invalida, por favor ingrese un numero." << endl;
			cout << "\nPresione Enter para continuar...";
			cin.ignore();
			cin.get();
			continue;
		}

		if (tipo < 1 || tipo > 3) {
			cout << "Tipo invalido. Intente de nuevo." << endl;
			cout << "\nPresione Enter para continuar...";
			cin.ignore();
			cin.get();
			continue;
		}

		try {
			shared_ptr<Creatura> nueva = FactoryCreature::crearInstancia(tipo);
			Enviroment::getInstancia()->agregarCreatura(nueva);
			cout << "Creatura agregada exitosamente: " << nueva->toString() << endl;
		}
		catch (const std::exception& e) {
			cerr << "Error al crear la creatura: " << e.what() << endl;
			cout << "\nPresione Enter para continuar...";
			cin.ignore();
			cin.get();
			continue;
		}

		cout << endl;
		cout << "Mostrando los objetos del entorno..." << endl;
		cout << Enviroment::getInstancia()->getMapa()->mostrarMapa();

		cout << endl;
		cout << "Desea agregar otra creatura? (1: Si, 0: No): ";
		cin >> opcion;

		while (cin.fail() || (opcion != 0 && opcion != 1)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Opcion invalida, ingrese 0 o 1: ";
			cin >> opcion;
		}

	} while (opcion != 0);
}

void Interfaz::ingresarRecurso() {
	int opcion = 0;
	int tipo = 0;

	do {
		system("cls");
		cout << "   ---[ Ingresar Recurso ]---   " << endl;

		cout << "Seleccione el tipo de Recurso (1:Planta flor , 2: Planta Rosa, 3: Meat ). ";
		cin >> tipo;

		if (cin.fail()) {
			cin.clear();                // Limpia el error
			cin.ignore(1000, '\n');     // Ignora entrada invalida hasta el salto de linea
			cout << "Entrada invalida, por favor ingrese un numero." << endl;
			continue;
		}

		if (tipo < 1 || tipo > 3) {
			cout << "Tipo invalido. Intente de nuevo." << endl;
			continue;
		}

		try {
			shared_ptr<Recursos> nueva = FactoryResources::crearInstancia(tipo);
			Enviroment::getInstancia()->agregarRecurso(nueva);
			cout << "Recurso agregado exitosamente " << nueva->toString() << endl;
		}
		catch (const std::exception& e) {
			cout << "Error al crear el Recurso: " << e.what() << endl;
			continue;
		}

		cout << endl;
		cout << "Mostrando los objetos del entorno" << endl;
		cout << Enviroment::getInstancia()->getMapa()->mostrarMapa();


		cout << "Desea agregar otro Recurso? (1: Si, 0: No): ";
		cin >> opcion;

		while (cin.fail() || (opcion != 0 && opcion != 1)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Opcion invalida, ingrese 0 o 1: ";
			cin >> opcion;
		}

	} while (opcion != 0); // si el usuario marca 0 sale del ciclo

	cout << "\nPresione Enter para continuar...";
	cin.ignore();
	cin.get();
}

void Interfaz::ingresarRecursoAleatorios() {
	int opcion = 0;
	int maxRecursoPosible = 5;
	int agua = 0;
	int sol = 0;
	int cantRecurso = 0;

	cout << "Niveles actuales de agua y sol:\n";
	cout << "Agua: " << agua << ", Sol: " << sol << endl;

	cout << "Desea modificarlos? (1: Si, 0: No): ";
	cin >> opcion;
	cout << endl;

	while (cin.fail() || (opcion != 0 && opcion != 1)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Opcion invalida. Ingrese 0 o 1: ";
		cin >> opcion;
	}

	if (opcion == 1) {
		do {
			cout << "Ingrese el nivel de AGUA [(0) Nada, (1) Poca, (2) Mucha]: ";
			cin >> agua;
			cout << endl;

			if (cin.fail() || agua < 0 || agua > 2) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Entrada invalida. Intente nuevamente.\n";
			}
			else break;
		} while (true);

		do {
			cout << "Ingrese el nivel de SOL [(0) De noche, (1) Nublado, (2) Soleado]: ";
			cin >> sol;

			if (cin.fail() || sol < 0 || sol > 2) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Entrada invalida. Intente nuevamente.\n";
			}
			else break;
		} while (true);

		Enviroment::getInstancia()->setNivelAgua(agua);
		Enviroment::getInstancia()->setNivelSol(sol);
		cout << endl;
		cout << "Niveles actualizados exitosamente.\n\n";
	}
	//se quita mas bien, lo de crear recursos aleatorios, aqui depende del sol y el aguita, mas los tick de tiempo
	//factoryResources::crearRecursos();

	cout << "¿Desea agregar recursos manualmente? (1: Si, 0: No): ";
	cin >> opcion;

	while (cin.fail() || (opcion != 0 && opcion != 1)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Opción invalida. Ingrese 0 o 1: ";
		cin >> opcion;
	}

	if (opcion == 1) {
		do {
			cout << "Ingrese la cantidad de recursos a agregar (max " << maxRecursoPosible << "): ";
			cin >> cantRecurso;

			if (cin.fail() || cantRecurso < 0 || cantRecurso > maxRecursoPosible) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Cantidad invalida. Intente nuevamente.\n";
			}
			else break;
		} while (true);

		FactoryResources::crearRecursosPorCan(cantRecurso);
	}

	cout << "\nRecursos generados. Mostrando el entorno:\n";
	cout << Enviroment::getInstancia()->getMapa()->mostrarMapa();


	cout << "\nPresione Enter para continuar...";
	cin.ignore();
	cin.get();
}


void Interfaz::mostrarEntorno(){
	cout << "   ---[ Entorno Actual ]---   " << endl;
	cout << Enviroment::getInstancia()->getMapa()->mostrarMapa() << endl;
	cout << "Clima: " << Enviroment::getInstancia()->getClima() << endl;
	cout << "Estacion: " << Enviroment::getInstancia()->getEstacion() << endl;
	cout << "Nivel de Agua: " << Enviroment::getInstancia()->getNivelAgua() << endl;
	cout << "Nivel de Sol: " << Enviroment::getInstancia()->getNivelSol() << endl;
	
}

void Interfaz::ejecutarSimulacion(int tickTiempo){
	if (tickTiempo <= 0) {
		cerr << "El tick de tiempo debe ser un numero positivo." << endl;
		return;
	}
	Enviroment::getInstancia()->simularTickTiempo(tickTiempo);
	cout << "Simulacion ejecutada por " << tickTiempo << " ticks de tiempo." << endl;
	cout << "Mostrando el entorno actual:" << endl;
	cout << Enviroment::getInstancia()->getMapa()->mostrarMapa() << endl;
}

void  Interfaz::entornoPersonalizado() {
	int subopcion = -1;
	while (!(cin >> subopcion) || subopcion < 0 || subopcion > 3) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Opcion invalida, ingrese 0 a 2: ";
	}

	if (subopcion == 1) {
		ingresarCreatura();
	}
	if (subopcion == 2) {
		ingresarRecurso();
	}
	else if (subopcion == 3) {
		ingresarRecursoAleatorios();
	}

}

void Interfaz::iniciarSimulacion() {

	int tickTiempo = 0;
	int iniciarSimulacion = 0;

	cout << "Desea iniciar la simulacion? (1: Si, 0: No): " << endl;

	while (!(cin >> iniciarSimulacion) || (iniciarSimulacion != 0 && iniciarSimulacion != 1)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cerr << "Entrada invalida. Ingrese 0 o 1: ";
	}

	if (iniciarSimulacion == 1) {
		cout << "Ingrese los ticks de tiempo para ejecutar la simulacion: " << endl;
		while (!(cin >> tickTiempo) || tickTiempo < 0) {
			cin.clear();
			cin.ignore(1000, '\n');
			cerr << "Entrada invalida. Ingrese un numero positivo: ";
		}
		ejecutarSimulacion(tickTiempo);
		cout << "\nPresione Enter para continuar...";
		cin.ignore();
		cin.get();
	}
	else {
		cout << "Simulacion no iniciada, regresando..." << endl;
		cout << "\nPresione Enter para continuar...";
		cin.ignore();
		cin.get();
	}

}

void Interfaz::limpiarEntorno() {

	Enviroment::getInstancia()->eliminarTodo();

	cout << "Entorno limpio" << endl;

	mostrarEntorno();

	cout << "\nPresione Enter para continuar...";
	cin.ignore();
	cin.get();
	
}


void Interfaz::MostrarReporteCreaturas(){

	cout<< Enviroment::getInstancia()->mostrarCreaturas()->toString() << endl;
	cout << "\nPresione Enter para continuar...";
	cin.ignore();
	cin.get();

}
void Interfaz::MostrarReporteRecursos(){

	cout << Enviroment::getInstancia()->mostrarRecursos()->toString() << endl;
	cout << "\nPresione Enter para continuar...";
	cin.ignore();
	cin.get();

}

void Interfaz::GuardarCreaturas() {

	auto env = Enviroment::getInstancia(); 

	if (env->getLista()->estaVacia()) { 
		cout << "No hay elementos a guardar" << std::endl;
	}
	else {
		const string nombreArchivo = "creaturasYrecursos.txt";
		env->guardarDatos(nombreArchivo);
		cout << "Creaturas guardadas en archivo: " << nombreArchivo << endl;
	}
}

void Interfaz::GuardarRecursos(){
	auto env = Enviroment::getInstancia();

	if (env->getLista()->estaVacia()) {
		cout << "No hay recursos a guardar" << endl;
	}
	else {
		const string nombreArchivo = "creaturasYrecursos.txt"; 

		env->guardarDatos(nombreArchivo);

		cout << "Recursos guardados en archivo: " << nombreArchivo << endl;
	}

} 

void Interfaz::CargarCreaturas() {
	const string nombreArchivo = "creaturasYrecursos.txt"; 

	auto env = Enviroment::getInstancia(); 
	
	env->cargarDatos(nombreArchivo);

	cout << "Creaturas cargadas desde archivo: " << nombreArchivo << endl;

}

void Interfaz::CargarRecursos(){

	const string nombreArchivo = "creaturasYrecursos.txt";

	auto env = Enviroment::getInstancia(); 

	env->cargarDatos(nombreArchivo);

	cout << "Recursos cargados desde archivo: " << nombreArchivo << endl;
}

//hace falta implementar el cargar y guardar recursos y creaturas de los metodos enviroment 