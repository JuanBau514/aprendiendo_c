#include <iostream>
#include <math.h>
# define Pi 3.141516
using namespace std;

int main () {

    int pesoInicial;
    int elegir_planeta;
    elegir_planeta = 0;
    double pesoFinal = 0 ;

    cout << "Este es un programa para que usted sepa cual seria su peso en otro planeta " << endl ;
    cout << "Cual es su peso en el planeta tierra " << endl ;
        cin >> pesoInicial;
    cout << "Digite en que planeta quiere saber su peso ; 1 marte, 2 Jupiter, 3 neptuno, 4 saturno " << endl  ;
        cin >> elegir_planeta ;

switch (elegir_planeta)
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

    //if (elegir_planeta = 1)
    //{
      //  pesoFinal = pesoInicial * 3.8/9.8 ;
        //cout << "Su peso final en marte es " << pesoFinal << " Kg" << endl ;
   // }
    

 
    system ("pause");
    return 1;

}
