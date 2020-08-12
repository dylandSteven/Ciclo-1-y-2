#pragma once
#include<iostream>
#include"Persona.h"
#include"Profesores.h"
#include"Estudiantes.h"
#include"Empleado.h"
#include"PersonalServicios.h"
#include<vector>
using namespace std;
class CentroDocente {
private:
	vector<Profesores>* profesor;
	vector<Estudiantes>* Estudiante;
	vector<PersonalServicio>* personal;
	vector<Persona>* arrPersona;
	string _departamento; int anho; short numeroDespavhO;
	string nombre,seccion, apellido,curso;
	int dni;
	char estado;
public:

	CentroDocente() {
		profesor = new vector<Profesores>;
		Estudiante = new vector<Estudiantes>;
		personal = new vector<PersonalServicio>;
		arrPersona = new vector<Persona>;
	}

	~CentroDocente() {}


	void anhadirEstudiantes()
	{
			cout << "Nombre: "; cin >> nombre;
			cout << "Apellido: "; cin >> apellido;
			cout << "DNI: "; cin >> dni;
			cout << "Estado: "; cin >> estado;
			cout << "Curso: "; cin >> curso;
			Estudiantes estudi(nombre, apellido, dni, estado, curso);
			Estudiante[0].push_back(estudi);
			arrPersona[0].push_back(estudi);
	}


	void eliminarEstudiante(int pos) {
	
		for (int i = 0; i < Estudiante->size(); i++)
		{
			if (pos == i) {
				Estudiante->erase(Estudiante->begin() + i - 1);
			}
		}
	
	}


	void añadirPersonas() {
		short persona;
		do {
			cout << "Persona a añadir"; cin >> persona;
		} while (!(persona == 'P' || persona == 'E' || persona == 'S'));

		if ('P' == persona) {
			cout << "Nombre: "; cin >> nombre;
			cout << "Apellido: "; cin >> apellido;
			cout << "DNI: "; cin >> dni;
			cout << "Estado: "; cin >> estado;
			cout << "Departamento: "; cin >> _departamento;
			cout << "Año de integracion: "; cin >> anho;
			cout << "Numero de despacho: "; cin >> numeroDespavhO;
			Profesores ps(nombre, apellido, dni, estado, _departamento, anho, numeroDespavhO);
			profesor[0].push_back(ps);
			arrPersona[0].push_back(ps);
		}

		if ('S' == persona) 
		{
			cout << "Nombre: "; cin >> nombre;
			cout << "Apellido: "; cin >> apellido;
			cout << "DNI: "; cin >> dni;
			cout << "Estado: "; cin >> estado;
			cout << "Seccion: "; cin >> _departamento;
			cout << "Año de integracion: "; cin >> anho;
			cout << "Numero de despacho: "; cin >> numeroDespavhO;
			PersonalServicio Pers(nombre, apellido, dni, estado, anho, numeroDespavhO,seccion);
			personal[0].push_back(Pers);
			arrPersona[0].push_back(Pers);
		}	
		if ('E' == persona) {
			anhadirEstudiantes();
		}
		
	}

	void eliminarpersonaDNi(int dni) {
	
		for (int i = 0; i < arrPersona->size(); i++)
		{
			if (dni == arrPersona[0].at(i).getdni()) 
			{
				arrPersona[0].erase(arrPersona->begin() + i - 1);
			}
		}
	}




	void cambiarEstadoCivil() {
		char cambio;
		char opcion;
		cin >> opcion;
		if (opcion == 'E') {
			cin >> cambio;
			Estudiante[0].at(0).cambiarEstadoCivil(cambio);
		}
		
		if (opcion == 'S') {

			cin >> cambio;
			personal[0].at(0).cambiarEstadoCivil(cambio);
		}
		
		if (opcion == 'P') {

			cin >> cambio;
			profesor[0].at(0).cambiarEstadoCivil(cambio);
		}
	}
	
	
	
	
	
};