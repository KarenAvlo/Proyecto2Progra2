#pragma once
#include "Objeto.h"
#include "Estrategia.h"
#include "Enviroment.h"

#include <memory>
#define MAX_ENERGIA 100 // Energía máxima que puede tener una criatura

class Estrategia;

class Creatura: public Objeto{
protected:
	int energía;
	int edad;
	shared_ptr<EstrategiaMovimiento> em;
	shared_ptr<EstrategiaReproducción> er;
	shared_ptr<EstrategiaAlimentacion> ea;

public:
	Creatura();
	Creatura(int, int, int, int, shared_ptr<EstrategiaMovimiento>, shared_ptr<EstrategiaReproducción>,
		shared_ptr<EstrategiaAlimentacion>);
	virtual ~Creatura();
	void moverse();
	virtual void alimentarse() = 0;
	void reproducirse();
	int getEnergia();
	int getEdad();
	virtual void AumentarEnergia(int);
	void ReducirEnergía(int);
	void setEdad(int);
	void setEstrategiaMovimiento(shared_ptr<EstrategiaMovimiento> );
	void setEstrategiaReproduccion(shared_ptr<EstrategiaReproducción>);
	void setEstrategiaAlimentacion(shared_ptr<EstrategiaAlimentacion>);
	bool isDead();
	virtual string toString() const override;
	string getEtiqueta() const override;
};

