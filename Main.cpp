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

void atenderPacientes(List<Persona>* lista){
    int eleccion;
    cout << "=== PACIENTES EN ESPERA ===" << endl;
    for(int i = 0 ; i < lista->getSize() - 1; i++){
        cout << i+1 << ". " << lista->get(i).getId() << " - " << lista->get(i).getNombre() << endl;
    };
    cout << "\nIndique cuantos pacientes va a atender: ";
    cin >> eleccion;


}
int main() {
    try{
    bool archivoLeido = false;
    int opcion;
    List<Persona>* lista = new List<Persona>();
    List<Servicio>* listaServicio = new List<Servicio>();
    cargarTxt(archivoLeido, lista, listaServicio);
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
                atenderPacientes(lista);
                break;
            case 2:
                cout << "Opcion2" << endl;
                break;
            case 3:
                cout << "Option3" << endl;
                break;
        };
        

    } while (opcion != 4);

    cout << "Hasta Luego :D" << endl;
    } catch (int e) {
        cout << "Error capturado (codigo " << e << ")" << endl;
    } catch (exception& e){
        cout << "Error: " << e.what() << endl;
    }
}