/*#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

#define ALEATORIO(INI, FIN) rand() % (FIN - INI + 1) + INI
#define NFILAS              6
#define NCOLUMNAS           8

void medirLuz(short luzCielo[NFILAS][NCOLUMNAS]) {
	for (short f = 0; f < NFILAS; ++f) {
		for (short c = 0; c < NCOLUMNAS; ++c) {
			luzCielo[f][c] = ALEATORIO(0, 20);
			//cout << setw(2) << setfill('0') << luzCielo[f][c] << " ";
		}
		//cout << endl;
	}
}

void dibujarEstrellas(short luzCielo[NFILAS][NCOLUMNAS]) {
	for (short f = 1; f < NFILAS - 1; ++f) {
		cout << "   ";
		for (short c = 1; c < NCOLUMNAS - 1; ++c) {
			short luz = luzCielo[f][c] +
				luzCielo[f + 1][c] +
				luzCielo[f - 1][c] +
				luzCielo[f][c + 1] +
				luzCielo[f][c - 1];
			if (luz > 50) cout << " * ";
			else          cout << "   ";
		}
		cout << endl;
	}
}

int main() {
	srand(time(0));
	short luzCielo[NFILAS][NCOLUMNAS];
	medirLuz(luzCielo);
	dibujarEstrellas(luzCielo);
	system("pause>0");
	return 0;
}

*/
/****************************************************
*/
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
using namespace System;

#define ALEATORIO(INI, FIN) rand() % (FIN - INI + 1) + INI
#define LADO                20
#define CAMINO              0 
#define BLANCO              0 
#define NEGRO               1 

void colorearFondo(short color) {
	switch (color) {
	case 2:
	case 0: Console::BackgroundColor = ConsoleColor::White; break;
	case 1: Console::BackgroundColor = ConsoleColor::Black; break;
	}
}

void enegrecerTexto() {
	Console::ForegroundColor = ConsoleColor::Black;
}

struct escenario {
	short _mapa[LADO][LADO] = {
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2},
		{2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2},
		{2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2},
		{2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2},
		{2,2,2,2,2,1,0,0,0,0,0,0,0,0,1,2,2,2,2,2},
		{2,2,2,2,2,2,1,0,0,0,0,0,0,1,2,2,2,2,2,2},
		{2,2,2,2,2,2,2,1,0,0,0,0,1,2,2,2,2,2,2,2},
		{2,2,2,2,2,2,2,1,0,0,0,0,1,2,2,2,2,2,2,2},
		{2,2,2,2,2,2,2,1,0,0,0,0,1,2,2,2,2,2,2,2},
		{2,2,2,2,2,2,2,1,0,0,0,0,1,2,2,2,2,2,2,2},
		{2,2,2,2,2,2,1,0,0,0,0,0,0,1,2,2,2,2,2,2},
		{2,2,2,2,2,1,0,0,0,0,0,0,0,0,1,2,2,2,2,2},
		{2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2},
		{2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2},
		{2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2},
		{2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2},
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}
	};
	void validaPosicion(short& x, short& y) {
		do {
			cout << "Ingrese la coordenada (x, y)";
			cin >> x >> y;
		} while (!esCamino(x, y));
	}
	bool esCamino(short x, short y) {
		return _mapa[y][x] == CAMINO;
	}
	void dibujar() {
		for (short f = 0; f < LADO; ++f) {
			for (short c = 0; c < LADO; ++c) {
				colorearFondo(_mapa[f][c]);
				cout << " ";
			}
			cout << endl;
		}
	}
};

struct personaje {
	short _x, _y, _dx;
	personaje(short x, short y) {
		enegrecerTexto();
		_x = x;
		_y = y;
		_dx = 1;
	}
	void animar(escenario& esc) {
		while (true) {
			Console::SetCursorPosition(_x, _y);
			cout << " ";
			if (!esc.esCamino(_x + _dx, _y)) _dx *= -1;
			_x += _dx;
			Console::SetCursorPosition(_x, _y);
			cout << "*";
			_sleep(200);
		}
	}
};

int main() {
	srand(time(0));
	escenario esc;
	esc.dibujar();
	short x, y;
	esc.validaPosicion(x, y);
	personaje pepito = personaje(x, y);
	pepito.animar(esc);
	return 0;
}

/********************************************************/