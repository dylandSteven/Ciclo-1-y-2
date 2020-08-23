#pragma once

#include"Usuarioh.h"
#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

class Arreglo {

public:

	
	Usuario* arreglo;
	string nombre;
	string Ticket;
	long codigo;
	char tipoCliente;
	short indice;
	Arreglo() {
	indice = 0;
	arreglo = new Usuario[100];
	};

	string clave(string Ticket)
	{
		char upper[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
		int numbers[] = { 0,1,2,3,4,5,6,7,8,9 };
		short nuppers = 0;
		short nnumbers = 0;
		short lenght = 6;
		string clave;
		srand(time(NULL));

		for (int i = 0; i < lenght / 2; i++) {
			//Ticket=upper[rand() % 26];
			Ticket.push_back(upper[rand() % 26]);
			Ticket = Ticket + to_string(numbers[rand() % 10]);
		}
		return Ticket;

	}
	void Registrar() {

		cout << "Ingrese su nombre: " << endl;
		cin >> nombre;
		cout << "Ingrese un codigo: " << endl;
		cin >> codigo;
		do {
			cout << "Ingrese tipo de cliente: " << endl;
			cin >> tipoCliente;
		} while (!(tipoCliente == 'V' || tipoCliente == 'S' || tipoCliente == 'NS'));
		arreglo[indice].setNombre(nombre);
		arreglo[indice].setCodigo(codigo);
		arreglo[indice].setTipoCliente(tipoCliente);
		arreglo[indice].setTicket(clave(Ticket));
		indice++;
	}



	void mostrar() {
		for (int i = 0; i< indice; i++) {

			cout << "Nombre: " <<arreglo[i].getNombre();
			cout << "Codigo: " <<arreglo[i].getCodigo();
			cout << "Tipo de Cliente: " << arreglo[i].getTipoCliente();
			cout << " Ticket: " << arreglo[i].getTicket()<< endl;

		}
	}
};