#pragma once
#include<vector>
using namespace std;


class CNumeros {
	vector<int> enteros;
public:
	void insertar(int o) {
		enteros.push_back(o);
	}
	int recuperar(int p) {
		if (p >= 0 && p < enteros.size())
			return enteros[p];
	}
	int contar(int o) {
		int c = 0;
		for (int i = 0; i < enteros.size(); ++i) {
			if (o == enteros[i])c++;
		}
		return c;
	}
	void eliminar(int p) {
		if (p >= 0 && p < enteros.size())
			enteros.erase(enteros.begin() + p);
	}
	void modificar(int p, int valor) {
		if (p >= 0 && p < enteros.size())
			enteros[p] = valor;
	}
	void ordenar() {
		for (int i = 0; i < enteros.size() - 1; ++i) {
			for (int j = i; j < enteros.size(); ++j) {
				if (enteros[i] > enteros[j]) {
					int t = enteros[i];
					enteros[i] = enteros[j];
					enteros[j] = t;
				}
			}
		}
	}
	void limpiar() { enteros.clear(); }
	int cantidad() { return enteros.size(); }
};