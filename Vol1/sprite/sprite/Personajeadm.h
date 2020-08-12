#pragma once
#include<cstdlib>
#include<ctime>
using namespace System::Drawing;
using namespace System::Windows;
using namespace System::Windows::Forms;
ref class PersonajeADM {
private:
	int anchoSprite;
	int altoSprite;
	int anchoImagen, altoImagen;
	int dx, dy;
	int filas, columnas;
	bool pulsado;
	int velocidadx;
	int velocidady;
	int idFilas;
	int idColumnas;
	int x, y;
	int nro;
	Graphics^ canvas;
	Bitmap^ bmp;

	
public:
	PersonajeADM(Graphics^ canvas, int x, int y,int n) {
		this->canvas = canvas;
		bmp = gcnew Bitmap("Personaje1.png");
		anchoSprite = bmp->Width;
		altoSprite = bmp->Height;
		nro = n;
		anchoImagen = anchoSprite/ 4;
		altoImagen = altoSprite / 4;
		idColumnas = idFilas= 0;
		this->x = x;
		this->y = y;
		dx = 1; dy = 1;
		velocidadx = 1;
	
	}
	void dibujar() 
	{
		//canvas->Clear(SystemColors::Control);
		Rectangle areaVisible = Rectangle(anchoImagen * idColumnas, altoImagen * idFilas, anchoImagen, altoImagen);
	//	Rectangle aVisible();
	canvas->DrawImage(bmp, x, y, areaVisible, GraphicsUnit::Pixel);
		canvas->DrawString(nro + "",gcnew Font("Arial", 16), Brushes::Red, x,y);
	idColumnas++;
	if (idColumnas > 3)idColumnas = 0;

	}

	void mover(System::Windows::Forms::KeyEventArgs^tecla)
	{
		switch (tecla->KeyCode)
		{
		case Keys::Up:
			dy--;
			idFilas = 3;
			break;

		case Keys::Down:
			dy++; idFilas = 0;
			break;

		case Keys::Right:
			x += dx; idFilas = 2;
			break;

		case Keys::Left:
			dx -= x; idFilas = 1;
			break;
		default:
			break;
		}
	}

	bool colision(Rectangle r1, Rectangle r2)
	{
		return (r1.X + r1.Width && r2.X + r2.Width < r1.X&& r1.Y + r1.Height < r2.Y&& r2.Y + r2.Height < r1.Y);
	}

	void moverAutomatico()
	{
		x += (rand()%2==0)?(-1)*(rand()%20):rand()%20;
	
	}
	//Rectangle seccion() {

		//return Rectangle(x,y )
	//}







};