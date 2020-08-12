#pragma once
#include"Empleado.h"
class Secretario :public Empleado {

private:
	int numeroOficina;
	int faxNUmber;

public:
	Secretario() {}
	Secretario(string _nombre, string _apellido, int _dni, string _direccion, double _salario, int _telefono):
		Empleado(_nombre, _apellido,  _dni, _direccion, _salario,  _telefono)
	{
		numeroOficina = rand() % 101;
		faxNUmber = 1000 + rand() % 101;
		incremento = 5;
	}
	~Secretario() {}

	void getSecretarioInfo() {
	
		infoEmpleado();
		cout << "Numero de oficina: "<<numeroOficina<<endl;
		cout << "Numero de Fax: " << faxNUmber<<endl;
	}

	void getSupirvisorInfo()
	{
		supervisor->infoEmpleado();
	}
};