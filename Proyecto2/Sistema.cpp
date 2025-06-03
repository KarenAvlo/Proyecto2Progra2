#include "Sistema.h"
#include "visuales.h"
#include "utilitarios.h"

Sistema::Sistema(){
	i= make_shared<Interfaz>();
}
Sistema::~Sistema(){
// la memoria se libera sola :)
}

// Lógica de los submenús:
void Sistema::mostrarMenuPrincipal(){
	int opcion;

	do {

		//limpiarPantallaPortable();
		visualMenuPrincipal();

		cin >> opcion;
	/*	opcion = obtenerOpcion(0, 4);*/

		switch (opcion) {

		case 0:
		/*	limpiarPantallaPortable();*/
			cout << "Salida exitosa..." << endl;
			break;

		case 1:
			mostrarSubmenuRegistroDatos();
			break;

		case 2:
			mostrarSubmenuModificacionDatos();
			break;

		case 3:
			mostrarSubmenuReportes();
			break;

		case 4:
			mostrarSubmenuPersistenciaDeDatos();
			break;
		}

	} while (opcion != 0);

}
void Sistema::mostrarSubmenuRegistroDatos(){
	int opcion;

	do {

		/*limpiarPantallaPortable();*/
		visualsubmenuRegistro();

		cin >> opcion;
		/*	opcion = obtenerOpcion(0, 4);*/

		switch (opcion) {

		case 0:
			break;

		case 1:
			/*	limpiarPantallaPortable();*/
			i->ingresarCreatura();
			break;

		case 2:
			/*limpiarPantallaPortable();*/
		/*	i->ingresarUsuario();*/
			break;

		case 3:/*
			limpiarPantallaPortable();*/
			/*	i->ingresarSolicitudDePrestamo();*/
			break;

		case 4:
			/*limpiarPantallaPortable();*/
			/*i->devoluciondePrestamos();*/
			break;
		}
		

	} while (opcion != 0);


}
void Sistema::mostrarSubmenuModificacionDatos(){}
void Sistema::mostrarSubmenuReportes(){}
void Sistema::mostrarSubmenuPersistenciaDeDatos(){}
