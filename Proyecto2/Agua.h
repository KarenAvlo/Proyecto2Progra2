#pragma once
#include "Recursos.h"

class Agua: public Recursos{
public:
	Agua(int = 0 , int = 0, int = 0);
	void regenerarse() override;
	string toString() const override;
};

