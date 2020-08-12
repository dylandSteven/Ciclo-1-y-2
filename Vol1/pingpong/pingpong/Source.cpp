#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include <ctype.h>
#include<windows.h>
#include<vector>
#include<ctime>//cronometro
#include<cstdlib>//cronometro
#include"Header.h"
#include"Menu.h"
using namespace std;
using namespace System;


int main() {

	CONSOLE_CURSOR_INFO cc = { 100,FALSE };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cc);
	int cont = 0,opJuego;
	Menu M;
	M.pintar_portada(opJuego);
	Jugador a(6, 15); a.pintar();
	Jugador b(74, 15); b.pintar();
	Pelota P(38, 14, 1, 1);
	char tecla;

	while (1) {

		if (kbhit()) {
			a.borrar(); b.borrar();
			tecla = getch();
			if (tecla == 'q'&&a.RY()>5)a.Y(-1); else if (tecla == 'a'&& a.RY()< 21) a.Y(1);
			if (opJuego == '1') {
				if (tecla == 'o' && b.RY() > 5)b.Y(-1);
				else if (tecla == 'l' && b.RY() < 21) b.Y(1);
			}
				a.pintar(); b.pintar();
			
		}
		if (opJuego == '2'&&!cont)b.moverCpu(P.PX(),P.PY(),P.dX());
		if(!cont++)P.mover(a,b);
		if (cont > 5)cont = 0;
		Sleep(10);
	}
	//a.borrar();
	//OcultaCursor();
	return 0;
}
