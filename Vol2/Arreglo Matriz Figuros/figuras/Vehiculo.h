#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
using namespace System;
class Vehiculo
{
public:
	Vehiculo(int, int);
	void AsignarCoordenadaXY();
	void mostrarFigura();
	void MoverFigura();
	void Borrar();
	void setFigura(char **);
	~Vehiculo();

private:
	int x, y;
	int dir;
	int filas;
	int columnas;
	char** figVehiculo;
	void liberarMatriz();
	/*char figVehiculo[5][29] = {

	   {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','~','(','@','/',' ',' ',' ','/',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	   {' ',' ','_','_','_','_','_','_','_','_','_',']','_','[','_','_','/','_','>','_','_','_','_','_','_','_','_',' ',' '},
	   { ' ','/',' ',' ','_','_','_','_',' ','/',' ','<','>',' ',' ',' ',' ',' ','|',' ',' ','_','_','_','_',' ',' ','/',' '},
	   {'=','/','_','/',' ','_','_',' ','/','_','/','_','_','_','_','_','_','_','|','_','/',' ','_','_',' ','/','_','_',' '},
	   {' ',' ',' ',' ','(','_','_',')',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','(','_','_',')',' ',' ',' ',' '} };*/
};

Vehiculo::Vehiculo(int _filas, int _columnas)
{
	dir = 1;
	filas = _filas;
	columnas = _columnas;
}

Vehiculo::~Vehiculo(void)
{
	liberarMatriz();
}

void Vehiculo::setFigura(char **_figura)
{
	figVehiculo = _figura;
}

void Vehiculo::AsignarCoordenadaXY() {
	srand(time(NULL));
	x = 2 + rand()%70;
	y = 2 + rand()%20;
}
void Vehiculo::mostrarFigura() {

	int auxY = y;
	for (int i = 0; i < filas; i++) {
		Console::SetCursorPosition(x, auxY);
		for (int j = 0; j < columnas; j++)
		{
			if (figVehiculo[i][j] == ' ') {
				cout << " ";
			}
			else 
				cout << figVehiculo[i][j];
		}
			auxY++;
		
	}

}
void Vehiculo::MoverFigura() {

	if (x + dir < 0 || x + dir>79) 
		dir = dir * -1;
		x += dir;
}
void Vehiculo::Borrar() {

	int auxY = y;
	for (int i = 0; i < filas; i++) {
		Console::SetCursorPosition(x, auxY);
		for (int j = 0; j < columnas; j++) {
			cout << " ";		
		}
		auxY++;
	}
}
void Vehiculo::liberarMatriz() {
	for (int i = 0; i < filas; i++) 
		delete[] figVehiculo[i];
		delete[] figVehiculo;
}