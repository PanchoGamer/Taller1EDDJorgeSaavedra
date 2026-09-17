#include <iostream>
#include "Persona.h"
#include <string>
using namespace std;

Persona::Persona(int ID, string nombre,int edad, string servicio){
    this->ID = ID;
    this->nombre = nombre;
    this->edad = edad;
    this->servicio = servicio;
}