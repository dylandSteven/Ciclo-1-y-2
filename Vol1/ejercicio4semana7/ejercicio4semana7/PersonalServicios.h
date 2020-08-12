#pragma once
#include"Empleado.h"
class PersonalServicio :public Empleado{
private:
	string seccion;
public:

	PersonalServicio(string _nombre, string apellido, int dni, char estado, int anho, short numeroDespacho, string _seccion)
		:Empleado(_nombre, apellido, dni, estado, anho, numeroDespacho)
	{
		seccion = _seccion;
	}
	
	void transladoSeccion(string _servicio)
	{
		seccion = _servicio;
	}
	int calcularSueldo(int mes) {
		int sueldo = 850;
		mes =mes* sueldo;
		return mes;
	}

	string info() {
		string aux;
		aux.append(imptrimirDatos());
		aux.append("Seccion: ");
		aux.append(seccion);
		return aux;
	}

};