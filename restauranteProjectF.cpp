#include <iostream>
#include <list>
#include <string>
#include <limits>
#include <locale.h>
#include <fstream>
#include <ctime>
using namespace std;

// Definicion de una clase para representar un pedido
int totalGanancias = 0;

class Pedido {
public:
  // Constructor con parametros
  Pedido(string nombrePlato, int cantidad, string prioridad, int precio) :
    nombrePlato(nombrePlato), cantidad(cantidad), prioridad(prioridad), precio(precio) {}
    string prioridad;
  // Getters
  string getNombrePlato() const { return nombrePlato; }
  int getCantidad() const { return cantidad; }
  string getPrioridad() const { return prioridad; }
  int getPrecio() const { return precio; }

  // Setters
  void setNombrePlato(string nombrePlato) { this->nombrePlato = nombrePlato; }
  void setCantidad(int cantidad) { this->cantidad = cantidad; }
  void setPrioridad(string prioridad) { this->prioridad = prioridad; }
  void setPrecio(int precio) { this->precio = precio; }

private:
  string nombrePlato;
  int cantidad;
  int precio;
};

// Definicion de una pila
class Pila {
public:
  // Constructor
  Pila() {}

  // Añade un elemento a la pila
  void push(const Pedido& pedido) {
    lista_.push_front(pedido);
  }

  // Obtiene el elemento primero de la pila
  Pedido top() {
    return lista_.front();
  }

  // Elimina el elemento primero de la pila
  void pop() {
    lista_.pop_front();
  }

  // Comprueba si la pila esta vacia
  bool empty() {
    return lista_.empty();
  }

private:
  // Lista para almacenar los elementos de la pila
  list<Pedido> lista_;
};

// Definicion de una cola
class Cola {
public:
  // Constructor
  Cola() {}

  // Añade un elemento a la cola
  void push(const Pedido& pedido) {
    lista_.push_back(pedido);
  }

  // Obtiene el elemento primero de la cola
  Pedido front() {
    return lista_.front();
  }

  // Elimina el elemento primero de la cola
  void pop() {
    lista_.pop_front();
  }

  // Comprueba si la cola esta vacia
  bool empty() {
    return lista_.empty();
  }

  // Obtener el tamaño de la cola
  int size() const {
    return lista_.size();
  }

private:
  // Lista para almacenar los elementos de la cola
  list<Pedido> lista_;
};
list<Pedido> pedidosDespachados;
// Funciones para imprimir informacion
void imprimirPedido(const Pedido& pedido) {
  cout << "Pedido: " << pedido.getNombrePlato() << ", " << pedido.getCantidad() << ", " << pedido.getPrioridad() << endl;
}

void imprimirPedidosPendientes(const Cola& colaEspera) {
  Cola colaEsperaCopia = colaEspera;
  int numeroPedido = 1;

  if (!colaEsperaCopia.empty()) {
    cout << "Pedidos pendientes:" << endl;
    while (!colaEsperaCopia.empty()) {
      const Pedido& pedido = colaEsperaCopia.front();
      cout << "Pedido # " << numeroPedido << ": " << pedido.getNombrePlato() << ", Prioridad: " << pedido.getPrioridad() << endl;
      colaEsperaCopia.pop();
      numeroPedido++;
    }
  } else {
  	cout<<"  "<<endl;
    cout << "No hay pedidos en espera." << endl;
  }
}

void visualizarPedidos(const Cola& colaEspera, const Pila& pilaPreparacion) {
  cout << "Cola de Espera:" << endl;
  imprimirPedidosPendientes(colaEspera);

  Pila pilaCopia = pilaPreparacion;
  cout << "Pila de Preparacion:" << endl;
  while (!pilaCopia.empty()) {
    const Pedido& pedido = pilaCopia.top();
    cout << "Pedido: " << pedido.getNombrePlato() << ", Prioridad: " << pedido.getPrioridad() << endl;
    cout << "Precio: " << pedido.getPrecio() << endl;
    pilaCopia.pop();
  }
}

string obtenerFechaActual() {
    time_t now = time(0);
    struct tm* tstruct = localtime(&now);
    char buf[80];

    if (tstruct !=NULL) {
        strftime(buf, sizeof(buf), "%Y-%m-%d", tstruct);
        return buf;
    } else {
        return "";
    }
}

void facturarPedido(const Pedido& pedido) {
    // Obtén la fecha actual
    string fecha = obtenerFechaActual();

    // Crea el archivo con la fecha actual si no existe
    ofstream archivo("factura_.txt", ios::app);

    // Verifica si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo para facturar el pedido." << endl;
        exit(1);
    }

    // Escribe los datos de la factura en el archivo
    archivo << "Restaurante EL ARRIERO" << endl;
    archivo << "Fecha: " << fecha << endl;
    archivo << "Nombre del plato: " << pedido.getNombrePlato() << endl;
    archivo << "Cantidad: " << pedido.getCantidad() << endl;
    archivo << "Precio unitario: " << pedido.getPrecio() << endl;
    archivo << "!MUCHAS GRACIAS VUELVA PRONTO¡" << endl;
    archivo << "               " << endl;
    
    // Cierra el archivo
    archivo.close();

    // Actualiza las ganancias totales
    totalGanancias += (pedido.getCantidad() * pedido.getPrecio());
}


void imprimirListaPedidosDespachados(const list<Pedido>& pedidosDespachados) {
  cout << "Pedidos despachados:" << endl;

  // se utiliza un bucle for para iterar sobre la lista de pedidos despachados
  int i = 1;
  for (auto it = pedidosDespachados.begin(); it != pedidosDespachados.end(); ++it) {
    const Pedido& pedido = *it;
    cout << i << ". " << pedido.getNombrePlato() << endl;
    i++;
  }
}


void imprimirTotalGanancias() {
  cout << "Ganancias totales: $" << totalGanancias << endl;
}

void consultarFacturas() {
    cout << "\033[36m******************************\033[0m" << endl;
    cout << "\033[36mConsultar Facturas de Pedidos\033[0m" << endl;

    ifstream archivoFacturas("factura_.txt", ios::in);

    if (!archivoFacturas.is_open()) {
        cout << "No hay facturas disponibles." << endl;
        return;
    }

    string linea;
    while (getline(archivoFacturas, linea)) {
        cout << linea << endl;
    }

    archivoFacturas.close();
    cout << "\033[36m******************************\033[0m" << endl;
}

int main() {
  setlocale(LC_CTYPE, "Spanish");
  int opcion = 0;
    Cola colaEspera;
    Pila pilaPreparacion;

    while (opcion != 9) {
      opcion = 0;
      cout << "\033[33mRestaurante el arriero\033[0m - Gestion de Pedidos" << endl;
      cout << "     /\\  " <<endl;
      cout << "    /  \\ " << endl;
      cout << "   /    \\" <<endl;
      cout << "  /______\\"<<endl;
      cout << "     ||   " <<endl;
      cout << "     ||   " <<endl;
      cout <<"  "<<endl;
      cout << "1. Agregar Pedido(Meseros)" << endl;
      cout << "2. Atender Pedidos(Cocineros)" << endl;
      cout << "3. Completar Pedido(Meseros)" << endl;
      cout << "4. Facturar pedidos(Cajeros)" << endl;
      cout << "5. Visualizar  pedidos y Ganancias  (Administradores)" << endl;
      cout << "6. Cancelar algun pedido(Meseros) " << endl;
      cout << "7. Cambiar la prioridad de un pedido(Meseros) " << endl;
      cout << "8. Consultar facturas pasadas(Administradores) " << endl;
      cout << "9. Salir" << endl;
      cout << "Seleccione una opcion: ";
      cin >> opcion;

      switch (opcion) {
        

case 7:
	{
	int opcionPedido;
	cout << "\033[34m*****************************\033[0m" << endl;
    cout << "\033[34mCambiar prioridad de pedido\033[0m" << endl;
    
    if (!colaEspera.empty()) {
        imprimirPedidosPendientes(colaEspera);
    
     }else{
     	cout<<" no hay pedidos que se puedan cambiar"<<endl;
	 }
    
    cout << "Ingrese el numero del pedido que desea cambiar de prioridad: ";
    cin >> opcionPedido;

    if (opcionPedido > 0 && opcionPedido <= colaEspera.size()) {
      Pedido pedido = colaEspera.front();
      cout << "Ingrese la nueva prioridad (alta, media, baja): ";
      cin >> pedido.prioridad;
      colaEspera.pop();
      colaEspera.push(pedido);
      cout << "Prioridad del pedido cambiada." << endl;
    } else {
      cout << "Opcion no valida." << endl;
    }
    cout << "\033[34m*****************************\033[0m" << endl;
  break;
}

        case 5:
        	cout << "\033[35m***********************************\033[0m" << endl;
        	cout << "\033[35mVisualizar pedidos y Ganancias\033[0m" << endl;
             visualizarPedidos(colaEspera, pilaPreparacion);
             cout<<" Ganancias de hoy:"<<endl;
             imprimirTotalGanancias();
            cout << "\033[35m***********************************\033[0m" << endl;
                   break;
                   
         case 8:
         	consultarFacturas();
		 
		 break;          
        case 3:
           cout << "\033[34m*****************************\033[0m" << endl;
           cout << "\033[34mCompletar Pedido\033[0m" << endl;
            if (!pilaPreparacion.empty()) {
              const Pedido& pedidoCompleto = pilaPreparacion.top();
              pilaPreparacion.pop();
              imprimirPedido(pedidoCompleto);
              cout<<" Pedido completado"<<endl;
            } else {
              cout << "No hay pedidos en preparacion." << endl;
            }
           cout << "\033[34m*****************************\033[0m" << endl;
          break;
        case 2:
        cout << "\033[31m******************************\033[0m" << endl;	
        cout << "\033[31mAtender pedidos\033[0m" << endl;	
        cout << "Sugerencia: Atienda primero los pedidos de prioridad alta." << endl;

    if (!colaEspera.empty()) {
        imprimirPedidosPendientes(colaEspera);
        cout << "Seleccione un pedido para atender: ";
        int opcionPedido;
        cin >> opcionPedido;

        if (opcionPedido > 0 && opcionPedido <= colaEspera.size()) {
            const Pedido& pedidoAtendido = colaEspera.front();
            pilaPreparacion.push(pedidoAtendido);
            cout << "Pedido atendido: " << pedidoAtendido.getNombrePlato() << endl;

            // Guardar el pedido atendido en la lista de pedidos despachados
            pedidosDespachados.push_back(pedidoAtendido);

            colaEspera.pop();
        } else {
            cout << "Opcion no valida." << endl;
        }
    } else {
        cout << "No hay pedidos en espera." << endl;
    }
    cout << "\033[31m******************************\033[0m" << endl;
    break;
   case 6:
   	{
  cout << "\033[34m*****************************\033[0m" << endl;
  cout << "\033[34mCancelar algun Pedido\033[0m" << endl; 		
  cout << "Ingrese el numero del pedido que desea cancelar: ";
  imprimirPedidosPendientes(colaEspera);
  int opcionPedido;
  cin >> opcionPedido;

  if (opcionPedido > 0 && opcionPedido <= colaEspera.size()) {
    // Obtener el pedido a cancelar
    Pedido pedidoCancelar = colaEspera.front();

    // Eliminar el pedido de la cola de espera
    colaEspera.pop();

    // Actualizar las ganancias totales
    totalGanancias -= (pedidoCancelar.getCantidad() * pedidoCancelar.getPrecio());

    cout << "Pedido cancelado." << endl;
  } else {
    cout << "Opcion no valida." << endl;
  }
  cout << "\033[34m*****************************\033[0m" << endl;
  break;
}
case 4:
{   
    cout << "\033[32m******************************\033[0m" << endl;
	cout << "\033[32mFacturar pedidos\033[0m" << endl;
  if (!pedidosDespachados.empty()) {
    imprimirListaPedidosDespachados(pedidosDespachados);
    int numeroPedido;
    cout << "Seleccione el pedido a facturar: ";
    if (!(cin >> numeroPedido) || numeroPedido <= 0 || numeroPedido > pedidosDespachados.size()) {
      cout << "Error: El numero del pedido debe ser un numero valido mayor que 0 y menor o igual al numero de pedidos despachados." << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      break;
    }

    // Obtener el pedido seleccionado de la lista de pedidos despachados
    auto it = pedidosDespachados.begin();
    advance(it, numeroPedido - 1);
    Pedido pedido = *it;

    facturarPedido(pedido);

    // Eliminar el pedido facturado de la lista de pedidos despachados
    pedidosDespachados.erase(it);
  } else {
    cout << "No hay pedidos despachados." << endl;
  }
  cout << "\033[32m******************************\033[0m" << endl;
  break;
}

        case 1:
           cout << "\033[34m*****************************\033[0m" << endl;
           cout << "\033[34mAgregar Pedido\033[0m" << endl;
            string nombrePlato, prioridad;
            int cantidad;

            cout << "Nombre del plato: ";
            cin >> nombrePlato;

            cout << "Cantidad: ";
            if (!(cin >> cantidad) || cantidad <= 0) {
              cout << "Error: La cantidad debe ser un numero valido mayor que 0." << endl;
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
              cout << "Prioridad (alta, media, baja): ";
              cin >> prioridad;

              int precio;
              cout << "Precio: ";
              cin >> precio;
   
              Pedido nuevoPedido(nombrePlato, cantidad, prioridad, precio);
              colaEspera.push(nuevoPedido);
              cout<<"Pedido agregado correctamente"<<endl;
              
            }
            cout << "\033[34m*****************************\033[0m" << endl;
          
          break;
           
         

     
         
      }
      
    }
   
    system("cls");
  return 0;
}