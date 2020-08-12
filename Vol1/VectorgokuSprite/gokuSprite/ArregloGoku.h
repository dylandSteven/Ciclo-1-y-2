#pragma once
#include"CJugador.h"
#include<vector>
using namespace std;

class CArregloGoku 
{

private:
	int num;
	vector<CJugador*>arregloene;

public:

	CArregloGoku() {
		num = 0;
		arregloene = vector<CJugador*>();
	}
	~CArregloGoku() {}

	void agregar() {

		CJugador* nuevo = new CJugador();
		arregloene.push_back(nuevo);
	}

	void dibujar(BufferedGraphics^ buffer, Bitmap^ bmpenemigo, int x , int y)
	{
		for (int i = 0; i < num; i++)
			arregloene.at(i)->dibujar(buffer, bmpenemigo,x,y);
		num++;
	}
	void mover(BufferedGraphics^ buffer, Bitmap^ bmpenemigo,int x2,int y2) {
	
		for (int i = 0; i < num; i++) {
			arregloene.at(i)->mover(buffer, bmpenemigo,x2,y2);
		}
	}
	vector<CJugador*>getGoku(){
		return arregloene; 
	}

};