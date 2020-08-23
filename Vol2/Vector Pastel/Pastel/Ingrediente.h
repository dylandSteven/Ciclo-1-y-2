#pragma once
#include<string>
using namespace std;


//string Peso[3]{ "Gramos","Litros","Kg" };

class Ingredientes {
private:
	string nombre;
	string UnidadMedida;
	int cantidad;
	int CalxPorcion;

public:
	Ingredientes(string nombre,string peso,int cantidad, int otroDato) {
		this->nombre = nombre;
		UnidadMedida =peso ;
		this->cantidad=cantidad;
		 CalxPorcion= otroDato;
	}
	~Ingredientes() {}
	int CaloriasDELIngrediente()
	{

		int aux;
		aux = cantidad * CalxPorcion;
		return aux;

	}
};