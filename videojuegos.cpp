#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Personaje {
  public:
    string nombre,proteccion;
    int fuerza;
    int defensa;
    int inteligencia;
    int vidas;
    int posicion_x;
    int posicion_y;
    int contador;
    stack<int> vidas_pila;
    queue<string> armas;
    
    Personaje(string nombre,string proteccion,int defensa,int fuerza, int inteligencia, int vidas, int posicion_x, int posicion_y) {
      this->nombre = nombre;
      this->fuerza = fuerza;
      this->defensa=defensa;
      this->proteccion =proteccion;
      this->vidas = vidas;
      this->posicion_x = posicion_x;
      this->posicion_y = posicion_y;
      this->contador = 0;
      this->vidas_pila.push(vidas);
      this->armas.push(" ");
    }
    
    void atacar(Personaje& objetivo) {
      int dano = fuerza - objetivo.defensa / 2;
      objetivo.vidas_pila.pop();
      if (objetivo.vidas_pila.empty()) {
        objetivo.vidas = 0;
      } else {
        objetivo.vidas = objetivo.vidas_pila.top();
      }
    }

    void moverse(int x, int y) {
      this->posicion_x += x;
      this->posicion_y += y;
    }

    void turno() {
      this->contador++;
    }
    void defender() {
      this->defensa = defensa + 10;
    }

  private:
    void modificarNombre(string nombre) {
      this->nombre = nombre;
    }

    void modificarFuerza(int fuerza) {
      this->fuerza = fuerza;
    }

    void modificarInteligencia(int inteligencia) {
      this->inteligencia = inteligencia;
    }

    void modificarDefensa(int defensa) {
      this->defensa = defensa;
    }

    void modificarVidas(int vidas) {
      this->vidas = vidas;
    }

    void modificarPosicionX(int posicion_x) {
      this->posicion_x = posicion_x;
    }

    void modificarPosicionY(int posicion_y) {
      this->posicion_y = posicion_y;
    }

    void modificarContador(int contador) {
      this->contador = contador;
    }
};

class Guerrero : public Personaje {
  public:
    Guerrero(string nombre,string proteccion, int fuerza, int inteligencia, int defensa, int vidas, int posicion_x, int posicion_y) : Personaje(nombre,proteccion,fuerza, inteligencia, defensa, vidas, posicion_x, posicion_y) {
      this->armas.push("espada");
      this->armas.push("hacha");
      this->armas.push("daga");
      this->defensa=20;
	  this->fuerza = 150;
      this->inteligencia = 50;
      this->proteccion = "escudo";
      
    }
};

class Mago : public Personaje {
  public:
    Mago(string nombre,string proteccion ,int fuerza, int inteligencia, int defensa, int vidas, int posicion_x, int posicion_y) : Personaje(nombre,proteccion,fuerza, inteligencia, defensa, vidas, posicion_x, posicion_y) {
      this->armas.push("varita magica");
      this->armas.push("libro");
      this->armas.push("pociones");
	  this->fuerza = 50;
	  this->defensa=10;
      this->inteligencia = 150;
      this->proteccion = "tunica";
    }
};
class Ninja : public Personaje {
  public:
    Ninja(string nombre,string proteccion, int fuerza, int inteligencia, int defensa, int vidas, int posicion_x, int posicion_y) : Personaje(nombre,proteccion, fuerza, inteligencia, defensa, vidas, posicion_x, posicion_y) {
      this->fuerza = 75;
      this->inteligencia = 75;
      this->defensa=40;
      this->proteccion = "escudo antebrazo";
      this->armas.push("Shuriken");
      this->armas.push("espada");
      this->armas.push("kunai");
    }
};
class Hada : public Personaje {
public:
    Hada(string nombre, string proteccion, int fuerza, int inteligencia, int defensa, int vidas, int posicion_x, int posicion_y) : Personaje(nombre, proteccion, fuerza, inteligencia, defensa, vidas, posicion_x, posicion_y) {
        this->fuerza = 25;
        this->defensa = 80;
        this->inteligencia = 90;
        this->proteccion = "alas";
        this->armas.push("varita");
        this->armas.push("libro");
        this->armas.push("polvos");
    }
};

class Troll : public Personaje {
public:
    Troll(string nombre, string proteccion, int fuerza, int inteligencia, int defensa, int vidas, int posicion_x, int posicion_y) : Personaje(nombre, proteccion, fuerza, inteligencia, defensa, vidas, posicion_x, posicion_y) {
        this->fuerza = 80;
        this->defensa = 25;
        this->inteligencia = 25;
        this->proteccion = "antebrazo";
        this->armas.push("mazo");
        this->armas.push("puño");
        this->armas.push("rugido");
    }
};

class Duende : public Personaje {
public:
    Duende(string nombre, string proteccion, int fuerza, int inteligencia, int defensa, int vidas, int posicion_x, int posicion_y) : Personaje(nombre, proteccion, fuerza, inteligencia, defensa, vidas, posicion_x, posicion_y) {
        this->fuerza = 10;
        this->defensa = 80;
        this->inteligencia = 80;
        this->proteccion = "sombrero";
        this->armas.push("hechizos");
        this->armas.push("hipnosis");
        this->armas.push("desaparecer");
    }
};
int main() {
    cout << "1. Elegir personaje" << endl;
    cout << "2. Elegir arma" << endl;
    cout << "3. Comenzar combate" << endl;
    cout << "4. Salir" << endl;

    int opcion;
    Personaje* selectedCharacter = nullptr;
    string selectedWeapon = "";

    while (true) {
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            cout << "Selecciona un personaje:" << endl;
            cout << "1. Guerrero" << endl;
            cout << "2. Mago" << endl;
            cout << "3. Ninja" << endl;
            cout << "4. Hada" << endl;
            cout << "5. Troll" << endl;
            cout << "6. Duende" << endl;

            int characterChoice;
            cout << "Personaje: ";
            cin >> characterChoice;

            if (selectedCharacter != nullptr) {
                delete selectedCharacter; // Free the previously selected character
            }

            switch (characterChoice) {
            case 1:
                selectedCharacter = new Guerrero("Guerrero", "escudo", 150, 50, 20, 100, 0, 0);
                break;
            case 2:
                selectedCharacter = new Mago("Mago", "tunica", 50, 150, 10, 100, 0, 0);
                break;
            case 3:
                selectedCharacter = new Ninja("Ninja", "escudo antebrazo", 75, 75, 40, 100, 0, 0);
                break;
            case 4:
                selectedCharacter = new Hada("Hada", "alas", 25, 90, 80, 100, 0, 0);
                break;
            case 5:
                selectedCharacter = new Troll("Troll", "antebrazo", 80, 25, 25, 100, 0, 0);
                break;
            case 6:
                selectedCharacter = new Duende("Duende", "sombrero", 10, 80, 80, 100, 0, 0);
                break;
            default:
                cout << "Personaje no válido." << endl;
                break;
            }
            break;
        }
        case 2: {
    if (selectedCharacter != nullptr) {
        cout << "Selecciona un arma para " << selectedCharacter->nombre << ":" << endl;
        int weaponChoice;
        int i = 1;
        queue<string> weaponsCopy = selectedCharacter->armas;
        while (!weaponsCopy.empty()) {
            cout << i << ". " << weaponsCopy.front() << endl;
            weaponsCopy.pop();
            i++;
        }
        cout << "Arma: ";
        cin >> weaponChoice;

        // Set the selected weapon based on the user's choice
        i = 1;
        while (i < weaponChoice && !selectedCharacter->armas.empty()) {
            selectedCharacter->armas.pop();
            i++;
        }

        if (!selectedCharacter->armas.empty()) {
            selectedWeapon = selectedCharacter->armas.front();
        }
        break;
    } else {
        cout << "Primero selecciona un personaje." << endl;
    }
    break;
}

        case 3: {
            if (selectedCharacter != nullptr) {
                // Add your combat logic here...
                cout << "Comenzando el combate con " << selectedCharacter->nombre << " usando " << selectedWeapon << "..." << endl;
            }
            else {
                cout << "Primero selecciona un personaje y un arma." << endl;
            }
            break;
        }
        case 4: {
            // Clean up and exit the program
            if (selectedCharacter != nullptr) {
                delete selectedCharacter;
            }
            return 0;
        }
        default:
            cout << "Opción no válida." << endl;
            break;
        }
    }
}





