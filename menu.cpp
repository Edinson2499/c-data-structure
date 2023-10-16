#include <iostream>
using namespace std;

int main() {
    while (true) {
        cout << "Menú Principal" << endl;
        cout << "1. Opción 1" << endl;
        cout << "2. Opción 2" << endl;
        cout << "3. Opción 3" << endl;
        cout << "4. Salir" << endl;

        int opcion;
        cout << "Selecciona una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Has seleccionado la Opción 1." << endl;
                break;
            case 2:
                cout << "Has seleccionado la Opción 2." << endl;
                break;
            case 3:
                cout << "Has seleccionado la Opción 3." << endl;
                break;
            case 4:
                cout << "Saliendo del programa." << endl;
                return 0;
            default:
                cout << "Opción no válida." << endl;
                break;
        }
    }
}
