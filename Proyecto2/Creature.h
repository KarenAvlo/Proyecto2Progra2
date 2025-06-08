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
	shared_ptr<EstrategiaAtaque> E2; // Estrategia de ataque

public:
	Creatura();

	Creatura(int, int, int, int, shared_ptr<Estrategia>, shared_ptr<EstrategiaAtaque>);

	virtual ~Creatura();

	void moverse();

	EstrategiaAtaque* getEstrategiaAtaque() const;

	virtual void setEstrategiaAtaque(shared_ptr<EstrategiaAtaque> estrategia);

	virtual void recibirDanio(int danio);

	virtual void atacar(Creatura&);

	virtual void ejecutarEstrategia();

	virtual void alimentarse() = 0;

	virtual void reproducirse();

	int getEnergia();

	int getEdad();

	void AumentarEdad();

	virtual void AumentarEnergia(int);

	void ReducirEnergia(int);

	void setEdad(int); //no necesitamos cambiar la edad

	void setEstrategia(shared_ptr<Estrategia>);

	virtual bool isDead() const;

	virtual string toString() const override;

	virtual void guardarDatos(ofstream& archivo) const = 0;

	virtual string getEtiqueta() const override;
};

