#pragma once
#include "Objeto.h"
#include "Enviroment.h"

class Creatura;

class Recursos: public Objeto{
protected:
	int EnergyValue; // para saber cu�nto valor de energ�a brinda
	bool disponible; // para saber si est� disponible para comerlo (opcional) ver despu�s

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

