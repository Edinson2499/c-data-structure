#include <iostream>
using namespace std; 

class Lista {
private:
    int *elementos;
    int TM;
    int cantidad;
public:
    Lista(int size) {
        TM = size;
        elementos = new int[TM];
        cantidad = 0;
    }



    void insertarAlInicio(int valor);
    void mostrarElementos();
    void insertarAlFinal(int valor);
    void eliminarEnPosicion(int posicion);
    void insertarEnPosicion(int valor, int posicion); 
    void transferirL(Lista &lista2);
    bool listaVacia(); 
    bool listallena(); 
    int QuitarUL();
    int Contador(int elementos);
    void vaciarLista();
    int buscarL(int elementos);
    int LogintudLista();
    void extend(Lista &lista1, Lista &lista2);
    void insertarL1L2();







};


void Lista::vaciarLista() {
    cantidad = 0; 
}


bool Lista::listaVacia(){

  return cantidad  == 0; 
     
    }


bool Lista::listallena(){
  return cantidad >= TM; 
}





void Lista::mostrarElementos() {
  cout<<endl; 
        cout << "Valores ingresados:" << std::endl;
        for (int i = 0; i < cantidad; ++i) {
            cout<<"|"<<elementos[i]<<"|";
  
         
        }
           cout<<endl;
           cout<<endl;
    }




void Lista::insertarAlInicio(int valor) {
        if (cantidad < TM) {
            for (int i = cantidad; i > 0; --i) {
                elementos[i] = elementos[i - 1];
            }
            elementos[0] = valor;
            cantidad++;
        } else {
            std::cout << "La lista está llena. No se puede insertar al inicio." << std::endl;
        }
    }













void Lista::insertarAlFinal(int valor) {
        if (cantidad < TM) {
            elementos[cantidad] = valor;
            cantidad++;
        } else {
            std::cout << "La lista está llena. No se puede insertar al final." << std::endl;
        }
    }











 void Lista::eliminarEnPosicion(int posicion) {
        if (posicion >= 0 && posicion < cantidad) {
            
            for (int i = posicion; i < cantidad - 1; ++i) {
                elementos[i] = elementos[i + 1];
            }
            cantidad--;
        } else {
            std::cout << "La posición especificada no es válida." << std::endl;
        }
    }









void Lista::insertarEnPosicion(int valor, int posicion) {
    if (posicion >= 0 && posicion <= cantidad && cantidad < TM) {
        // Desplazar los elementos a la derecha para hacer espacio para el nuevo valor
        for (int i = cantidad; i > posicion; --i) {
            elementos[i] = elementos[i - 1];
        }
        elementos[posicion] = valor;
        cantidad++; // Incrementar la cantidad solo una vez después de la inserción
    } else {
        std::cout << "La posición especificada no es válida o la lista está llena." << std::endl;
    }
}




//Quitar un ultimo elemento//

int Lista::QuitarUL(){
	if (!listaVacia()){
		int EliminarVa = elementos[cantidad - 1];
		cantidad--;
		return EliminarVa;
	}
	return -1;
}




//{Transferir para invertir los valores de la lista}//

void Lista::transferirL(Lista &lista2){
  while (!listaVacia() && !lista2.listallena()) {
    int elemento = QuitarUL();
    if (elemento != -1) { 
      lista2.insertarAlFinal(elemento);
    }
  }
}

//contador de elementos


int Lista::Contador(int _elemento) {
  int count = 0;
  for (int i = 0; i < cantidad; i++) {
    if (elementos[i] == _elemento) {
      count++;
    }
  }
  return count; 
}



//Mostrar la posicion en donde esta el elemento// 

int Lista::buscarL(int _elemento){
  for (int i = 0; i < cantidad; i++) {
    if (elementos[i] == _elemento) {
        return i; 
    }
  }
  return -1;
}


int  Lista::LogintudLista(){

  cout<<cantidad; 
  
}


void Lista::extend(Lista &lista1, Lista &lista2) {
  while (!lista1.listaVacia() && !listallena()) {
    int elemento = lista1.QuitarUL();
    if (elemento != -1) { 
      insertarAlFinal(elemento);
    }
  }
  while (!lista2.listaVacia() && !listallena()) {
    int elemento = lista2.QuitarUL();
    if (elemento != -1) { 
      insertarAlFinal(elemento);
    }
  }
}



int main(){



  
  int TM;
  int PosciElemento;
  int cantidadElementos;
  int elementoABuscar; 

  cout<<"¿De que tamaño será la lista? ";cin>>TM; 
  cout<<endl; 
  cout<<"¡ASIGNADO CORRECTAMENTE!"; 
  cout<<endl; 
    std::cout << "    *" << std::endl;
    std::cout << "   ***" << std::endl;
    std::cout << "  *****" << std::endl;
    std::cout << "    *" << std::endl;
    std::cout << "    *" << std::endl;
    
  
  


  Lista l1(TM);
  Lista l2(TM); 
  Lista l3(TM);
  Lista l4(TM);
  Lista l5(TM);
  


  

  

    int opc;
   

  do{

    int valor; 

    
cout<<endl; 
    
      cout<<"(1)  — Insertar incio lista "<<endl; 
      cout<<"(2)  — Insertar final lista "<<endl;
      cout<<"(3)  — Eliminar posicion 'n' lista"<<endl;
      cout<<"(4)  — Insertar en posicion 'n' de la lista"<<endl;
      cout<<"(5)  — Eliminar ultimo elemento "<<endl;
      cout<<"(6)  — Invertir valores de la lista"<<endl; 
      cout<<"(7)  — Limpiar lista"<<endl;
      cout<<"(8)  — Contabilizar elementos de la lista"<<endl;
      cout<<"(9)  — Mostrar posicion de elemento 'n'"<<endl;
      cout<<"(10) — Longuitud lista"<<endl; 
      cout<<"(11) - Extender lista en una"<<endl; 
    
    
  
    
    cout<<endl; 
      cout<<"   ------> OPCION: ";  cin>>opc; 
    cout<<endl; 
    cout<<"                       ¡OPCION ELEGIDA CORRECTAMENTE!"; 
    cout<<endl; 
                           cout<<endl; 
    
    
    

    int cantidadElementos =0; 
    int opc2;
    
    
    switch(opc){

      case 1:

        int opc2; 
  

        cout<<"         (5) — Para insertar en la Lista '1'  "<<endl; 
        cout<<"         (6) — Para insertar en la Lista '2' "<<endl;
        cout<<"         Digite aqui: "; cin>>opc2; 

        if(opc2 ==5){
          cout<<endl; 
          cout<<endl;
          cout<<"        Ha seleccionado la Lista 1"<<endl; 
          cout<<"        Digite el valor a insertar: ";  cin>>valor;  
          cout<<endl; 
          l1.insertarAlInicio(valor);
          l1.mostrarElementos(); 
          
          
        }if(opc2 ==6){
          cout<<endl; 
          cout<<endl;
          cout<<"        Ha seleccionado la Lista 2"<<endl; 
          cout<<"        Digite el valor a insertar: ";  cin>>valor;  
          cout<<endl; 
          l2.insertarAlInicio(valor); 
          l2.mostrarElementos(); 
        }

      break; 
      



      case 2:

        cout<<"¡OPCION PARA INSERTAR AL FINAL DE LA LISTA!"<<endl; 
        cout<<endl; 
        

        cout<<"         (5) — Para insertar en la Lista '1'  "<<endl; 
        cout<<"         (6) — Para insertar en la Lista '2' "<<endl;
        cout<<"         Digite aqui: "; cin>>opc2; 
        cout<<endl; 
        
        if(opc2 ==5){
          cout<<endl; 
          cout<<endl;
          cout<<"        Ha seleccionado la Lista 1"<<endl; 
          cout<<"        Digite el valor a insertar: ";  cin>>valor;  
          cout<<endl; 
          l1.insertarAlFinal(valor); 
          l1.mostrarElementos(); 
          
          
        }if(opc2 ==6){
          cout<<endl; 
          cout<<endl;
;          cout<<"         Ha seleccionado la Lista 2"<<endl; 
          cout<<"         Digite el valor a insertar: ";  cin>>valor;  
          cout<<endl; 
          l2.insertarAlFinal(valor);  
          l2.mostrarElementos(); 
        }
        break;



      
        case 3:
          int posicionEliminar;
                    
          cout<<"¡OPCION PARA ELIMINAR UNA POSICION!"<<endl; 
          cout<<endl; 

          
        

          cout<<"         (5) — Para eliminar en la Lista '1'  "<<endl; 
          cout<<"         (6) — Para eliminar en la Lista '2' "<<endl;
          cout<<"         Digite aqui: "; cin>>opc2; 
          cout<<endl; 
        
        if(opc2 ==5){
          cout<<endl; 
          cout<<endl;
          cout<<"        Ha seleccionado la Lista 1"<<endl; 
          cout<<endl; 
          cout<<"        Elementos dentro de la lista 1: "<<endl; 
          l1.mostrarElementos();
          cout<<"        Digite la posicion a eliminar";  cin>>posicionEliminar;
          cout<<endl; 
          l1.eliminarEnPosicion(posicionEliminar);
          l1.mostrarElementos(); 
          
          
        }if(opc2 ==6){ 
          cout<<endl; 
          cout<<endl;
          cout<<"        Ha seleccionado la Lista 2"<<endl; 
          cout<<"        Digite la posicion a eliminar";  cin>>posicionEliminar;
          cout<<endl; 
          l2.eliminarEnPosicion(posicionEliminar);
          l2.mostrarElementos(); 
        }
        break;



      
      case 4: 

        
         int posicion;
          cout<<"¡OPCION PARA INVERTIR VALORES EN LA LISTA!"<<endl; 
          cout<<endl; 

          cout<<"         (5) — Para riverse en la Lista '1'  "<<endl; 
          cout<<"         (6) — Para riverse en la Lista '2' "<<endl;
          cout<<"         Digite aqui: "; cin>>opc2; 
          cout<<endl; 
        
        if(opc2 ==5){
          cout<<endl; 
          cout<<endl;
          cout<<"        Ha seleccionado la Lista 1"<<endl; 
          cout<<endl; 
           int posicion;
        cout << "              Ingrese la posición ";cin >> posicion;
   
        cout<<"               Ingrese el valor"; cin>>valor;
        
        l1.insertarEnPosicion(valor, posicion);
        l1.mostrarElementos();

        }if(opc2 ==6){ 
          cout<<endl; 
          cout<<endl;
          cout<<"        Ha seleccionado la Lista 2"<<endl; 
          cout<<endl; 
         cout << "              Ingrese la posición ";cin >> posicion;
   
        cout<<"                 Ingrese el valor"; cin>>valor;
        
        l2.insertarEnPosicion(valor, posicion);
        l2.mostrarElementos();
        }
        break; 
      


      case 5:




          cout<<"¡OPCION PARA ELIMINAR ULTIMA ELEMENTO EN LA LISTA!"<<endl; 
          cout<<endl; 

          cout<<"         (5) — Para eliminar en la Lista '1'  "<<endl; 
          cout<<"         (6) — Para eliminar en la Lista '2' "<<endl;
          cout<<"         Digite aqui: "; cin>>opc2; 
          cout<<endl; 
        
        if(opc2 ==5){
          cout<<endl; 
          cout<<endl;
          cout<<"          Ha seleccionado la Lista 1"<<endl; 
          cout<<endl; 
          l1.QuitarUL();
          l1.mostrarElementos();


        }if(opc2 ==6){ 
          cout<<endl; 
          cout<<endl;
          cout<<"        Ha seleccionado la Lista 2"<<endl; 
          cout<<endl; 
          l2.QuitarUL();
          l2.mostrarElementos();
        }
        break; 



      case 6: 
    
          cout<<"¡OPCION PARA INVERTIR VALORES EN LA LISTA!"<<endl; 
          cout<<endl; 

          
        

          cout<<"         (5) — Para riverse en la Lista '1'  "<<endl; 
          cout<<"         (6) — Para riverse en la Lista '2' "<<endl;
          cout<<"         Digite aqui: "; cin>>opc2; 
          cout<<endl; 
        
        if(opc2 ==5){
          cout<<endl; 
          cout<<endl;
          cout<<"        Ha seleccionado la Lista 1"<<endl; 
          cout<<endl; 
          cout<<"        Elementos invertidos de lista 1: "<<endl; 
          l1.transferirL(l4);
          l1=l4; 
          l1.mostrarElementos();

        }if(opc2 ==6){ 
          cout<<endl; 
          cout<<endl;
          cout<<"        Ha seleccionado la Lista 2"<<endl; 
          cout<<endl; 
          cout<<"        Elementos invertidos de lista 1: "<<endl; 
          l2.transferirL(l5);
          l2=l5; 
          l2.mostrarElementos();
        }
        break; 
      
 case 7:



                    
          cout<<"¡OPCION PARA VACIAR LISTAS!"<<endl; 
          cout<<endl; 

          
        

          cout<<"         (5) — Para vaciar en la Lista '1'  "<<endl; 
          cout<<"         (6) — Para vaciar en la Lista '2' "<<endl;
          cout<<"         Digite aqui: "; cin>>opc2; 
          cout<<endl; 
        
        if(opc2 ==5){
          cout<<endl; 
          cout<<endl;
          cout<<"        Ha seleccionado la Lista 1"<<endl; 
          l1.vaciarLista();
          cout<<"La cantidad de elementos de la lista se han vaciado correctamente"<<endl;
          l1.mostrarElementos();
          
        }if(opc2 ==6){ 
          cout<<endl; 
          cout<<endl;
          cout<<"        Ha seleccionado la Lista 2"<<endl; 
          l2.vaciarLista();
          cout<<"La cantidad de elementos de la lista se han vaciado correctamente"<<endl;
          l2.mostrarElementos();
        }
        break; 

      case 8: 
        

                    
          cout<<"¡OPCION PARA CONTAR REPETIDOS EN LA LISTA!"<<endl; 
          cout<<endl; 

          cout<<"         (5) — Para contar en la Lista '1'  "<<endl; 
          cout<<"         (6) — Para contar en la Lista '2' "<<endl;
          cout<<"         Digite aqui: "; cin>>opc2; 
          cout<<endl; 
        
        if(opc2 ==5){
          cout<<endl; 
          cout<<endl;
          cout<<"        Ha seleccionado la Lista 1"<<endl; 

        cout << "        Ingrese el elemento que desea contar: ";
        int elementoContar; 
        cin >> elementoContar;
        cantidadElementos = l1.Contador(elementoContar);
        cout << "Cantidad de elementos " << elementoContar << " en la lista: " << cantidadElementos << endl;
          cout<<endl; 

        }if(opc2 ==6){ 
         cout<<endl; 
          cout<<endl;
          cout<<"        Ha seleccionado la Lista 2"<<endl; 

        cout << "        Ingrese el elemento que desea contar: ";
        int elementoContar; 
        cin >> elementoContar;
        cantidadElementos = l2.Contador(elementoContar);
        cout << "Cantidad de elementos " << elementoContar << " en la lista: " << cantidadElementos << endl;

          cout<<endl;
        }
  
        break;

      case 9: 

          cout<<"¡OPCION PARA SABER POSICION DE UN ELEMENTO EN LA LISTA!"<<endl; 
          cout<<endl; 

          cout<<"         (5) — Para posicion en la Lista '1'  "<<endl; 
          cout<<"         (6) — Para posicion en la Lista '2' "<<endl;
          cout<<"         Digite aqui: "; cin>>opc2; 
          cout<<endl; 
        
        if(opc2 ==5){
          cout<<endl; 
          cout<<endl;
          cout<<"        Ha seleccionado la Lista 1"<<endl; 

        cout << "Digite el elemento que desea saber la posicion: ";
        int elementoABuscar;
        cin >> elementoABuscar;
        PosciElemento = l1.buscarL(elementoABuscar);
        if (PosciElemento != -1) {
            cout << "La posicion en la que se encuentra " << elementoABuscar << " es: " << PosciElemento << endl;
        } else {
            cout << "El elemento " << elementoABuscar << " no se encuentra en la lista." << endl;
        }

        }if(opc2 ==6){ 
         cout << "Digite el elemento que desea saber la posicion: ";
        int elementoABuscar;
        cin >> elementoABuscar;
        PosciElemento = l2.buscarL(elementoABuscar);
        if (PosciElemento != -1) {
            cout << "La posicion en la que se encuentra " << elementoABuscar << " es: " << PosciElemento << endl;
        } else {
            cout << "El elemento " << elementoABuscar << " no se encuentra en la lista." << endl;
        }
        }
  
        break;

      
      case 10:
     
    cout<<"La cantidad de elementos que hay en la lista es: "<<endl; 
        
    l1.LogintudLista();
    l2.LogintudLista();
      break;


      case 11:

     l3.extend(l1,l2);
     l3.mostrarElementos();cout<<endl; 

      break; 
      


    }  







    
      
  }while(opc!=11); 
  
  }
