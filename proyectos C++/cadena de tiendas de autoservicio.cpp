// La cadena de tiendas de autoservicio "El mandilón" cuenta con sucursales en C ciudades diferentes de la República, 
// en cada ciudad cuenta con T tiendas y cada tienda cuenta con N empleados, asimismo,
// cada una registra lo que vende de manera individual cada empleado, cuánto fue lo que vendió cada tienda,
// cuánto se vendió en cada ciudad y cuánto recaudó la cadena en un solo día.	
// Realice un algoritmo para determinar lo anterior y represéntelo mediante un diagrama de flujo, utilizando ciclos
// desarrollar utilizando for y while, utilizar do-while para que el programa se repita hasta que el usuario dese

#include<iostream>
#include<locale.h>
#include <iomanip>
using namespace std;
 
int main (){
	
int cCiudades,tTiendas, nEmpleados;

cout << "Digite el numero al cual usted va a sumar o restar " << endl ;
cin >> numeroSuma;

cout << "Digite el numero por el cual se va a sumar o restar " << endl ;
cin >> sumando;

cout << "Cuantas veces quiere que se repita la suma " << endl ;
cin >> i;

for (int f=1; f<= i; f++) {
		numeroSuma = numeroSuma+sumando;
		cout<<" El Resultado Final es  " << numeroSuma<<endl;
}
	//	cout<<" El Resultado Final es  " << resultado <<endl;
	
	
}
