#pragma once
#include <string>
#include "Queue.h"
#include "Persona.h"

class Servicio{
    private:    
        std::string nombre;
        Queue<Persona> pacientes;
    public:
        Servicio(std::string nombre);

        std::string getNombre();
        Queue<Persona>& getPacientes();
        void agregarPaciente(Persona p);
        Persona atenderPaciente();
        bool pendientes();
        int cantidadPacientes();

        ~Servicio();
};