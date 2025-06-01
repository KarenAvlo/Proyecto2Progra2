#pragma once
#include "Creature.h"

class Carn�voro: public Creatura{
public:
	Carn�voro(int x = 0, int  y = 0, int energia = 0, int edad = 0, shared_ptr<EstrategiaMovimiento> em = nullptr,
		shared_ptr<EstrategiaReproducci�n> er = nullptr, shared_ptr<EstrategiaAlimentacion> ea = nullptr);

	virtual ~Carn�voro() = default;

	string toString() const override;

	string getEtiqueta() const override;

	void alimentarse() override;


};

