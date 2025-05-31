#pragma once
#include "Objeto.h"
#include "Enviroment.h"

class Creatura;

class Recursos: public Objeto{
protected:
	int EnergyValue; // para saber cuánto valor de energía brinda
	bool disponible; // para saber si está disponible para comerlo (opcional) ver después

public:
	Recursos(int, int, int);

	virtual ~Recursos();

	virtual string getEtiqueta() const = 0;

	virtual void regenerarse() = 0;

	virtual string toString() const = 0;

	virtual void consumir(Creatura*c);

	string formatear();

	void cargar();
};

