#pragma once

#include "Creature.h"

class Carnivoro: public Creatura {

	public:

		Carnivoro(int x = 0, int  y = 0, int energia = 0, int edad = 0,
			shared_ptr<Estrategia> = nullptr);

		virtual ~Carnivoro() = default;

		string toString() const override;
		string getEtiqueta() const override;

		virtual void atacar() override;

		void reproducirse() override;
		void alimentarse() override;
		void guardarDatos(ofstream& archivo) const override;
};

