//#include "FactoryResources.h"
//#include "Agua.h"
//#include "Planta.h"
//#include "Meat.h"
//
//// se podría hacer con punteros inteligentes
//
//shared_ptr<Recursos> FactoryResources::crearInstancia(int t) {
//	shared_ptr<Observer> re = nullptr;
//	switch (t) {
//	case 1:
//		//hay que hacer cambio
//		re = make_shared<Agua>();
//		break;
//	case 2:
//		re = make_shared<Planta>();
//		break;
//	case 3:
//		re = make_shared<Meat>();
//		break;
//	default:
//		std::cerr << "Tipo desconocido: " << t << std::endl;
//		break;
//
//	}
//	return re;
//}
//
//shared_ptr<Criatura> FactoryResources::crearInstancia(int x, int y, int op)
//{
//	shared_ptr<Observer> cr = nullptr;
//	switch (op)
//	{
//	case 1: {// Criatura tipo hervivora
//		cr = make_shared<Criatura>(x, y);
//	}break;
//			
//	case 2: {// Criatura tipo  carnes
//		cr = make_shared<Criatura>(x, y);
//	}break;
//
//		case 3:{ // Criatura tipo de todo un poco
//			cr = make_shared<Criatura>(x, y);
//		}break;
//		default: {
//			std::cerr << "Tipo de criatura desconocido: " << op << std::endl;
//			
//	}
//		break;
//	}
//	return cr;
//}
//
