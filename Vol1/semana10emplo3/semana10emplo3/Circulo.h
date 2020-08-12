#pragma once
class Circulo {

private:
	int x, y;
	int dx, dy;
	int Color, Indice;
	int radio;

public:

	Circulo(int px, int py, int pdx, int pdy, int pradio, int pColor, int pIndice);
	~Circulo();
	//void borrar(System::Drawing::Graphics^ pCanvas);
	void mover(System::Drawing::Graphics^ pCanvas);
	void dibujar(System::Drawing::Graphics^ pCanvas);
};






Circulo::Circulo(int px, int py, int pdx, int pdy,int pradio, int pColor, int pIndice)
{
	 x=px;
	 y=py;
	 dx=pdx;
	 dy=pdy;
	 Color=pColor;
	 Indice=pIndice;
	 radio = pradio;
}
//void Circulo::borrar(System::Drawing::Graphics^ pCanvas) {
//	pCanvas->DrawEllipse(gcnew System::Drawing::Pen(System::Drawing::Color::Red), x - radio, y - radio, radio * 2, radio * 2);
//
//}
void Circulo::mover(System::Drawing::Graphics^pCanvas) {

	if ((x - radio) + dx<0 || (x + radio) + dx > pCanvas->VisibleClipBounds.Width) 
		dx *= -1; 

	if ((y - radio) + dy<0 || (y + radio) + dy>pCanvas->VisibleClipBounds.Height)  
		dy *= -1; 
	x += dx;
	y += dy;
}
void Circulo::dibujar(System::Drawing::Graphics^ pCanvas) 
{
	pCanvas->FillEllipse(System::Drawing::Brushes::Green, x - radio, y - radio, radio * 2, radio * 2);
	//pCanvas->FillEllipse(System::Drawing::Brushes::Red, x - radio, y - radio, radio*2, radio*2);
}
Circulo::~Circulo(void) {}