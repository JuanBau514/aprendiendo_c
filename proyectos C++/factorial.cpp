#include<iostream>
#include<locale.h>
#include <iomanip>
#include<math.h>

using namespace std; 

int Misterio (int a, int b){
	
	if (a<=0 && b<=0)
	return 1;
	if ((a,2)mod)=0){
		return a + Misterio (b,b-1);
	}else {
		return b + Misterio (a+1,b);
	}
}

int main (){
	int a, b;

	setlocale(LC_ALL,"spanish");
	cout<<"digite un numero para calcular su factorial"<<endl;
	cin>>a;
	cin>>b;
	
	cout<<" el numero en factorial es "<< Misterio(a,b) <<endl;
}
