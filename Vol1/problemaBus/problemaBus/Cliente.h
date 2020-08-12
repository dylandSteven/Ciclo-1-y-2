#pragma once
#include<iostream>
#include"Autoh.h"
#include<string>
#include<vector>
typedef unsigned long us;
using namespace std;


class Cliente {

private:
	string nombre;
	vector<Auto>nuevoAuto;
	us dni;
public:
	//Cliente() {}
	Cliente(string _nombre, us _dni){
		
		this->nombre = _nombre;
		this->dni = _dni;
	}
	~Cliente() {}
	void datosAutos() {
	   string auplaca;
		int cantaux;
		cout << "Escriba el codigo de la placa: "; cin >> auplaca;
		cout << "Escriba la cantidad de galones: "; cin >> cantaux;
		nuevoAuto.push_back(Auto(auplaca, cantaux));
	}
	string getNombree() { return nombre; }
	us getdni() { return dni; }

};