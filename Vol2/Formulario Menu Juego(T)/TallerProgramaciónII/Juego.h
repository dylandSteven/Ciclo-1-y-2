#pragma once
#include "Jugador.h"
#include "Enemigo.h"
#include <iostream>
#include <time.h>

class Juego
{
private:
	int nivel;
	Jugador* jugador;
	Enemigos* enemigos;

	int tiempo;
	clock_t start;
public:
	Juego(int nivel)
	{
		start = clock();
		tiempo = 110 - 10 * nivel;
		this->nivel = nivel;
		jugador = new Jugador();
		enemigos = new Enemigos();
		
		int cant = 3 * nivel + rand() % nivel;

		for (int i = 0; i < cant; i++)
		{
			Entidad* E = new Entidad();
			E->SetX(rand() % 300);
			E->SetY(rand() % 300);

			E->SetDX(rand() % 10 - 5);
			E->SetDY(rand() % 10 - 5);
			
			E->SetAncho(rand() % 30 + 20);
			E->SetAlto(rand() % 30 + 20);

			enemigos->AgregarElemento(E);
		}
	}
	~Juego()
	{
		delete jugador;
	}

	void SetJugadorDX(int n)
	{
		jugador->SetDX(n);
	}
	void SetJugadorDY(int n)
	{
		jugador->SetDY(n);
	}
	void SetJugadorAccion(Accion n)
	{
		jugador->SetAccion(n);
	}

	void Colisiones()
	{
		for (int i = 0; i < enemigos->GetCantidad(); i++)
		{
			Entidad* E = enemigos->Get(i);
			if (jugador->Area().IntersectsWith(E->Area()))
			{
				enemigos->EliminarElemento(i--);
			}
		}
	}

	void Mover(Graphics^ g)
	{
		Colisiones();
		jugador->Mover(g);
		enemigos->Mover(g);

		if (clock() - start >= (double)CLOCKS_PER_SEC)
		{
			tiempo--;
			start = clock();
		}
	}
	void Mostrar(Graphics^ g, Bitmap^ jug)
	{
		if (nivel == 1)
			g->Clear(Color::Red);
		else if (nivel == 2)
			g->Clear(Color::Orange);
		else if (nivel == 3)
			g->Clear(Color::Yellow);
		else if (nivel == 4)
			g->Clear(Color::Green);
		else if (nivel == 5)
			g->Clear(Color::LightBlue);
		else if (nivel == 6)
			g->Clear(Color::Blue);
		else if (nivel == 7)
			g->Clear(Color::DarkViolet);
		jugador->Mostrar(g, jug);
		enemigos->Mostrar(g);

		g->DrawString(tiempo.ToString(), gcnew Font("Arial", 12), Brushes::Black, 0, 0);
	}

	int CantEnemigos()
	{
		return enemigos->GetCantidad();
	}
	int Tiempo()
	{
		return tiempo;
	}
};