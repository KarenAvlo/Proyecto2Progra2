#pragma once
#include "Creature.h"

class Omnivoro: public Creatura{
	public:
	Omnivoro(int x = 0, int  y = 0, int energia = 0, int edad = 0, 
		shared_ptr<Estrategia> em = nullptr, shared_ptr<EstrategiaAtaque> = nullptr);

	virtual ~Omnivoro() = default;

	string toString() const override;

	string getEtiqueta() const override;

	void alimentarse() override;

	 void atacar(Creatura& obj) override;

	 void setEstrategiaAtaque(shared_ptr<EstrategiaAtaque> estrategia) override;

	 void recibirDanio(int danio) override;

	 void guardarDatos(ofstream& archivo) const override;

};

