#include "Hervivoro.h"

Hervivoro::Hervivoro(int x, int y, int energia) 
	: Criatura(x, y, energia)
{}

void Hervivoro::update()
{
}

string Hervivoro::toString() const
{
	return "nada";
}

string Hervivoro::getEtiqueta() const
{
	return "Hervivoro";
}
