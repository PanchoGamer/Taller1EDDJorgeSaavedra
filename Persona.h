#pragma once
#include <string>
using namespace std;

class Persona{
    private:
        int ID;
        string nombre;
        int edad;
        string servicio;
    public:
        Persona(int ID, string nombre,int edad, string servicio);
        ~Persona();
};