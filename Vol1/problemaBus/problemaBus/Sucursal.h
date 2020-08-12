#pragma once
#include<string>
#include<time.h>
#include<iostream>
#include<random>
#include"combustible.h"
#include"Surtidor.h"

using namespace std;

class Sucursal {

	Surtidor *nueSurtidor;
	Combustible *nueocomb;
	int  numero;

public:

	Sucursal() {
		srand(time(NULL));
		numero =rand() % 4+1;
	}
	~Sucursal() {}

	void Añadirclases(Surtidor *nueSurtidor, Combustible *nueoComb) {
		this->nueSurtidor = nueSurtidor;
		this->nueocomb = nueoComb;
	}
	void eliminarClases() {
		nueSurtidor = nullptr;
		nueocomb = nullptr;
	
	}
	string MOstrarResultados() {
		string aux;
		aux.append("Numero de Sucursal: ");
		aux.append(to_string(numero));
		aux.append("\n");
		aux.append("Numero de surtidor: ");
		aux.append(to_string(nueSurtidor->getNumero()));
		aux.append("\n");
		aux.append("Nombre de Combustible: ");
		aux.append(nueocomb->getNombre());
		aux.append("\n");
		aux.append("Precio: ");
		aux.append(to_string(nueocomb->getPrecio()));

		return aux;
	}



};