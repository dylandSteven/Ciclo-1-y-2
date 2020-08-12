#include<iostream>
#include<conio.h>
using namespace std;
using namespace System;

#define ORIGENX   10
#define ORIGENY    8
#define ANCHO     23
#define ALTO      20
#define GRIS       1
#define BLANCO     0
#define ARRIBA    72
#define IZQUIERDA 75
#define DERECHA   77
#define ABAJO     80


void colorearFondo(short color) {
	switch (color)
	{
	case BLANCO: Console::BackgroundColor = ConsoleColor::White; break;
	case GRIS: Console::BackgroundColor = ConsoleColor::Gray; break;
	}
}

struct escenario {
	short _mapa[ALTO][ANCHO] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};
	escenario() {
		dibujar();
	}
	void dibujar() {
		for (short fila = 0; fila < ALTO; ++fila) {
			for (short columna = 0; columna < ANCHO; ++columna) {
				colorearFondo(_mapa[fila][columna]);
				cout << " ";
			}
			cout << endl;
		}
		colorearFondo(GRIS);
	}
	bool esCamino(short x, short y) {
		return _mapa[y][x] == GRIS;
	}
};
struct personaje {
	short _x, _y;
	personaje() {
		_x = ORIGENX;
		_y = ORIGENY;
		dibujar();
	}
	void animar(escenario& esc, short direccion) {
		borrar();
		mover(esc, direccion);
		dibujar();
	}
	void borrar() {
		Console::SetCursorPosition(_x, _y);
		cout << " ";
	}
	void mover(escenario& esc, short direccion) {
		switch (direccion) {
		case ARRIBA: _y--; break;
		case ABAJO: _y++; break;
		case IZQUIERDA: _x--; break;
		case DERECHA: _x++; break;
		}
		if (!esc.esCamino(_x, _y)) {
			_x = ORIGENX;
			_y = ORIGENY;
		}
	}
	void dibujar() {
		Console::SetCursorPosition(_x, _y);
		Console::ForegroundColor = ConsoleColor::Red;
		cout << "*";
	}
};

void jugar() {
	escenario esc;
	personaje p;
	while (true) {
		if (kbhit()) {
			p.animar(esc, getch());
		}
	}
}

int main() {
	jugar();
	return 0;
}