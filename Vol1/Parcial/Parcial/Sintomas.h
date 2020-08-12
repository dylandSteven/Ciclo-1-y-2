#pragma once
#include<string>
using namespace std;
#include<iostream>

class Sintomas {

private :
	string nombre;

public:
	Sintomas(string nombre) {
		this->nombre = nombre;
	}

	void setNombre(string _nombre) { nombre = _nombre; }
	string getNombre() { return nombre; }




};