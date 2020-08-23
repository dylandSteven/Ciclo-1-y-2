#pragma once
#include "Entidad.h"

class Flecha : public Entidad
{
public:
	Flecha(int x, int y, int dx, int dy)
	{
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;

		ancho = alto = 2;

		if (dx != 0)
			ancho = 20;
		if (dy != 0)
			alto = 20;
	}
	void Mover(Graphics^ g)
	{
		x += dx;
		y += dy;
	}
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		g->FillRectangle(Brushes::Brown, Area());
	}
};

class Flechas
{
private:
	Flecha** arreglo;
	int cant;
public:
	Flechas()
	{
		cant = 0;
	}
	~Flechas()
	{
		for (int i = 0; i < cant; i++)
			delete arreglo[i];
		delete[] arreglo;
	}

	void AgregarElemento(Flecha* nuevo)
	{
		Flecha** aux = new Flecha *[cant + 1];

		for (int i = 0; i < cant; i++)
			aux[i] = arreglo[i];

		aux[cant] = nuevo;

		cant++;
		arreglo = aux;
	}
	void EliminarElemento(Flecha* eliminado)
	{
		Flecha** aux = new Flecha *[cant - 1];
		int i;
		for (i = 0; arreglo[i] != eliminado; i++)
			aux[i] = arreglo[i];

		for (int j = i; j < cant - 1; j++)
			aux[j] = arreglo[j + 1];

		delete eliminado;
		cant--;
		arreglo = aux;
	}
	void EliminarElemento(int pos)
	{
		Flecha** aux = new Flecha *[cant - 1];

		for (int i = 0; i < pos; i++)
			aux[i] = arreglo[i];

		for (int j = pos; j < cant - 1; j++)
			aux[j] = arreglo[j + 1];

		delete arreglo[pos];
		cant--;
		arreglo = aux;
	}

	Flecha* Get(int pos)
	{
		return arreglo[pos];
	}
	int Size()
	{
		return cant;
	}

	void Mover(Graphics^ g)
	{
		for (int i = 0; i < cant; i++)
			arreglo[i]->Mover(g);

		Rectangle pantalla = Rectangle(0, 0, g->VisibleClipBounds.Width, g->VisibleClipBounds.Height);
		for (int i = 0; i < cant; i++)
			if (pantalla.IntersectsWith(arreglo[i]->Area()) == false)
			{
				EliminarElemento(i--);
			}
	}
	void Mostrar(Graphics^ g)
	{
		for (int i = 0; i < cant; i++)
			arreglo[i]->Mostrar(g, nullptr);
	}
};