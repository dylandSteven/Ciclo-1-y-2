#pragma once
#include<string.h>
#include<time.h>
#include<iostream>
#include<random>
using namespace std;

string nombreCombustible[6] = { "Gasohol 90","Gasohol 95 ","Gasohol 97","Diesel Ultra","GLP","GNV"};

class Combustible{

protected:
	string nombre; 
	double precio;

public:

	Combustible() 
	{ nombre = nombreCombustible[rand()%6];
	}
	string getNombre() { return nombre; }

	double getPrecio() {
		
		if (getNombre() == "Gasohol 90") { precio = 9.82 ; }
		if (getNombre() == "Gasohol 95") { precio = 11.29 ; }
		if (getNombre() == "Gasohol 97") { precio = 12.89 ; }
		if (getNombre() == "Diesel Ultra") { precio = 9.36; }
		if (getNombre() == "GLP") { precio = 1.54 ; }
		if (getNombre() == "GNV") { precio = 1.57 ; }

		return precio;
	}



};
