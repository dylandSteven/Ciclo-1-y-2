#pragma once
#include<iostream>
#include<string>
using namespace std;

string Continentes[5] = { "America del Sur","Europa","Africa","America del Norte", "Asia" };
string Estilos[4] = { "Vintage","Barroco","Moderno","Simple" };
string Nombres[3] = { "Marriot","Wisen","Clausem" };

class Hotel
{
protected:
	string nombre;
	string ubicacion;
	string estilo;

public:

	Hotel() {
		nombre = Nombres[rand() % 3];
		estilo = Estilos[rand() % 4];
		ubicacion = Continentes[rand() % 5];
	}
	~Hotel() {}

	string getUbicaion() { return ubicacion; }
	string getEstilo() { return estilo;}
	string getNombre() { return nombre; }

	void getInfoHotel() {

		cout << "Hotel" << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "Ubicacion: " << ubicacion << endl;
		cout << "Estilo: " << estilo << endl << endl;
	}

};