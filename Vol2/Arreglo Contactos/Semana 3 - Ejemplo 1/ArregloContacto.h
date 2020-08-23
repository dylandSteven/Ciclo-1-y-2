#pragma once
#include"Contacto.h"
class ArregloContacto {

private:
	Contacto** arregloContacto;
	short* N;

public:
	ArregloContacto();
	~ArregloContacto();

	void AgregarContacto(Contacto* dato);
	Contacto* getContacto(short indice);
	short getN();

};

ArregloContacto::ArregloContacto(void)
{
	arregloContacto = NULL;
	 N = new short;
	*N = 0;
}

ArregloContacto::~ArregloContacto(void)
{
	for (int i = 0; i < *N; i++) {
		delete arregloContacto[i];

	}
	delete N;
}

void ArregloContacto::AgregarContacto(Contacto* dato) {
	Contacto** aux;
	aux = new Contacto*[*N + 1];
	if (aux != NULL)
	{
		for (int i = 0; i < *N; i++) {
			aux[i] = arregloContacto[i];
		}
		aux[*N] = dato;
		*N = *N + 1;

		if (arregloContacto != NULL)
			delete arregloContacto;

		arregloContacto = aux;
	}
}
Contacto* ArregloContacto::getContacto(short indice)
{
	return arregloContacto[indice];
}


short ArregloContacto::getN()
{
	return *N;
}
