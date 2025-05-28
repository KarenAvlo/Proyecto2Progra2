#pragma once
#include "Recursos.h"

class Planta: public Recursos{
public:
	Planta(int=0, int=0, int=0);
	void regenerarse() override;
	string toString() const override;
};

