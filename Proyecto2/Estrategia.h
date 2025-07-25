#pragma once

class Creatura;
class Enviroment;

class Estrategia {

	public:

		virtual void EjecutarEstrategia(shared_ptr<Creatura> c) = 0;

		virtual ~Estrategia() = default;
};

//--------------------derivadas de estrategia------------------------

class EstrategiaReproduccion:public Estrategia {
	public:

		 void EjecutarEstrategia(shared_ptr<Creatura> c);
};

class EstrategiaMovimiento :public Estrategia {
public:

	void EjecutarEstrategia(shared_ptr<Creatura> c) override;
};

class EstrategiaAlimentacion:public Estrategia {
	public:

		 void EjecutarEstrategia(shared_ptr<Creatura> c) = 0;
};


 
//---derivada de alimentación, canívoro, hervíboro y omnivoro

class EstrategiaAlimentacionC :public EstrategiaAlimentacion {
	public:

		 void EjecutarEstrategia(shared_ptr<Creatura> c) override;
};


class EstrategiaAlimentacionH :public EstrategiaAlimentacion {
	public:

		 void EjecutarEstrategia(shared_ptr<Creatura> c) override;
};

class EstrategiaAlimentacionO :public EstrategiaAlimentacion {
	public:

		void EjecutarEstrategia(shared_ptr<Creatura> c) override;
};

//------------------------ATAQUE----------------------------

//--------------------derivadas de estrategia de ataque------------------------
class EstrategiaAtaque :public Estrategia {
	public:

		virtual ~EstrategiaAtaque() = default;

		virtual void EjecutarEstrategia(shared_ptr<Creatura> c) = 0;
};

class EstrategiaAtaqueH :public EstrategiaAtaque {
	public:

		void EjecutarEstrategia(shared_ptr<Creatura> c) override;
};

class EstrategiaAtaqueC :public EstrategiaAtaque {
	public:

		void EjecutarEstrategia(shared_ptr<Creatura> c) override;
};

class EstrategiaAtaqueO :public EstrategiaAtaque {
	public:

		void EjecutarEstrategia(shared_ptr<Creatura> c) override;	
};