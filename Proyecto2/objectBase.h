#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Base {
public:
	virtual~Base() = default;
	virtual string toString() const = 0;
};

ostream& operator<<(ostream& out, const Base& obj);
