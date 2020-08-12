#pragma once
#include"Empleado.h"

class Profesores :public Empleado
{
private:
	
	string departamento;
public:
	Profesores(string _nombre, string apellido, int dni, char _estado, string _departamento, int anho, short numeroDespavhO) :Empleado(_nombre, apellido, dni, _estado, anho, numeroDespavhO)
	{
		departamento = _departamento;
	}
	void csambiarDEpartamento(string _departamento) {
		departamento = _departamento;
	}

	int calcularSueldo(int horas) {
		int sueldo = 30;
		horas= horas* sueldo;
		return horas;
	}
	string info() {
		string aux;
		aux.append(imptrimirDatos());
		aux.append("Departamento: ");
		aux.append(departamento);
		return aux;
	}
};