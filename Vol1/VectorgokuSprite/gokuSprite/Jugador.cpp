#include"CJugador.h"

CJugador::CJugador() {}
CJugador::~CJugador() {}

CJugador::CJugador(int x, int y) 
{
	this->x = x;
	this->y = y;
	dx = 0;
	dy = 0;

	ultimaTecla = Direcciones::Abajo;
	direccion = Direcciones::Ninguna;
	ancho = 25;
	alto = 39;

	indiceX = 0;
	indiceY = 0;

}

void CJugador::dibujar(BufferedGraphics^ buffer, Bitmap^ bmp, int x1 , int y1)
{
	Rectangle porcionAUSar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	Rectangle aumentoPersonaje = Rectangle(x1, y1, ancho * 3, alto * 3);
	buffer->Graphics->DrawImage(bmp, aumentoPersonaje, porcionAUSar, GraphicsUnit::Pixel);
	x += dx;
	y += dy;
}


void CJugador::mover(BufferedGraphics^ buffer, Bitmap^ bmp, int x2,int y2) 
{
	switch (direccion)
	{

	case Direcciones::Arriba:
		indiceX = 2;
	
		if (indiceY >= 0 && indiceY < 2)
			indiceY++;
		else
			indiceY = 0;
		dx = 0;
		dy =- 10;
		ultimaTecla = Arriba;
		break;

	case Direcciones ::Abajo:
		indiceX = 0;

		if (indiceY >= 0 && indiceY < 2)
			indiceY++;
		else
			indiceY = 0;
		dx = 0;
		dy = 10;
		ultimaTecla = Abajo;
		break;

	case Direcciones::Izquierda:
		indiceX = 1;

		if (indiceY >= 0 && indiceY < 2)
			indiceY++;
		else
			indiceY = 0;
		dx = -10;
		dy = 0;
		ultimaTecla = Izquierda;
		break;


	case Direcciones::Derecha:
		indiceX = 3;

		if (indiceY >= 0 && indiceY < 2)
			indiceY++;
		else
			indiceY = 0;
		dx = 10;
		dy = 0;
		ultimaTecla = Derecha;
		break;


	case Direcciones::Ninguna:
		
		dx = 0;
		dy = 0;
		switch (ultimaTecla)
		{
		case Direcciones::Abajo:
			indiceX = 0;
			indiceY = 0;
			break;
		case Direcciones::Arriba:
			indiceX = 2;
			indiceY = 0;
			break; 
		case Direcciones::Derecha:
			indiceX = 3;
			indiceY = 0;
			break;
		case Direcciones::Izquierda:
			indiceX = 1;
			indiceY = 0;
			break;
		
		}
		break;
		
	default:
		break;
	}
	dibujar(buffer,bmp,x2,y2 );
}