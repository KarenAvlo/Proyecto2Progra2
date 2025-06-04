#include <iostream>
#include <string>
#include <limits>
#include "utilitarios.h"


using namespace std;

static void limpiarPantallaPortable()
{
#ifdef _WIN32
    system("CLS");

#else
    system("clear");

#endif
}

static int obtenerOpcion(int min, int max)
{
    int opcion;

    cout << " Ingrese una opcion: ";

    while (!(cin >> opcion) || opcion < min || opcion > max) {

        cin.clear();

        cin.ignore(1000, '\n');

        cout << "Opcion no valida. Intente de nuevo: ";
    }

    cin.ignore(1000, '\n');

    return opcion;
}

static string obtenerEntrada(const string& mensajeP)
{
    string entrada;

    do {

        cout << mensajeP;

        getline(cin, entrada);

        cout << endl;

        if (entrada.empty()) {
            cerr << "Error: Debe ingresar una entrada valida." << endl << endl;
        }

    } while (entrada.empty());

    return entrada;
}

static int obtenerNumero()
{
    int numero;

    while (true) {

        cout << "Ingrese un numero entero no negativo: ";

        cin >> numero;

        if (cin.fail() || numero < 0) {

            cerr << "Error: Debe ingresar un entero no negativo." << endl << endl;

            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            // Consumir el salto de línea pendiente
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            return numero;
        }
    }
}

static int obtenerMes()
{
    int mes;

    while (true) {

        cout << "Ingrese un mes (1-12): ";
        cin >> mes;

        if (cin.fail() || mes < 1 || mes > 12) {

            cerr << "Error: Debe ingresar un mes valido." << endl << endl;
            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        else {
            // Consumir el salto de línea pendiente
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            return mes;
        }
    }
}

static int obtenerDia(int mes)
{
    int dia, maxDias;

    switch (mes) {


        //febrero
    case 2: { maxDias = 28; }
          break;

          // meses con 30 dias
    case 4: case 6: case 9: case 11:
    { maxDias = 30; }
    break;

    // meses con 31 dias
    default:
    { maxDias = 31; }
    break;
    }

    while (true) {

        cout << "Ingrese un dia (1-" << maxDias << "): ";

        cin >> dia;

        if (cin.fail() || dia < 1 || dia > maxDias) {

            cout << "Error: debe ingresar un dia valido para el mes " << mes << endl << endl;
            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            return dia;
        }
    }
}