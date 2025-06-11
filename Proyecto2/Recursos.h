#pragma once
#include "Objeto.h"
#include "Enviroment.h"

class Creatura;

class Recursos: public Objeto{
protected:
	int EnergyValue; // para saber cu�nto valor de energ�a brinda

public:
	Recursos(int=0, int=0, int=0);

	virtual ~Recursos();

	virtual string getEtiqueta() const override;

	virtual string toString() const override;

	virtual void guardarDatos(ofstream& archivo) const = 0;
};

