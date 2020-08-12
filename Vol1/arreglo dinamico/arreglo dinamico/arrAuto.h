#pragma once
#include "auto.h"

class ArregloAuto
{
public:
	ArregloAuto() {
		arreglo = new Carro * [100];
		indice = -1;
	}
	~ArregloAuto();

	void registrar(Carro* nuevoRegistro) {
		indice++;
		arreglo[indice] = nuevoRegistro;
	}
	void elimnar() {
		for (int i = 0; i <= indice; i++) {
			arreglo[i] = arreglo[i + 1];
		}
		indice--;
	}
	Carro* devolver(int pos) {
		return arreglo[pos];
	}

	int longitud() {
		return indice;
	}
	void eliminarPorAnhio(int anioeliminar) {
		for (int i = 0; i <= indice; i++)
		{
			if (arreglo[i]->getanho() == anioeliminar) {

				elimnarPorpos(i);
				i--;

			}
		}
	}
	void elimnarPorpos(int pos) {
		for (int i = pos; i <= indice; i++)
		{
			arreglo[i] = arreglo[i + 1];
		}
		indice--;
	}

	double promedio() {

		int cont = 0;
		double suma=0;

		for (int i = 0; i <= indice; i++)
		{
			suma = suma + arreglo[i]->getprecio();
			cont++;
		}
		return (suma/cont);
	}

	

private:
	Carro** arreglo;
	int indice;
};
