#pragma once
#include"Objeto.h"
#include<cstdlib>
using namespace System::Drawing;
class CPrimitiva : public CObjeto
{
public:
	CPrimitiva()
	{
		x = rand() % 600 + 30;
		y = rand() % 300;
		color = rand() % 5;
		ancho = alto = 20;
	}

	void dibujar(Graphics ^lienzo)
	{
		Brush^ brocha;
		switch (color)
		{
		case 0:brocha = Brushes::Yellow; break;
		case 1:brocha = Brushes::Red; break;
		case 2:brocha = Brushes::Orange; break;
		case 3:brocha = Brushes::Green; break;
		case 4:brocha = Brushes::Blue; break;
		default:
			break;
		}
		lienzo->FillEllipse(brocha, x, y, ancho, alto);
	}
	~CPrimitiva() {}



};