#include <iostream>
#include "Persona.h"
#include <string>

Persona::Persona(int ID, std::string nombre,int edad, std::string servicio){
    this->id = ID;
    this->nombre = nombre;
    this->edad = edad;
    this->servicio = servicio;
}

int Persona::getId(){
    return id;
}

std::string Persona::getNombre(){
    return nombre;
}

int Persona::getEdad(){
    return edad;
}

std::string Persona::getServicio(){
    return servicio;
}