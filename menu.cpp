#include <iostream>
using namespace std;

int main() {
    while (true) {
        cout << "Men� Principal" << endl;
        cout << "1. Opci�n 1" << endl;
        cout << "2. Opci�n 2" << endl;
        cout << "3. Opci�n 3" << endl;
        cout << "4. Salir" << endl;

        int opcion;
        cout << "Selecciona una opci�n: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Has seleccionado la Opci�n 1." << endl;
                break;
            case 2:
                cout << "Has seleccionado la Opci�n 2." << endl;
                break;
            case 3:
                cout << "Has seleccionado la Opci�n 3." << endl;
                break;
            case 4:
                cout << "Saliendo del programa." << endl;
                return 0;
            default:
                cout << "Opci�n no v�lida." << endl;
                break;
        }
    }
}
