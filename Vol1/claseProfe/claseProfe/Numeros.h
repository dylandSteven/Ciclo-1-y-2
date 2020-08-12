#pragma once
#include<vector>
using namespace std;

class Numeros
{
private :
	vector<int>numeros;
public:
	void insertar(int o) {
		numeros.push_back(o);
	}

	int recuperar(int pos)
	{
		if (pos >= 0 && pos < numeros.size()) {
			return numeros[pos];
		}
	}


	int contar(int o) {
		int cont=0;
		for (int i = 0; i < numeros.size(); i++)
		{
			if (o == numeros[i]) {
				cont++;
			}		
		}
		return cont;
	}

	void eliminar(int pos) {
		if (pos >= 0 && pos < numeros.size())
		{
			numeros.erase(numeros.begin() + pos);
		}
	}

	void limpiar()
	{
		numeros.clear();
	}
	void modificar(int pos, int val) {

		if (pos >= 0 && pos < numeros.size())
			numeros[pos] = val;
	}

	void ordenar() {
		int aux;
		for (int i = 0; i < numeros.size(); i++) {
			for (int j = 0; j < numeros.size(); j++) {
				if (numeros[i] > numeros[j]) {
					aux = numeros[i];
					numeros[i]=numeros[j];
					numeros[j] = aux;
				}
			}
	    }
	}

	int cantidad()
	{
		return numeros.size();
	}




};