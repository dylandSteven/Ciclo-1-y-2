#pragma once
#include"Entidad.h"

class jugadorAmbulancia :public::Entidad{
private:
	Direcciones direccion;
	int puntos;
public:
	jugadorAmbulancia() {
		x = 10; y = 10;
		dx = 0; dy = 0;
		alto =0 ;
		ancho =0 ;
		direccion = Abajo;
		indiceX = 0;
		indiceY = 0;
		puntos=0;
	}


	void setPuntos(int valor) { puntos = valor; }
	int getPuntos() { return puntos; }

	void mover(Graphics ^g) {
		
			if (x + dx >= 0 && x + ancho + dx < g->VisibleClipBounds.Width)
				x += dx;
			if (y + dy >= 0 && y + alto + dy < g->VisibleClipBounds.Height)
				y += dy;
	
	}

	void dibujar(Graphics ^g , Bitmap ^bmp ) {

		if (direccion == Abajo) {	
		ancho = bmp->Width/4;
		alto = bmp->Height;
			
		Rectangle porcionAUsar = Rectangle( 3* ancho,  0* alto, ancho, alto);
		
		g->DrawImage(bmp, Zoom(), porcionAUsar, GraphicsUnit::Pixel);
		}

		if (direccion == Arriba) {
		

			ancho = bmp->Width / 4;
			alto = bmp->Height;

			Rectangle porcionAUsar = Rectangle(0 * ancho, 0 * alto, ancho, alto);
			g->DrawImage(bmp, Zoom(), porcionAUsar, GraphicsUnit::Pixel);
		}

		if (direccion == Izquierda) {
		

			ancho = bmp->Width ;
			alto = bmp->Height;
			Rectangle porcionAUsar = Rectangle(0*ancho, 0*alto, ancho, alto);
			g->DrawImage(bmp, Zoom(), porcionAUsar, GraphicsUnit::Pixel);
		}


		if (direccion == Derecha) {
			ancho = bmp->Width;
			alto = bmp->Height;
			Rectangle porcionAUsar = Rectangle(0* ancho, 0 * alto, ancho, alto);
			g->DrawImage(bmp, Zoom(), porcionAUsar, GraphicsUnit::Pixel);
		}
		
		
	}
	void setDireccion(Direcciones nueva) {

		direccion = nueva;
	}

	void moverJUgadorDX(int valor) { dx = valor; }
	void moverJUgadorDY(int valor) { dy = valor; }
};
