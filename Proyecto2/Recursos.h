#pragma once
#include "Objeto.h"
#include "Enviroment.h"

class Creatura;

class Recursos: public Objeto{
protected:
	int EnergyValue; // para saber cuánto valor de energía brinda
	bool disponible; // para saber si está disponible para comerlo (opcional) ver después

public:
	Recursos(int=0, int=0, int=0);

	virtual ~Recursos();

	virtual string getEtiqueta() const override;

	virtual void regenerarse();

	virtual string toString() const override;

	void consumir(Creatura* c);

	string formatear();

	void cargar();
};

