#pragma once
class Creatura;
class Enviroment;


class Estrategia {
public:
	virtual void EjecutarEstrategia(Creatura* c) = 0;
};


//--------------------derivadas de estrategia------------------------

class EstrategiaReproducción:public Estrategia {
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
//---derivada de alimentación, canívoro y hervíboro

class EstrategiaAlimentacionC :public EstrategiaAlimentacion {
public:
	virtual void EjecutarEstrategia(Creatura* c) override;
};

//
//class EstrategiaAlimentacionH :public EstrategiaAlimentacion {
//public:
//	virtual void EjecutarEstrategia(Creatura* c) override;
//};

