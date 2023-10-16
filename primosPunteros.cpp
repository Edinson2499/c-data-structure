#include<iostream>
#include<conio.h>
using namespace std;

int main(){

 int numero,*dir_numero,c;
 bool primo=false;
 c=0;// contador que se inicializa en 0
 cout<<"Digita un numero: "<<endl;
 cin>>numero;
 if(numero>=1){
 dir_numero=&numero;//guarda la posicion de memoria
 for(int i=2;i<=numero;i++){
 	if(numero%i==0)c++;
	 primo=true;
	 break;    
 }
 if(primo)cout<<"El numero "<<*dir_numero<<" es primo"<<endl;
 else cout<<"El numero "<<*dir_numero<<" no es primo "<<endl;
 cout<<"la direccion de memoria del numero "<<numero<<" es "<<dir_numero<<endl;
 	
 }else{
 	cout<<"ingresa un numero valido y que sea positivo"<<endl;
 }
 
  getch();
 
return 0;
 }
