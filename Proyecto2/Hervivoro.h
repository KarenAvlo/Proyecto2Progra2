#pragma once
#include "Creature.h"

class Hervivoro : public Creatura {
public:
	Hervivoro(int x= 0, int  y= 0, int energia = 0,int edad = 0, EstrategiaMovimiento * em = nullptr);

	virtual ~Hervivoro() = default;

	string toString() const;

	string getEtiqueta() const override;
};

