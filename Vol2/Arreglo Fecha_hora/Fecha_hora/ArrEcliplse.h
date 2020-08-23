#pragma once
#include"Fecha.h"
#include"Hora.h"
#include"Eclipse.h"
#include<iostream>
#include <string>
#include <vector>

using namespace std;

class arrfecha {

private:
	vector<Eclipse*>newEclipse;

public:
	arrfecha() {}
	~arrfecha() {}

	void AgregarEclipse()
	{
		Eclipse* aux = new Eclipse();
		newEclipse.push_back(aux);
	}

	void InsertarEclipse(int posicion)
	{
		Eclipse* aux = new Eclipse();
		newEclipse.insert(newEclipse.begin() + posicion, aux);
		
	}
	void Elimimnar(int posicion)
	{
		newEclipse.erase(newEclipse.begin() + posicion);
	}

	void Modificar(int posicion, string valor) 
	{
		newEclipse.at(posicion)->setTipo(valor);
	}

	void MostrarEclipse()
	{
		for (int i = 0; i < newEclipse.size(); i++)
		{
			newEclipse[i]->MostrarInfo();
	}
	}

	void EclipseEuropeo()
	{
		for (int i = 0; i < newEclipse.size(); i++)
		{
			if (newEclipse[i]->getVisibilidad() == "Europa")
			{
				newEclipse[i]->MostrarInfo();

			}
		}
	}

	void EclipseENNoche()
	{
		for (int i = 0; i < newEclipse.size(); i++)
		{
			if (newEclipse[i]->getHoora().getHora() >= 18)
			{
				newEclipse[i]->MostrarInfo();
			}
		}

	}
	void eclipseSismo() 
	{
		for (int i = 0; i < newEclipse.size(); i++) {

			if (newEclipse[i]->getSismo() == "SI") {

				newEclipse[i]->MostrarInfo();

			}

		}
	}


};