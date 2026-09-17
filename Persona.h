#pragma once
#include <string>
using namespace std;

class Persona{
    private:
        int id;
        string nombre;
        int edad;
        string servicio;
    public:
        Persona(int id, string nombre,int edad, string servicio);
        int getId();
        string getNombre();
        int getEdad();
        string getServicio();
        ~Persona();
};