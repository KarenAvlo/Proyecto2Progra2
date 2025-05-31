#pragma once
#include "Objeto.h"
#include "Estrategia.h"
#include <memory>
#define MAX_ENERGIA 100 // Energía máxima que puede tener una criatura

class Estrategia;

class Creatura: public Objeto{
protected:
	int energía;
	int edad;
	shared_ptr<EstrategiaMovimiento> em;
	shared_ptr<EstrategiaReproducción> er;

public:
	Creatura();
	Creatura(int, int, int, int, shared_ptr<EstrategiaMovimiento>, shared_ptr<EstrategiaReproducción>);
	virtual ~Creatura();
	void moverse();
	void alimentarse();
	void reproducirse();
	int getEnergia();
	int getEdad();
	void AumentarEnergia(int);
	void ReducirEnergía(int);
	void setEdad(int);
	void setEstrategiaMovimiento(shared_ptr<EstrategiaMovimiento> );
	void setEstrategiaReproduccion(shared_ptr<EstrategiaReproducción>);
	bool isDead();

	virtual string toString() const override;
	string getEtiqueta() const override;
};

