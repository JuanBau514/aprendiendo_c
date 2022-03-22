#include <iostream>
#include <locale.h>
using namespace std;

int main () {
	
	setlocale (LC_ALL, "spanish");
		
	do {
		char respuesta ;
		bool exit = false;	
		cout<< "teclee quiere continuar con la ejecucion del programa" << endl ;
	
		cout << "Quiere continuar 0 o NO 1" << endl;
		cin >> respuesta;
		switch (respuesta)
		{
		case 0:
			exit == true ;
			break;
			
		case 1:
			exit == true ;
			break;
		
		default:
    		cout << "ERROR "  << endl ;
    	break;	
		}
	}
	while ((respuesta == true)); 
	
    
    system ("pause");
    return 1;
}
