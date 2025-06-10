#pragma once

#include "Objeto.h"
#include "Estrategia.h"
#include "Enviroment.h"

#include <memory>
#include <fstream>

#define MAX_ENERGIA 100 // energia máxima que puede tener una criatura

class Estrategia;

class Creatura: public Objeto, public enable_shared_from_this<Creatura> {

	protected:

		int energia;
		int edad;

		shared_ptr<Estrategia> E;

	public:

		Creatura();
		Creatura(int, int, int, int, shared_ptr<Estrategia>); 

		virtual ~Creatura();
		virtual void atacar();
		virtual void alimentarse() = 0;
		virtual void reproducirse();
		virtual void AumentarEnergia(int);
		virtual void ReducirEnergia(int);
		virtual void guardarDatos(ofstream& archivo) const = 0;

		virtual string toString() const override;
		virtual string getEtiqueta() const override;

		virtual bool isDead() const;

		void AumentarEdad();
		void moverse();
		void setEdad(int); 
		void setEstrategia(shared_ptr<Estrategia>);

		int getEnergia();
		int getEdad();
};

