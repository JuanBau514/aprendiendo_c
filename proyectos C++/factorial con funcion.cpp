#include<iostream>
#include<locale.h>
#include <iomanip>
using namespace std; 
int main (){
	setlocale(LC_ALL,"spanish");
	long double numero,cont, factorial=1, factorial_i=1;
	cout<<"digite un numero para calcular su factorial"<<endl;cin>>numero;
	
	factorial=numero;
	while(numero>1){
		factorial_i=factorial*(numero-1);
		factorial=factorial_i;
		numero--;
	} 
	cout<<" el numero en factorial es"<<factorial<<endl;
}
