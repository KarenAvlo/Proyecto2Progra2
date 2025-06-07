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

class EstrategiaAlimentacion:public Estrategia {
public:
	 void EjecutarEstrategia(shared_ptr<Creatura> c) = 0;
};

class EstrategiaMovimiento :public Estrategia {
public:
	  void EjecutarEstrategia(shared_ptr<Creatura> c) override;
};


class EstrategiaAtaque :public Estrategia {
public:
	virtual void EjecutarEstrategia(shared_ptr<Creatura> c) override;
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
