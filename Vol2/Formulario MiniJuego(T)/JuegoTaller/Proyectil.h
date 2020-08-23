#pragma once
#include "Entidad.h"

class Proyectil : public Entidad
{
public:
	Proyectil(int x, int y, int fx, int fy)
	{
		this->x = x;
		this->y = y;

		double V = 7;
		double c1 = fx - x;
		double c2 = fy - y;
		double h = Math::Sqrt(c1*c1 + c2*c2);
		double C = V / h;
		dx = c1 * C;
		dy = c2 * C;

		ancho = alto = 10;
	}
	void Mover(Graphics^ g)
	{
		x += dx;
		y += dy;
	}
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		g->FillEllipse(Brushes::DarkGray, Area());
	}
};

class Proyectiles
{
private:
	Proyectil** arreglo;
	int cant;
public:
	Proyectiles()
	{
		cant = 0;
	}
	~Proyectiles()
	{
		for (int i = 0; i < cant; i++)
			delete arreglo[i];
		delete[] arreglo;
	}

	void AgregarElemento(Proyectil* nuevo)
	{
		Proyectil** aux = new Proyectil *[cant + 1];

		for (int i = 0; i < cant; i++)
			aux[i] = arreglo[i];

		aux[cant] = nuevo;

		cant++;
		arreglo = aux;
	}
	void EliminarElemento(Proyectil* eliminado)
	{
		Proyectil** aux = new Proyectil *[cant - 1];
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
		Proyectil** aux = new Proyectil *[cant - 1];

		for (int i = 0; i < pos; i++)
			aux[i] = arreglo[i];

		for (int j = pos; j < cant - 1; j++)
			aux[j] = arreglo[j + 1];

		delete arreglo[pos];
		cant--;
		arreglo = aux;
	}

	Proyectil* Get(int pos)
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