#pragma once
#include "Lista.h"
#include "Observer.h"
#include "objectBase.h"
#include <memory>

class Subject: public Base{
private:
	shared_ptr<lista<shared_ptr<Observer>>> lo;
public:
	virtual ~Subject() = default;

	virtual void eliminar(shared_ptr<Observer> obj)=0;

	virtual void add(shared_ptr<Observer> obj)=0;

	virtual void notifyObservers() = 0;

	virtual string toString() const = 0;

};

