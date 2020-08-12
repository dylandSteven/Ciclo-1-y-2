#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"Sintomas.h"
#include "TipoVIrus.h"
using namespace std;


class Paciente {
private:
	short valor;
	short  contador;
	Virus nuevoVirus;
	string nombre;
	short edad;
		

public:
	Paciente() {}
	Paciente(string _nombre,short _edad) {
		nombre = _nombre;
		edad = _edad;
		
		valor = 1;
	}

	void setNombre(string _nombre) { nombre = _nombre; }
	void setEdad(short _edad) { edad = _edad; }

	string getNombre() { return nombre; }
	short getEdad() { return edad; }


	void VerificarSintomas() {
		char n1, n2, n3;
		cout << "¿Tiene fiebre ?"; cin >> n1;
		cout << "¿Tiene tos ?"; cin >> n2;
		cout << "¿Tiene  disnea "; cin >> n3;
		cout << endl;
		
		if (n1 == 'S' && n2 == 'S' && n3 == 'S') {
			contador=1;
		}
		else {
			contador = 0;
		}
	}

	short getContador() { return contador; }

};