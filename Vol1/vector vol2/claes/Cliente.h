#pragma once

#include <string>
using namespace std;

class Cliente {
private:
	string nombre;
	short edad;
public:
	Cliente(string _nombre, short _edad) 
	{
		nombre = _nombre;
		edad = _edad;
	}

	~Cliente() {}
	string mostrar() {
		string aux;

		aux.append(nombre);
		aux.append(to_string(edad));
		return aux;
	}
};


