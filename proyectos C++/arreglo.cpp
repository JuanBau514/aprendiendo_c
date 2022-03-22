#include <iostream>
#include<conio.h>

using namespace std;

main()
{
	int numeros [100], n ;
	
	cout<<"Digite el numero de elementos que va a tener el arreglo"<< endl ;
	cin >> n ;
	
	for (int i=0; i<n;i++) {
		cout<<"Digite un numero: "<< endl ;
		cin >> numeros[i];// guardando elementos del vector
	}
	
	//mostrando los elementos del vector 
	
	for (int i=0;i<n;i++) {
		cout<< i+1 <<  "  -->  "<< numeros[i] << endl ;
	}
	
}

