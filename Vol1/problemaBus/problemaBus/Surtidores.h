#pragma once

#include"Surtidor.h"
using namespace std;

class Surtidores {

private:
	Surtidor** arr;
	int cant;

public:
	Surtidores() {
		cant = 0;
		arr = new Surtidor*[cant];
	
	}
	~Surtidores() {
		for (int i = 0; i < cant; i++)
		{
			delete arr[i];
		}
		delete arr;
	}

	void agregarSurtidor(Surtidor *n)
	{
		Surtidor** aux = new Surtidor * [cant + 1];

		for (int i = 0; i < cant; i++)
		{
			aux[i] = arr[i];
		}

		aux[cant] = n;
		cant++;
		arr = aux;
	}
	int getCant() { return cant; }
};