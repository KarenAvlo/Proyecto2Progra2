#pragma once
#include "Objeto.h"

#define MAX_ENERGIA 100 // Energía máxima que puede tener una criatura

class Creatura: public Objeto{
public:
	Creatura(int x = 0, int y = 0, int energia = 100);

	virtual ~Creatura();

	int getEnergia() const;

	void AumentarEnergia(int e);

	virtual string toString() const override;

private:
	int energia = MAX_ENERGIA;
};

