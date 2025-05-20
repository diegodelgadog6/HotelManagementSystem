#include <iostream>

using namespace std;

class Habitacion {
private:
    int numero, adultos, infantes;
    string nombre;
    double credito, cargo;
    bool disponible;

public:
    Habitacion();
    Habitacion(int Numero);
    int getNumero();
    bool getDisponible();
    void setNumero(int nuevoNumero);
    bool checkin(string Nombre, int Adultos, int Infantes, double Credito);
    bool checkout();
    double getTarifaBase();
    bool realizarCargo(double cargo_extra);
    string toString();
};