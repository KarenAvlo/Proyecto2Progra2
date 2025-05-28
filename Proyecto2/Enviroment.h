#pragma once
#include "Subject.h"


class Enviroment:public Subject{ // singleton
protected:
	static unique_ptr<Enviroment> instancia;
	Enviroment();
	string clima;
	string estacion;
	int energia;
	shared_ptr<lista<shared_ptr<Observer>>> observers;
public:
	//singleton
	static Enviroment* getInstancia();

	//metodos derivados de subject
	void eliminar(shared_ptr<Observer> obj) override;
	void add(shared_ptr<Observer> obj)override;
	void notifyObservers() override;

	//setters
	void setClima(string cli);
	void setEstacion(string est);
	void setEnergia(int Energy);

	//getters
	string getClima();
	string getEstación();
	int getEnergia();

};

