#pragma once
#include"MatrizBidimencional.h"
#include<ctime>
#include<cstdlib>
using namespace System::Drawing;
class CMejora
{
private:
	int i, j;
	int indiceX, indiceY;

	int ancho;
	int alto;

	int tipo;

	bool ubicado;


public:
	CMejora() {
		srand(time(NULL));
		ubicado = false;
		i = rand() % 13 + 1;
		j = rand() % 15 + 1;

		ancho = 128 / 8;
		alto = 96 / 6;

		indiceX = 0;
		indiceY = 0;
		tipo = rand() % 5 + 1;
	}
	~CMejora() {}

	void dibujar(Graphics^ g, Bitmap^ bmpMejoras, int** matriz)
	{
		Rectangle porcionUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);

		while (ubicado == false)
		{
			if (matriz[i][j] == 3) {
				ubicado = true;
			}
			else {
				if (j < 17) {
					i++;
					if (filas == 14) {
						i = 0;
						j++;
					}
				}
			}
		}
		Rectangle aumento = Rectangle(j * 50, i * 50, ancho * 3.125, alto * 3.125);
		g->DrawImage(bmpMejoras, aumento, porcionUsar, GraphicsUnit::Pixel);
	}


	Rectangle devolverRectangulo()
	{
		return  Rectangle(j * 50, i * 50, ancho * 3.125, alto * 3.125);

	}
	void animar() {
		switch (tipo)
		{
		case 1:
			//bombaadicional
			indiceX = 0;
			if (indiceY >= 0 && indiceY < 1)
				indiceY++;
			else
				indiceY = 0;
			break;


		case 2:
			//moverbomba
			indiceX = 4;
			if (indiceY >= 0 && indiceY < 1)
				indiceY++;
			else
				indiceY = 0;
			break;

		case 3:
			//calavera
			indiceX = 5;
			if (indiceY >= 0 && indiceY < 1)
				indiceY++;
			else
				indiceY = 0;
			break;

		case 4:
			//patines
			indiceX = 8;
			if (indiceY >= 0 && indiceY < 1)
				indiceY++;
			else
				indiceY = 0;

			break;

		case 5:
			//vidas
			indiceX = 9;
			if (indiceY >= 0 && indiceY < 1)
				indiceY++;
			else
				indiceY = 0;

			break;
		default:
			break;
		}
	}

	int getTipoMejora() { return tipo; }

};
