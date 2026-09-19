#pragma once
#include <string>

class Persona{
    private:
        int id;
        std::string nombre;
        int edad;
        std::string servicio;
    public:
        Persona(int id, std::string nombre,int edad, std::string servicio);
        int getId();
        std::string getNombre();
        int getEdad();
        std::string getServicio();
        ~Persona();
};
#include "Persona.cpp"