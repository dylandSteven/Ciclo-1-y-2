#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include <ctype.h>
#include<windows.h>
#include<vector>
#include<ctime>//cronometro
#include<cstdlib>//cronometro

using namespace std;
using namespace System;
#define ARRIBA    72
#define IZQUIERDA 75
#define ABAJO     80
#define DERECHA   77
#define filas      2
#define columnas   5
#define DISPARAR 32

#define ALEATORIO(INI, FIN) rand() % (FIN - INI + 1) + INI

enum Color { NEGRO, BLANCO, AZUL, ROJO, VERDE, AMARILLO };

void cambiarColorFondo(Color miColor) {
	switch (miColor)
	{
	case NEGRO:  Console::BackgroundColor = ConsoleColor::Black; break;
	case BLANCO:  Console::BackgroundColor = ConsoleColor::White; break;
	case AZUL:  Console::BackgroundColor = ConsoleColor::Blue; break;
	case ROJO:  Console::BackgroundColor = ConsoleColor::Red; break;
	case VERDE:  Console::BackgroundColor = ConsoleColor::Green; break;
	case AMARILLO:  Console::BackgroundColor = ConsoleColor::Yellow; break;
	}
}
void cambiarColorCaracter(Color miColor) {
	switch (miColor)
	{
	case NEGRO:  Console::ForegroundColor = ConsoleColor::Black; break;
	case BLANCO:  Console::ForegroundColor = ConsoleColor::White; break;
	case AZUL:  Console::ForegroundColor = ConsoleColor::Blue; break;
	case ROJO:  Console::ForegroundColor = ConsoleColor::Red; break;
	case VERDE:  Console::ForegroundColor = ConsoleColor::Green; break;
	case AMARILLO:  Console::ForegroundColor = ConsoleColor::Yellow; break;
	}
}
void gotoxy(int x, int y) {
	Console::SetCursorPosition(x, y);
}

struct Personaje
{
	short x, y, pasos, vidas = 4;
	char matriz[filas][columnas] = { { ' ','|','*','|',' ' },
	{ 'o','{','+','}','o' } };
	int X() { return x; }
	int Y() { return y; }
	Personaje(short _x = 50, short _y = 25, short _vidas = 3) {
		x = _x;
		y = _y;
		vidas = _vidas;
	}
	void pintar() {
		cambiarColorCaracter(VERDE);
		for (int i = 0; i < filas; i++) {
			for (int j = 0; j < columnas; j++) {
				gotoxy(x + j, y + i);
				cout << matriz[i][j];
			}
		}
	}
	void borrar() {
		for (int i = 0; i < filas; i++) {
			for (int j = 0; j < columnas; j++) {
				gotoxy(x + j, y + i);
				cout << " ";
			}
		}

	}
	void mover(char direccion) {
		switch (toupper(direccion)) {
		case IZQUIERDA: if (x > 0) x--; break;
		case DERECHA: if (x + 5 < 110)x++; break;
		}
	}
};
struct Enemigo
{
	short x, y, pasos;
	short dx, dy, retraso;
	char enemy[2][5] = { { '!','(',' ',')','!' },
	{ ' ',' ','s',' ',' ' } };
	Enemigo(short _x = 10, short _y = 10) {
		x = _x;
		y = _y;
		dx = 1;
		dy = 1;
		retraso = 0;
	}
	int X() { return x; }
	int Y() { return y; }
	void animar() {
		if (retraso == 100) {
			borrar();
			mover();
			pintar();
			retraso = 0;
		}
		retraso++;
	}
	void pintar() {
		cambiarColorCaracter(AZUL);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 5; j++) {
				gotoxy(x + j, y + i);
				cout << enemy[i][j];
			}
		}
	}
	void borrar() {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 5; j++) {
				gotoxy(x + j, y + i);
				cout << "  ";
			}
		}
	}
	void mover() {
		if (x == 2 || x + 2 == 100) dx *= -1;
		if (y == 2 || y + 4 == 20) dy *= -1;
		x += dx;
		y += dy;
	}


};
struct bala {
	int x, y, dy; int daño = 1;
	bala(int _x, int _y, int _dy) {
		x = _x;
		y = _y;
		dy = _dy;
	}
	int X() { return x; }
	int Y() { return y; }

	~bala() {
		Console::SetCursorPosition(x, y);
		cout << " ";
	}
	int lento = 0;
	void animar() {
		if (lento == 80) {
			mover();
			fuera();
			lento = 0;
		}
		lento++;
	}
	void mover() {
		gotoxy(x, y); printf("  ");
		y += dy;;
		gotoxy(x, y); printf("|");
	}
	bool bala::fuera() {
		if (y == 4) return true;
		return false;
	}

	/*	void colision(Enemigo *E) {
	for (int i = 0; i < 6; i++) {
	if (x >= E[i].X() && x < E[i].X() + 6 && y >= E[i].Y() && y <= E[i].Y() + 2) {
	E[i].borrar();
	}
	}
	}*/
};
struct EnemigoMedio
{
	short x, y, pasos;
	short dx, dy, retraso;
	char medio[2][5] = { { 'Z','*','.','*','Z' },
	{ ' ','I','!','I',' ' } };

	EnemigoMedio(short _x = 2, short _y = 2) {
		x = rand() % 18 + 31;
		y = rand() % 6 + 9;
		dx = 1;
		dy = 1;
		retraso = 0;
	}

	void animar() {
		if (retraso == 150) {
			borrar();
			mover();
			pintar();
			retraso = 0;
		}
		retraso++;
	}
	void pintar() {
		cambiarColorCaracter(ROJO);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 5; j++) {
				gotoxy(x + j, y + i);
				cout << medio[i][j];
			}
		}
	}
	void borrar() {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 5; j++) {
				gotoxy(x + j, y + i);
				cout << "  ";
			}
		}
	}

	void mover() {
		if (x == 30 || x + 4 == 70) dx *= -1;
		x += dx;
		if (y < 9 || y + 3 > 15) dy *= -1;
		y += dy;
	}
};
struct Jefe
{
	short x, y, pasos;
	short dx, dy, retraso, vidas = 2;
	char enemy[4][7] = { { 'I','|','I','|','I','|','I' },
	{ ' ','X','.','X','.','X',' ' },
	{ ' ',' ','<','*','>',' ',' ' },
	{ ' ',' ',' ','W',' ',' ',' ' } };
	Jefe(short _x = 2, short _y = 2) {
		x = _x;
		y = _y;
		dx = 1;
		dy = 0;
		retraso = 0;
	}
	void animar() {
		if (retraso == 150) {
			borrar();
			mover();
			pintar();
			retraso = 0;
		}
		retraso++;
	}
	void pintar() {
		if (vidas == 2) {
			cambiarColorCaracter(AMARILLO);

		}
		else
		{
			Console::ForegroundColor = ConsoleColor::DarkMagenta;
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 7; j++) {
				gotoxy(x + j, y + i);
				cout << enemy[i][j];
			}
		}
	}
	void borrar() {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 7; j++) {
				gotoxy(x + j, y + i);
				cout << "  ";
			}
		}
	}

	void mover() {
		if (rand() % 100 == 0) {
			dx = 0; dy = 1;
		}
		if (x + dx == 0 || x + 7 + dx == 80) {
			dx *= -1;
		}
		x += dx;

		if (y + dy <= 2 || y + 3 + dy >= 25) {
			if (dy == 1)
				dy *= -1;
			else
			{
				dx = dy;
				dy = 0;
			}
		}
		y += dy;
	}
};

bool colision(Personaje pj, bala* B) {
	if (pj.x <= B->x && B->x < pj.x + 5 && pj.y <= B->y && B->y < pj.y + 1) return true;
	else return false;
}
bool colision(Enemigo* pj, bala* B) {
	if (pj->x <= B->x && B->x < pj->x + 5 && pj->y <= B->y && B->y < pj->y + 1) return true;
	else return false;
}
bool colision(Personaje pj, Enemigo* B) {
	if ((pj.x <= B->x && B->x < pj.x + 5 && pj.y <= B->y && B->y < pj.y + 1) ||
		(pj.x <= B->x + 5 && B->x + 5 < pj.x + 5 && pj.y <= B->y && B->y < pj.y + 1) ||
		(pj.x <= B->x && B->x < pj.x + 5 && pj.y <= B->y + 1 && B->y + 1 < pj.y + 1) ||
		(pj.x <= B->x + 5 && B->x + 5 < pj.x + 5 && pj.y <= B->y + 1 && B->y + 1 < pj.y + 1)
		) return true;
	else return false;
}

bool colision(EnemigoMedio* pj, bala* B) {
	if (pj->x <= B->x && B->x < pj->x + 5 && pj->y <= B->y && B->y < pj->y + 1) return true;
	else return false;
}
bool colision(Personaje pj, EnemigoMedio* B) {
	if ((pj.x <= B->x && B->x < pj.x + 5 && pj.y <= B->y && B->y < pj.y + 1) ||
		(pj.x <= B->x + 5 && B->x + 5 < pj.x + 5 && pj.y <= B->y && B->y < pj.y + 1) ||
		(pj.x <= B->x && B->x < pj.x + 5 && pj.y <= B->y + 1 && B->y + 1 < pj.y + 1) ||
		(pj.x <= B->x + 5 && B->x + 5 < pj.x + 5 && pj.y <= B->y + 1 && B->y + 1 < pj.y + 1)
		) return true;
	else return false;
}
bool colision(Jefe* pj, bala* B) {
	if (pj->x <= B->x && B->x < pj->x + 7 && pj->y <= B->y && B->y < pj->y + 3) return true;
	else return false;
}
bool colision(Personaje pj, Jefe* B) {
	if ((pj.x <= B->x && B->x < pj.x + 7 && pj.y <= B->y && B->y < pj.y + 3) ||
		(pj.x <= B->x + 7 && B->x + 7 < pj.x + 7 && pj.y <= B->y && B->y < pj.y + 3) ||
		(pj.x <= B->x && B->x < pj.x + 7 && pj.y <= B->y + 3 && B->y + 3 < pj.y + 3) ||
		(pj.x <= B->x + 7 && B->x + 7 < pj.x + 7 && pj.y <= B->y + 3 && B->y + 3 < pj.y + 3)
		) return true;
	else return false;
}

void nivel1() {
	cout << endl << endl;
	cambiarColorCaracter(VERDE);
	cout << "  ********************               **              *****                      **            ********************               **         ";                 cout << endl;
	cout << "  ********************              ****             *****                     ****           ********************              ****         ";				  cout << endl;
	cout << "   ******                           ******            *****                    ******          ******                           ******                    ";				  cout << endl;
	cout << "   ******                          *      *           *****                   *      *         ******                          *      *               ";			  cout << endl;
	cout << "    ******                         **      **          *****                  **      **        ******                         **      **        ";				  cout << endl;
	cout << "    ******        ******          ************         *****                 ************       ******        ******          ************      ";				  cout << endl;
	cout << "   ******        ******         **************        *****                **************      ******        ******         **************          ";				  cout << endl;
	cout << "   ******           ***        ****        ****       *****               ****        ****     ******           ***        ****        ****          ";				  cout << endl;
	cout << "  ********************       ****          ****      ***************    ****          ****    ********************       ****          ****     ";				  cout << endl;
	cout << "  *********************     ****            ****     ***************   ****            ****   *********************     ****            ****   ";				  cout << endl;

	cambiarColorCaracter(AZUL);
	cout << endl << endl;
	cout << "Dyland Steven Saldaña ";
	cambiarColorCaracter(ROJO);
	cout << endl << endl;
	cout << " <- : " << "Izquierda";
	cout << endl << endl;
	cout << " -> : " << "Derecha";
	cout << endl << endl;
	cout << " s  : " << "Disparo";

}
void nivel2() {
	cout << endl << endl;
	Console::ForegroundColor = ConsoleColor::DarkMagenta;
	cout << "           ****************                      ";                 cout << endl;
	cout << "           ****************                       ";				  cout << endl;
	cout << "              ****  ****                         ";				  cout << endl;
	cout << "              ****  ****                         ";				  cout << endl;
	cout << "              ****  ****                        ";				  cout << endl;
	cout << "              ****  ****                        ";				  cout << endl;
	cout << "              ****  ****                        ";				  cout << endl;
	cout << "              ****  ****                        ";				  cout << endl;
	cout << "           ****************                     ";				  cout << endl;
	cout << "           ****************                          ";			  cout << endl;
	cout << "                                    ";							  cout << endl;

}
void nivel3() {
	cout << endl << endl;
	Console::ForegroundColor = ConsoleColor::DarkCyan;
	cout << "          **********************                      ";                 cout << endl;
	cout << "          **********************                       ";				  cout << endl;
	cout << "             ****  ****  ****                         ";				  cout << endl;
	cout << "             ****  ****  ****                         ";				  cout << endl;
	cout << "             ****  ****  ****                        ";				  cout << endl;
	cout << "             ****  ****  ****                        ";				  cout << endl;
	cout << "             ****  ****  ****                        ";				  cout << endl;
	cout << "             ****  ****  ****                        ";				  cout << endl;
	cout << "          **********************                     ";				  cout << endl;
	cout << "          **********************                          ";			  cout << endl;
	cout << "                                    ";							  cout << endl;
}
void nivel4() {
	cout << endl << endl;
	Console::ForegroundColor = ConsoleColor::Cyan;
	cout << "            *************  ****            ****                ";                 cout << endl;
	cout << "            *************   ****          ****                  ";				  cout << endl;
	cout << "                ****         ****        ****                  ";				  cout << endl;
	cout << "                ****          ****      ****                   ";				  cout << endl;
	cout << "                ****           ****    ****                   ";				  cout << endl;
	cout << "                ****            ****  ****                    ";				  cout << endl;
	cout << "                ****             ********                     ";				  cout << endl;
	cout << "                ****              ******                      ";				  cout << endl;
	cout << "           *************           ****                      ";				  cout << endl;
	cout << "           *************            **                            ";			  cout << endl;
}

void jugar() {
	//int minutos = 0, segundos = 0;

	Personaje P;
	P.pintar();
	srand(time(NULL));
	vector<bala*>B;
	clock_t ini = clock();
	//Enemigo *Enemy1 = new Enemigo[6];
	//EnemigoMedio *Enemy2 = new EnemigoMedio[5];
	int nivel = 1;
	int cooldown = 0;
	vector<Enemigo*>E;
	vector<EnemigoMedio*>E1;
	vector<Jefe*>Jfe;
	for (short i = 0; i < 3 * nivel; i++) {
		int x1 = ALEATORIO(5, 20);
		int y2 = ALEATORIO(5, 15);
		E.push_back(new Enemigo(x1, y2));
	}
	for (short i = 0; i < 4 * nivel; i++) {
		int x1 = ALEATORIO(5, 50);
		int y2 = ALEATORIO(5, 15);
		E1.push_back(new EnemigoMedio(x1, y2));
	}
	for (short i = 0; i < nivel; i++) {
		int x1 = ALEATORIO(60, 75);
		int y2 = ALEATORIO(5, 15);
		Jfe.push_back(new Jefe(x1, y2));
	}

	bool continuar = false;
	int puntos = 0;
	while (!continuar) {
		Console::ForegroundColor = ConsoleColor::White;
		gotoxy(4, 2); cout << "Puntos : " << puntos;
		gotoxy(4, 3); cout << "tiempo :   \b\b\b\b " << 110 - ((clock() - ini) / CLOCKS_PER_SEC);
		gotoxy(4, 4); cout << "vidas  :   \b\b\b\b "; for (int i = 0; i < P.vidas; i++)cout << char(2);
		if (kbhit()) {
			char tecla = getch();
			P.borrar();
			P.mover(tecla);
			P.pintar();


			if (tecla == 's' && cooldown == 0) {
				cooldown = 300;
				B.push_back(new bala(P.X() + 2, P.Y() - 1, -1));
			}
		}
		if (cooldown > 0)cooldown--;

		for (short i = 0; i < B.size(); ++i) {

			Console::ForegroundColor = ConsoleColor::White;
			B[i]->animar();

			if (B[i]->y == 0 || B[i]->y == 29) {
				delete B[i];
				B.erase(B.begin() + i);
				--i;
			}
			if (i >= 0 && colision(P, B.at(i))) {
				P.vidas--;
				delete B.at(i);
				B.erase(B.begin() + i);
				--i;
			}
			//colision bala enemigo
			for (int j = 0; j < E.size(); j++)
			{
				if (i >= 0 && j >= 0 && colision(E.at(j), B.at(i))) {
					E.at(j)->borrar();
					puntos += 100;
					delete E.at(j);
					E.erase(E.begin() + j);
					--j;
					delete B.at(i);
					B.erase(B.begin() + i);
					--i;
				}
			}
			for (int j = 0; j < E1.size(); j++)
			{
				if (i >= 0 && j >= 0 && colision(E1.at(j), B.at(i))) {
					E1.at(j)->borrar();
					puntos += 160;
					delete E1.at(j);
					E1.erase(E1.begin() + j);
					--j;
					delete B.at(i);
					B.erase(B.begin() + i);
					--i;
				}
			}
			for (int j = 0; j < Jfe.size(); j++)
			{
				if (i >= 0 && j >= 0 && colision(Jfe.at(j), B.at(i))) {
					Jfe.at(j)->vidas--;
					if (Jfe.at(j)->vidas == 0) {
						Jfe.at(j)->borrar();
						puntos += 400;
						delete Jfe.at(j);
						Jfe.erase(Jfe.begin() + j);
						--j;
					}
					delete B.at(i);
					B.erase(B.begin() + i);
					--i;
				}
			}

		}
		for (int i = 0; i < E.size(); i++) {
			if (rand() % 100 == 5 && E.at(i)->x == P.x) {
				B.push_back(new bala(E.at(i)->x + 2, E.at(i)->Y() + 4, 1));
			}
			E.at(i)->animar();
		}
		for (int i = 0; i < E1.size(); i++) {
			if (rand() % 100 == 5 && E1.at(i)->x == P.x) {
				B.push_back(new bala(E1.at(i)->x + 2, E1.at(i)->y + 4, 1));
			}
			E1.at(i)->animar();
		}
		for (int i = 0; i < Jfe.size(); i++) {
			if (rand() % 100 == 5 && Jfe.at(i)->x == P.x) {
				B.push_back(new bala(Jfe.at(i)->x + 2, Jfe.at(i)->y + 4, 1));
				B.at(B.size() - 1)->daño = 2;
			}
			Jfe.at(i)->animar();
		}

		if (puntos > 8500 || (E.size() == 0 && E1.size() == 0 && Jfe.size() == 0)) {
			puntos = 0; nivel++;
			for (short i = 0; i < 5 * nivel; i++) {
				int x1 = ALEATORIO(5, 20);
				int y2 = ALEATORIO(5, 15);
				E.push_back(new Enemigo(x1, y2));
			}
			for (short i = 0; i < 6 * nivel; i++) {
				int x1 = ALEATORIO(5, 50);
				int y2 = ALEATORIO(5, 15);
				E1.push_back(new EnemigoMedio(x1, y2));
			}
			for (short i = 0; i < nivel; i++) {
				int x1 = ALEATORIO(60, 75);
				int y2 = ALEATORIO(5, 15);
				Jfe.push_back(new Jefe(x1, y2));
			}
			ini = clock();

			system("cls");
			switch (nivel)
			{
			case 2:nivel2(); _getch();
				system("cls"); break;
			case 3:nivel3(); _getch();
				system("cls"); break;
			case 4:nivel4(); _getch();
				system("cls"); break;
			default:
				break;
			}
			if (nivel > 4) {
				system("cls");
				cout << endl << endl;
				Console::ForegroundColor = ConsoleColor::DarkGreen;
				cout << "****     ****  *************   ****     ****    ****  **********          ***************             " << endl;
				cout << " ****   ****   *************   ****     ****     ***  ***** *****         ***************            " << endl;
				cout << "  **** ****    ****     ****   ****     ****      **  ****    ****        *****                     " << endl;
				cout << "   *******     ****     ****   ****     ****       *  ****    ****        *****                    " << endl;
				cout << "    *****      ****     ****   ****     ****          ****** *****        ***************         " << endl;
				cout << "     ***       ****     ****   ****     ****          *************       ***************         " << endl;
				cout << "     ***       ****     ****   ****     ****          ****      ****      *****                   " << endl;
				cout << "     ***       ****     ****   ****     ****          ****       ****     *****                   " << endl;
				cout << "     ***       *************   *************          ****        ****    ***************         " << endl;
				cout << "     ***       *************   *************          ****         ****   ***************          " << endl;


				cout << endl << endl;

				cout << "   ****                     ****  *************    *****      ****    *****      ****      ***************    **********        " << endl;
				cout << "    ****                   ****   *************    ******     ****    ******     ****       ***************   ***** *****       " << endl;
				cout << "     ****                 ****         ****        *******    ****    *******    ****        *****            ****    ****       " << endl;
				cout << "      ****               ****          ****        **** ***   ****    **** ***   ****         *****           ****    ****        " << endl;
				cout << "       ****             ****           ****        ****  ***  ****    ****  ***  ****         *************** ****** *****        " << endl;
				cout << "        ****     *     ****            ****        ****   *** ****    ****   *** ****         *************** *************       " << endl;
				cout << "         ****   ***   ****             ****        ****    *******    ****    *******         *****           ****      ****      " << endl;
				cout << "          **** ***** ****              ****        ****     ******    ****     ******         *****           ****       ****     " << endl;
				cout << "           *************          *************    ****      *****    ****      *****        ***************  ****        ****    " << endl;
				cout << "            ***********           *************    ****       ****    ****       ****       ***************   ****         ****  " << endl;

				cout << endl << endl;
				_getch();
				return;
				//winner();
			}
		}



		if (P.vidas <= 0 || 100 - ((clock() - ini) / CLOCKS_PER_SEC) < 0) {
			system("cls");
			Console::ForegroundColor = ConsoleColor::Red;

			cout << endl << endl;

			cout << "************           **           ****         ****  *************** " << endl;
			cout << "************          ****          *****       *****  *************** " << endl;
			cout << "***      ***         ******         ******     ******  *****           " << endl;
			cout << "***      ***        *      *        *******   *******  *****           " << endl;
			cout << "***                **      **       *****************  *************** " << endl;
			cout << "***               ************      ***** ***** *****  *************** " << endl;
			cout << "***    *****     **************     ****   ***   ****  *****           " << endl;
			cout << "***      ***    ****        ****    ****    *    ****  *****           " << endl;
			cout << "************   ****          ****   ****         ****  *************** " << endl;
			cout << "************  ****            ****  ****         ****  *************** " << endl;

			cout << endl << endl;
			cout << "************* ****            ****   ***************    **********            " << endl;
			cout << "*************  ****          ****    ***************    ***** *****           " << endl;
			cout << "****     ****   ****        ****     *****              ****    ****           " << endl;
			cout << "****     ****    ****      ****      *****              ****    ****           " << endl;
			cout << "****     ****     ****    ****       ***************    ****** *****          " << endl;
			cout << "****     ****      ****  ****        ***************    *************         " << endl;
			cout << "****     ****       ********         *****              ****      ****        " << endl;
			cout << "****     ****        ******          *****              ****       ****       " << endl;
			cout << "*************         ****           ***************    ****        ****       " << endl;
			cout << "*************          **            ***************    ****         ****     " << endl;

			cout << endl << endl;
			_getch();
			return;
		}
		/*
				/*for (short i = B.size() - 1; i >= 0; --i) {
				bala* balaNave = B[i];
				balaNave->mover();
				if (balaNave->fuera()) {
				delete balaNave;
				B.erase(B.begin() + i);

				}
				Sleep(30);
				}*/

	}
	//delete[] Enemy1;

}

int main(void) {

	Console::CursorVisible = false;
	nivel1();
	_getch();
	system("cls");
	jugar();
}