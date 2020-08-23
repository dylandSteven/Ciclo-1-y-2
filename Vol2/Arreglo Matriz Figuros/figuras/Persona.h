#pragma once
using namespace std;
#include"VehiculoAereo.h"
class Persona:public VehiculoAereo {

private:

	void inciializarMatriz(int , int);
public:

	Persona(int ,int );
	~Persona();

};

Persona::Persona(int _filas, int _columnas) :VehiculoAereo(_filas, _columnas)
{}
Persona::~Persona() {}

void Persona::inciializarMatriz(int _filas, int _columnas) {
	
	char figPersona[3][3]{
			{' ','o',' '},
			{'-','|','-'},
			{'/',' ','l'}};

	char **figura;

	figura = new char*[_filas];

	for (int k = 0; k <_filas; k++) {
		figura[k]=new char[_columnas];
	}

	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {

			figura[i][j] = figPersona[i][j];

		}
	}
	setFigura(figura);

}