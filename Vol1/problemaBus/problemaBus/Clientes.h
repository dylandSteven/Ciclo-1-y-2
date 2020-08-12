#pragma once
#include"Cliente.h"
#include<iostream>
#include<string>
#include<vector>
#include"Autoh.h"
using namespace std;
typedef unsigned long us;


class Clientes {
private:
	vector< Cliente*>arrcliente;
	vector<Auto*>nue;
public:

	Clientes() {}

	void agregarCliente() {

		string nombreaux;
		us dniaux;
		Cliente*nuevo; 
		cout << "Nombre: ";  cin >>nombreaux;
		cout << "DNI: ";       cin >> dniaux;
		nuevo =new Cliente(nombreaux, dniaux);

		//nuevo->datosAutos();

		arrcliente.push_back(nuevo);
	}

	void mostrarDatosCliente() {
		for (int i = 0; i <arrcliente.size(); i++) {
			cout<< endl;
			cout<<arrcliente[i]->getNombree();
			cout<<arrcliente[i]->getdni();
			//cout << "Placa: "<< nue[i]->getPlaca();
			//cout << "NUmero de galones: " << nue[i]->getCangalo();
		}
	}

};