#pragma once
#include "Creature.h"

class Hervivoro :public Creatura {
public:
	Hervivoro(int x= 0, int  y= 0, int energia = 0,int edad = 0, shared_ptr<EstrategiaMovimiento> em = nullptr,
		shared_ptr<EstrategiaReproducción> er = nullptr);

	virtual ~Hervivoro() = default;

	string toString() const override;

	string getEtiqueta() const override;
};

