#pragma once
#include "Entidad.h"

class Mensaje : public Entidad
{
	int IDy;
public:
	Mensaje(int x, int y, int dx, int dy, int IDy)
	{
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		ancho = alto = 0;
		escala = 0.2f;
		this->IDy = IDy;
	}
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		ancho = img->Width / 2;
		alto = img->Height / 3;

		Rectangle corte = Rectangle(IDx * ancho, IDy * alto, ancho, alto);

		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);

		IDx = (IDx + 1) % 2;
	}
};

class Mensajes
{
private:
	Mensaje** arreglo;
	int cant;
public:
	Mensajes()
	{
		cant = 0;
	}
	~Mensajes()
	{
		for (int i = 0; i < cant; i++)
			delete arreglo[i];
		delete[] arreglo;
	}

	void AgregarMensaje(Mensaje* nuevo)
	{
		Mensaje** aux = new Mensaje *[cant + 1];

		for (int i = 0; i < cant; i++)
			aux[i] = arreglo[i];

		aux[cant] = nuevo;

		cant++;
		arreglo = aux;
	}
	void EliminarMensaje(Mensaje* eliminado)
	{
		Mensaje** aux = new Mensaje *[cant - 1];
		int i;
		for (i = 0; arreglo[i] != eliminado; i++)
			aux[i] = arreglo[i];

		for (int j = i; j < cant - 1; j++)
			aux[j] = arreglo[j + 1];

		delete eliminado;
		cant--;
		arreglo = aux;
	}
	void EliminarMensaje(int pos)
	{
		Mensaje** aux = new Mensaje *[cant - 1];

		for (int i = 0; i < pos; i++)
			aux[i] = arreglo[i];

		for (int j = pos; j < cant - 1; j++)
			aux[j] = arreglo[j + 1];

		delete arreglo[pos];
		cant--;
		arreglo = aux;
	}

	Mensaje* GetMensaje(int pos)
	{
		return arreglo[pos];
	}
	int GetCantidad()
	{
		return cant;
	}

	void Mover(Graphics^ g)
	{
		for (int i = 0; i < cant; i++)
		{
			Mensaje* msj = arreglo[i];
			if (msj->GetX() >= g->VisibleClipBounds.Width ||
				msj->GetX() + msj->GetAncho() < 0 ||
				msj->GetY() >= g->VisibleClipBounds.Height ||
				msj->GetY() + msj->GetAlto() < 0)
				EliminarMensaje(i--);
		}

		for (int i = 0; i < cant; i++)
			arreglo[i]->Mover(g);
	}
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		for (int i = 0; i < cant; i++)
			arreglo[i]->Mostrar(g, img);
	}
};