#pragma once
#include"Figura.h"

class Circulo :public Figura {

private:
public:

	Circulo(int _x,int _y, int _diametro,int _color,int _despla,bool _visible, int _filas , int _columnas):
		Figura(_x,_y,_diametro,_color,_despla,_visible,_filas,_columnas) {
		incialirMatriz(_filas, _columnas);
	}

	
	

	void incialirMatriz(int filas, int columnas)
	{
		char  matriz[5][5] =
		  { {' ',' ','*',' ',' '},
			{' ','*','*','*',' '},
			{'*','*','*','*','*'},
			{' ','*','*','*',' '},
			{' ',' ','*',' ',' '}
		};



	   char** figura;
	   figura = new char* [filas];
	   for (int i = 0; i < filas; i++) {
		   figura[i] = new char[columnas];
	   }

	   for (int j = 0; j < filas; j++) {
		   for (int k = 0; k < columnas; k++)
		   {
			   figura[j][k] = matriz[j][k];
		   }
	   }
	   setFigura(figura);
	  
	}


};