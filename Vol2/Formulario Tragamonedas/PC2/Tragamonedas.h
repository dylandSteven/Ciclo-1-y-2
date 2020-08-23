#pragma once
#include<cstdlib>
#include<ctime>
using namespace System::Drawing;

class Tragamonedas {
private:
	int x; int y;
	int largo; int ancho;
	int indiceX, indiceY;


public:

	Tragamonedas(int x, int y, int indiceX, int indiceY) {
		srand(time(NULL));
		largo = 800 / 3;
		ancho = 800 / 3;
		this->x = x;
		this->y = y;
		this->indiceX = indiceX;
		this->indiceY = indiceY;
	}

	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle areaVisible = Rectangle(ancho * indiceX, indiceY * largo, ancho, largo);
		Rectangle Zoom = Rectangle(x, y, ancho, largo);

		g->DrawImage(bmp, Zoom, areaVisible, GraphicsUnit::Pixel);

	}

	void Mover(Graphics^ g)
	{

		if (x > 0) {
			indiceX++;
			if (indiceX > 2)indiceX = 0;
		}

	}
	int getindiceX() { return indiceX; }
	int getIndiceY() { return  indiceY; }


};