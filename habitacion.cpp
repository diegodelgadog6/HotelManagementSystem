#include "habitacion.h"

Habitacion::Habitacion() {
    numero = 0;
    adultos = 0;
    infantes = 0;
    credito = 0;
    cargo = 0;
    nombre = "";
    disponible = true;
}

Habitacion::Habitacion(int Numero) {
    numero = Numero;
    disponible = true;
    adultos = 0;
    infantes = 0;
    credito = 0;
    cargo = 0;
    nombre = "";
}

int Habitacion::getNumero() {
    return numero;
}

bool Habitacion::getDisponible() {
    return disponible;
}

void Habitacion::setNumero(int nuevoNumero) {
    numero = nuevoNumero;
}

bool Habitacion::checkin(string Nombre, int Adultos, int Infantes, double Credito) {

    if (disponible == true) {
        nombre  = Nombre;
        adultos = Adultos;
        infantes = Infantes;
        credito = Credito;
        disponible = false;
        cargo = 0;

        return true;
    } else {
        return false;
    }

}

bool Habitacion::checkout() {

    if (disponible == false) {
        nombre  = "";
        adultos = 0;
        infantes = 0;
        credito = 0;
        disponible = true;
        cargo = 0;

        return true;
    }
    else {
        return false;
    }

}

double Habitacion::getTarifaBase() {
    double tarifa_adulto = adultos * 650.00;
    double tarifa_infante = infantes * 250.00;
    double tarifa_base = tarifa_adulto + tarifa_infante;
    return tarifa_base;
}

bool Habitacion::realizarCargo(double cargo_extra) {
    if (cargo_extra > 0 && cargo + cargo_extra <= credito) {
        cargo = cargo + cargo_extra;
        return true;
    } else {
        return false;
    }
}

string Habitacion::toString() {
    string mensaje = to_string(numero) + ",Huesped:" + nombre + ",Tarifa Base:" + to_string(getTarifaBase()) + ",Credito:" + to_string(credito) + ",Cargos:" + to_string(cargo);
    return mensaje;
}






