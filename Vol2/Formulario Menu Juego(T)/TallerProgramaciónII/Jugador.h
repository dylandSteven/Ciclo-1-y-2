#pragma once
#include "Entidad.h"

class Jugador : public Entidad
{
	Accion accion;

public:
	Jugador()
	{
		x = y = 200;
		dx = dy = 0;
		ancho = alto = 0;

		escala = 1;
		IDx = 0;

		accion = Abajo;
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

	void SetAccion(Accion n)
	{
		accion = n;
	}
};