#pragma once
#include "Entidad.h"
#include "Proyectil.h"

enum AccionEsqueleto { Arriba, Izquierda, Abajo, Derecha, Muerte};

class Esqueleto : public Entidad
{
private:
	AccionEsqueleto accion;
public:
	Esqueleto()
	{
		x = rand() % 400;
		y = rand() % 300;

		dx = rand() % 11 - 5;
		dy = rand() % 11 - 5;

		ancho = alto = 0;

		IDx = 0;
		SetAccion();
	}

	void SetAccion()
	{
		if (accion != Muerte)
			if (dx*dx > dy*dy)
			{
				if (dx > 0)
					accion = Derecha;
				else
					accion = Izquierda;
			}
			else
			{
				if (dy > 0)
					accion = Abajo;
				else
					accion = Arriba;
			}
	}
	void SetAccion(AccionEsqueleto n)
	{
		accion = n;
		this->IDx = 1;
		dx = dy = 0;
	}
	AccionEsqueleto GetAccion()
	{
		return accion;
	}

	void Disparar(Proyectiles* proyectiles , int jx, int jy)
	{
		proyectiles->AgregarElemento(new Proyectil(x + ancho / 2, y + alto / 2, jx, jy));
	}

	void Mover(Graphics^ g)
	{
		if (x + dx < 0 || x + ancho + dx >= g->VisibleClipBounds.Width)
			dx *= -1;

		if (y + dy < 0 || y + alto + dy >= g->VisibleClipBounds.Height)
			dy *= -1;

		x += dx;
		y += dy;

		SetAccion();
	}
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		ancho = img->Width / 9;
		alto = img->Height / 5;

		Rectangle corte = Rectangle(IDx * ancho, accion * alto, ancho, alto);
		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);

		if (accion == Muerte)
		{
			IDx = (IDx + 1) % 6;
		}
		else
			IDx = (IDx + 1) % 9;


	}
};

class Esqueletos
{
private:
	Esqueleto** arreglo;
	int cant;
public:
	Esqueletos()
	{
		cant = 0;
	}
	~Esqueletos()
	{
		for (int i = 0; i < cant; i++)
			delete arreglo[i];
		delete[] arreglo;
	}

	void AgregarElemento(Esqueleto* nuevo)
	{
		Esqueleto** aux = new Esqueleto *[cant + 1];

		for (int i = 0; i < cant; i++)
			aux[i] = arreglo[i];

		aux[cant] = nuevo;

		cant++;
		arreglo = aux;
	}
	void EliminarElemento(Esqueleto* eliminado)
	{
		Esqueleto** aux = new Esqueleto *[cant - 1];
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
		Esqueleto** aux = new Esqueleto *[cant - 1];

		for (int i = 0; i < pos; i++)
			aux[i] = arreglo[i];

		for (int j = pos; j < cant - 1; j++)
			aux[j] = arreglo[j + 1];

		delete arreglo[pos];
		cant--;
		arreglo = aux;
	}

	Esqueleto* Get(int pos)
	{
		return arreglo[pos];
	}
	int Size()
	{
		return cant;
	}

	void Disparar(Proyectiles* proyectiles, int jx, int jy)
	{
		for (int i = 0; i < cant; i++)
			if (rand() % 50 == 0)
				arreglo[i]->Disparar(proyectiles, jx, jy);
	}


	void Mover(Graphics^ g)
	{
		for (int i = 0; i < cant; i++)
			arreglo[i]->Mover(g);

		for (int i = 0; i < cant; i++)
			if (arreglo[i]->GetAccion() == Muerte && arreglo[i]->GetIDx() == 0)
			{
				EliminarElemento(i--);
			}
	}
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		for (int i = 0; i < cant; i++)
			arreglo[i]->Mostrar(g, img);
	}
};