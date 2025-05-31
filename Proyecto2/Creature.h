#pragma once
#include "Objeto.h"
#include "Estrategia.h"
#include <memory>
#define MAX_ENERGIA 100 // Energ�a m�xima que puede tener una criatura

class Estrategia;

class Creatura: public Objeto{
protected:
	int energ�a;
	int edad;
	shared_ptr<EstrategiaMovimiento> em;
	shared_ptr<EstrategiaReproducci�n> er;

public:
	Creatura();
	Creatura(int, int, int, int, shared_ptr<EstrategiaMovimiento>, shared_ptr<EstrategiaReproducci�n>);
	virtual ~Creatura();
	void moverse();
	void alimentarse();
	void reproducirse();
	int getEnergia();
	int getEdad();
	void AumentarEnergia(int);
	void ReducirEnerg�a(int);
	void setEdad(int);
	void setEstrategiaMovimiento(shared_ptr<EstrategiaMovimiento> );
	void setEstrategiaReproduccion(shared_ptr<EstrategiaReproducci�n>);
	bool isDead();

	virtual string toString() const override;
	string getEtiqueta() const override;
};

