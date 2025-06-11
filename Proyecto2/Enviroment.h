#pragma once
#include <thread>   // Para this_thread::sleep_for
#include <chrono>  // Para chrono::seconds y que dure un segundo los ticks
#include <fstream>

#include "Lista.h"
#include "Mapa.h"
#include "Recursos.h"

class Herbivoro;
class Omnivoro;
class Creatura;
class Planta;
class Recursos;
class Meat;

static int tickGlobal = 0;

class Enviroment { // singleton
	public:

		//singleton
		static Enviroment* getInstancia();

		~Enviroment() = default; // destructor por defecto

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

		bool hayPlantaCerca(shared_ptr<Creatura> cre) const;
		bool hayHerviroroCerca(shared_ptr<Creatura> cre) const;
		bool hayCarnivoroCerca(shared_ptr<Creatura> cre) const;
		bool hayOmnivoroCerca(shared_ptr<Creatura> cre) const;
		bool hayCarneCerca(shared_ptr<Creatura> cre) const;

		shared_ptr<Recursos> getPlantaCerca(shared_ptr<Creatura> hervivoro);
		shared_ptr<Meat>getCarneCerca(shared_ptr<Creatura> depredador);
		shared_ptr<Creatura> getCreaturaDebilCerca(shared_ptr<Creatura> depredador);
		shared_ptr<Creatura> getCreaturaFuerteCerca(shared_ptr<Creatura> depredador);
		
		void ticksDeRecursos();
		void isDeadtoMeat();
		void eliminarTodo();
		void simularTickTiempo(int maxTicks); //ticks de tiempo

		void guardarDatosCreaturas(const string& nombreArchivo);
		void guardarDatosRecursos(const string& nombreArchivo);
		void cargarDatosCreaturas(const string& nombreArchivo);
		void cargarDatosRecursos(const string& nombreArchivo);

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
};

