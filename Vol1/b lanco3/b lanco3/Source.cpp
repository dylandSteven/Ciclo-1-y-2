#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
using namespace System;

struct mapa {

	int escenario[19][19] = {
		{1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1},
		{1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1},
		{1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1},
		{1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1},
		{1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1},
		{1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1},
		{1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1},
		{1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1},
		{1,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1}
	};


	void dibujar() {

		for (int i=0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {

		        if (escenario[i][j] == 0) {
					Console::ForegroundColor = ConsoleColor::White;
					cout << char(219);
				}else  {
					Console::ForegroundColor = ConsoleColor::Black;
					cout << char(219);
				}
			}
			cout << endl;
		}
	}


	bool validar(short x, short y,short obj[2][3]) {
		for (int f = 0; f < 2; f++) {
			for (int j = 0; j < 3; j++) {
				if (obj[f][j] != 0 && escenario[y + f][x + j] == 1)
					return false;
			}
		}
		return true;
	}
};


struct personaje {

	int x, y;

	personaje(int _x, int _y) {

		x = _x;
	    y = _y;
	}
	

		short perso[2][3] = {
			{1,1,1},
			{0,1,0}
		};

		void pintar() {
			Console::SetCursorPosition(x, y);
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 3; j++) {
				Console::SetCursorPosition(x+j, y +i);
					if (perso[i][j] == 1) {
						Console::ForegroundColor = ConsoleColor::Green;
						cout << char(219);
					}
					else {
						cout << " ";
					}

				}
			}
		}

		void borrar() {
			Console::SetCursorPosition(x, y);
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 3; j++) {
				Console::SetCursorPosition(x+j, y +i);
					if (perso[i][j] == 1) {
						Console::BackgroundColor = ConsoleColor::White;
						cout << " ";
					}

				}
			}

		}
		
		void mover(char opcion, mapa esc){

			switch (toupper(opcion))
			{
			case 'W':if(y-1>=0 &&esc.validar(x,y-1,perso))y-- ;break;
			case'A':if (esc.validar(x-1,y,perso))  x-- ;break;
			case 'S':if (esc.validar(x , y+1,perso))   y++; break;
			case 'D':if (esc.validar(x+1,y, perso))x++;break;

			}


	
	}
};




int main(void) {
	Console::CursorVisible = false;
	mapa esc;
	personaje p(10,10);
	esc.dibujar();

	while (true) {

		if (kbhit()) {
			char direccion = getch();
			p.borrar();
			p.mover(direccion,esc);
			p.pintar();

		}
	}
	getch();

}