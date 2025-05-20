#include <iostream>
#include "hotel.h"

using namespace std;

int main() {
    Hotel hotel("Hotel Plaza");

    int opcion;

    cout << "=== SISTEMA DE HOTEL ===" << endl;

    do {
        cout << "\n1. Check-in" << endl;
        cout << "2. Check-out" << endl;
        cout << "3. Ver ocupacion" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            string nombre;
            int adultos, ninos;
            double credito;

            cout << "Nombre: ";
            cin >> nombre;
            cout << "Adultos: ";
            cin >> adultos;
            cout << "Infantes: ";
            cin >> ninos;
            cout << "Credito: ";
            cin >> credito;

            int habitacion = hotel.checkin(nombre, adultos, ninos, credito);
            if (habitacion != -1) {
                cout << "Check-in en habitacion " << habitacion << endl;
            }
            else {
                cout << "Hotel lleno" << endl;
            }
        }

        else if (opcion == 2) {
            int num;
            cout << "Numero de habitacion: ";
            cin >> num;

            if (hotel.checkout(num)) {
                cout << "Check-out exitoso" << endl;
            }
            else {
                cout << "Error en check-out" << endl;
            }
        }

        else if (opcion == 3) {
            hotel.imprimeOcupacion();
        }

    }

    while (opcion != 0);

    cout << "Hasta luego!" << endl;
    return 0;
}