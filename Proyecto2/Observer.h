#pragma once
#include "objectBase.h"

class Observer :public Base{
public:
	virtual void update() = 0;
	virtual string toString() const = 0;


	//para recursos y criaturas
	int getPosX() const { return posX; }
	int getPosY() const { return posY; }
	void setPosX(int x) { posX = x; }
	void setPosY(int y) { posY = y; }

protected:
	int posX;
	int posY;
};

