#pragma once
using namespace System::Windows;
using namespace System::Drawing;
#include<iostream>
class Personaje 
{
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
	
public:
	Personaje(int ws,int hs, int f, int c) 
	{
		anchoSprite = ws;
		altoSprite = hs;
		anchoImagen =anchoSprite / c;
		altoImagen = altoSprite / f;
		idFilas = idColumnas = dx=dy=0;
		velocidadx = velocidady = 10;
	}

	~Personaje() {}
	void graficar(Graphics ^lienzo,Image ^img)
	{
		Rectangle areaVisible=Rectangle(anchoImagen*idColumnas,altoImagen*idFilas,anchoImagen,altoImagen);
		lienzo->DrawImage(img, 0, 0, areaVisible, GraphicsUnit::Pixel);
		idColumnas++;
		if (idColumnas > 3)idColumnas = 0;
	}



	void moverR() { dx++; dx +=velocidadx; idFilas = 2; }

	void moverL() { dx--;idFilas = 1; }

	void moverU() { dy++;  idFilas = 3; }

	void moverD() { dy--;  idFilas = 0;}
	void acelerar() { velocidadx += 3; }
	/*void mover(char tipo ) 
	{
		tipo = toupper(tipo);
		switch (tipo)
		{
		case'L':


		default:
			break;
		}
		
	
	}*/
};