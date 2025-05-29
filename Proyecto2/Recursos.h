#pragma once
#include "Observer.h"
#include "Enviroment.h"

class Recursos: public Observer{
protected:
	int x; 
	int y; 
	int EnergyValue; // para saber cuánto valor de energía brinda
	bool disponible; // para saber si está disponible para comerlo (opcional) ver después
public:
	Recursos(int, int, int);

	virtual ~Recursos() = default;

	void update() override;

	virtual void regenerarse() = 0;

	virtual string toString() const = 0;

	void consumir();

	string formatear();

	void cargar();

	//faltan getters y setters

};

