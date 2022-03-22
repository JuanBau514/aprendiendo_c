#include <iostream>
#include <locale.h>
#include <math.h>
using namespace std;

int main () {
	
	string longitudInicial;
    int unidadConvertir;
	
	setlocale (LC_ALL, "spanish");
	
	cout << "Este es un programa para convertir cualquier unidad de metros a; kilometros, Decimetros, centimetros" << endl ;
	cout << "Cual es su valor inicial en metros" << endl ;
	cin >> longitudInicial;

	
     if (longitudInicial > 0)
      {
      	cout << "En que unidad quiere convertir su valor Inicial " << endl ;
      	cout << " 1 Kilometros, 2 Decimetros, 3 Centimetros " << endl ;
		cin >> unidadConvertir;
		
      	switch (unidadConvertir)
        	
 		{	
		case 1:
    		pesoFinal = pesoInicial * 3.8/9.8 ;
    		cout << "Su peso final en Marte es " << pesoFinal << " Kg" << endl ;
    		break;
		case 2:
    		pesoFinal = pesoInicial * 24.8/9.8 ;
    		cout << "Su peso final en Jupiter es " << pesoFinal << " Kg" << endl ;
    		break;

		case 3:
    		pesoFinal = pesoInicial * 11.15/9.8 ;
    		cout << "Su peso final en Neptuno es " << pesoFinal << " Kg" << endl ;
    		break;

		case 4:
    	pesoFinal = pesoInicial * 10.44/9.8 ;
    	cout << "Su peso final en Saturno es " << pesoFinal << " Kg" << endl ;
    	break;
    	
		default:
    			cout << "ERROR "  << endl ;
    			cout << "error usted a escogido una opcion incorrecta "  << endl ;
    	break;
		} 
      }
  
 
    system ("pause");
    return 1;

}
