#pragma once
#include <string>

class Persona{
    private:
        std::string id;
        std::string nombre;
        int edad;
        std::string servicio;
    public:
        Persona(std::string id, std::string nombre,int edad, std::string servicio);
        std::string getId();
        std::string getNombre();
        int getEdad();
        std::string getServicio();
        ~Persona();
};