#pragma once
#include<string>
using namespace std;
class Persona {

	protected:
	int dni;
	char estado;
	string nombre, apellido;
public:
	Persona() {}
	Persona(string _nombre, string apellido, int dni,char _estado) {
		nombre = _nombre;
		this->apellido = apellido;
		this->dni = dni;
		estado = _estado;
	}
	~Persona() {}


	
	void cambiarEstadoCivil(char _estado) {
		estado = _estado;
	}
	int getdni(){ return dni; }
	

string imptrimirDatos() 
	{
	string aux;
	aux.append(nombre);
	aux.append(" -- ");
	aux.append(apellido);
	aux.append(" -- ");
	aux.append(to_string(dni));
	aux.append(" -- ");
	aux.append(to_string(estado));
	return aux;
	}



};