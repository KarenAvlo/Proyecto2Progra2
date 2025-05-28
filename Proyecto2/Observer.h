#pragma once
#include "objectBase.h"

class Observer :public Base{
public:
	virtual void update() = 0;
	virtual string toString() const = 0;
};

