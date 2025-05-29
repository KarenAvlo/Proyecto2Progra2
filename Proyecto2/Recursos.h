#pragma once
#include "Observer.h"
#include "Enviroment.h"

class Recursos: public Observer{
protected:
	int EnergyValue; // para saber cu�nto valor de energ�a brinda
	bool disponible; // para saber si est� disponible para comerlo (opcional) ver despu�s
public:
	Recursos(int, int, int);

	virtual ~Recursos() = default;

	void update() override;

	virtual string getEtiqueta() const = 0;

	virtual void regenerarse() = 0;

	virtual string toString() const = 0;

	void consumir();

	string formatear();

	void cargar();

	//faltan getters y setters

};

