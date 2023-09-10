#include <cstdlib>
#include <iostream>
using namespace std;
#define MaxTamaPila 5
class Pila {
private:
	float pila[MaxTamaPila];
    int cima;
    int elemento;
    int aux;
public:
	Pila();   //constructor
    ~Pila(); //destructor
	bool pilaBVacia; //rastrea si la pila b esta vacia
    void vaciaP();
    void imprimirP();
    void transferirP(Pila & pilaB);
    void operacionesP();
    int estallenaP();
    void insertarP(int elemento);
    void agregarElemento();
    int quitarP();
    int estavaciaP();
    float encontrarMayor();
    float encontrarMenor();
};

Pila::Pila() { //Constructor
    cima = -1;
    pilaBVacia = true;
}

Pila::~Pila() //Destructor
{
    cout << "\nGracias por utilizar este programa. \n";
}
void Pila::agregarElemento() {
    if (estavaciaP()) {
        cout << "La pila cuenta con espacio \nIngresa un dato a la pila: ";
        int valor;
        cin >> valor;
        insertarP(valor);
    } else {
        cout << "La pila está llena.\nNo se pueden agregar más elementos." << endl;
    }
}
void Pila::imprimirP() {
    cout << "DATOS :" << endl;
    for (int i = 0; i <= cima; i++) {
        cout << "[" << pila[i] << "]" <<endl ;
    } 
    cout << endl;
    if (cima >= 0) {
        cout << "La cima de la pila es: " << pila[cima] << endl;
    } else {
        cout << "La pila esta vacia." << endl;
    }
    cout << endl;
}

void Pila::transferirP(Pila & pilaB ) {
     while(!estavaciaP()&&!pilaB.estallenaP()){
     	int elemento= quitarP();
     	pilaB.insertarP(elemento);
	 }
}
float Pila::encontrarMayor() {
    if (estavaciaP()) {
        cout << "La pila esta vacia no se puede encontrar el mayor valor." << endl;
        return -1; 
    }
    float mayor = pila[0];
    for (int i = 1; i <= cima; i++) {
        if (pila[i] > mayor) {
            mayor = pila[i];
        }
    }
    return mayor;
}

float Pila::encontrarMenor() {
    if (estavaciaP()) {
        cout << "La pila esta vacia, no se puede encontrar el menor valor." << endl;
        return -1; 
    }

    float menor = pila[0];
    for (int i = 1; i <= cima; i++) {
        if (pila[i] < menor) {
            menor = pila[i];
        }
    }
    return menor;
}

void Pila::operacionesP() {
    if (pilaBVacia) {
        cout << "La Pila B esta vacia. Agregue elementos primero." << endl;
    } else {
        cout << "El Mayor valor en la Pila B es : " << encontrarMayor() << endl;
        cout << "El Menor valor en la Pila B es : " << encontrarMenor() << endl;
    }
}
void Pila::vaciaP() {
    cima = -1;
}

void Pila::insertarP(int _elemento) {
    if (estallenaP()) {
        cout << "\nDesbordamiento pila";
    }
    else {
        cima++;
        pila[cima] = _elemento;
        cout << "Se inserta la cima: " << _elemento << " -> cima: " << cima << endl;
    }
}

int Pila::quitarP() {
    int aux;
    if (estavaciaP()) {
        cout << "\nSe intenta sacar un elemento en pila vacía";
        return -1;
    }
    else {
        aux = pila[cima];
        cout << "\nSe elimina la cima: " << aux << " -> cima: " << cima;
        cima--;
        return aux;
    }
}

int Pila::estallenaP() {
    return cima == MaxTamaPila - 1;
}

int Pila::estavaciaP() {
    return cima == -1;
}

int main() {
    Pila P1, P2;
    
    cout << "---Este programa que nos permite trabajar de varias formas con PILAS ---" << endl;
    cout << " PILA"<<endl;
    cout << " ____" << endl;
    cout << "|____|" << endl;
    cout << "|____|" << endl;
    cout << "|____|" << endl;
    cout << "|____|" << endl;
    int opcion, x,i;
    do {
        cout << "1. Ingresar o quitar los valores de la pila" << endl;
        cout << "2. Imprimir la pila " << endl;
        cout << "3. Transferir elementos de una pila A a una pila B" << endl;
        cout << "4. Operaciones con las Pilas" << endl;
        cout << "5. Salir" << endl;
        cin >> opcion;
        switch (opcion) {
        case 1:
            cout << "Deseas quitar o agregarle algun elemento a la pila?\n (A) para agregar\n (Q) para quitar" << endl;
            char o;
            cin >> o;
            if (o == 'A' || o == 'a') {
                cout << "Deseas agregar un solo dato (S) o varios datos (M)? ";
                char op;
                cin >> op;
                if (op == 'S' || op == 's') {
                    P1.agregarElemento();
                } else if (op == 'M' || op == 'm') {
                    if (P1.estavaciaP()) {
                        cout << "La pila cuenta con espacio \nIngresa los datos de la pila : " << endl;
                        while (!P1.estallenaP()) {
                            cout << "Ingresa el valor " << i++ << " de la pila " << endl;
                            cin >> x;
                            P1.insertarP(x);
                        }
                    } else {
                        cout << "La pila está llena.\nNo se pueden agregar mas elementos." << endl;
                    }
                } else {
                    cout << "Opcion invalida." << endl;
                }
            } else if (o == 'Q' || o == 'q') {
             if (!P1.estavaciaP()) {
              x = P1.quitarP();
                cout << "Se quito el valor " << x << " de la pila." << endl;
             } else {
                cout << "La pila esta vacia.\n No se pueden quitar elementos." << endl;
                 }
               } else {
             cout << "Opción no valida." << endl;
                     }
                     system("pause"); 
                    system("cls"); 
                   break;
        case 2:
             cout << "Datos de la pila:" << endl;
            if (P1.estavaciaP()) {
                cout << "La pila esta vacia "<<endl;
				 cout << "la cima  es -1" << endl;
               
            }else if (P1.estallenaP()) {
                cout << "La pila esta llena." << endl;
                P1.imprimirP();
            }else {
                P1.imprimirP();
            }
            system("pause"); 
            system("cls"); 
            break;
        case 3:
           if(P1.estavaciaP()){
           	cout<<"No hay todavia ningun dato en la Pila A por lo tanto no se puede hacer ninguna trasferencia de datos "<<endl;
		   }else{
		   cout<<" Pila A "<<endl;
           P1.imprimirP();
           P1.transferirP(P2);
           cout<<" Se acabaron de transferir los elementos de la Pila A hacia la Pila B"<<endl;
           cout <<"Pila B con los valores de la pila A:" << endl;
           P2.imprimirP();
           P2.pilaBVacia = false;// porque ya le pasaron los datos de la pila a por lo tanto ya no esta vacia
		    }
		system("pause"); 
        system("cls"); 
            break;
        case 4:
             P2.operacionesP();
             system("pause"); 
             system("cls"); 
			    break;	
		case 5:
             system("cls");
            break;

        default:
            cout << "Opcion invalida. Por favor, selecciona una opcion valida" << endl;			
        }
    } while (opcion != 5);
    cout << "\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}


