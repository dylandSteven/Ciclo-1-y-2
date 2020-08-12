#pragma once
#include<ctime>
#include<cstdlib>
using namespace System::Drawing;

enum Estado_Enemigo {
	Eliminado,
	Normal
};

class CEnemigo {

private:

	int x, y;

	int i, j;

	int dx;

	int indiceX, indiceY;

	int ancho, alto;

	bool ubicado;

	Estado_Enemigo estado;
public:
	CEnemigo() 
	{
		srand(time(NULL));
		i = rand() % 13 + 1;
		j = rand() % 13 + 2;
		x = 715;
		y = 650;
		dx = 5;
		indiceX = 0;
		indiceY = 0;

		ancho = 96 / 6;
		alto = 16;

		ubicado = false;
		
		estado =Estado_Enemigo:: Normal;

	}
	~CEnemigo() {}

	void dibujar(Graphics^ g, Bitmap^ bmpEnemigo, int** matriz)
	{
		Rectangle porcionAUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		while ((matriz[i][j-1]!=2||matriz[i][j]!=2||matriz[i][j+1]!=2)&&i<14&&ubicado==false)
		{
			j++;
			if (j == 15)
			{
				i++;
				j = 0;
			}
			if (i >= 14)break;
			x = j * 50;
			y = i * 50;


		}

		//ubicado == true;
		Rectangle Aumento = Rectangle(x, y, 40,40);
		g->DrawImage(bmpEnemigo, Aumento, porcionAUsar, GraphicsUnit::Pixel);
		ubicado = true;
		x += dx;
		if ((matriz[y / 50][(x + 50) / 50] == 3 || matriz[y / 50][(x + 50) / 50]==1)
			||(matriz[y/50][(x-10)/50]==3||matriz[y / 50][(x - 10) / 50] == 1))
		{
			dx *= -1;
		}

	}
	void animar(){
		if (indiceX >= 0 && indiceX < 5)
		{
			indiceX++;
		}
		if (indiceX == 5)
		{
			while (indiceX != 0)
				indiceX--;
		}
	}

	Rectangle retornarRectangle() {
		return Rectangle(x, y, 50, 50);
	}
};