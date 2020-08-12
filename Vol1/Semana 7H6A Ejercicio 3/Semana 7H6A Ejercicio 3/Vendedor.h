#pragma once

#include"Empleado.h"
#include"car.h"
#include<vector>
#include"Person.h"

using namespace std;
class Vendedor :public Empleado {

	Auto *nuevoAuto;
	vector<Persona>*nClientes;
	string areaVenta;
	int incrementoComisiones;
	double valorPorcentaje;


public:
	
	Vendedor(string _nombre, string _apellido, int _dni, string _direccion,
		double _salario, int _telefono,string _areaVenta )
		:Empleado( _nombre, _apellido, _dni,_direccion, _salario, _telefono)
	{
		nClientes = new vector<Persona>;
		incrementoComisiones = 10;
		nuevoAuto = nullptr;
	}

	void agregarAuto(Auto *nuevoAuto) {
		this->nuevoAuto= nuevoAuto ;

	
	}
	~Vendedor() {}
	void incrementarSalario()
	{
		salario = salario + (salario * incrementoComisiones / 100);
	}

	/*void CambiarCoche(Auto nuevo) {
		nuevoAuto = nuevo;
	}*/

	/*void getInfo() {
		infoEmpleado();
		cout << "Datos Auto: " << endl;
		nuevoAuto.mostrar();
	}*/

	void agregarCliente() {
		string _nombre; string _apellido; int _dni; string _direccion;
		cout << "Nombre: "; cin >> _nombre;
		cout << "Apellido: "; cin >> _apellido;
		cout << "DNI: "; cin >> _dni;
		cout << "Direccion: "; cin >> _direccion;
		Persona nueva(_nombre, _apellido,_dni,_direccion);
		nClientes[0].push_back(nueva);	
	}
	void eliminarCliente() {
		nClientes->pop_back();
	}



};