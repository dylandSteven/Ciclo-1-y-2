#pragma once
using namespace System::Drawing;
class Cuadrado {

private:

	int x,y, dx, dy;
	int lado;

public:

	Cuadrado(void);
	Cuadrado(int px, int y, int lado);
	~Cuadrado(void);


	void borrar(System::Drawing::Graphics ^gr);
	void mover(System::Drawing::Graphics ^gr);
		void dibujar(System::Drawing::Graphics ^gr);
};

Cuadrado::Cuadrado(void) 
{
	x = y = lado = dx = dy = 0;

}

Cuadrado::Cuadrado(int px, int py, int plado)
{
	x = px;
	y = py;
	lado = plado;
	dx = 5;
	dy = 5;
}
Cuadrado::~Cuadrado(void) {}

void Cuadrado::borrar(Graphics ^gr) 
{
	gr->DrawRectangle(gcnew System::Drawing::Pen(System::Drawing::Color::Red), x, y, lado,lado);

}


void Cuadrado::dibujar(System::Drawing::Graphics^ gr) {

	gr->DrawRectangle(gcnew System::Drawing::Pen(System::Drawing::Color::Yellow), x, y, lado, lado);
}

void Cuadrado::mover(System::Drawing::Graphics^ gr)
{
	borrar(gr);
	if (x + dx < 1||x+dx+lado>gr->VisibleClipBounds.Width) {
		dx = dx * -1;
	}
	if (y + dy < 1 || y + dy + lado>gr->VisibleClipBounds.Height) {
		dy = dy * -1;
	}
	x += dx;
	y += dy;
	dibujar(gr);
}

