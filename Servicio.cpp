#include "Servicio.h"

Servicio::Servicio(std::string nombre){
    this->nombre = nombre;
}

std::string Servicio::getNombre(){
    return this->nombre;
}

Queue<Persona>& Servicio::getPacientes(){
    return pacientes;
}

void Servicio::agregarPaciente(Persona p){
    pacientes.push(p);
}

Persona Servicio::atenderPaciente(){
    Persona p = pacientes.front();
    pacientes.pop();
    return p;
}

bool Servicio::pendientes(){
    return !pacientes.empty();
}

int Servicio::cantidadPacientes(){
    return pacientes.size();
}

Servicio::~Servicio(){
}