#pragma once

#include "Recursos.h"

class Meat: public Recursos {

	public:

		Meat(int = 0, int = 0, int = 0);

		string getEtiqueta() const override;

		string toString() const override;

		void guardarDatos(ofstream& archivo) const;
};

