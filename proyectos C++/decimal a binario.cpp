#include<iostream>
using namespace std;

int main () 
{
	int decimal,cociente,residuo;
	short binario[8];
	
	cout << "Escribe algun numero "<< endl ;
    cin >> decimal; //3
    
    for (int i=0; i<8; i++) 
    {
    	cociente=decimal/2;
		residuo=decimal%2;
		printf("cociente %d\n",cociente);
		printf("residuo %d\n",residuo);
	}
    
        cout << "El numero convertido a binario es " << endl ;
        
    for (int i = 7; i>=0; i++)
	{
    	cout << residuo << endl ;
	}
    
    cout << endl ;
}
