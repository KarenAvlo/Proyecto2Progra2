#pragma once
#include "Lista.h"
#include "Mapa.h"
class Hervivoro;
class Creatura;
class Planta;

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

	//setters
	void setClima(int cli);
	void setEstacion(string est);

	//getters
	string getClima();
	string getEstación();


	shared_ptr<Mapa> getMapa() const;

	virtual string toString() const;

	bool hayPlantaCerca(Hervivoro* her) const;

	bool hayCreaturaDebilCerca(Creatura* cre );

};

