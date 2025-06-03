#pragma once
#include <thread>   // Para this_thread::sleep_for
#include <chrono>   // Para chrono::seconds
#include "Lista.h"
#include "Mapa.h"

class Hervivoro;
class Omnivoro;
class Creatura;
class Planta;
class Recursos;
class Meat;

class Enviroment { // singleton

protected:
	static unique_ptr<Enviroment> instancia;

	string clima;  

	string estacion;

	shared_ptr<Mapa> mapa;

	lista<shared_ptr<Objeto>> objetos;

	Enviroment(); // constructor privado para el singleton

public:
	//singleton
	static Enviroment* getInstancia();

	//metodos de mapa
	void agregarRecurso(shared_ptr<Objeto> recurso);  
	void agregarCreatura(shared_ptr<Objeto> criatura);
	void eliminarCreatura(shared_ptr<Objeto> creatura);
	void eliminarRecurso(shared_ptr<Objeto> recurso);


	//setters
	void setClima(int cli);
	void setEstacion(string est);

	//getters
	string getClima();
	string getEstacion();


	const lista<shared_ptr<Objeto>>* getLista() const;
	shared_ptr<Mapa> getMapa() const;

	virtual string toString() const;

	bool hayPlantaCerca(Hervivoro* her) const;
	shared_ptr<Planta> getPlantaCerca(shared_ptr<Creatura> hervivoro);

	shared_ptr<Meat>getCarneCerca(shared_ptr<Creatura> depredador);

	shared_ptr<Creatura> getCreaturaDebilCerca(shared_ptr<Creatura> depredador);
	bool hayCreaturaDebilCerca(Creatura* cre) const;

	//ticks de tiempo
	void simularTiempo(int n);
	void simularTickTiempo(int maxTicks);



};

