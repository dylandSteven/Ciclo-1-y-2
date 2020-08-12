#pragma once
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include <ctype.h>
#include<windows.h>
#include<vector>
#include<ctime>//cronometro
#include<cstdlib>//
using namespace std;
void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}



class Jugador {

	int x, y;
public:
	Jugador(int _x, int _y);
	void pintar();
	void borrar();
	void moverCpu(int _x, int _y, int _dx);
	void X(int _x) { x += _x; }
	void Y(int _y) { y += _y; }
	int RY() { return y; }
	int RX() { return x; }
};


Jugador::Jugador(int _x, int _y) :x(_x), y(_y) {}

void Jugador::pintar() {
	gotoxy(x, y - 1); printf("%c", 219);
	gotoxy(x, y); printf("%c", 219);
	gotoxy(x, y + 1); printf("%c", 219);

}

void Jugador::borrar() {
	gotoxy(x, y - 1); printf("  ");
	gotoxy(x, y); printf("  ");
	gotoxy(x, y + 1); printf("  ");

}

void Jugador::moverCpu(int _x, int _y, int _dx) {

	if (_x > 65 && _dx > 0) {

		borrar();
		if (_y > y&&y+1<22)y++;
		if (_y < y&&y-1>4)y--;
		pintar();
	}

}




class Pelota {

	int x, y;
	int dx; int dy;

public:
	Pelota(int _x, int _y, int _dx, int _dy);

	void pintar();
	void borrar();
	void mover(Jugador A, Jugador B);
	void asign(int _x, int _y) { x = _x; y = _y; }
	int PX() { return x; }
	int PY() { return y; }
	int dX() { return dx; }
};

Pelota::Pelota(int _x, int _y, int _dx, int _dy) :x(_x), y(_y), dx(_dx), dy(_dy) {}
void Pelota::pintar() {
	gotoxy(x, y); printf("%c", 184);
}
void Pelota::borrar() {
	gotoxy(x, y); printf(" ");
}
void Pelota::mover(Jugador A, Jugador B) {
	borrar();
	x += dx;
	y += dy;
	pintar();

	if (x + dx == 3 || x + dx == 76) {

		borrar();
		asign(38, 14);
		dx = -dx;
	}
	if (y + dy == 3 || y + dy == 23) {

		//borrar();
		dy = -dy;
	}

	if (x + dx == A.RX() && y >= A.RY() - 2 && y <= A.RY() + 2) { dx = -dx; }

	if (x + dx == B.RX() && y >= B.RY() - 2 && y <= B.RY() + 2) { dx = -dx; }

} 