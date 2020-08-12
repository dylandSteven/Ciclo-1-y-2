#pragma once
#include"Mejora.h"
#include<vector>
using namespace std; 
class arrMejoras 
{

private:
	vector<CMejora*>vectorMejora;

public:

	arrMejoras() {}
	~arrMejoras() {}
	void agregarMejora()
	{
		CMejora* nuevaMejora = new CMejora();
		vectorMejora.push_back(nuevaMejora);
	}

	void dibujar(Graphics ^g, Bitmap^bmpMejoras, int **matriz)
	{
		for (int i = 0; i < vectorMejora.size(); i++)
		{
			vectorMejora.at(i)->dibujar(g, bmpMejoras, matriz);
			vectorMejora.at(i)->animar();
		
		}
	}
	vector<CMejora*>getVectorMejoras()
	{
		return vectorMejora;
	}
	void eliminarenpos(int pos)
	{
		vectorMejora.erase(vectorMejora.begin() + pos);
	
	}

};