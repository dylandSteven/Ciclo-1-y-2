#pragma once
using namespace System::Drawing;
enum  Direcciones
{
	Ninguna , Abajo,Arriba, Izquierda , Derecha
};


class CJugador
{

private:
	int x;
	int y;
	int dx;
	int dy;

	int ancho;
	int alto;

	int indiceX;
	int indiceY;

	Direcciones ultimaTecla;


public:

	CJugador() ;
	~CJugador();
	Direcciones direccion;
	CJugador(int x, int y) ;
	void dibujar(BufferedGraphics^ buffer, Bitmap^ bmp, int x1, int y1);
	void mover(BufferedGraphics^ buffer, Bitmap^ bmp,int x2 , int y2);
};

