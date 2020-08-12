#pragma once
using namespace System::Drawing;

enum  Direcciones {Arriba ,Abajo ,Izquierda ,Derecha,Ninguna};

class CJugador
{
private:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int indiceX, indiceY;
	int vidas;
	int acelerar;
	Direcciones direccion;
	Direcciones ultima;

	Rectangle CDI;
	Rectangle CAA;

public:
	CJugador(int X, int Y) {
		x = X;
		y = Y;
		//MOvimiento Del jugador
	//Bitmap^ avatar=gcnew Bitmap("Jugador.png");
		acelerar = 0;
		dx = 0;
		dy = 0;
		ancho = 18;
		alto = 26;
		indiceX = 0;
		indiceY = 0;
		direccion = Direcciones::Ninguna;
		ultima = Direcciones::Abajo;
		vidas = 5;
		
	}
	~CJugador() {}
	void setAcelerar(int valor) { acelerar = valor; }
	int getAcelerar() { return acelerar; }
	int getX() { return x + 2 * 3; }
	int getY() { return y + 15 * 3 + dy; }
	void setDX(int dx) { this->dx = dx; }
	void setDY(int dy) { this->dy = dy; }
	void setDireccion(Direcciones direccion)
	{
		this->direccion = direccion;

	}
	Direcciones getDireccion() { return direccion; }
	Rectangle retornarRectangle()
	{
		return Rectangle(x + 2 * 3 + dx, y + 15 * 3, (ancho - 4) * 3, (alto - 15) * 3);

	}
	void ValidarMovimiento(int** matriz)
	{
		int X, Y = 0;
		for (int i = 0; i < 15; i++) {

			X = 0;
			for (int j = 0; j < 17; j++) {
				Rectangle c1 = Rectangle(X, Y, 50, 50);

				if (matriz[i][j] == 1 || matriz[i][j] == 3)
				{
					if (CDI.IntersectsWith(c1)) { dx = 0; }
					if (CAA.IntersectsWith(c1)) { dy = 0; }

				}
				X += 50;
			}
			Y += 50;
		}
	}

	void disminuirVidas() {

		x = 50;
		y = 50;
		vidas--;

	}
	void disminuirVidas(int puntaIzquierda, int puntaDerecha, int centroInicioY, int centrolFinalY,
		int PuntaSuperior, int PuntaInferior, int CentroInicioX, int CentrofinalX)
	{
		if (getX() >= puntaIzquierda && getX() <= puntaDerecha && getY() >= centroInicioY && getY() <= centrolFinalY)
		{
			x = 50;
			y = 50;
			vidas--;
		}
		if (getY() >= PuntaSuperior && getY() <= PuntaInferior && getX() >= CentroInicioX && getX() <= CentrofinalX)
		{
			x = 50;
			y = 50;
			vidas--;

		}



	}
	void setVidas(int nuevaVida) { vidas = nuevaVida; }
	int getVidas() { return vidas; }

	void dibujarJugador(Graphics^ g, Bitmap^ bmp,int **matriz)
	{
		CDI = Rectangle(x + 2 * 3 + dx, y + 15 * 3, (ancho - 4) * 3, (alto - 15) * 3);
		g->DrawRectangle(Pens::Transparent, CDI);
		CAA = Rectangle(x + 2 * 3, y + 15 * 3 + dy, (ancho - 4) * 3, (alto - 15) * 3);
		g->DrawRectangle(Pens::Transparent, CAA);


		ValidarMovimiento(matriz);

		Rectangle PorcionAUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle Aumento = Rectangle(x, y, ancho * 3, alto * 3);

		g->DrawImage(bmp, Aumento, PorcionAUsar, GraphicsUnit::Pixel);

	
		
		x += dx;
		y += dy;
	
	}
	void moverJugador(Graphics^ g, Bitmap^ bmpJugador, int **matriz)
	{
		//direccion == Arriba?ancho=17:ancho=18;

		switch (direccion)
		{
		case Direcciones:: Arriba:
				indiceY = 0;
				if (indiceX >= 1 && indiceX < 3)
					indiceX++;
				else
					indiceX = 1;
				dx = 0;
				dy = -10-acelerar;
				ultima = Arriba;

				break;

		case Direcciones:: Abajo:
			indiceX = 0;
			if (indiceY >=1  && indiceY < 3)
				indiceY++;
			else
				indiceY = 1;
			dx = 0;
			dy = +10+acelerar;
			ultima = Abajo;

			break;

		case Direcciones ::Izquierda:
			indiceY = 3;
			if (indiceX >= 1 && indiceX < 3)
				indiceX++;
			else
				indiceX = 1;
			dx = -10-acelerar;
			dy = 0;
			ultima = Izquierda;

			break;


		case Direcciones ::Derecha:
			indiceY = 1;
			if (indiceX >= 1 && indiceX < 3)
				indiceX++;
			else
				indiceX = 1;
			dx = 10+acelerar;
			dy = 0;
			ultima = Derecha;
			break;
		case Direcciones ::Ninguna:
			dx = dy = 0;
			if (ultima == Direcciones::Abajo) {
				indiceX = 0; indiceY = 2;
			}

			if (ultima == Direcciones::Arriba) {
				indiceX = 0; indiceY = 0;
			}

			if (ultima == Direcciones::Derecha) {
				indiceX = 1; indiceY = 1;
			}

			if (ultima == Direcciones::Izquierda) {
				indiceX = 1; indiceY = 3;
			}
			break;

		default:
			break;
		}



		dibujarJugador(g, bmpJugador,matriz);
	}
	

};