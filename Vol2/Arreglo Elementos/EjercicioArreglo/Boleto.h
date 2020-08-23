#pragma once
#include"Fecha.h"
#include<ctime>
#include<cstdlib>
#include<vector>
class Boleto {

private:
	Fecha fecha;
	long codigo;
	double precio;
public:
	
	Boleto() {
	
		codigo = rand() % 9543142;
		precio = rand() % 1000;
	}
	~Boleto() {}
	
	int getdia() { return fecha.getdia(); }
	int getmes() { return fecha.getmes(); }
	int getanho() { return fecha.getanho(); }
	
	void getInfoBoleto()
	{
		cout << "Boleto" << endl;
		cout << "Codigo: " << codigo<<endl;
		cout << "Precio: " <<precio<< endl;
		cout << "Fecha: " << fecha.toString() << endl;
	}
};