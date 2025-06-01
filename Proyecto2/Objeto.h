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
	virtual~Objeto() = default;
	virtual string toString() const = 0;
	int getX() const;
	int getY() const;
	void setX(int );
	void setY(int );
	virtual string getEtiqueta() const = 0;
	bool operator==(const Objeto& otro) const;
};

ostream& operator<<(ostream& out, const Objeto& obj);