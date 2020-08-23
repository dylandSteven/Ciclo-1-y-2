#pragma once
#include "Entidad.h"
#include <iostream>
#include <vector>

class Enemigo : public Entidad
{
private:
	int IDx;
	Accion accion;
public:
	Enemigo()
	{
		x = rand() % 500;
		y = rand() % 500;

		dx = rand() % 10 - 5;
		dy = rand() % 10 - 5;

		ancho = alto = 0;

		IDx = 0;
		
		if (dx*dx > dy*dy)
		{
			if (dx > 0)
				accion = Derecha;
			else
				accion = Izquierda;
		}
		else if (dx*dx < dy*dy)
		{
			if (dy > 0)
				accion = Abajo;
			else
				accion = Arriba;
		}
		else
		{
			accion = Abajo;
		}


	}
	void Mover(Graphics^ g)
	{
		if (x + dx < 0 || x + ancho + dx >= g->VisibleClipBounds.Width)
			dx *= -1;
		if (y + dy < 0 || y + alto + dx >= g->VisibleClipBounds.Height)
			dy *= -1;

		x += dx;
		y += dy;

		if (dx*dx > dy*dy)
		{
			if (dx > 0)
				accion = Derecha;
			else
				accion = Izquierda;
		}
		else if (dx*dx < dy*dy)
		{
			if (dy > 0)
				accion = Abajo;
			else
				accion = Arriba;
		}
		else
		{
			accion = Abajo;
		}
	}
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		ancho = img->Width / 9;
		alto = img->Height / 4;

		Rectangle corte = Rectangle(IDx * ancho, accion * alto, ancho, alto);

		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);

		IDx = (IDx + 1) % 9;

		if (dx == 0 && dy == 0)
			IDx = 0;
	}

};

class Enemigos
{
	std::vector<Enemigo*> enemigos;
public:
	void Agregar(Enemigo* enemigo)
	{
		enemigos.push_back(enemigo);
	}
	void Eliminar(int pos)
	{
		enemigos.erase(enemigos.begin() + pos);
	}
	int Size()
	{
		return (int)enemigos.size();
	}
	Enemigo* Get(int pos)
	{
		return enemigos[pos];
	}

	void Mover(Graphics^ g)
	{
		for each (Enemigo * e in enemigos)
			e->Mover(g);
	}
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		for each(Enemigo* e in enemigos)
			e->Mostrar(g, img);
	}
};