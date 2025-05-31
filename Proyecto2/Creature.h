#pragma once
#include "Objeto.h"
#include "Estrategia.h"


#define MAX_ENERGIA 100 // Energía máxima que puede tener una criatura
class Estrategia;

class Creatura: public Objeto{
private:
	int energía;
	int edad;
	EstrategiaMovimiento* em;

public:
	Creatura(int, int, int, int, EstrategiaMovimiento*);
	~Creatura();
	void moverse();
	void alimentarse();
	void reproducirse();
	int getEnergia();
	int getEdad();
	void AumentarEnergia(int);
	void setEdad(int);
	virtual string toString() const override;
	virtual string getEtiqueta() const override;
};

