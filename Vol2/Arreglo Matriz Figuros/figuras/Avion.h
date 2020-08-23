#pragma once
#pragma once
#include"VehiculoAereo.h"

class Avion :public VehiculoAereo
{
public:
	Avion(int, int);
	~Avion();
private:
	void inicioMatrizAvion(int, int);
};

Avion::Avion(int _filas, int _columnas) :VehiculoAereo(_filas, _columnas)
{
	inicioMatrizAvion(_filas, _columnas);
}

Avion::~Avion()
{}

void Avion::inicioMatrizAvion(int filas, int columnas)
{
	char matrizEstatica[6][19] =
	{{'_','_',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{ '/',' ',' ','/',' ',' ',' ',' ',' ','_',' ','_',' ',' ',' ',' ',' ',' ',' ' },
	{ '/',' ','*',' ','*','/',' ','_','_','_','/',' ','/',' ','/',' ',' ',' ',' ' },
	{ 'X',' ','*',' ','#','#','#','#','#',' ','*',' ','+','^',' ','^','/','_','/' },
	{ ' ',' ',' ',' ','o','/','/',' ',' ','/',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ','/','_','_','/',' ',' ',' ',' ',' ',' ',' ',' ' }};

	char** figura;
	figura = new char* [filas];

	for (int k = 0; k < filas; k++)
		figura[k] = new char[columnas];

	for (int i = 0; i < 6; i++) {

		for (int j = 0; j < 19; j++) {

			figura[i][j] = matrizEstatica[i][j];
		}
		
	}
	setFigura(figura);
}