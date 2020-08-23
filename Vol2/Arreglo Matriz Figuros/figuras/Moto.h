#pragma once
#include"VehiculoTerrestre.h"

class Moto:public VehiculoTerrestre
{
public:
	Moto(int , int);
	~Moto();
private:
	void inicioMatrizMoto(int, int);
};

Moto::Moto(int _filas, int _columnas):VehiculoTerrestre( _filas, _columnas)
{
	inicioMatrizMoto(_filas,_columnas);
}

Moto::~Moto()
{}

void Moto::inicioMatrizMoto(int filas, int columnas)
{
	char matrizEstatica[4][15] = {
	{' ',' ',' ',')','/',' ','_','_','_',' ',' ',' ',' ',' ',' '},
	{' ', '_', '_', '/', ' ', '(', '_', '_', '_', ')', ' ', ' ', ' ', ' ', ' '},
	{'/',' ','/','/',' ','/',' ','|','|',' ',' / ',' / ',' ',' ','/'},
	{'/','_','_','/',' ',' ',' ',' ',' ',' ',' ','/','_','_','/'}};

	char** figura;
	figura = new char* [filas];

	for (int k = 0; k < filas; k++)
		figura[k] = new char[columnas];

	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 15; j++) {

			figura[i][j]=matrizEstatica[i][j];
		}
	}
	setFigura(figura);
	
	
}