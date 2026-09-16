#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    cout << "------------------- Menu Principal -------------------" << endl;
    int opcion;
    do{
        cout << "1. Cargar Pacientes." << endl;
        cout << "2. Mostrar cola de pacientes pendientes" << endl;
        cout << "3. Atender a cierta cantidad" << endl;
        cout << "4. Mostrar el estado general de los servicios" << endl;
        cout << "5. Mostrar el historial de atenciones" << endl;
        cout << "6. Salir" << endl;
        cout << "Eliga la opcion: ";
        cin >> opcion;
        cout << "" << endl;

        if (cin.fail()){
            throw invalid_argument("Error. Use solo numeros");
        }

        if (opcion < 1 || opcion > 6){
            throw invalid_argument("Eliga una opcion valida");
        }

        switch(opcion){
            case 1:
                cout << "Opcion1" << endl;
                break;
            case 2:
                cout << "Opcion2" << endl;
                break;
            case 3:
                cout << "Option3" << endl;
                break;
            case 4:
                cout << "Option4" << endl;
                break;
            case 5:
                cout << "Option5" << endl;
                break;
        };
        

    } while (opcion != 6);

    cout << "Hasta Luego :D" << endl;
}

int cargarTxt(){
    
}