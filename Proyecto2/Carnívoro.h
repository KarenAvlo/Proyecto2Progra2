#pragma once
#include "Creature.h"

class Carnívoro: public Creatura{
public:

	Carnívoro(int x = 0, int  y = 0, int energia = 0, int edad = 0, shared_ptr<Estrategia> =nullptr);

	virtual ~Carnívoro() = default;

	string toString() const override;

	string getEtiqueta() const override;

	void alimentarse() override;

	void atacar() override;

	void guardarDatos(ofstream& archivo) const override;

};

