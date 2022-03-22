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

char map[22][22] =   {{' ',' ','A',' ','B',' ','C',' ','D',' ','E',' ','F',' ','G',' ','H',' ','I',' ','J',' '},
       {' ',' ','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',' '},
       {'0','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
       {' ','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
       {'1','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
       {' ','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
       {'2','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
       {' ','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
       {'3','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
       {' ','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
       {'4','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
       {' ','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
       {'5','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
       {' ','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
       {'6','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
       {' ','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
       {'7','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
       {' ','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
       {'8','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
       {' ','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|','-','|'},
       {'9','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
       {' ',' ','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',' '},};
       
       
  struct coordenadas {
  	int x; 
	int y;
  };
  
  struct pieza {
  	coordenadas ori; 
  	cordenadas per [3];
	  
	char 0; 
  };


class enemigo {
	
	private: 
	
	
	
	public:
		void mostrarMap();
		void pintar (int,int);
		void borrar (int, int);
		void mover (int &, int &);
		
};

void enemigo :: mostrarMap (){
	for(int i = 0; i < 22; i++){
		cout << endl;
		for(int j = 0; j < 22; j++){
			cout << map[i][j];
		}
	}
}

void enemigo::pintar(int x, int y ){
	movCaracter(x,y);
	cout << "O" ;
}

void enemigo::borrar(int x, int y){
	movCaracter(x,y); 
	cout << (" ");
}

void enemigo::mover(int &x, int &y){
	if(kbhit())
	{
		enemigo::borrar(x,y);
		char tecla = getch();
		if (tecla == 'a' && x>2)  x = x-2 ;
		if (tecla == 'd' && x<20) x = x+2 ;
		if (tecla == 'w' && y>3)  y = y-2 ;
		if (tecla == 's' && y<21)  y = y+2 ;
		enemigo :: pintar (x,y);
	}
}

class jugador {
	private:
		
	
	public:  
		void pintarPortaviones (int, int, int);
		void borrarPortaviones (int, int, int);
		void moverPortaviones (int &, int &, int );
		void mover ( pieza &P, int &);
};

void jugador::pintarPortaviones(int x, int y, int c)
{
	if (c == 0){
		movCaracter (x,y);
		cout << "P";
		movCaracter (x,y+2);
		cout << "P";
		movCaracter (x,y+4);
		cout << "P";
		movCaracter (x,y+6);
		cout << "P";
	}
	else {
		movCaracter (x,y);
		cout << "P";
		movCaracter (x+2,y);
		cout << "P";
		movCaracter (x+4,y);
		cout << "P";
		movCaracter (x+6,y);
		cout << "P";
	}
}

void jugador ::borrarPortaviones (int x ,int y , int c) {
		if (c == 0){
		movCaracter (x,y);
		cout << " ";
		movCaracter (x,y+2);
		cout << " ";
		movCaracter (x,y+4);
		cout << " ";
		movCaracter (x,y+6);
		cout << " ";
	}
	else {
		movCaracter (x,y);
		cout << " ";
		movCaracter (x+2,y);
		cout << " ";
		movCaracter (x+4,y);
		cout << " ";
		movCaracter (x+6,y);
		cout << " ";
	}
}

void jugador :: moverPortaviones (int &x, int &y, int c)
{
	if(kbhit())
	{
		jugador::borrarPortaviones(x,y,c);
		char tecla = getch();
		if (tecla == 'a' && x>2)  x = x-2 ;
		
		if(c==0){
			if (tecla == 'd' && x<20) x = x+2 ;
		}
		
		if (c ==1 ){
			if (tecla == 'd' && x<14) x = x+2 ;
		}
		
		if (tecla == 'w' && y>28) y = y-2 ;
		if ( c == 0 ) {
			if (tecla == 's' && y<40) y = y+2 ;
		}
		if (c == 1 ) {
			if (tecla == 's' && y<40) y = y+2 ;
		}
		jugador::pintarPortaviones (x,y,c);
	}
}

void jugador::mover(pieza &P, int &r)
{
	if(kbhit())
	{
		pieza copia = P;
		char tecla = getch();
		if (tecla == 'a' )  P.ori.x -= 2;
		if (tecla == 'd' )  P.ori.x += 2;
		if (tecla == 'w' )  P.ori.y -= 2;
		if (tecla == 's' )  P.ori.y += 2;
		
		if (tecla == 'c')
		{
			jugador::rotar(P);
		}
		
		if (jugador :: colision (P,1)) 
		{
			P = copia;
		}
		
		jugador::borrar(copia);
		jugador::pintar(P,1);
		
		if (tecla == 'x')
		{
			jugador::pintar(P,2);
			r++;
			jugador::seleccionarMapa(P,r,1);
		}
	}
}

int main (){
	
	enemigo a;
	jugador b;

	int q1=2, w1=3;
	int q2=2, w2=28;
	
	a.mostrarMap();
	
	movCaracter(0,25);
	a.mostrarMap();
		
	while(true)
	{
		b.moverPortaviones(q2,w2,0);		
	}	
    
}
