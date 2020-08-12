#pragma once
#include <string>
#include <iostream>

using namespace std;
class Persona {
private:

	string nombre; string apellido; int dni; string direccion;
public:
	//Persona() {}
	Persona(string _nombre, string _apellido, int _dni, string _direccion) {
		nombre = _nombre;
		apellido = _apellido;
		dni = _dni;
		direccion = _direccion;
	}
	~Persona() {}


	string getnombre(){ return nombre; }
	string getapellido() { return apellido; }
	int getdni() { return dni; }
	string getdireccion() { return direccion; }

	void getPersonInfo()
	{
		cout << "Nombre: "<<nombre<<endl;
		cout << "Apellido: " << apellido << endl;
		cout << "DNI: " << dni << endl;
		cout << "Direccion: " <<direccion<< endl;
	}




};