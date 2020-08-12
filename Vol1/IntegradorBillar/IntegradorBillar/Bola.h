#pragma once
#include"Objeto.h"
#include<cmath>
using namespace System::Drawing;
class CBola :public CObjeto
{
	CBola()
	{
		idx = idy = 0;
		nfil = 17;
		ncol = 25;
		x = 0;
		dx = 0;
	}
	~CBola() {}
	void inicializar(Bitmap^ imagen, Graphics^ lienzo)
	{
		ancho = imagen->Width / ncol;
		alto = imagen->Height / nfil;
		y = 0.5 * (lienzo->VisibleClipBounds.Height - alto);
	}

	void mover()
	{
		dy = dx * tan(angulo);
		x += dx;
		y += dy;
	}

	void dibujar(Bitmap^ imagen, Graphics^ lienzo)
	{
		Rectangle aVisible = Rectangle(idx * ancho, idy * alto, ancho, alto);
		lienzo->DrawImage(imagen, x, y, aVisible, GraphicsUnit::Pixel);
	}

	void setAngulo(int nx, int ny)
	{
		angulo = atan((double)(ny - y) / (double)(nx - x));
		dx = 10;

	}
	void disminuye()
	{
		if (dx > 0)
			dx -= 5;
	}

	void animar()
	{
		if (++idy > 9)
			idy = 0;
	}

private:
	int idx, dx, dy, idy, nfil, ncol;
	double angulo;


};