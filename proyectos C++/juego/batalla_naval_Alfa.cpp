#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void movCaracter(int x, int y){
HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
 COORD dwPos;
 dwPos.X = x;
 dwPos.Y = y;
 SetConsoleCursorPosition(hcon, dwPos);
}

char map[22][22] =   
	   {{' ',' ','A',' ','B',' ','C',' ','D',' ','E',' ','F',' ','G',' ','H',' ','I',' ','J',' '},
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
  	int x, y;
  };
  
  struct pieza {
  	coordenadas ori; 
  	coordenadas per [3];
	  
	char D; 
	char d = '*';
	
	coordenadas posicion (int n );
	
  };
  
  coordenadas pieza :: posicion (int n) 
  {
  	coordenadas ret = {ori.x, ori.y};
  	if (n !=0)
  	{
  		ret.x += per [n-1].x;
  		ret.y += per [n-1].y;

	}
	return ret;
  }
  
 

coordenadas perifericos [5] [3] = {  {{2,0},{4,0},{6,0}}, 
                                     {{2,0},{4,0},{   }},
								     {{2,0},{4,0},{   }},
								     {{   },{   },{   }},
									 {{   },{   },{   }}, };
								     
								     
char barcos [4] = {'P', 'S', 'D', 'F'};

char juego [22][22];

char end [22][22];

char end2 [22][22];


class jugador {
	private:
		int turno = 0;
		int turno1;
		int ganojuego = 0, ganoenemigo = 0;
	
	public:  
	
		int reganjuego(){return ganojuego;}
		int reganenem (){return ganoenemigo;}
		void pasarMapa();
		void dibujarmapajuego();
		void pintar (pieza &, int);
		void borrar (pieza &);
		void rotar (pieza &);
		coordenadas rotar (coordenadas &);
		void seleccionar (pieza &, int);
		void mover(pieza &, int &);
		bool colision (pieza &, int);
		int obtenerxy ();
		void seleccionarMapa (pieza &, int, int);
		void disparo (pieza &, int);
		int verificar ( pieza& );
		void IAGeneral (pieza &, int &, int);
		void cambioTurno (pieza &, int &, int);
		
};

void jugador::pasarMapa()
{
	for(int i = 0; i < 22; i++)
	{
		cout << endl;
		for(int j = 0; j < 22; j++)
		{
			juego[i][j] = map[i][j];
			end [i][j] = map [i][j];
			end2 [i][j] = map [i][j];
		}
	}
}

void jugador :: dibujarmapajuego ()
{
	for(int i = 0; i < 22; i++){
		cout << endl;
		for(int j = 0; j < 22; j++){
			cout << juego[i][j];
		}
	}
}

void jugador::pintar(pieza &P, int r) 
{
	for (int i = 0 ; i <4 ; i++)
	{
		coordenadas c = P.posicion(i);
		if (r == 1) juego[c.y][c.x] = P.d;
		else juego[c.y][c.x] = P.D;
	}
}

void jugador::borrar (pieza &P){
	
	for (int i =0; i <4; i++)
	{
		coordenadas c = P.posicion(i);
		juego[c.y] [c.x] = ' ';
	}

}

coordenadas jugador :: rotar (coordenadas &c)
{
	coordenadas ret = {c.y, c.x};
	return ret;
}

void jugador::rotar (pieza &P)
{
	for ( int i = 0; i<3; i++)
	{
		P.per[i]= jugador::rotar(P.per[i]);
	}
}

void jugador::seleccionar(pieza &P, int r)
{
	P.ori.x = jugador::obtenerxy();
	P.ori.y = jugador::obtenerxy();
	P.D = barcos[r];
	for (int i = 0; i < 3; i++ )
	{
		P.per[i] = perifericos[r][i];
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
		
		if (tecla == 'q')
		{
			jugador::pintar(P,2);
			r++;
			jugador::seleccionarMapa(P,r,1);
		}
	}
}

bool jugador::colision (pieza &P, int q)
{
	for (int i =0; i <4; i++)
	{
		coordenadas c = P.posicion(i);
		
		if (c.x < 2 || c.x >20) return true;
		
		if (c.y <2 || c.y > 20) return true;
		
		if (q == 1)
		{
			if (juego[c.y][c.x] == 'P' || juego[c.y][c.x] == 'S' || juego[c.y][c.x] == 'D' || juego[c.y][c.x] == 'F') return true;
		}
		else 
		{
			if (juego[c.y][c.x] == 'X' || juego[c.y][c.x] == 'O' ) return true;
		}
	}
	return false;
}

int jugador::obtenerxy()
{
	while (true)
	{
		int x = rand()%19 + 2;
		if (x%2 == 0 ) return x;
	}	
}

void jugador :: seleccionarMapa (pieza &P, int r, int q)
{
	while (true)
	{
		jugador::seleccionarMapa(P,r,q);
		if (!jugador::colision(P,q)) break;
	}
}

void jugador ::disparo(pieza &P, int q)
{
	for (int i = 0; i < 4; i ++)
	{
		coordenadas c = P.posicion(i);
		
		if (q == 1)
		{
			if (end2 [c.y][c.x] == 'P' || end2 [c.y][c.x] == 'S' || end2 [c.y][c.x] == 'D' || end2 [c.y][c.x] == 'F')
			{
				 end [c.y][c.x] = 'O';
				 ganojuego ++;
			}
			if (end2 [c.y][c.x] == ' ') end [c.y][c.x] == 'X';
		}
		if (q ==2)
		{
			if (juego [c.y][c.x] == 'P' || juego [c.y][c.x] == 'S' || juego [c.y][c.x] == 'D' || juego [c.y][c.x] == 'F')
			{
				if (juego [c.y][c.x] == 'P') P.D == 'P';
				if (juego [c.y][c.x] == 'S') P.D == 'S';
				if (juego [c.y][c.x] == 'D') P.D == 'D';
				if (juego [c.y][c.x] == 'F') P.D == 'F';
				juego [c.y][c.x] = 'O';
				turno1 = 1;
				ganoenemigo ++;
			}  
			if (juego [c.y][c.x] == ' ') juego [c.y][c.x] == 'X';
		}
			
	}	
};

int jugador::verificar(pieza &P)
{
	for(int i = 2; i < 21; i++)
	{
		for(int j = 2; j < 21; j++)
		{
			if (juego [i][j] == P.D) 
			{
				P.ori.x = j;
				P.ori.y = i;
				return 1;
			}
		}
	}
	return 2;
}

void jugador::cambioTurno(pieza &P, int &t, int r)
{
	jugador::seleccionarMapa(P,r,2);
	jugador::disparo (P,2);
	t = 1;
}

void jugador::IAGeneral(pieza &P ,int &t, int r)
{
	if (turno1 == 0) turno = 0;
	if (turno1 == 1) turno = 1;
	
	if (turno == 0) 
	{
		jugador::cambioTurno(P,t,r);
	}
	
	if (turno = 1)
	{
		if (jugador::verificar(P) == 1)
		{
			jugador::disparo(P,2);
			t = 1;
		}
		if (jugador::verificar(P) == 2)
		{
			jugador::cambioTurno(P,t,r);
			turno1 = 0;  
		}
	}

	
}

class enemigo : public jugador
{
	public :
		
		void dibujarmapaend();
		void pintar (pieza &, int);
		void borrar (pieza &);
		void mover(pieza &, int &, int &);
		bool colision (pieza &, int);
		void seleccionarMapa (pieza &, int);
		void inicializarBarcos (pieza &);
		int obtenerrot ();
		
};

void enemigo :: dibujarmapaend ()
{
	for(int i = 0; i < 22; i++)
	{
		cout << endl;
		for(int j = 0; j < 22; j++)
		{
			cout << end[i][j];
		}
	}
}

void enemigo::pintar(pieza &P, int r)
{
	for (int i = 0; i < 4 ; i ++)
	{
		coordenadas c = P.posicion(i);
		if (r == 1) end[c.y][c.x]= P.d;
		else end2[c.y][c.x]= P.D;
	}
}

void enemigo::borrar(pieza &P) 
{
	for (int i =0; i <4; i++)
	{
		coordenadas c = P.posicion(i);
		end[c.y][c.x] = ' ';
	}
}

void enemigo :: mover(pieza &P, int &r, int &t) 
{
	if(kbhit())
	{
		pieza copia = P;
		char tecla = getch();
		if (tecla == 'a' )  P.ori.x -= 2;
		if (tecla == 'd' )  P.ori.x += 2;
		if (tecla == 'w' )  P.ori.y -= 2;
		if (tecla == 's' )  P.ori.y += 2;
		
		if (enemigo::colision(P,2))
		{
			P = copia;
		}
		enemigo::borrar(copia);
		enemigo::pintar(P,1);
		
		if ( tecla == 'z')
		{
			enemigo::disparo(P,1);
			enemigo::seleccionarMapa(P,r);
			t = 2;
			copia = P;
		}
	}
}

bool enemigo :: colision (pieza &P, int q)
{
	for (int i =0; i <4; i++)
	{
		coordenadas c = P.posicion(i);
		
		if (c.x < 2 || c.x >20) return true;
		
		if (c.y <2 || c.y > 20) return true;
		
		if ( q == 1 )
		{
			if (end2[c.y][c.x] == 'P' || end2[c.y][c.x] == 'S' || end2[c.y][c.x] == 'D' || end2[c.y][c.x] == 'F') return true; 
		}
		if ( q == 2)
		{
			if (end[c.y][c.x] == 'X' || end[c.y][c.x] == 'O' ) return true; 
		}
		
	}
	return false;
}

void enemigo :: seleccionarMapa (pieza &P, int r)
{
	while (true)
	{
		enemigo::seleccionarMapa(P,r);
		if (!enemigo::colision(P,2)) break;
	}
}

int enemigo::obtenerrot()
{
	int x = rand()%2;
	return  x;
}

void enemigo::inicializarBarcos(pieza &P) 
{
	for (int i = 0; i < 5 ; i++)
	{
		while (true)
		{
			enemigo::seleccionar(P,i);
			if (enemigo::obtenerrot() == 0 ) enemigo::rotar(P);
			if (!enemigo::colision(P,1)) 
			{
				enemigo::pintar(P,2);
				break;
			} 
		}
	}
}

int main (){
	
	system("cls");
	
	srand (time(NULL));
	
	jugador a;
	enemigo b;
	
	pieza S, S1;
	int r = 0;
	int t = 0;
	
	int contador = 0;
	
	a.pasarMapa();
	a.seleccionar(S,r);
	
	b.inicializarBarcos(S1);
	
	bool gameover = true;
	
	
	while(gameover)
	{
		if (contador == 20)
		{
			t = 2;
			contador = 0;
		}
		movCaracter(0,25);
		a.dibujarmapajuego();
		
		movCaracter(0,0);
		b.dibujarmapaend();


		if(t == 0)
		{
			a.mover(S,r);
			if (r == 4 ) t = 1;

		}
		if (t == 1) 
		{
			b.mover(S1,r,t);
			contador = 0;
		}
		if (t == 2)
		{
			a.IAGeneral(S,t,r);
		}
		if (a.reganenem() == 11 )
		{
			gameover = false;
			system ("cls");
			cout << 'has perdido'  << endl;
			Sleep (1000);
		}
		if (a.reganjuego() ==11)
		{
			gameover = false;
			system ("cls");
			cout <<  'ganado' << endl;
			Sleep (1000);

		}
		
	    Sleep(30);
		 if (t!=0)contador ++;
	}
	
		int g ;
		system("cls");
		cout <<   'deseas seguir jugando Si = 1       No = 2'  << endl;
	    cin >> g;
	    switch(g)
	    {
	    	case 1 : main ();
	    	break;
	    	case 2: return 0;
	    	break;
		}
	    
}
