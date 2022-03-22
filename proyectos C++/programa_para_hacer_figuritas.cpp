#include <iostream>
#include <windows.h>
#include <conio.h>
#include <math.h>

using namespace std;

void movCaracter(int x, int y){
HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
 COORD dwPos;
 dwPos.X = x;
 dwPos.Y = y;
 SetConsoleCursorPosition(hcon, dwPos);
}

class enemigo {
	
	private: 
	
	public:
		void pintar (int,int);
		void mover (int &, int &);
		
};

void enemigo::pintar(int x, int y ){
	movCaracter(x,y);
	cout << "O" ;
}

void enemigo::mover(int &x, int &y){
	if(kbhit())
	{
		char tecla = getch();
		if (tecla == 'a')  x-- ;
		if (tecla == 'd')  x++ ;
		if (tecla == 'w')  y-- ;
		if (tecla == 's')  y++ ;
		enemigo :: pintar (x,y);
	}
}

int main (){
	
	enemigo a;
	int q1=5, w1=5;
	
	while(true){
			a.mover(q1,w1);
	}	
    
}
