#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Observer {
public:
	virtual void update() = 0;
};

