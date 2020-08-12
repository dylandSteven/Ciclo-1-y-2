#pragma once
#include<vector>
#include "Bomba.h"
using namespace std;
class ArregloBomba 
{
private:
	vector<CBomba*>arregloBombas;
	int totalBombas;

public:
	ArregloBomba() {
		//arregloBombas = vector<CBomba*>();
		
		totalBombas = 1; }

	~ArregloBomba() {}

	void crearBomba(int x, int y) {

		if (arregloBombas.size() < totalBombas) {
			CBomba* nuevaBomba = new CBomba(x, y);
			arregloBombas.push_back(nuevaBomba);
			//totalBombas++;
		}	
	}
	vector<CBomba*>getArregloBombas() 
	{
		return arregloBombas;
	}

	void dibujarBomba(Graphics ^g, Bitmap ^bmpBomba, Bitmap^bmpExplosion, int xJugador, int yJugador,int **matriz)
	{
		for (int i = 0; i < arregloBombas.size(); i++)
		{
			switch (arregloBombas.at(i)->getEstado())
			{
			case Estado::normal:
				arregloBombas.at(i)->dibujarBomba(g,bmpBomba,xJugador,yJugador,matriz);
				arregloBombas.at(i)->animarBomba();
				break;


			case Estado::explosion:

				arregloBombas.at(i)->DibujarExplosion(g, bmpExplosion,matriz);
				arregloBombas.at(i)->animarExplosion();
				break;

			case Estado::desaparecer:
				arregloBombas.erase(arregloBombas.begin() + i);
				break;
			}
		
		}
	}
	void setBombas(int bombas)
	{
		totalBombas = bombas;
	}
	int getBombas() { return totalBombas; }


};