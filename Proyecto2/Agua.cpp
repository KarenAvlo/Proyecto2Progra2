//#include "Agua.h"
//
//  SE PUEDE VOLAR ESTA
//Agua::Agua(int xx, int yy, int ee, int nive): Recursos(xx,yy,ee), nivel(nive){}
//
//
//void Agua::regenerarse() {
//	if (Enviroment::getInstancia()->getClima() == "lluvioso") {
//		disponible = true;
//	}
//}
//
//string Agua::getEtiqueta() const{return "Agua";}
//
//void Agua::nivelAgua(int n){ //cual es la finalidad de esto?  //afecta la constancia de generacion de recursos en el entorno
//	//modificar despues
//	if (n == 0) {
//		nivel = 0; // sin agua
//	}
//	else if (n == 1) {
//		nivel = 1; // poca agua
//	}
//	else if (n == 2) {
//		nivel = 2; // mucha agua
//	}
//	else {
//		throw std::out_of_range("Nivel de agua fuera de rango");
//	}
//}
//
//string Agua::toString() const {
//	stringstream s;
//	s << "A(" << x << "," << y << ") E:" << EnergyValue; // A de Agua, sus coordenadas y respectiva energía
//	return s.str();
//}