#pragma once
#include "Creature.h"

class Carn�voro: public Creatura{
public:

	Carn�voro(int x = 0, int  y = 0, int energia = 0, int edad = 0, shared_ptr<Estrategia> =nullptr);

	virtual ~Carn�voro() = default;

	string toString() const override;

	string getEtiqueta() const override;

	void alimentarse() override;

	void atacar() override;

	void guardarDatos(ofstream& archivo) const override;

};

