#include <iostream>
#include <locale.h>
#include <math.h>
using namespace std;

int main () {
	
	setlocale (LC_ALL, "spanish");

  char nombreUsuario [15];
  int precioFinal,categoria,contador, pagoTotal;
  precioFinal = 0;
  categoria = 0;
  contador=0;
  pagoTotal=0;
  
  		cout << "Digite su nombre de usuario " << endl ;
      	cin >> nombreUsuario;
  
  if(nombreUsuario > 0)
	{
      	cout << "Digite su categoria de afiliación de la EPS: 1 : A   2 : B   3 : C   4 : Otra categoria " << endl ;
      	cin >> categoria;
      	
      	if ( categoria > 0 ) {
      		
      		for (contador = 0; contador < 3 ; contador++)
		  	{
		  	
      		switch (categoria)
    			{
      				case 0 :
      				cout << "Digite su nombre de usuario " << endl ;
     				cin >> nombreUsuario;
      				cout << "Digite su categoria de afiliación de la EPS: 1:A   2:B   3:C   4 : Otra categoria " << endl ;
      				cin >> categoria;
      				break;

    				case 1:
      				precioFinal = 2500 + pagoTotal;
      				cout << "La cantidad de usuarios registrados son " << contador << endl ;
      				break;

    				case 2:
      				precioFinal = 5200 + pagoTotal;
      				cout << "La cantidad de usuarios registrados son " << contador << "debe de pagar " << precioFinal << endl ;
      				break;

    				case 3:
      				precioFinal = 12000 + pagoTotal;
      				cout << "La cantidad de usuarios registrados son " << contador << "debe de pagar " << precioFinal << endl ;
     				 break;

      				case 4:
      				precioFinal = 25000 + pagoTotal;
      				cout << "La cantidad de usuarios registrados son " << contador << "debe de pagar " << precioFinal << endl ;
      				break;
    
    		default:
     			cout << "error usted a escogido una opcion incorrecta " << "debe de pagar " << precioFinal << endl ;
      		break;
    			};
		  	}; //ciclo
		}
	
	else	
	{
		cout << "error usted a escogido una opcion incorrecta "  << endl ;
	};
}
	system ("pause");
    return 1;
}
