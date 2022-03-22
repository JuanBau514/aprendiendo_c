// Hacer un algoritmo para convertir un número decimal N dado a binario
//Recordar al profe al final un punto sobre el parcial


#include<iostream>
#include<locale.h>
#include <iomanip>

#include<stdio.h>
#include<math.h>
using namespace std;
 
main () 
{
    int n1, x, binario;
 
    cout << "Escribe algun numero "<< endl ;
    cin >> n1; //3

    x=1;
    binario = 0;
    cout << "El numero "<< n1 << " convertido a binario es " << endl ;
    
    while (n1>= 1){
    	if (n1%2 == 1) {
    		binario = binario + x ;
		} 
    	// round es una funcion de la libreria math.h para redondear numeros
    	n1= round (n1/2);
    	x=x*10;
	}
    cout <<  binario << endl ;
}
