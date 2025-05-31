#pragma once
#include "Objeto.h"
#include "Enviroment.h"

class Creatura;

class Recursos: public Objeto{
protected:
	int EnergyValue; // para saber cu�nto valor de energ�a brinda
	bool disponible; // para saber si est� disponible para comerlo (opcional) ver despu�s

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

