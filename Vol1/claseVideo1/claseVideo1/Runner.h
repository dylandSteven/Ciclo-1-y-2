#pragma once
#include<iostream>
using namespace std;
using namespace System ::Drawing;
class Runner {
private:

	double X;
	double Y;
	double ancho;
	double alto;

	int indiceX;
	int indiceY;
	double velocidad;

	bool direccion;

public:

	Runner(double x, double y, int direccion) {

		X = x;
		Y = y;
		this->direccion = direccion;

		velocidad = 10;
		ancho = 50;
		alto = 50;
		if (this->direccion) 
		{
			this->indiceX = 0;
			this->indiceY = 0;
		}
		else
		{
			this->indiceX = 3;
			this->indiceY = 3;

		}
		printInfo();
	}
	Runner() 
	{
		this->X = 0;
		this->Y = 0;
		this->indiceX = 0;
		this->indiceY = 0;
		velocidad = 20;
		ancho = 50;
		alto = 50;
		printInfo();
	
	
	}

	~Runner() {};

	void printInfo() {
	
		cout << "X->" << X << endl;
		cout << "Y->" << Y << endl;
		cout << "IndiceX->" << indiceX << endl;
		cout << "IndiceY->" << indiceY << endl;
		cout << "alto->" << alto << endl;
		cout << "aancho->" << ancho << endl;
		cout << "velocidad->" << velocidad << endl;
		cout << endl;
	
	
	}

	bool getDireccion() { return direccion; }
	double getX() { return X; }
	double getY() { return Y; }
	double getAlto() { return alto; }
	void dibujar(BufferedGraphics^ buffer, Bitmap^ bmp) {
		Rectangle porciooUso = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle aumento = Rectangle(X, Y, ancho, alto);
		buffer->Graphics->DrawImage(bmp, aumento, porciooUso, GraphicsUnit::Pixel);

	
	}

	void mover(BufferedGraphics^ buffer, Bitmap^ bmp) {
	
		if (direccion)
		{
			X = X + velocidad;
			if (indiceX < 3)
				indiceX++;
			else {
				indiceY++;
				indiceX = 0;
			}
			if (indiceX == 3 && indiceY == 3) {
				indiceX = indiceY = 0;
			}
		
		}
		printInfo();
		dibujar(buffer, bmp);
	
	}



};