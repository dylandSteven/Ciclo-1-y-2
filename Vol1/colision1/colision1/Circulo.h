#pragma once
using namespace System::Drawing;

class Circulo
{
	int x, y, dx, dy, color, numero;

public:

	Circulo(int x, int y, int dx, int dy, int color, int numero) {
	
		this->x=x;
		this->y=y;
		this->dx=dx;
		this->dy=dy; 
		this->color=color;
		this->numero=numero;
	}
	~Circulo(void) {}

	void moverCirculo(Graphics^ g) {
		int limX = (int)g->VisibleClipBounds.Width;
		int limY = (int)g->VisibleClipBounds.Height;
		if (x + dx<0 || x + dx + 40>limX)
			dx = dx * (-1);
		if (y + dy<0 || y + dy + 40>limY)
			dy = dy*(-1);

		x = x + dx;
		y = y + dy;
	
	}
	void dibujarCirculo(Graphics^ g) {
		Font^ f = gcnew Font("Arial", 20, FontStyle::Bold);
		if (color == 1)
		{
			g->FillEllipse(Brushes::DarkBlue, x, y, 40, 40);
			g->DrawEllipse(Pens::White, x, y, 40, 40);
			g->DrawString(numero.ToString(), f, Brushes::White, x + 7, y + 4);
		}
		else
		{
			g->FillEllipse(Brushes::Red, x, y, 40, 40);
			g->DrawEllipse(Pens::White, x, y, 40, 40);
			g->DrawString(numero.ToString(), f, Brushes::White, x + 7, y + 4);
		}
	}

	int getXCirculo() { return x; }
	int getYCirculo() { return y; }

	int getdesXCirculo() { return dx; }
	int getdesYCirculo() { return dy; }

	void setDesX(int valor) { dx = valor; }
	void setDesY(int valor) { dy = valor; }

	int getColorCirculo() { return dx; }
	void setColorCirculo(int valor) { color=valor; }

	int getNumeroCirculo() { return numero; }
	void setNumeroCirculo(int valor) { numero = valor; }

};