#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Objeto {
protected:
	int x;
	int y;
public:
	Objeto(int = 0, int = 0);
	~Objeto() = default;
	virtual string toString() const = 0;
	int getX();
	int getY();
	void setX(int );
	void setY(int );
	virtual string getEtiqueta() const = 0;
};

ostream& operator<<(ostream& out, const Objeto& obj);