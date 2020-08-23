#pragma once
#include<iostream>
#include"Ingrediente.h"
#include<vector>
using namespace std;

class Pastel {
private :
	string Nombre;
	int CantidadPersona;
	int Precio;
	vector<Ingredientes*>ListaIngredientes;
public:
	Pastel(string Nombre ,int CantidadPersona, int Precio) 
	{
		this->Nombre = Nombre;
		this->CantidadPersona = CantidadPersona;
		this->Precio=Precio;
	}
	~Pastel() {}

	void AgregarIngredientes(Ingredientes *i){
		ListaIngredientes.push_back(i);
	}
	int  CantidadIngredientes()
	{
		return ListaIngredientes.size();
	}
	int CaloriasTotalesPastel() 
	
	{
		int aux=0;

		for (int i = 0; i < ListaIngredientes.size(); i++)
		{
			aux += ListaIngredientes[i]->CaloriasDELIngrediente();

		}
		return aux;
	}

};
