#include<iostream>
#include<iostream>
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

using namespace std;


void gotoxy(int x, int y){
HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

char ma[22][22] = 	 {{' ',' ','A',' ','B',' ','C',' ','D',' ','E',' ','F',' ','G',' ','H',' ','I',' ','J',' '},
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
					  

struct coord{
	int x, y;
};

struct pieza{
	
	coord ori;
	
	coord peri[3];
	
	char D;
	char d = '*';
	
	coord posicion(int n);
	
};

coord pieza::posicion(int n)
{
	coord ret = {ori.x, ori.y};
	if(n != 0)
	{
		ret.x += peri[n-1].x;
		ret.y += peri[n-1].y;
	}
	return ret;
}

coord peris[5][3] = {{{2,0},{4,0},{6,0}},
					{{2,0},{4,0},{  }},
					{{2,0},{4,0},{  }},
					{{   },{   },{  }},
					{{   },{   },{  }},};
					
char barcos[4] = {'P','S','D','F'};


char ju[22][22];
char en[22][22];
char en2[22][22];


class jugador{
	
	private:
		int turno = 0;
		int turno1;
		int ganju = 0, ganen = 0;
	
	public:
		
		int reganju(){ return ganju;}
		int reganen(){ return ganen;}
		void pasarmapa(); 
		void dibujarmapaju();
		void pintar(pieza &, int);
		void borrar(pieza &);
		void rotar(pieza &);
		coord rotar(coord &);
		void seleccionar(pieza &, int);
		void mover(pieza &, int &);
		bool colision(pieza &,int);
		int obtenerxy();
		void seleccionamapa(pieza &, int, int);
		void disparo(pieza &, int);
		int verificar(pieza &);
		void IAgeneral(pieza &, int &, int);
		void cambioturno(pieza &, int &,int);
		
		
};

void jugador::pasarmapa()
{
	for(int i=0;i<22;i++)
	{
		cout<<endl;
		for(int j=0;j<22;j++)
		{
			ju[i][j] = ma[i][j];
			en[i][j] = ma[i][j];
			en2[i][j] = ma[i][j];
		}
	}
}

void jugador::dibujarmapaju()
{
	for(int i=0;i<22;i++)
	{
		cout<<endl;
		for(int j=0;j<22;j++)
		{
			cout<<ju[i][j];
		}
	}
}


void jugador::pintar(pieza &P, int r)
{	

		for(int i=0; i<4;i++)
		{
		coord c = P.posicion(i);
		if(r == 1)ju[c.y][c.x] = P.d;
		else ju[c.y][c.x] = P.D;
		}	
}

void jugador::borrar(pieza &P)
{	
	for(int i=0; i<4;i++)
	{
		coord c = P.posicion(i);
		ju[c.y][c.x] = ' ';
	}	
}

coord jugador::rotar(coord &c)
{
	coord ret = {c.y, c.x};
	return ret;
}

void jugador::rotar(pieza &P)
{
	for(int i=0;i<3;i++)
	{
		P.peri[i] = jugador::rotar(P.peri[i]);
	}
}

void jugador::seleccionar(pieza &P, int r)
{
	P.ori.x = jugador::obtenerxy();
	P.ori.y = jugador::obtenerxy();
	P.D = barcos[r];
	for(int i = 0; i<3; i++)
	{
		P.peri[i] = peris[r][i];
	}
}

void jugador::mover(pieza &P, int &r)
{
	if(kbhit())
	{
		pieza copia = P;
		char tecla = getch();
		if(tecla == 'a') P.ori.x -=2;
		if(tecla == 'd') P.ori.x +=2;
		if(tecla == 'w') P.ori.y -=2;
		if(tecla == 's') P.ori.y +=2;
		
		if(tecla == 'c')
		{
			jugador::rotar(P);
		}
		
		if(jugador::colision(P,1))
		{
			P = copia;
		}
		
		jugador::borrar(copia);
		jugador::pintar(P,1);
		
		if(tecla == 'x')
		{
			jugador::pintar(P,2);
			r++;
			jugador::seleccionamapa(P,r,1);
		}
	}
}

bool jugador::colision(pieza &P, int q)
{
	for(int i=0; i<4;i++)
	{
		coord c = P.posicion(i);
		
		if(c.x < 2 || c.x > 20) return true;
		
		if(c.y < 2 || c.y > 20) return true;
		
		if(q == 1)
		{
			if(ju[c.y][c.x] == 'P' || ju[c.y][c.x] == 'S' || ju[c.y][c.x] == 'D' || ju[c.y][c.x] == 'F') return true;	
		}
		if(q == 2)
		{
			if(ju[c.y][c.x] == 'X' || ju[c.y][c.x] == 'O' ) return true;
		}
		
			
	}
	
	return false;
}

int jugador::obtenerxy()
{
	while(true)
	{
		int x = rand()%19 + 2;
		if(x%2 == 0) return x;
	}
	
}

void jugador::seleccionamapa(pieza &P, int r, int q)
{
	while(true)
	{
		jugador::seleccionar(P,r);
		if(!jugador::colision(P,q)) break;
	}
}

void jugador::disparo(pieza &P, int q)
{
	for(int i = 0; i<4;i++)
	{
		coord c = P.posicion(i);
		
		if(q == 1)
		{
			if(en2[c.y][c.x] == 'P' || en2[c.y][c.x] == 'S' || en2[c.y][c.x] == 'D' || en2[c.y][c.x] == 'F') 
			{
				en[c.y][c.x] = 'O';
				ganju ++;	
			}
			if(en2[c.y][c.x] == ' ') en[c.y][c.x] = 'X';
		}
		if(q == 2)
		{
			if(ju[c.y][c.x] == 'P' || ju[c.y][c.x] == 'S' || ju[c.y][c.x] == 'D' || ju[c.y][c.x] == 'F') 
			{
				if(ju[c.y][c.x] == 'P') P.D = 'P';
				if(ju[c.y][c.x] == 'S') P.D = 'S';
				if(ju[c.y][c.x] == 'D') P.D = 'D';
				ju[c.y][c.x] = 'O';
				turno1 = 1;
				ganen ++;
			}
			if(ju[c.y][c.x] == ' ') ju[c.y][c.x] = 'X';
		}
	}
}

int jugador::verificar(pieza &P)
{
	for(int i=2;i<21;i++)
	{
		for(int j=2;j<21;j++)
		{
			if(ju[i][j] == P.D)
			{
				P.ori.x = j;
				P.ori.y = i;
				return 1;
			}
		}
	}
	return 2;
}

void jugador::cambioturno(pieza &P, int &t, int r)
{
	jugador::seleccionamapa(P,r,2);
	jugador::disparo(P,2);
	t = 1;
}

void jugador::IAgeneral(pieza &P, int &t, int r)
{
	if(turno1 == 0) turno = 0;
	if(turno1 == 1) turno = 1;
	
	if(turno = 0)
	{
		jugador::cambioturno(P,t,r);
	}
	
	if(turno = 1)
	{
		if(jugador::verificar(P) == 1)
		{
			jugador::disparo(P,2);
			t = 1;
		}
		
		if(jugador::verificar(P) == 2)
		{
			jugador::cambioturno(P,t,r);
			turno1 = 0;
		}
		
	}
}

class enemigo : public jugador
{
	public:
		
		void dibujarmapaen();
		void pintar(pieza &, int);
		void borrar(pieza &);
		void mover(pieza &, int &, int &);
		bool colisionen(pieza & , int);
		void seleccionamapa(pieza &, int);
		void inicializarbarcos(pieza &);
		int obtenerrot();
		
};

void enemigo::dibujarmapaen()
{
	for(int i=0;i<22;i++)
	{
		cout<<endl;
		for(int j=0;j<22;j++)
		{
			cout<<en[i][j];
		}
	}
}

void enemigo::pintar(pieza &P,int r)
{
	for(int i=0; i<4;i++)
	{
		coord c = P.posicion(i);
		if(r == 1)en[c.y][c.x] = P.d;
		else en2[c.y][c.x] = P.D;
	}
}

void enemigo::borrar(pieza &P)
{
	for(int i=0; i<4;i++)
	{
		coord c = P.posicion(i);
		en[c.y][c.x] = ' ';
	}
}

void enemigo::mover(pieza &P, int &r, int &t)
{
	if(kbhit())
	{
		pieza copia = P;
		char tecla = getch();
		if(tecla == 'a') P.ori.x -=2;
		if(tecla == 'd') P.ori.x +=2;
		if(tecla == 'w') P.ori.y -=2;
		if(tecla == 's') P.ori.y +=2;
		
		if(enemigo::colisionen(P,2))
		{
			P=copia;
		}
		
		enemigo::borrar(copia);
		enemigo::pintar(P,1);
		
		if(tecla == 'z')
		{
			enemigo::disparo(P,1);
			enemigo::seleccionamapa(P,r);
			t = 2;
			copia = P;
		}
	}
}

bool enemigo::colisionen(pieza &P, int q)
{
	for(int i=0; i<4;i++)
	{
		coord c = P.posicion(i);
		
		if(c.x < 2 || c.x > 20) return true;
		
		if(c.y < 2 || c.y > 20) return true;
		
		if(q == 1)
		{
			if(en2[c.y][c.x] == 'P' || en2[c.y][c.x] == 'S' || en2[c.y][c.x] == 'D' || en2[c.y][c.x] == 'F') return true;
		}
		if(q == 2)
		{
			if(en[c.y][c.x] == 'X' || en[c.y][c.x] == 'O') return true;
		}
			
	}
	
	return false;
}

void enemigo::seleccionamapa(pieza &P, int r)
{
	while(true)
	{
		enemigo::seleccionar(P,r);
		if(!enemigo::colisionen(P,2)) break;
	}
}

void enemigo::inicializarbarcos(pieza &P)
{
	for(int i = 0; i<5;i++)
	{
		while(true)
		{
			enemigo::seleccionar(P,i);
			if(enemigo::obtenerrot() == 0 ) enemigo::rotar(P);
			if(!enemigo::colisionen(P,1))
			{
				enemigo::pintar(P,2);
				break;	
			} 
		}
	}
}

int enemigo::obtenerrot()
{
	int x = rand()%2;
	return x;
}


int main()
{
	
	system("cls");
	//rand()
	srand(time(NULL));
	
	jugador a;
	enemigo b;
	
	pieza S, S1;
	int r = 0;
	int t=0;
	
	int contador = 0;
	
	a.pasarmapa();
	a.seleccionar(S,r);
	
	b.inicializarbarcos(S1);
	
	bool gameover = true;
	
	while(gameover)
	{
		if(contador == 20)
		{
			t = 2;
			contador = 0;
		}
		gotoxy(0,25); a.dibujarmapaju();
		gotoxy(0,0); b.dibujarmapaen();
		
		if(t == 0)
		{
			a.mover(S,r);
			if(r == 4) t=1;
		}
		if(t == 1)
		{
			b.mover(S1,r,t);
			contador = 0;
		}
		if(t == 2)
		{
			a.IAgeneral(S,t,r);
		}
		if(a.reganen() == 11)
		{
			gameover = false;
			system("cls");
			cout<<"has perdido"<<endl;
			Sleep(1000);
		}
		if(a.reganju() == 11)
		{
			gameover = false;
			system("cls");
			cout<<"has ganado"<<endl;
			Sleep(1000);	
		}
		
		Sleep(30);
		if( t != 0)contador++;
	}
	
	int g;	
	system("cls");
	cout<< "deseas seguir jugado Si = 1   No = 2" <<endl;
	cin>>g;
	switch(g)
	{
		case 1: main();
		break;
		case 2: return 0;
		break;
	}
	
}
