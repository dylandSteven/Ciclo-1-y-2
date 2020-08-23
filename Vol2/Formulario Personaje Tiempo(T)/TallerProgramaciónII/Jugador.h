#pragma once
#include "Entidad.h"
class Jugador : public Entidad
{
	int IDx;
	Accion accion;
public:
	Jugador()
	{
		x = y = 200;
		dx = dy = 0;
		IDx = 0;
		accion = Abajo;
	}
	void SetAccion(Accion n)
	{
		accion = n;
	}
	Accion GetAccion()
	{
		return accion;
	}

	void Mover(Graphics^ g)
	{
		if (x + dx >= 0 && x + ancho + dx < g->VisibleClipBounds.Width)
			x += dx;
		if (y + dy >= 0 && y + alto + dy < g->VisibleClipBounds.Height)
			y += dy;
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
