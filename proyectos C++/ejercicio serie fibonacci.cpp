#include<iostream>
#include<stdlib.h>
#include<locale.h>
#include <iomanip>
using namespace std;
 
  main (){
	setlocale(LC_ALL,"spanish");
	
	int nNumeros,x=0,y=1,z=1;
	
	cout<<"Numero de elementos en la serie fibonacii" <<endl;
	cin>>nNumeros;
	
	//imprimir los elementos de la serie menores que 1000
		
	for (int i=1; i<=nNumeros; i++){
		z = x + y;//1,2,3,5
		cout << z << " " <<endl; // imprime 1, 2,3,5
		x = y; // 1 1 2
		y = z; // 1 2 3
	}
}
