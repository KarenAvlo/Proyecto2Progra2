#pragma once
#include "Subject.h"
#include "Mapa.h"

//Entorno
class Enviroment: public Subject{ // singleton
protected:
	static unique_ptr<Enviroment> instancia;
	string clima;  //esto se puede cambiar a int para solo crear 3 tipos por asi decirlo /soleado/lluvioso/nublado
	string estacion;
	int energia;  // energia de que?
	shared_ptr<Mapa> mapa;
	shared_ptr<lista<shared_ptr<Observer>>> observers;

	Enviroment(); // constructor privado para el singleton

public:
	//singleton
	static Enviroment* getInstancia();

	//metodos derivados de subject
	void eliminar(shared_ptr<Observer> obj) override;
	void add(shared_ptr<Observer> obj)override;
	void notifyObservers() override;

	//metodos de mapa
	void agregarRecurso(shared_ptr<Mapa> m, shared_ptr<Observer> recurso);  //para ir agregando al mapilla
	void agregarCriatura(shared_ptr<Mapa> m, shared_ptr<Observer> criatura);

	//setters
	void setClima(int cli);
	void setEstacion(string est);
	void setEnergia(int Energy);

	//getters
	string getClima();
	string getEstación();
	int getEnergia();
	shared_ptr<lista<shared_ptr<Observer>>> getLista();
	shared_ptr<Mapa> getMapa() const;

	virtual string toString() const override;

};

