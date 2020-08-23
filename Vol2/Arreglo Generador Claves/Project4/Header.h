#pragma once
#include<iostream>
#include<string>
using namespace std;

class Contrasena {

private:

	short longitud;
	string contrasena;

public:

	Contrasena() {

		longitud = 10;
	}
	~Contrasena();

	Contrasena(short longitud) {
		this->longitud = longitud;
		GenerarContrasena();
	}
	void setLongitud(short longitud) { this->longitud = longitud;}

	short getLongitud() { return longitud; }

	string getContrasena() { return contrasena; }


	void GenerarContrasena() {

		contrasena = "";

		for (short i = 0; i < longitud; i++) { 
			contrasena += generarCaracter();
		}
	}

	char generarCaracter() {

		if (rand() % 2) {

			return (char)(48 + rand() % 10);
		}
		else
		{
			if (rand() % 2) {
				return (char)(65 + rand() % 26);
			}
			else
			{
				return(char)(97 + rand() % 26);
			}
		}
	}

	bool isSafe() {
		short min;
		short mayus;
		short num;

		for (short i = 0; i < longitud; i++) 
		{
			if (contrasena[i] >= '0' && contrasena[i] <= '9') { num++; }
			else if (contrasena[i] >= 'A' && contrasena[i] <= 'Z') { mayus++; }
			else if (contrasena[i] >= 'a' && contrasena[i] <= 'z') { min++; }
		}
		return (mayus > 2 && min > 1 && num > 5);
	}




}; 