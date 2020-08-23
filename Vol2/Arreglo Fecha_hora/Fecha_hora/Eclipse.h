#pragma once
#include "Hora.h"
#include"Fecha.h"
#include<string>
#include <iostream>
using namespace std;

string Continentes[5] = { "America","Europa","Asia","Africa","Oceania" };
string Tipos[2] = { "Lunar","Solar" };
string Frases[2] = { "Si","No" };


class Eclipse {

private:
	string Tipo;
	Fecha fecha;
	Hora hora;
	string Sismo;
	string Lluvia;
	string Visibilidad;

public:

	Eclipse() {

		Tipo = Tipos[rand() % 2];
		fecha = Fecha();
		hora = Hora();
		Sismo = Frases[rand() % 2];
		Lluvia = Frases[rand() % 2];
		Visibilidad = Continentes[rand() % 5];
	}
	~Eclipse() {}
	//probar
	void setTipo(string v) { Tipo = v; }
	string getTipo() { return Tipo; }
	string getVisibilidad() { return Visibilidad; }
	string getSismo() { return Sismo; }
	Hora getHoora(){ return hora; }


	void MostrarInfo() {
		cout << "Tipo: " << Tipo << endl;
		cout << "Fecha: " << fecha.getFechaCompleta() << endl;
		cout << "Hora: " << hora.getHoraCompleta() << endl;
		cout << "Sismo: " << Sismo << endl;
		cout << "LLuvias: " << Lluvia << endl;
		cout << "Visibilidad: " << Visibilidad << endl << endl;
	}
};