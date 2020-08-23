#pragma once
#include "Entidad.h"
#include "Flecha.h"

enum Accion {
	CampoArriba, CampoIzquierda, CampoAbajo, CampoDerecha,
	CaminarArriba, CaminarIzquierda, CaminarAbajo, CaminarDerecha,
	DispararArriba, DispararIzquierda, DispararAbajo, DispararDerecha,
	Morir
};

class Jugador : public Entidad
{
private:
	Accion accion;
	Flechas* flechas;

	int x_campo, y_campo, r_campo;
	int vidas;
	int cant_escudo;

public:
	Jugador()
	{
		x = y = 200;
		dx = dy = 0;
		ancho = alto = 0;
		IDx = 0;
		x_campo = y_campo = r_campo = 0;
		accion = CaminarAbajo;
		flechas = new Flechas();
		cant_escudo = 3;
		vidas = 10;
	}
	~Jugador()
	{
		delete flechas;
	}

	Accion GetAccion()
	{
		return accion;
	}
	void SetAccion(Accion n)
	{
		accion = n;
	}

	int GetCantEscudo()
	{
		return cant_escudo;
	}
	void SetCantEscudo(int n)
	{
		cant_escudo += n;
	}

	Flechas* GetFlechas()
	{
		return flechas;
	}

	int GetVidas()
	{
		return vidas;
	}
	void SetVidas(int n)
	{
		vidas += n;
	}

	void Disparar()
	{
		int dx = 0, dy = 0;
		if (accion == DispararArriba)
			dy = -15;
		else if (accion == DispararAbajo)
			dy = 15;
		else if (accion == DispararIzquierda)
			dx = -15;
		else if (accion == DispararDerecha)
			dx = 15;

		Flecha* F = new Flecha(x + ancho / 2, y + alto / 2, dx, dy);
		flechas->AgregarElemento(F);
	}
	Rectangle Campo()
	{
		return Rectangle(x_campo - r_campo, y_campo - r_campo, 2 * r_campo, 2 * r_campo);
	}

	void Mover(Graphics^ g)
	{
		if (x + dx >= 0 && x + ancho + dx < g->VisibleClipBounds.Width)
			x += dx;
		if (y + dy >= 0 && y + alto + dy < g->VisibleClipBounds.Height)
			y += dy;

		flechas->Mover(g);
	}
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		flechas->Mostrar(g);

		ancho = img->Width / 13;
		alto = img->Height / 13;

		Rectangle corte = Rectangle(IDx * ancho, accion * alto, ancho, alto);

		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);


		if (accion == CampoAbajo || accion == CampoArriba || accion == CampoIzquierda || accion == CampoDerecha)
		{
			IDx = (IDx + 1) % 7;
			if (IDx == 0)
			{
				if (accion == CampoAbajo)
					accion = CaminarAbajo;
				else if (accion == CampoArriba)
					accion = CaminarArriba;
				else if (accion == CampoIzquierda)
					accion = CaminarIzquierda;
				else if (accion == CampoDerecha)
					accion = CaminarDerecha;
			}

			x_campo = this->x + ancho / 2;
			y_campo = this->y + alto / 2;

			r_campo = IDx * 10;
			Pen^ p = gcnew Pen(Color::Blue, 3);
			g->DrawEllipse(p, Campo());
		}
		if (accion == CaminarAbajo || accion == CaminarArriba || accion == CaminarIzquierda || accion == CaminarDerecha)
		{
			IDx = (IDx + 1) % 9;
			if (dx == 0 && dy == 0)
				IDx = 0;
		}

		if (accion == DispararAbajo || accion == DispararArriba || accion == DispararIzquierda || accion == DispararDerecha)
		{
			IDx = (IDx + 1) % 13;
			if (IDx == 0)
			{
				if (accion == DispararAbajo)
					accion = CaminarAbajo;
				else if (accion == DispararArriba)
					accion = CaminarArriba;
				else if (accion == DispararIzquierda)
					accion = CaminarIzquierda;
				else if (accion == DispararDerecha)
					accion = CaminarDerecha;
			}
		}
		if (accion == Morir)
		{
			IDx = (IDx + 1) % 6;
		}
	}
};