#include <iostream>
#include <conio.h>
using namespace std;
using namespace System;

#define LADO        15
#define ARRIBA      72
#define IZQUIERDA   75
#define DERECHA     77
#define ABAJO       80
#define PARED        1
#define CAMINO       0
#define LIMITE    3000

struct escenario {
	short _mapa[LADO][LADO] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,1,1,1,1,1,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,0,0,0,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,1,1,1,1,1,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	void dibujar() {
		for (short f = 0; f < LADO; ++f) {
			for (short c = 0; c < LADO; ++c) {
				cout << (_mapa[f][c] == PARED ? char(219) : ' ');
			}
			cout << endl;
		}
	}
	bool esPosicionValida(short x, short y) {
		return ((x > 0 || y > 0 || x < LADO - 1 || y < LADO - 1) && (_mapa[y]   [x] == CAMINO));
	}
};
struct carroPrueba {
	short _x, _y;
	carroPrueba(short x = 1, short y = 1) {
		_x = x;
		_y = y;
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
		case ARRIBA: if (esc.esPosicionValida(_x, _y - 1)) _y--; break;
		case ABAJO: if (esc.esPosicionValida(_x, _y + 1)) _y++; break;
		case IZQUIERDA: if (esc.esPosicionValida(_x - 1, _y)) _x--; break;
		case DERECHA: if (esc.esPosicionValida(_x + 1, _y)) _x++; break;
		}
	}
	void dibujar() {
		Console::SetCursorPosition(_x, _y);
		cout << "*";
	}
};
struct carroNormal {
	short _x, _y, _dy, _retraso;
	bool _yaFuiChocado;
	carroNormal(short x, short y) {
		_x = x;
		_y = y;
		_dy = 1;
		_retraso = 0;
		_yaFuiChocado = false;
	}
	void animar(escenario& esc) {
		if (_retraso == LIMITE) {
			borrar();
			mover(esc);
			dibujar();
			_retraso = 0;
		}
		++_retraso;
	}
	void borrar() {
		Console::SetCursorPosition(_x, _y);
		cout << " ";
	}
	void mover(escenario& esc) {
		if (!esc.esPosicionValida(_x, _y + _dy)) _dy *= -1;
		_y += _dy;
	}
	void dibujar() {
		Console::SetCursorPosition(_x, _y);
		cout << "*";
	}
	bool choca(carroPrueba principiante) {
		if (_yaFuiChocado == false && _x == principiante._x && _y == principiante._y) {
			_yaFuiChocado = true;
			return true;
		}
		else if (_x != principiante._x || _y != principiante._y) {
			_yaFuiChocado = false;
		}
		return false;
	}
};

void ingresarCoordenadas(escenario& esc, short& x, short& y) {
	do {
		cout << "Ingrese coordenadas (x,y): ";
		cin >> x >> y;
	} while (!esc.esPosicionValida(x, y));
	cout << "Coordenadas aceptadas" << endl;
}
void jugar() {
	escenario esc;
	bool continuar = true;
	short x, y, choques = 0;
	ingresarCoordenadas(esc, x, y);
	carroPrueba miCarro = carroPrueba(x, y);
	ingresarCoordenadas(esc, x, y);
	carroNormal carro1 = carroNormal(x, y);
	ingresarCoordenadas(esc, x, y);
	carroNormal carro2 = carroNormal(x, y);
	system("cls");
	esc.dibujar();
	miCarro.dibujar();
	while (continuar) {
		if (kbhit()) {
			char tecla = getch();
			if (tecla == 'S') continuar = false;
			else {
				miCarro.animar(esc, tecla);
			}
		}
		carro1.animar(esc);
		choques += carro1.choca(miCarro);
		carro2.animar(esc);
		choques += carro2.choca(miCarro);
	}
	Console::SetCursorPosition(0, LADO + 1);
	cout << "El numero de choques fue de: " << choques << endl;
	system("pause");
}

int main() {
	Console::CursorVisible = false;
	jugar();
	return 0;
}

