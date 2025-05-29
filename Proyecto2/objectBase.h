#pragma once
#include <iostream>
#include <sstream>
#include <memory>	
using namespace std;

class Base {
public:
	virtual~Base() = default;
	virtual string toString() const = 0;

};

ostream& operator<<(ostream& out, const Base& obj);
