#include "Interfaz.h"

Interfaz::Interfaz(){}
Interfaz::~Interfaz(){}

void Interfaz::generarAleatorio()
{
	//para entornos completamente aleatorios
	cout << "   --- Generando Entorno Aleatorio ---   " << endl;

}

void Interfaz::ingresarCreatura(int op) {
	int opcion = op;
	int tipo = 0;

	do {
		system("cls"); 
		cout << "   ---[ Generar Creatura ]---   " << endl;

		cout << "Seleccione el tipo de Creatura (1:Hervivoro , 2:Carnivoro, 3:Omnivoro): ";
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

void Interfaz::ingresarRecurso(int a, int s) {
	int opcion = 0;
	int maxRecursoPosible = 5;
	int agua = a;
	int sol = s;
	int cantRecurso = 0;

	cout << "Los niveles actuales de AGUA y SOL son:" << endl;
	cout << "Agua: " << agua << ", Sol: " << sol << endl;
	cout << "Desea cambiarlos? (1: Si, 0: No): ";
	cin >> opcion;
	cout << string(50, '-') << endl;

	while (cin.fail() || (opcion != 0 && opcion != 1)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Opcion invalida, ingrese 0 o 1: ";
		cin >> opcion;
	}

	if (opcion == 1) {
		do {
			cout << "Nivel de AGUA: [(0)Nada, (1)Poca, (2)Mucha]: ";
			cin >> agua;

			if (cin.fail() || agua < 0 || agua > 2) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Entrada invalida, ingrese un numero entre 0 y 2." << endl;
			}
			else break;
		} while (true);

		do {
			cout << "Nivel de SOL: [(0)De noche, (1)Nublado, (2)Soleado]: ";
			cin >> sol;

			if (cin.fail() || sol < 0 || sol > 2) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Entrada invalida, ingrese un numero entre 0 y 2." << endl;
			}
			else break;
		} while (true);
		Enviroment::getInstancia()->setNivelAgua(agua);
		Enviroment::getInstancia()->setNivelSol(sol);
		cout << "Niveles actualizados exitosamente." << endl;
	}

	// Generar automaticamente los recursos segun los niveles de agua y sol
	Enviroment::getInstancia()->generarRecursos();

	//pos si quiere agregar recursos manualmente pero en cant
	cout << "Desea agregar recursos manualmente? (1: Si, 0: No): ";
	cin >> opcion;

	while (cin.fail() || (opcion != 0 && opcion != 1)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Opcion invalida, ingrese 0 o 1: ";
		cin >> opcion;
	}

	if (opcion == 1) {
		do {
			cout << "Ingrese la cantidad de recursos a agregar (max " << maxRecursoPosible << "): ";
			cin >> cantRecurso;

			if (cin.fail() || cantRecurso < 0 || cantRecurso > maxRecursoPosible) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Cantidad invalida. Debe ser entre 0 y " << maxRecursoPosible << "." << endl;
			}
			else break;
		} while (true);

		Enviroment::getInstancia()->agregarRecursoPorCan(cantRecurso); // Agrega recursos manuales
	}

	cout << "\nRecursos generados. Mostrando el entorno:\n";
	cout << Enviroment::getInstancia()->getMapa()->mostrarMapa();
}



void Interfaz::MostrarEntornoAndInteractions(){}

void Interfaz::MostrarReporteCreaturas(){
	

	cout<< Enviroment::getInstancia()->mostrarCreaturas()->toString() << endl;
}
void Interfaz::MostrarReporteRecursos(){
	cout << Enviroment::getInstancia()->mostrarCreaturas() << endl;
}

void Interfaz::GuardarCreaturas() {
	ofstream archivo("creaturas_guardadas.txt"); 
	if (!archivo.is_open()) { 
		cerr << "Error al abrir archivo para guardar criaturas\n"; 
		return;
	}

	// Obtener todas las criaturas y guardarlas si están vivas
	auto listaCreaturas = Enviroment::getInstancia()->mostrarCreaturas(); 

	for (const auto& c : *listaCreaturas) { 
		if (!c->isDead()) {
			c->guardarDatos(archivo); 
		} 
	}
	archivo.close(); 
	cout << "Creaturas guardadas correctamente.\n"; 
}

void Interfaz::GuardarRecursos(){} 

void Interfaz::CargarCreaturas() {
	std::ifstream archivo("creaturas_guardadas.txt");
	if (!archivo.is_open()) {
		std::cerr << "Error al abrir archivo para cargar criaturas\n";
		return;
	}

	Enviroment* env = Enviroment::getInstancia();

	std::string linea;
	while (std::getline(archivo, linea)) {
		std::stringstream ss(linea);
		std::string tipo;
		std::getline(ss, tipo, ',');

		int x, y, energia, edad;
		char coma;

		ss >> x >> coma >> y >> coma >> energia >> coma >> edad;

		// Crear instancia dependiendo del tipo
		shared_ptr<Creatura> nueva;

		if (tipo == "Hervivoro") {
			nueva = make_shared<Hervivoro>(x, y, energia, edad);
		}
		else if (tipo == "Carnivoro") {
			nueva = make_shared<Carnívoro>(x, y, energia, edad);
		}
		else if (tipo == "Omnivoro") {
			nueva = make_shared<Omnivoro>(x, y, energia, edad);
		}
		else {
			std::cerr << "Tipo desconocido: " << tipo << "\n";
			continue;
		}

		env->agregarCreatura(nueva);
	}
	archivo.close();
	std::cout << "Creaturas cargadas correctamente.\n";
}

void Interfaz::CargarRecursos(){}