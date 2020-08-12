#pragma once
#include"Persona.h"
class Empleado : public Persona{


private:

	int anho;
	short numeroDespavhO;
public:

	Empleado(string _nombre, string apellido, int dni, char _estado, int _anho, short ndespacho) :Persona(_nombre, apellido, dni, _estado)
	{
		anho = _anho;
		numeroDespavhO = ndespacho;
	}
	~Empleado(){}



	int getAnho() {
		return anho;
	}

	short getNumeroDespacho() {
		return numeroDespavhO;
	}
	
	
	void setAnho(int aho) {
		anho = aho;
	}
	void reasignarDespacho(short _numerodespa)
	{
		numeroDespavhO = _numerodespa;
	}


	string info() {
		string aux;
		aux.append(imptrimirDatos());
		aux.append("Año: ");
		aux.append(to_string(anho));
		aux.append("\n");
		aux.append("Numero Despacho: ");
		aux.append(to_string(numeroDespavhO));
		return aux;
	}

};