#include <iostream>
#include "habitacion.h"

using namespace std;

class Hotel {
private:
    Habitacion habitaciones[40];
    int numHabitaciones;
    string nombre;

public:
    Hotel(string Nombre);
    int checkin(string Nombre, int Adultos, int Infantes, double Credito);
    bool checkout(int numerohabitacion);
    bool realizarCargoHabitacion(int numerohabitacion, double cargo_extra);
    double getTotalXTarifaBase();
    void imprimeOcupacion();
};