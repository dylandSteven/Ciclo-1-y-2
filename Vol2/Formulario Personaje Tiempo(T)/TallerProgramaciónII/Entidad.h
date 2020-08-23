#pragma once

using namespace System;
using namespace System::Drawing;

enum Accion { Arriba, Izquierda, Abajo, Derecha };

class Entidad
{
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
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
	void SetAncho(int n)
	{
		ancho = n;
	}
	void SetAlto(int n)
	{
		alto = n;
	}

	Rectangle Area()
	{
		return Rectangle(x, y, ancho, alto);
	}

	virtual void Mover(Graphics^ g)
	{
		x += dx;
		y += dy;
	}
	virtual void Mostrar(Graphics^ g, Bitmap^ img)
	{
		g->FillRectangle(Brushes::Black, Area());
	}
};