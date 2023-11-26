	#include <iostream>
	#include  <string> 
	#include <stdio.h>
	#include <fstream>
	using namespace std;
	
	
	
	class Libreta{
	
	
	
	private: 
	class Contacto{
	    public: 
	    string nombre,apellido, sim; 
	    int edad;
	    string num; 
	    Contacto* siguiente; 
	
	}; 
	
	
	public: 
	
	
	Contacto *raiz; 
	int cantidad; 
	void insertarSim(string sim); 
	int agregarcontacto(string nombre,  string  apellido, int edad, string num); 
	void eliminarC(string nombre); 
	void eliminarC2(string num); 
	void eliminarC3(string apellido);
	void mostrarC();
	void llamarC(); 
	void estallena(); 
	void  estavacia(); 
	void ModificarContact(string nombre, string newname, string apellido, string newapellido, int edad, int newedad, string num, string newnum); 
	void guardarContactos();
	void cargarContactos();
	void centrarTexto(string texto, int x);
	
	};
	
	

	
	void Libreta::guardarContactos() {
	    ofstream archivoSalida("ContactosMovistar.txt");
		archivoSalida<<"                            LISTA DE CONTACTOS MOVISTAR"<<endl;	
	    if (!archivoSalida.is_open()) {
	        cout << "No se pudo abrir el archivo de salida: ContactosMovistar.txt" << endl;
	        return;
	    }
		
		archivoSalida<<endl;
		archivoSalida<<endl; 
		
	    Contacto* recorrido = raiz;
	    
	    
	    while (recorrido != NULL) {
	        archivoSalida<<"                            -Nombre:   "<<recorrido->nombre<<endl;
	        archivoSalida<<"                            -Apellido: "<<recorrido->apellido<<endl;
	        archivoSalida<<"                            -Edad:     "<<recorrido->edad<<endl;
	        archivoSalida<<"                            -Numero:   "<<recorrido->num<<endl;
	        archivoSalida<<endl; 
	        archivoSalida<<endl;
	        recorrido = recorrido->siguiente;
	    }
	
	    archivoSalida.close();
	
	    if (archivoSalida.fail()) {
	    } else {
	    	centrarTexto("Contactos guardados correctamente",1);
	    

	    }
	    
	    
	}
	
	
	
	void Libreta::cargarContactos() {
	    ifstream archivoEntrada("ContactosMovistar.txt");
	
	    if (!archivoEntrada.is_open()) {
	    	centrarTexto("No se pudo abrir el archivo de entrada: ContactosMovistar.txt",1);
	    
	        return;
	    }
	
	    string titulo;
	    Contacto* recorrido = NULL;  
	
	   
	    getline(archivoEntrada, titulo);
	
	    
	    while (archivoEntrada >> titulo) {
	        if (titulo == "-Nombre:") {
	            Contacto* nuevo = new Contacto();
	            archivoEntrada >> nuevo->nombre;
	            archivoEntrada >> titulo; // "-Apellido:"
	            archivoEntrada >> nuevo->apellido;
	            archivoEntrada >> titulo; // "-Edad:"
	            archivoEntrada >> nuevo->edad;
	            archivoEntrada >> titulo; // "-Numero:"
	            archivoEntrada >> nuevo->num;
	
	            nuevo->siguiente = NULL;
	
	            // Insert the new contact into the list
	            if (raiz == NULL) {
	                raiz = nuevo;
	                recorrido = nuevo;
	            } else {
	                recorrido->siguiente = nuevo;
	                recorrido = nuevo;
	            }
	        }
	    }
	
	    archivoEntrada.close();
	
	    if (archivoEntrada.fail()) {
	    } else {
	    	centrarTexto("Contactos cargados correctamente",1);
	        
	    }
	}
	
	
	
	int Libreta::agregarcontacto(string nombre, string apellido, int edad, string num){
	
	
	
	    Contacto *nuevo = new Contacto();
	
	    nuevo->nombre = nombre; 
	    nuevo->apellido = apellido;
	    nuevo->edad =edad; 
	    nuevo ->num=num; 
	    nuevo->siguiente =NULL;
	
	    if(raiz == NULL){
	      raiz = nuevo; 
	
	    }else{
	
	      Contacto *recorrido = raiz;
	      while(recorrido->siguiente != NULL){
	        recorrido = recorrido->siguiente; 
	
	    }
	      recorrido->siguiente = nuevo;
	
	  }
	  return 0; 
	
	}; 
	
	
	
void Libreta::ModificarContact(string nombre, string newname, string apellido, string newapellido, int edad, int newedad, string num, string newnum) {
    int cc;
    
    centrarTexto("Opciones de contacto",1);
    centrarTexto("(1) Modificar nombre",1);
    centrarTexto("(2) Modificar Apellido",1);
    centrarTexto("(3) Modificar Edad",1);
    centrarTexto("Ingrese su opcion aqui:",0); cin >> cc;
    cout << endl;

    Contacto *recorrido = raiz;

    while (recorrido != NULL) {
        if (cc == 1 && recorrido->nombre == nombre) {
        	
        	centrarTexto("MODIFICAR NOMBRE",1);
        	centrarTexto("Digite el nuevo nombre:",0); cin >> newname;
            
            recorrido->nombre = newname;
            centrarTexto("Se ha realizado el cambio de nombre",1);
            break;  
        } else if (cc == 2 && recorrido->apellido == apellido) {
        	centrarTexto("MODIFICAR APELLIDO",1);
        	centrarTexto("Digite el nuevo apellido:",0);cin >> newapellido;
            recorrido->apellido = newapellido;
            centrarTexto("Se ha realizado el cambio de apellido",1);
            break;  
        } else if (cc == 3 && recorrido->nombre == nombre) {
        	centrarTexto("MODIFICAR EDAD",1);
        	centrarTexto("Digite la nueva edad:",0);cin >> newedad;
            recorrido->edad = newedad;
            centrarTexto("Se ha realizado el cambio de edad",1);
            break;  
        } 

        recorrido = recorrido->siguiente;
    }
}

	

	
	void Libreta::eliminarC(string nombre) {
	
	
	
	    if (raiz != NULL) {
	        if (raiz->nombre == nombre) {
	            Contacto *borrar = raiz;
	            raiz = raiz->siguiente;
	            delete borrar;
	            cout<<endl; 
	            centrarTexto("El contacto fue borrado exitosamente",1);
	            
	        } else {
	            Contacto *recorrido = raiz;
	            Contacto *anterior = NULL;
	            while (recorrido != NULL && recorrido->nombre != nombre) {
	                anterior = recorrido;
	                recorrido = recorrido->siguiente;
	            }
	
	            if (recorrido != NULL) {
	                anterior->siguiente = recorrido->siguiente;
	                delete recorrido;
	                centrarTexto("El paciente fue borrado exitosamente",1);
	                
	            }
	        }
	    } else {
	    	centrarTexto("La lista de contactos está vacía.",1);
	        
	    }
	}
	
	

	
	void Libreta::eliminarC2(string num) {
	    if (raiz != NULL) {
	        if (raiz->num == num) {
	            Contacto *borrar = raiz;
	            raiz = raiz->siguiente;
	            delete borrar;
	            cout<<endl; 
	            centrarTexto("El contacto fue borrado exitosamente",1);
	            
	        } else {
	            Contacto *recorrido = raiz;
	            Contacto *anterior = NULL;
	            while (recorrido != NULL && recorrido->num != num) {
	                anterior = recorrido;
	                recorrido = recorrido->siguiente;
	            }
	
	            if (recorrido != NULL) {
	                anterior->siguiente = recorrido->siguiente;
	                delete recorrido;
	                centrarTexto("El contacto se borró exitosamente",1);
	                
	            }
	        }
	    } else {
	    	centrarTexto("La lista de contactos está vacía",1);
	        
	    }
	}
	

	void Libreta::eliminarC3(string apellido) {
	    if (raiz != NULL) {
	        if (raiz->apellido == apellido) {
	            Contacto *borrar = raiz;
	            raiz = raiz->siguiente;
	            delete borrar;
	            cout<<endl; 
	            centrarTexto("El contacto fue borrado exitosamente",1);
	       
	        } else {
	            Contacto *recorrido = raiz;
	            Contacto *anterior = NULL;
	            while (recorrido != NULL && recorrido->apellido != apellido) {
	                anterior = recorrido;
	                recorrido = recorrido->siguiente;
	            }
	
	            if (recorrido != NULL) {
	                anterior->siguiente = recorrido->siguiente;
	                delete recorrido;
	                centrarTexto("El contacto se borró exitosamente",1);
	                
	            }
	        }
	    } else {
	    	
	    	centrarTexto(" La lista de contactos está vacía",1);
	        
	    }
	}
	
	
	
	
	void Libreta::mostrarC(){
	
	    Contacto* recorrido = raiz;
	    while (recorrido != NULL)
	    {
	    	string MensajeN ="--NOMBRE: " +recorrido->nombre;
	    	centrarTexto(MensajeN,1);
			string MensajeA ="--APELLIDO: "+recorrido->apellido; 
			centrarTexto(MensajeA,1); 
			string MensajeE = "--EDAD: " + to_string(recorrido->edad);
			centrarTexto(MensajeE,1);
			string MensajeCall ="--NUMERO: "+recorrido->num;
	      	centrarTexto(MensajeCall,1);
	      recorrido = recorrido->siguiente;
	      cout<<endl; 
	      cout<<endl; 
	    }
	
	}
	
	
	void Libreta::centrarTexto(string texto, int x){
	int espacio = (120 - texto.size()) / 2; 
  	if(x > 0){
  		for(int i = 0; i < espacio; i++){
  			cout << " ";
    	}
    cout << texto << endl;
  	}else{
  		for(int i = 0; i < espacio; i++){
  			cout << " ";
    	}
    cout << texto;
  	}
}
	
	
	
	
	
	
	
	  int main(){
	     int n; 
	Libreta *l1 = new Libreta();
	    int opc; 
	    string nombre, newname, apellido, newapellido, num, newnum;
	    
	   int edad, newedad; 
	    
	
	
	    cout<<endl; 
			 l1->centrarTexto("LIBRETA DE CONTACTOS MOVISTAR",1);
		  	 cout<<endl; 
		   	 cout<<endl; 
		     cout<<endl; 
		     cout<<endl; 
		  
	do{
		  l1->centrarTexto("(1) Para agregar nuevo contacto",1);
		  l1->centrarTexto("(2) Para eliminar un contacto",1);
		  l1->centrarTexto("(3) Para mostrar mis contactos",1);
		  l1->centrarTexto("(4) Para modificar contacto",1);
		  l1->centrarTexto("(5) Guardar en la lista de contactos",1);
		  l1->centrarTexto("(6) Cargar la lista de contactos",1);
		  cout<<endl; 
		  l1->centrarTexto("Digite su opcion aqui: ",0); cin>>opc;
	      cout<<endl; 
	      cout<<endl; 
	      
	      switch(opc){
	
	        case 1: 
	        system("cls");
				l1->centrarTexto("MOVISTAR",1);
	          cout<<endl; 
	          cout<<endl; 
			l1->centrarTexto("NUEVO CONTACTO",1);
	        cout<<endl;  
	        l1->centrarTexto("Ingrese el nombre del contacto",1);
	        cout<<endl;
	        l1->centrarTexto("Digite aqui: ",0); cin>>nombre;
	        cout<<endl; 
	        l1->centrarTexto("Ingrese el apellido del contacto",1);
	        cout<<endl;
	        l1->centrarTexto("Digite aqui: ",0); cin>>apellido;
	        cout<<endl;
	        l1->centrarTexto("La edad del contacto",1);
	        cout<<endl;
	        l1->centrarTexto("Digite aqui: ",0); cin>>edad;
	        cout<<endl; 
	        l1->centrarTexto("Digite el numero del contacto",1);
	        cout<<endl;
	        l1->centrarTexto("Digite aqui: ",0); cin>>num; 
	          cout<<endl; 
	          cout<<endl; 
	        	l1->agregarcontacto(nombre, apellido,  edad,  num);


	          
	
	        break; 
	
	
	
	        case 2:
	        system("cls");
	
	         l1->centrarTexto("Indica de que forma desea borrar el contacto",1);
	         l1->centrarTexto("(1) Para borrar por el nombre",1);
	         l1->centrarTexto("(2) Para borrar por el numero",1);
	         l1->centrarTexto("(3) Para borrar por el apellido",1);
	         
	          
	          
	          l1->centrarTexto("Diguite aqui",0); cin>>n; 
	          cout<<endl; 
	          if(n ==1){
	          	l1->centrarTexto("Usted ha seleccionado la opcion de borrar por nombre",1);
	          	l1->centrarTexto("Digite el nombre aqui:",0); cin>>nombre; 
	            l1->eliminarC(nombre); 
	          }if(n==2){
	          	l1->centrarTexto("Usted ha seleccionado la opcion de borrar por numero",1);
	            l1->centrarTexto("Digite el nombre aqui:",0); cin>>num; 
	            l1->eliminarC2(num); 
	          }if(n==3){
	          	l1->centrarTexto("Usted ha seleccionado la opcion de borrar por apellido",1);
	            l1->centrarTexto("Digite el nombre aqui:",0); cin>>apellido; 
	            l1->eliminarC3(apellido);
	 
	           
	           }
	
	        break; 
	        
	        case 3:
	        system("cls");
	          l1->centrarTexto("TUS CONTACTOS MOVISTAR",1);
	          cout<<endl; 
	          l1->centrarTexto("ESTOS SON TUS CONTACTOS ACTUALES",1);
	          cout<<endl; 
	        l1->mostrarC(); 
	        break;
	
	
	
	
	        case 4:
	        system("cls");
	        	l1->centrarTexto("MODIFICACION DE CONTACTO",1);
	        	l1->centrarTexto("Digite el nombre del contacto que desea modificar: ",0);cin >> nombre;
                l1->ModificarContact(nombre, newname, apellido, newapellido, edad, newedad, num, newnum);
                l1->mostrarC();
                break;
	        
	        
	        case 5:
	        system("cls");
	        l1->guardarContactos();
	        break; 
	        
	        
	        case 6:
	        system("cls");
	        l1->cargarContactos();
	        break;
	        
	
	      }
	
	    }while(opc!=7);
	
	
	  }
	
	
	
	

