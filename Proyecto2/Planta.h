#pragma once
#include "Recursos.h"

class PlantaFlor: public Recursos{

public:

	PlantaFlor(int = 0, int = 0, int = 0);

	string toString() const override;

	string getEtiqueta() const override; 

	void guardarDatos(ofstream& archivo) const;
};



class PlantaRosa : public Recursos {

public:

	PlantaRosa(int = 0, int = 0, int = 0);

	string toString() const override;

	string getEtiqueta() const override;

	void guardarDatos(ofstream& archivo) const;
};


