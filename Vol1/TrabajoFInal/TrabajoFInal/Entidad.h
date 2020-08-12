#pragma once
using namespace System::Drawing;
using namespace System;

enum  Direcciones { Abajo, Izquierda, Derecha, Arriba };

class Entidad {

protected:
	int x, y, alto, ancho, dx, dy, indiceX, indiceY;
	float escala;

public:

	int GetX()
	{
		return x;
	}

	int GetY()
	{
		return y;
	}


	int GetDX()
	{
		return dx;
	}


	int GetDY()
	{
		return dy;
	}

	int GetAlto()
	{
		return alto;
	}

	int GetAncho()
	{
		return ancho;
	}

	int GetindiceX() 
	{
		return indiceX; 
	}

	int GetindiceY() 
	{
		return indiceY; 
	}

	void  SetX(int valor)
	{
		x=valor;
	}

	void  SetY(int valor)
	{
		y=valor;
	}


	void  SetDX(int valor)
	{
		dx=valor;
	}


	void  SetDY(int valor)
	{
		dy=valor;
	}

	void  SetAlto(int valor)
	{
		alto=valor;
	}

	void  SetAncho(int valor)
	{
		ancho=valor;
	}

	void  SetindiceX(int valor)
	{
		 indiceX=valor;
	}

	void SetindiceY(int valor)
	{
		indiceY=valor;
	}

	Rectangle AreaVisible()
	{
		return Rectangle(ancho * indiceX, alto * indiceY, ancho, alto);
	}

	Rectangle Zoom()
	{
		return Rectangle(x, y, ancho * escala, alto * escala);
	}

	virtual void Mover(Graphics^ g) {
		x += dx;
		y += dy;
	}


	bool colision(Entidad* num1, Entidad* num2)
	{
		if(num1->Zoom().IntersectsWith(num2->Zoom()))
		{
			return true;
		}

		return false;
	}

 virtual void Mostrar(Graphics^ g, Bitmap^ img)
	{
		g->FillRectangle(Brushes::Black,Zoom());
	}
	//virtual void Dibujar(Graphics^ g, Bitmap ^bmp) {
	////	g->DrawImage(bmp, Zoom(), AreaVisible(), GraphicsUnit::Pixel);
	//}

};