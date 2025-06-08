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


//--------------------derivadas de estrategia de ataque------------------------
class EstrategiaAtaque :public Estrategia {
public:
	virtual ~EstrategiaAtaque() = default;
	virtual void EjecutarEstrategia(shared_ptr<Creatura> c) = 0;
	virtual int calcularDanio() = 0;
	virtual string getTipoAtaque() = 0;  //dos tipos, debil, fuerte  
};
 
class EstrategiaAtaqueAleatorio :public EstrategiaAtaque {
public:
	void EjecutarEstrategia(shared_ptr<Creatura> c) override;
	int calcularDanio() override;
	string getTipoAtaque() override;
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

class EstrategiaAtaqueH :public EstrategiaAtaque {
public:
	void EjecutarEstrategia(shared_ptr<Creatura> c) override;
	int calcularDanio() override;
	string getTipoAtaque() override;
};

class EstrategiaAtaqueC :public EstrategiaAtaque {
public:
	void EjecutarEstrategia(shared_ptr<Creatura> c) override;
	int calcularDanio() override;
	string getTipoAtaque() override;
};

class EstrategiaAtaqueO :public EstrategiaAtaque {
public:
	void EjecutarEstrategia(shared_ptr<Creatura> c) override;
	int calcularDanio() override;
	string getTipoAtaque() override;
};