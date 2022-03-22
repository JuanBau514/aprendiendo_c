#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <locale.h>
#define max 300000

using namespace std;

char ejecucion;
int opcionMenu, opcion;
int numeros [100], n,datoBuscado,mayor, dato,x, i ;

void Menu () {
	
	cout<<"Bienvenido a la ejecucion del programa usted tiene las siguientes opciones :"<< endl ;
	
	cout<< endl <<  endl << "1. Digite la cantidad de elementos en su base de datos y sera mostrado en un arreglo."<< endl ;
	cout<<"2. En la base de datos digitada se buscara el numero mayor. "<< endl ;
	cout<<"3. En la base de datos digitada se buscara el numero menor. "<< endl ;
	cout<<"4. En la base de datos digitada se buscara los elementos repetidos "<< endl ;
	cin >> opcionMenu;
}

void LeerArreglo () {
	
	cout<<"Digite el numero de elementos que va a tener el arreglo"<< endl ;
	cin >> n ;
	
	for (int i=0; i<n;i++) {
		cout<<"Digite un numero: "<< endl ;
		cin >> numeros[i];// guardando elementos del vector
	}
}

void MostrarArreglo () {
	for (int i=0;i<n;i++) {
		cout<< i+1 <<  "  -->  "<< numeros[i] << endl ;
	}
}

void BuscarMayor () {
		i=0;
		mayor=numeros[0];
		while(numeros[i]!='\0')
		{
		    if(numeros[i]>mayor)
		    {mayor=numeros[i];
		    }
		    i++;
		}
	cout<<"Ek numero mayor de todo el arreglo es"<< mayor << endl ;
} 

	

int main () {
	
	setlocale (LC_ALL, "");
	
	do {
			
	Menu();
		switch (opcionMenu) {
				case 1 :
					LeerArreglo();
					MostrarArreglo();
					cout<<"¿ Quiere seguir con la ecucion del programa ?   V/F "<< endl ;
					cin >> ejecucion ;
					break;
				case 2:
					BuscarMayor ();
					cout<<"¿ Quiere seguir con la ecucion del programa ?   V/F "<< endl ;
					cin >> ejecucion ;
					break;
				case 3:
					//BuscarMenor ();
					break;
				case 4:
					//BuscarRepetido ();
					break;					
			} 
	} while (opcionMenu<6);		
}	
