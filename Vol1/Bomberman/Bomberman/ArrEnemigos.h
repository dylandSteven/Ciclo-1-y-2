#pragma once
#include<vector>
#include"Enemigo.h"
using namespace std;


class CArrEnemigos
{
private:
	vector<CEnemigo*>arrEnemigo;

public:
	CArrEnemigos() {
	
		arrEnemigo = vector <CEnemigo*>();
	
	}
	~CArrEnemigos() {}
	void crearEnemigo()
	{
		CEnemigo* nuevo = new CEnemigo();
		arrEnemigo.push_back(nuevo);
	
	}
	void dibujar(Graphics^ g, Bitmap^ bmpEnemigo, int** matriz)
	{
		for (int i = 0; i < arrEnemigo.size(); i++)
		{
			arrEnemigo.at(i)->dibujar(g, bmpEnemigo, matriz);
			arrEnemigo.at(i)->animar();

		}
	
	}
	vector<CEnemigo *> getenemigo() {
		return arrEnemigo;
	}


	
};