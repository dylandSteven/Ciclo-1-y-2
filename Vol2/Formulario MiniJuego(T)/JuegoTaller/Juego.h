#pragma once
#include "Jugador.h"
#include "Esqueleto.h"
#include "Proyectil.h"
#include <fstream>
using namespace std;

class Juego
{
private:
	Jugador* jugador;
	Esqueletos* esqueletos;
	Proyectiles* proyectiles;

	int cd_vidas;

	int tiempo;
	clock_t start;
public:
	Juego()
	{
		jugador = new Jugador();
		esqueletos = new Esqueletos();
		proyectiles = new Proyectiles();
		cd_vidas = 0;


		tiempo = 60;
		start = clock();

		Abrir();
	}
	~Juego()
	{
		delete jugador;
		delete esqueletos;
		delete proyectiles;
	}

	int VidasJugador()
	{
		return jugador->GetVidas();
	}

	void JugadorSetDX(int n)
	{
		jugador->SetDX(n);
	}
	void JugadorSetDY(int n)
	{
		jugador->SetDY(n);
	}
	void JugadorSetAccion(Accion n)
	{
		if ((n >= 0 && n <= 3 && jugador->GetCantEscudo() > 0) || n >= 4)
		{
			if (n >= 0 && n <= 3)
				jugador->SetCantEscudo(-1);

			jugador->SetAccion(n);
		}
	}
	Accion JugadorGetAccion()
	{
		return jugador->GetAccion();
	}

	void Colisiones()
	{
		//Esqueletos - Flechas
		Flechas* flechas = jugador->GetFlechas();
		for (int e = 0; e < esqueletos->Size(); e++)
			for (int f = 0; f < flechas->Size(); f++)
				if (esqueletos->Get(e)->Area().IntersectsWith(flechas->Get(f)->Area()))
				{
					esqueletos->Get(e)->SetAccion(Muerte);
					flechas->EliminarElemento(f--);
				}

		//Campo de fuerza - Proyectil
		for (int p = 0; p < proyectiles->Size(); p++)
		{
			if (proyectiles->Get(p)->Area().IntersectsWith(jugador->Campo()))
			{
				proyectiles->EliminarElemento(p--);
			}
		}
		//Esqueletos - Proyectil
		for (int e = 0; e < esqueletos->Size(); e++)
		{
			if (esqueletos->Get(e)->Area().IntersectsWith(jugador->Campo()))
			{
				esqueletos->Get(e)->SetAccion(Muerte);
			}
		}


		//Jugador - Proyectil
		for (int p = 0; p < proyectiles->Size(); p++)
		{
			if (proyectiles->Get(p)->Area().IntersectsWith(jugador->Area()) && cd_vidas <= 0)
			{
				proyectiles->EliminarElemento(p--);
				jugador->SetVidas(-1);
				cd_vidas = 3;
			}
		}
		//Jugador - Enemigos
		for (int e = 0; e < esqueletos->Size(); e++)
		{
			if (esqueletos->Get(e)->Area().IntersectsWith(jugador->Area()) && cd_vidas <= 0)
			{
				jugador->SetVidas(-1);
				cd_vidas = 3;

			}
		}
	}

	int Tiempo()
	{
		if (clock() - start >= (double)CLOCKS_PER_SEC)
		{
			tiempo--;
			cd_vidas--;
			start = clock();
		}
		return tiempo;
	}

	void Mover(Graphics^ g)
	{
		Colisiones();
		
		jugador->Mover(g);
		esqueletos->Mover(g);
		proyectiles->Mover(g);

		if (jugador->GetAccion() >= 8 && jugador->GetAccion() <= 11 && jugador->GetIDx() == 8)
			jugador->Disparar();

		esqueletos->Disparar(proyectiles, jugador->GetX() + jugador->GetAncho() / 2, jugador->GetY() + jugador->GetAlto() / 2);

		if (rand() % 50 == 0)
		{
			esqueletos->AgregarElemento(new Esqueleto());
		}
	}
	void Mostrar(Graphics^ g, Bitmap^ j, Bitmap^ e)
	{
		g->DrawString("Vidas: " + jugador->GetVidas().ToString() + " Tiempo: " + Tiempo().ToString() + " Escudo: " + jugador->GetCantEscudo().ToString(), gcnew Font("Arial", 12), Brushes::White, 0, 0);

		jugador->Mostrar(g, j);
		esqueletos->Mostrar(g, e);
		proyectiles->Mostrar(g);
	}

	void Guardar()
	{
		ofstream file("save.txt");
		//Jugador
		file << jugador->GetX() << " " << jugador->GetY() << endl;
		file << jugador->GetCantEscudo() << " " << jugador->GetVidas() << " " << tiempo << endl;

		//Enemigos
		file << esqueletos->Size() << endl;
		for (int i = 0; i < esqueletos->Size(); i++)
		{
			file << esqueletos->Get(i)->GetX() << " " << esqueletos->Get(i)->GetY() << endl;
			file << esqueletos->Get(i)->GetDX() << " " << esqueletos->Get(i)->GetDY() << endl;
		}

		file.close();
	}
	void Abrir()
	{
		int x, y, dx, dy, v, c, cant;
		ifstream file("save.txt");
		if (file.is_open())
		{
			file >> x >> y;
			file >> c >> v >> tiempo;

			jugador->SetX(x);
			jugador->SetY(y);
			jugador->SetVidas(v - 10);
			jugador->SetCantEscudo(c - 3);

			file >> cant;
			for (int i = 0; i < cant; i++)
			{
				file >> x >> y >> dx >> dy;
				Esqueleto* esqueleto = new Esqueleto();
				esqueleto->SetX(x); esqueleto->SetY(y);
				esqueleto->SetDX(dx); esqueleto->SetDY(dy);
				esqueletos->AgregarElemento(esqueleto);
			}
		}
		else
			Guardar();
	}

};