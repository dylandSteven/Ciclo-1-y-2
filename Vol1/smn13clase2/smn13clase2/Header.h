#pragma once
#include<fstream>
using namespace System;
using namespace System::Windows;
using namespace System::Drawing;

ref class Imagen
{
	short x;
	short y; 
	short dx;
	SolidBrush^ brocha;
	short dy;
public:
	Imagen(short _x, short _y)
	{	
		x = _x;
		y = _y;
		dx = 1;
		dy = 1;
		brocha = gcnew SolidBrush(Color::Black);
	}

	void paleta(short v )
	{
		Random r;

		switch (r.Next(0, 6))
		{
		case 0:brocha ->Color=(Color::Aqua); break;
		case 1:brocha ->Color=(Color::Blue); break;
		case 2:brocha ->Color=(Color::Green); break;
		case 3:brocha ->Color=(Color::Yellow); break;
		case 4:brocha ->Color=(Color::Red); break;
		case 5:brocha ->Color=(Color::Gray); break;
		default:
			break;
		}
	}
	void graficar(Graphics^ gr)
	{
		gr->FillEllipse(brocha, Rectangle(x, y, 10,10));
	}

	void mover(Graphics^ gr)
	{
		x += dx;
		y += dy;
	}

	void GuardarJuego(std ::ofstream archivo)
	{
		//std::ofstream temp;
		archivo<< x << "," << y << std::endl;
		//archivo = &temp;
	}

	int getX() { return x; }
	int getY() { return y; }
	
};