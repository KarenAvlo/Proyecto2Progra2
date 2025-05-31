#pragma once
class Creatura;
class Enviroment;


class Estrategia {
public:
	virtual void EjecutarEstrategia(Creatura* c) = 0;
};


//--------------------derivadas de estrategia------------------------

class EstrategiaReproducci�n:public Estrategia {
	public:
		virtual void EjecutarEstrategia(Creatura* c);
};

class EstrategiaAlimentacion:public Estrategia {
public:
	virtual void EjecutarEstrategia(Creatura* c) = 0;
};

class EstrategiaMovimiento :public Estrategia {
public:
	virtual void EjecutarEstrategia(Creatura* c) override;
};

//
//class EstrategiaAtaque :public Estrategia {
//public:
//	virtual void EjecutarEstrategia(Creatura* c) override;
//};
//
//class EstrategiaDefensa :public Estrategia {
//public:
//	virtual void EjecutarEstrategia(Creatura* c) override;
//};
//
// 
// 
//---derivada de alimentaci�n, can�voro y herv�boro

class EstrategiaAlimentacionC :public EstrategiaAlimentacion {
public:
	virtual void EjecutarEstrategia(Creatura* c) override;
};

//
//class EstrategiaAlimentacionH :public EstrategiaAlimentacion {
//public:
//	virtual void EjecutarEstrategia(Creatura* c) override;
//};

