#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include "Persona.h"
#include "List.h"
#include "Node.h"
#include "Queue.h"
#include "Servicio.h"
using namespace std;

void cargarTxt(bool &archivoLeido,List<Persona>* lista,List<Servicio>* listaServicio){
    if (archivoLeido == false){
        archivoLeido = true;

        ifstream archivo("Pacientes.txt");

        if(!archivo.is_open()) {
            archivoLeido = false;
            cout << "El archivo no existe" << endl;
            return;
        }

        string linea;
        int c = 0;
        
        while (getline(archivo,linea)){
            stringstream ss(linea);
            string id, nombre, edadTexto, servicio;

            getline(ss, id, ';');
            getline(ss, nombre, ';');
            getline(ss, edadTexto, ';');
            getline(ss, servicio, ';');

            int edad = stoi(edadTexto);

            Persona* p = new Persona(id,nombre,edad,servicio);
            lista->insert(*p,c);
            c++;
        }

        for(int i = 0; i < lista->getSize(); i++){
            Persona p = lista->get(i);
            
            bool encontrado = false;
            for(int j = 0; j < listaServicio->getSize(); j++){
                if(p.getServicio() == listaServicio->get(j).getNombre()){
                    encontrado = true;
                    break;
                }
            };


            if(!encontrado){
                Servicio* servicio = new Servicio(p.getServicio());
                listaServicio->insert(*servicio, listaServicio->getSize());
            }

        };
        
        cout << listaServicio->getSize() << endl;
        
        //for(int i = 0; i < lista->getSize()-1; i++){
            //cout << "ID: " << lista->get(i).getId() << "\nNombre: " << lista->get(i).getNombre() << "\nEdad: " << lista->get(i).getEdad() << "\nServicio: " << lista->get(i).getServicio() << endl;
        //};

        archivo.close();

        ///cout << "Archivo Leido" << endl;
    }
    else{
        cout << "El archivo ya se ha leido" << "\n" << endl;
    };
}

void atenderPacientes(List<Persona>* lista, List<Servicio>* listaServicio){
    int eleccion;
    if(lista->getSize() == 0){
        cout << "No quedan pacientes en espera\n" << endl;
        return;
    }

    cout << "=== PACIENTES EN ESPERA ===" << endl;
    for(int i = 0 ; i < lista->getSize(); i++){
        cout << i+1 << ". " << lista->get(i).getId() << " - " << lista->get(i).getNombre() << endl;
    };
    cout << "\nIndique cuantos pacientes va a atender: ";
    cin >> eleccion;

    cout << "\n=== ATENDIENDO PACIENTES ===" << endl;
    for(int i = 0; i < eleccion; i++){
        Persona p = lista->get(0);
        for(int j = 0; j < listaServicio->getSize(); j++){
            if (listaServicio->getRef(j).getNombre() == p.getServicio()){
                listaServicio->getRef(j).agregarPaciente(p);
                cout << "ID: " << p.getId() << endl;
                cout << "Nombre: " << p.getNombre() << endl;
                cout << "Edad: " << p.getEdad() << endl;
                cout << "Servicio: " << p.getServicio() << endl;
                cout << "\nPaciente enviado a " << p.getServicio() << "\n" << endl;
                break;
            }
        }
        lista->remove(0);
    }
}

void verDepartamentos(Servicio** indice, int total){
    int eleccion;
    cout << endl;
    cout << "=== DEPARTAMENTOS/SERVICIOS ===" << endl;
    for(int i = 0; i < total; i++){
        Servicio* s = *(indice + i);
        cout << i+1 << ". " << s->getNombre() << endl;
    };

    cout << "\nSeleccione Opcion: ";
    cin >> eleccion;
    if (eleccion < 1 || eleccion > total){
        cout << "Error. Elija entre los departamentos\n" << endl;
        return;
    }
    Servicio* elegido = *(indice + (eleccion - 1)); 
    cout << "=== ESTADO " << elegido->getNombre() << " ===" << endl;
    cout << "Pacientes en el departamento: " << elegido->cantidadPacientes() << endl;

    Node<Persona>* cursor = elegido->getPacientes().getStart();
    while(cursor != nullptr){
        cout << cursor->getValue().getNombre() << "(" << cursor->getValue().getEdad() << ")" << endl;
        cursor = cursor->getNext();
    }
    cout << "" << endl;   
}

int main() {
    try{
    bool archivoLeido = false;
    int opcion;
    List<Persona>* lista = new List<Persona>();
    List<Servicio>* listaServicio = new List<Servicio>();
    cargarTxt(archivoLeido, lista, listaServicio);
    int totalServicios = listaServicio->getSize();
    Servicio** indice = new Servicio*[totalServicios];

    for(int i = 0; i < totalServicios; i++){
        *(indice + i) = &listaServicio->getRef(i);
    }
    do{
        opcion = 0;
        cout << "=== HOSPITAL ===" << endl;
        cout << "1. Atender paciente" << endl;
        cout << "2. Ver departamento" << endl;
        cout << "3. Revisar historial de atencion" << endl;
        cout << "4. Salir" << endl;
        cout << "" << endl;
        cout << "Eliga la opcion: ";
        cin >> opcion;
        cout << "" << endl;

        if (cin.fail()){
            throw invalid_argument("Error. Use solo numeros");
        }

        if (opcion < 1 || opcion > 4){
            throw invalid_argument("Eliga una opcion valida");
        }

        switch(opcion){
            case 1:
                atenderPacientes(lista, listaServicio);
                break;
            case 2:
                verDepartamentos(indice, totalServicios);
                break;
            case 3:
                cout << "Option3" << endl;
                break;
        };
        

    } while (opcion != 4);

    delete[] indice;
    delete lista;
    delete listaServicio;

    cout << "Hasta Luego :D" << endl;
    } catch (int e) {
        cout << "Error capturado (codigo " << e << ")" << endl;
    } catch (exception& e){
        cout << "Error: " << e.what() << endl;
    }
}