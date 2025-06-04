#include "Interfaz.h"

Interfaz::Interfaz(){}
Interfaz::~Interfaz(){}

void Interfaz::generarAleatorio()
{
	//para entornos completamente aleatorios
	cout << "   --- Generando Entorno Aleatorio ---   " << endl;

}

void Interfaz::ingresarCreatura() {
	int opcion = 0;
	int tipo = 0;

	do {
		system("cls"); 
		cout << "   --- Ingresar Creatura ---   " << endl;

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
		cout << Enviroment::getInstancia()->getLista()->toString();

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
	int agua = 0;
	int sol = 0;

	do {
		cout << "   --- Generar Recurso ---   " << endl;

		cout << "Nivel de AGUA: [(0)Nada, (1)Poca, (2)Mucha] ";
		cin >> agua;

		if (cin.fail()) {
			cin.clear();                // Limpia el error
			cin.ignore(1000, '\n');     // Ignora entrada inválida hasta el salto de línea
			cout << "Entrada invalida, por favor ingrese un numero." << endl;
			continue;
		}

		if (agua < 0 || agua > 2) {
			cerr << "Tipo invalido. Intente de nuevo." << endl;
			continue;
		}

		cout << "Nivel de SOL: [(0)De noche, (1)Nublado, (2)Soleado] " << endl;
		cin >> sol;
		Enviroment::getInstancia()->setNivelAgua(agua);
		Enviroment::getInstancia()->setNivelSol(sol);
		cout << "Recurso agregado exitosamente "<<endl;

		Enviroment::getInstancia()->generarRecursos(); // Genera recursos basados en los niveles de agua y sol

		cout << endl;
		cout << "Mostrando los objetos del entorno" << endl;
		cout << Enviroment::getInstancia()->getLista()->toString();
		break;
		//cout << "Desea agregar otro Recurso? (1: Si, 0: No): ";
		//cin >> opcion;

		while (cin.fail() || (opcion != 0 && opcion != 1)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Opcion invalida, ingrese 0 o 1: ";
			cin >> opcion;
		}

	} while (opcion != 0); // si el usuario marca 0 sale del ciclo
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