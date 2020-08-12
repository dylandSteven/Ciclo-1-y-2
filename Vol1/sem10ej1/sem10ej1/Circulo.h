#pragma once

class Circulo {

private:

	int x, y, dx, dy;
	int radio;

public:

	Circulo(void);
	Circulo(int px, int y, int pradio);
	~Circulo();


	void borrar(System::Drawing::Graphics^ gr);
	void mover(System::Drawing::Graphics^ gr);
	void dibujar(System::Drawing::Graphics^ gr);
};

Circulo::Circulo(void)
{
	x = y = radio = dx = dy = 0;
}

Circulo::Circulo(int px, int py, int pradio)
{
	x = px;
	y = py;
	radio = pradio;
	dx = 5;
	dy = 5;
}
Circulo::~Circulo(void) {}

void Circulo::borrar(System::Drawing::Graphics^ gr)
{
	gr->DrawEllipse(gcnew System::Drawing::Pen(System::Drawing::Color::Red), x, y, radio, radio);

}


void Circulo::mover(System::Drawing::Graphics^ gr)
{
	borrar(gr);
	if (x + dx < 1 || x + dx + radio>gr->VisibleClipBounds.Width) {
		dx = dx * -1;
	}
	if (y + dy < 1 || y + dy + radio>gr->VisibleClipBounds.Height) {
		dy = dy * -1;
	}
	x += dx;
	y += dy;
	dibujar(gr);
}


void Circulo::dibujar(System::Drawing::Graphics^ gr) {

	gr->DrawEllipse(gcnew System::Drawing::Pen(System::Drawing::Color::Cyan), x, y, radio, radio);
}