#pragma once
#include "Creature.h"

class Carnívoro: public Creatura{
public:
	Carnívoro(int x = 0, int  y = 0, int energia = 0, int edad = 0, shared_ptr<EstrategiaMovimiento> em = nullptr,
		shared_ptr<EstrategiaReproducción> er = nullptr, shared_ptr<EstrategiaAlimentacion> ea = nullptr);

	virtual ~Carnívoro() = default;

	string toString() const override;

	string getEtiqueta() const override;

	void alimentarse() override;


};

