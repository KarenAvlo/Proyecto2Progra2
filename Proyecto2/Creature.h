#pragma once
#include "Objeto.h"
#include "Estrategia.h"
#include "Enviroment.h"
#include <memory>
#include <fstream>

#define MAX_ENERGIA 100 // energia máxima que puede tener una criatura

class Estrategia;

class Creatura: public Objeto, public enable_shared_from_this<Creatura> {
protected:
	int energia;

	int edad;

	shared_ptr<Estrategia> E;

public:
	Creatura();

	Creatura(int, int, int, int, shared_ptr<Estrategia>);

	virtual ~Creatura();

	void moverse();

	virtual void alimentarse() = 0;

	virtual void atacar() = 0;

	void reproducirse();

	int getEnergia();

	int getEdad();

	virtual void AumentarEnergia(int);
	void ReducirEnergia(int);
	void setEdad(int);
	void setEstrategia(shared_ptr<Estrategia>);

	bool isDead();
	virtual string toString() const override;
	string getEtiqueta() const override;

	virtual void guardarDatos(ofstream& archivo) const = 0;
};

