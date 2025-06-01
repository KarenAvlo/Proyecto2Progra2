#pragma once
#include "Recursos.h"

class Agua: public Recursos{
public:
	Agua(int = 0, int = 0, int = 0, int = 0);
	void regenerarse() override;
	string getEtiqueta() const override;

	void nivelAgua(int n);
	string toString() const override;

protected:
	int nivel; // nivel de agua, por ejemplo, 1 para poca agua, 2 para media, 3 para mucha
};

