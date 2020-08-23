#pragma once
using namespace System;
using namespace System::Drawing;
#include <iostream>

enum Tipo { UP, DOWN, PROT, NEU };

class Particula
{
protected:
	int x, y;
	int dx, dy;
	int radio;
	bool enlace;
	Tipo tipo;
public:
	Particula()
	{
		x = rand() % 500;
		y = rand() % 400;

		dx = rand() % 11 - 5;
		dy = rand() % 11 - 5;

		if (dx == 0) dx = rand() % 5 + 1;
		if (dy == 0) dy = rand() % 5 + 1;

		enlace = false;
	}

	void SetEnlace(bool n)
	{
		enlace = n;
	}
	bool GetEnlace()
	{
		return enlace;
	}

	void SetX(int n)
	{
		x = n;
	}
	int GetX()
	{
		return x;
	}

	void SetY(int n)
	{
		y = n;
	}
	int GetY()
	{
		return y;
	}

	void SetDX(int n)
	{
		dx = n;
	}
	int GetDX()
	{
		return dx;
	}

	void SetDY(int n)
	{
		dy = n;
	}
	int GetDY()
	{
		return dy;
	}

	int GetTipo(Tipo test)
	{
		return tipo == test;
	}

	bool Salir(Graphics^ g)
	{
		Rectangle pantalla = Rectangle(0, 0, g->VisibleClipBounds.Width, g->VisibleClipBounds.Height);
		if (pantalla.IntersectsWith(Area()) == false)
			return true;

		return false;
	}

	Rectangle Area()
	{
		return Rectangle(x - radio, y - radio, 2 * radio, 2 * radio);
	}
	Rectangle Area2()
	{
		int d = 2;
		return Rectangle(x - (radio - d), y - (radio - d), 2 * (radio - d), 2 * (radio - d));
	}

	void Mover(Graphics^ g)
	{
		if (enlace == true)
		{
			if (x - radio + dx < 0 || x + radio + dx >= g->VisibleClipBounds.Width)
				dx *= -1;
			if (y - radio + dy < 0 || y + radio + dy >= g->VisibleClipBounds.Height)
				dy *= -1;
		}

		x += dx;
		y += dy;
	}
	virtual void Mostrar(Graphics^ g)
	{

	}
};

class Particulas
{
private:
	Particula** arreglo;
	int cant;
public:
	Particulas()
	{
		cant = 0;
	}
	~Particulas()
	{
		for (int i = 0; i < cant; i++)
			delete arreglo[i];
		delete[] arreglo;
	}

	void AgregarElemento(Particula* nuevo)
	{
		Particula** aux = new Particula *[cant + 1];

		for (int i = 0; i < cant; i++)
			aux[i] = arreglo[i];

		aux[cant] = nuevo;

		cant++;
		arreglo = aux;
	}
	void EliminarElemento(Particula* eliminado)
	{
		Particula** aux = new Particula *[cant - 1];
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
		Particula** aux = new Particula *[cant - 1];

		for (int i = 0; i < pos; i++)
			aux[i] = arreglo[i];

		for (int j = pos; j < cant - 1; j++)
			aux[j] = arreglo[j + 1];

		delete arreglo[pos];
		cant--;
		arreglo = aux;
	}

	Particula* Get(int pos)
	{
		return arreglo[pos];
	}
	int GetCantidad()
	{
		return cant;
	}

	void Mover(Graphics^ g)
	{
		for (int i = 0; i < cant; i++)
			arreglo[i]->Mover(g);

		for (int i = 0; i < cant; i++)
			if (arreglo[i]->Salir(g) == true)
				if (arreglo[i]->GetEnlace() == false)
					EliminarElemento(i--);
			
	}
	void Mostrar(Graphics^ g)
	{
		for (int i = 0; i < cant; i++)
			arreglo[i]->Mostrar(g);
	}
};