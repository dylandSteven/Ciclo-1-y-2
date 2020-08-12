#pragma once
#include<iostream>
using namespace std;
using namespace System;
class Figura {

protected:
	char** figura;
	int posx, posy;
	int diametro;
	int color;
	int DesplazamientoX;
	bool visible;

	int filas, columnas, dir;

public:
	Figura() {}
	Figura(int posx, int  posy,
		int diametro,
		int color,int DesplazamientoX,
		bool visible,int _filas ,int _columnas){
		filas = _filas;
		columnas = _columnas;
		this->posx = posx;
		this->posy = posy;
		this->DesplazamientoX = DesplazamientoX;
		dir = 1;
	}
	
	void setFigura(char **matriz ) {
		figura = matriz;
	}

	void dibujar() {
		
		for (int i = 0; i < filas; i++) {
			for (int j = 0; j < columnas; j++)
			{
			Console::SetCursorPosition(posx+j, posy+i);
				cout << figura[i][j];	
			}
		}
	
	
	}


	void eliminar(){
	for (int i = 0; i < filas; i++) {
			for (int j = 0; j < columnas; j++)
			{
			Console::SetCursorPosition(posx+j, posy+i);
				cout << " ";
			}
		}

	
	}
	void mover() {

		if (posx + dir == 0 || posx + filas + dir == 30) {
			dir *= -1;
		}
		posx += dir;

	
	}
	int getX() { return posx; }
	int getY() { return posy; }
	int getDiametro() { return diametro; }
	void setVisible() {}
	bool isVisible() { return visible; }



};