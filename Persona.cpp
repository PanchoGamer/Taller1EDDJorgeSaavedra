#include <iostream>
#include "Persona.h"
#include <string>
using namespace std;

Persona::Persona(int ID, string nombre,int edad, string servicio){
    this->id = ID;
    this->nombre = nombre;
    this->edad = edad;
    this->servicio = servicio;
}

int Persona::getId(){
    return id;
}

string Persona::getNombre(){
    return nombre;
}

int Persona::getEdad(){
    return edad;
}

string Persona::getServicio(){
    return servicio;
}