#pragma once
using namespace System::Drawing;
#include"Circulo.h"
class Cuadrado {

private :
	int x, dy;
	int y, dx;
	int color;
	int numero;

public:

	Cuadrado(int x, int y, int dx, int dy, int color, int numero) {
	
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		this->color = color;
		this->numero = numero;
	}

	void moverCuadrado(Graphics ^g) {
		int limX = (int)g->VisibleClipBounds.Width;
		int limY = (int)g->VisibleClipBounds.Height;

		if (y + dy < 0 || y + dy + 40 > limY)
			dy = dy * (-1);
		y = y + dy;
	}

	void dinujarCuadrado(Graphics^ g) 
	{
		Font^ f = gcnew Font("Arial", 20, FontStyle::Bold);
		if (color == 1)
		{
			g->FillRectangle(Brushes::Red, x, y, 40, 40);


		}
	
	}

	bool esColison(Circulo * circulo) {
		Rectangle r1 = Rectangle(circulo->getXCirculo(), circulo->getYCirculo(), 40, 40);
		Rectangle r2 = Rectangle(x, y, 40, 40);
		return r1.IntersectsWith(r2);
	}
	
	int getXCuadrado() { return x; }
	int getYCUadrado() { return y; }
	int getdesy() { return dy; }

	void Setdesy_cuadrado(int valor) { dy = valor; }
	void setColor(int valor) { color = valor; }
	int getColor() { return color; }

	int GetNUmeroCuadrado() { return numero; }
	void setNumeroCuadrado(int valor) { numero = valor; }


};