#pragma once
#include "Entidad.h"
class Enemigos
{
private:
	Entidad** arreglo;
	int cant;
public:
	Enemigos()
	{
		cant = 0;
	}
	~Enemigos()
	{
		for (int i = 0; i < cant; i++)
			delete arreglo[i];
		delete[] arreglo;
	}

	void AgregarElemento(Entidad* nuevo)
	{
		Entidad** aux = new Entidad *[cant + 1];

		for (int i = 0; i < cant; i++)
			aux[i] = arreglo[i];

		aux[cant] = nuevo;

		cant++;
		arreglo = aux;
	}
	void EliminarElemento(Entidad* eliminado)
	{
		Entidad** aux = new Entidad *[cant - 1];
		int i;
		for (i = 0; arreglo[i] != eliminado; i++)
			aux[i] = arreglo[i];

		for (int j = i; j < cant - 1; j++)
			aux[j] = arreglo[j + 1];

		delete eliminado;
		cant--;
		arreglo = aux;
	}
	void EliminarElemento(int pos)
	{
		Entidad** aux = new Entidad *[cant - 1];

		for (int i = 0; i < pos; i++)
			aux[i] = arreglo[i];

		for (int j = pos; j < cant - 1; j++)
			aux[j] = arreglo[j + 1];

		delete arreglo[pos];
		cant--;
		arreglo = aux;
	}

	Entidad* Get(int pos)
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
			arreglo[i]->Mover(g);
	}
	void Mostrar(Graphics^ g)
	{
		for (int i = 0; i < cant; i++)
			arreglo[i]->Mostrar(g, nullptr);
	}
};