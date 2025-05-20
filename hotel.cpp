#include "hotel.h"

Hotel::Hotel(string Nombre) {
    nombre = Nombre;
    numHabitaciones = 40;

    for (int i = 0; i < 40; i++) {
        habitaciones[i] = Habitacion(100 + i);
    }
}

int Hotel::checkin(string Nombre, int Adultos, int Infantes, double Credito) {
    for (int i = 0; i < numHabitaciones; i++) {
        if (habitaciones[i].getDisponible()) {
            habitaciones[i].checkin(Nombre, Adultos, Infantes, Credito);
            return habitaciones[i].getNumero();
        }
    }
    return -1;
}

bool Hotel::checkout(int numerohabitacion) {
    if (numerohabitacion >= 100 && numerohabitacion <= 139) {
        int indice = numerohabitacion - 100;
        return habitaciones[indice].checkout();
    }
    else {
        return false;
    }
}

bool Hotel::realizarCargoHabitacion(int numerohabitacion, double cargo_extra) {
    int indice = numerohabitacion - 100;

    if (!habitaciones[indice].getDisponible()) {
        return habitaciones[indice].realizarCargo(cargo_extra);
    }

    return false;
}

double Hotel::getTotalXTarifaBase() {
    double totalTarifa = 0;

    for (int i = 0; i < 40; i++) {
        if (!habitaciones[i].getDisponible()) {
            totalTarifa += habitaciones[i].getTarifaBase();
        }
    }

    return totalTarifa;
}

void Hotel::imprimeOcupacion() {
    cout << "Ocupacion en " << nombre << ":" << endl;

    for (int i = 0; i < 40; i++) {
        if (!habitaciones[i].getDisponible()) {
            string mensaje = habitaciones[i].toString();
            cout << mensaje << endl;
        }
    }
}


