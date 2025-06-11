#pragma once

#include "Creature.h"

class Herbivoro : public Creatura {
	public:

		Herbivoro(int x = 0, int  y = 0, int energia = 0, int edad = 0, 
			shared_ptr<Estrategia> estrategia = nullptr);

		virtual ~Herbivoro() = default;

		string toString() const override;
		string getEtiqueta() const override;

		void reproducirse() override;
		void alimentarse() override;
		void atacar() override;

		void ReducirEnergia(int e) override;
		void guardarDatos(ofstream& archivo) const override;
		void setFueHerido(bool);

	private:

		bool fueHerido = false; 
};

