#pragma once
#include<string>
#include"Person.h"
using namespace std;
class Empleado :public Persona{

protected:
	double salario;
int telefono;
short anhoTrabajo;
double incremento;
Empleado* supervisor;
	
public:

	Empleado(string _nombre, string _apellido, int _dni, string _direccion, double _salario, int _telefono):
		Persona(_nombre, _apellido,_dni,_direccion)
	{
		telefono = _telefono;
		salario = _salario;
		anhoTrabajo = rand() % 20;
		supervisor = nullptr;
		incremento = NULL;
	}
	~Empleado(){}


	void infoEmpleado()
	{
		getPersonInfo();
		cout << "Años de trabajo: " << anhoTrabajo << endl;
		cout << "Telefono: " << telefono<<endl;
		cout << "Salario: " << salario << endl;
		cout << "Supervisor: " << supervisor;
	}

	void setSupervisor(Empleado *newSupervisor)
	{
		supervisor = supervisor;
	}

	void incrementarSalario()
	{
		salario = salario+(salario*incremento/100);
	}
};
