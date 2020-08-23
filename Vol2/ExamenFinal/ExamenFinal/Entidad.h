#pragma once
#include <iostream>
#include <time.h>

using namespace System::Drawing;
using namespace System;

enum  Direcciones { Abajo, Izquierda, Derecha, Arriba };
class  Entidad
{
public:
	Entidad() {
	
		x = 0;
		y = 0;
		ancho = 0;
		dx = 0; dy = 0;
		alto = 0;
	}


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

	int GetAlto()
	{
		return alto;
	}

	int GetAncho()
	{
		return ancho;
	}

	int GetindiceX()
	{
		return indiceX;
	}

	int GetindiceY()
	{
		return indiceY;
	}

	void  SetX(int valor)
	{
		x = valor;
	}

	void  SetY(int valor)
	{
		y = valor;
	}


	void  SetDX(int valor)
	{
		dx = valor;
	}


	void  SetDY(int valor)
	{
		dy = valor;
	}

	void  SetAlto(int valor)
	{
		alto = valor;
	}

	void  SetAncho(int valor)
	{
		ancho = valor;
	}

	void  SetindiceX(int valor)
	{
		indiceX = valor;
	}

	void SetindiceY(int valor)
	{
		indiceY = valor;
	}

	Rectangle AreaVisible()
	{
		return Rectangle(ancho * indiceX, alto * indiceY, ancho, alto);
	}

	Rectangle Zoom()
	{
		return Rectangle(x, y, ancho, alto);
	}
protected:

	int x, y, ancho, alto, dx, dy, indiceX, indiceY;

};
