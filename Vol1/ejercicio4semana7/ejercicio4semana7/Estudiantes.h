#pragma once
#include"Empleado.h"
class Estudiantes:public Persona {

private:

	string curso;
public:

	Estudiantes(string _nombre, string apellido, int dni, char _estado, string _curso) :Persona(_nombre, apellido, dni, _estado) {
		curso = _curso;
	}

	~Estudiantes() {}
	void matricularNUevoCurso(string _curso){
		curso = _curso;
	}
	void setCurso(string c) { curso = c; }
	string getCurso() { return curso; }

	string info() {
		string aux;
		aux.append(imptrimirDatos());
		aux.append("Curso: ");
		aux.append(curso);
		return aux;
	}



};