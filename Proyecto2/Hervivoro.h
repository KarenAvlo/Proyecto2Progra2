#pragma once
#include "Criatura.h"
class Hervivoro : public Criatura 
{
public:
	Hervivoro(int x = 0, int y = 0, int energia = 0);
	virtual ~Hervivoro() = default;

    void update();
	string toString() const;

	string getEtiqueta() const override;
private:
	int energia;
	int posX;
	int posY;
};

