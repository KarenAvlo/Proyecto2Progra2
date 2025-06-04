#pragma once
#include <thread>   // Para this_thread::sleep_for
#include <chrono>  // Para chrono::seconds
#include <fstream>
#include "Lista.h"
#include "Mapa.h"
#include "Recursos.h"

class Hervivoro;
class Omnivoro;
class Creatura;
class Planta;
class Recursos;
class Meat;

class Enviroment { // singleton

protected:
	int nivelAguita; 
	int nivelSol; 

	string clima;
	string estacion;
	shared_ptr<Mapa> mapa;
	shared_ptr<Recursos> recurso; 
	static unique_ptr<Enviroment> instancia;
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
	//agua, sol
	void setNivelAgua(int nivel);
	void setNivelSol(int nivel);


	//getters
	string getClima();
	string getEstacion();
	int getNivelAgua() const;
	int getNivelSol() const;

	int getAnchoMapa() const;
	int getAltoMapa() const;

	const lista<shared_ptr<Objeto>>* getLista() const;
	shared_ptr<lista<shared_ptr<Creatura>>>mostrarCreaturas() const;
	shared_ptr < lista < shared_ptr < Recursos >> > mostrarRecursos() const;

	shared_ptr<Mapa> getMapa() const;

	virtual string toString() const;

	int generarIntervaloDeRegeneracionRecursos()const;
	void generarRecursos();

	bool hayPlantaCerca(Hervivoro* her) const;
	shared_ptr<Planta> getPlantaCerca(shared_ptr<Creatura> hervivoro);

	shared_ptr<Meat>getCarneCerca(shared_ptr<Creatura> depredador);

	shared_ptr<Creatura> getCreaturaDebilCerca(shared_ptr<Creatura> depredador);
	bool hayCreaturaDebilCerca(Creatura* cre) const;

	//ticks de tiempo
	//void simularTiempo(int n);
	void simularTickTiempo(int maxTicks);

	//entornos aleatorios
	void generarAleatorio(int ancho, int alto, int cantCriaturas, int cantRecursos, int nivelAgua, int nivelSol);

	void guardarCreaturasEnArchivo(const string& nombreArchivo) const;

};

