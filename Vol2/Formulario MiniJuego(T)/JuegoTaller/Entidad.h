#pragma once
#include <iostream>
#include <time.h>

using namespace System;
using namespace System::Drawing;

class Entidad
{
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int IDx;
public:
	int GetX()
	{
		return x;
	}
	int GetY()
	{
		return y;
	}
	int GetDX()
	{
		return dx;
	}
	int GetDY()
	{
		return dy;
	}
	int GetAncho()
	{
		return ancho;
	}
	int GetAlto()
	{
		return alto;
	}
	int GetIDx()
	{
		return IDx;
	}

	void SetX(int n)
	{
		x = n;
	}
	void SetY(int n)
	{
		y = n;
	}
	void SetDX(int n)
	{
		dx = n;
	}
	void SetDY(int n)
	{
		dy = n;
	}

	Rectangle Area()
	{
		return Rectangle(x, y, ancho, alto);
	}

	virtual void Mover(Graphics^ g)
	{

	}
	virtual void Mostrar(Graphics^ g, Bitmap^ img)
	{

	}
};