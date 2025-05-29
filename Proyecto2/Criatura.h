#pragma once
#include "objectBase.h"
#include "Observer.h"

#define MAX_ENERGIA 100 // Energía máxima que puede tener una criatura

class Criatura : public Observer
{
public:
	Criatura(int x = 0, int y = 0, int energia = 100);
	virtual ~Criatura();

	virtual void update() override;

	// Getters y Setters
	int getEnergia() const;
	void setEnergia(int e);

	int getPosX() const;
	int getPosY() const;

	void setPosX(int x);
	void setPosY(int y);

	virtual string toString() const override;

private:
	int energia = MAX_ENERGIA	;
	int posX;  
	int posY;
	
};

