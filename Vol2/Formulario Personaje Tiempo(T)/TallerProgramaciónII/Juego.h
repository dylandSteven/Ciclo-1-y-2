#pragma once
#include "Jugador.h"
#include "Enemigo.h"
#include <time.h>
class Juego
{
private:
	Jugador* jugador;

	Enemigos* enemigos;
	int add_enemigo;
	int cool_down_enemigo;

	int tiempo;
	clock_t start;

public:
	Juego(int time_enemigos)
	{
		add_enemigo = time_enemigos;
		cool_down_enemigo = 0;
		jugador = new Jugador();
		enemigos = new Enemigos();
		tiempo = 10;
		start = clock();
	}
	~Juego()
	{
		delete jugador;
		delete enemigos;
	}

	void JugadorDX(int n)
	{
		jugador->SetDX(n);
	}
	void JugadorDY(int n)
	{
		jugador->SetDY(n);
	}
	void JugadorAccion(Accion n)
	{
		jugador->SetAccion(n);
	}
	
	void AgregarEnemigo()
	{
		enemigos->Agregar(new Enemigo());
	}

	int Tiempo()
	{
		if (clock() - start >= (double)CLOCKS_PER_SEC)
		{
			start = clock();
			tiempo--;

			cool_down_enemigo++;
			if (cool_down_enemigo == add_enemigo)
			{
				AgregarEnemigo();
				cool_down_enemigo = 0;
			}
		}
		return tiempo;
	}

	void Mover(Graphics^ g)
	{
		jugador->Mover(g);
		enemigos->Mover(g);
	}
	void Mostrar(Graphics^ g, Bitmap^ j, Bitmap^ e)
	{
		g->DrawString(tiempo.ToString(), gcnew Font("Arial", 20), Brushes::White, 0, 0);
		jugador->Mostrar(g, j);
		enemigos->Mostrar(g, e);
	}
};