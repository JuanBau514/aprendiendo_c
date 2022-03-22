#include <iostream>
#include <windows.h>
using namespace std;

int multiplicacion(int valor1, int valor2) {
	 int procedimiento;
	 procedimiento = valor1 * valor2;
	 return procedimiento;
}

int main (){
	int valor1;
	int valor2;
	
	cout << "Progroma para calcular la multiplicacion de 2 numeros  " ;
	cin >> valor1;
	cin >> valor2;
	
	cout << "la multiplicacion de su numero es " << multiplicacion (valor1, valor2) << endl ;
	
	return 1;
}
