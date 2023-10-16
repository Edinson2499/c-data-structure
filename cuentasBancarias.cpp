# include <iostream>
using namespace std;
# include <string>
void crearc(string &, long int &,float&, long int &, float &);
void conscte(string &, long int &,float&, long int &, float &);
//void consaho(string &, long int &,float&, long int &, float &);
bool creado=0;
float aho,cdt;
long int DNI,cte,opc;
string nombre;
int main()
{
    do
    {
    cout<<"1. Visualizar el saldo de la cuenta corriente del cliente."<<endl;
    cout<<"2. Visualizar el saldo de la cuenta de ahorros del cliente."<<endl;
    cout<<"3. Visualizar el saldo del CDT del cliente."<<endl;
    cout<<"4. Visualizar el saldo total que tiene el cliente en los productos del banco."<<endl;
    cout<<"5. Invertir un monto de dinero en un CDT."<<endl;
    cout<<"6. Cerrar la inversión en CDT."<<endl;
    cout<<"7. Consignar un monto de dinero en la cuenta corriente del cliente."<<endl;
    cout<<"8. Retirar un monto de dinero en la cuenta corriente del cliente."<<endl;
    cout<<"9. Consignar un monto de dinero en la cuenta de ahorros del cliente."<<endl;
    cout<<"10. Retirar un monto de dinero en la cuenta de ahorros del cliente."<<endl;
    cout<<"11. Avanzar en un mes la simulación."<<endl;
    cout<<"Digite 0 para salir"<<endl;
    cin>>opc;
        if(creado==1)
        {
            switch(opc)
            {
              case 1:
             conscte(nombre, DNI,aho, cte , cdt );
              break;
              case 2:
          //    consaho(nombre, DNI,aho, cte , cdt )
              break;
            }
        }
        else
        {
            crearc(nombre, DNI,aho, cte , cdt );
            creado=1;
        }
    }while(opc!=0);
}
void crearc(string & nombre, long int & DNI,float& aho , long int & cte, float & cdt)
{
    cin.ignore();
    cout<<"Digite el nombre del cliente"<<endl;
    getline(cin,nombre,'\n');
    cin.ignore();
    cout<<"Digite el numero de identificacion"<<endl;
    cin>>DNI;
    cout<<"Digite el valor apertura ahorros"<<endl;
    cin>>aho;
    cout<<"Digite el valor apertura cte"<<endl;
    cin>>cte;
    cout<<"Digite el valor apertura cdt"<<endl;
    cin>>cdt;
 }
void conscte(string & nombre, long int & DNI ,float& aho, long int & cte, float & cdt)
{
 cout<<"Nombre: "<<nombre<<endl;
 cout<<"Documento Identidad: "<<DNI<<endl;
 cout<<"Cta Corriente: "<<cte<<endl;
 return;
}
 
 
 
 
 
