#pragma once
#include<string>
#include<iostream>
using namespace std;

class Auto {

private:
	string placa, marca , modelo;

public:
	Auto() {}
	Auto(string _placa, string _marca , string _modelo) {
		placa = _placa;
		marca = _marca;
		modelo = _modelo;
	}
	~Auto() {}

	void mostrar(){
		cout << "Placa: " << placa << endl;
		cout << "Marca: " << marca << endl;
		cout << "Modelo: " << modelo << endl;
	}
};