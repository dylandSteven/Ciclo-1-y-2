#pragma once
#include"car.h"
#include"Secrteario.h"
#include"Vendedor.h"
#include"Empleado.h"

class JefeZona :public Empleado{

private:
	Auto nuevocar;
	Secretario nuevasecre;
	vector<Vendedor>*nuevoVendedor;
	double _salario;
	short incremento;
public:
	JefeZona(string _nombre, string _apellido, int _dni, string _direccion, double _salario, int _telefono)
		:Empleado(_nombre, _apellido, _dni, _direccion, _salario, _telefono)
	{
		nuevocar = Auto();
		nuevasecre ;
		incremento = 20;
		this->_salario = _salario;
	}
	

	~JefeZona() {}

	void incrementarSalario()
	{
		_salario += (_salario * incremento / 100);
	}
	
	void getInfo() {
		getPersonInfo();
	}
	void cambiarSecretaria(Secretario nu) {
		nuevasecre = nu;

	}

	void cambiaAuto(Auto pop) {
		nuevocar = pop;
	}





};