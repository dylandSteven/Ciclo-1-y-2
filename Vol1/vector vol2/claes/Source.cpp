#include"Cliente.h"
#include<vector>
#include<iostream>

using namespace std;

	vector<Cliente>*arrr;
void agregarCliente() {
string nombre;
	short edad;
	cout << "Nombre: "; cin>>nombre;
	cout << "Edad: "; cin >> edad;
	Cliente pC(nombre, edad);
	arrr[0].push_back(pC);
}

void mostrarClientes() {

	for (int i = 0; i < arrr->size(); i++)
	{
		cout << i + 1<<endl;
		cout << arrr[0].at(i).mostrar();
	}


}

void eliminar() {
	int numero;
	cin >> numero;
	for (int i = 0; i < arrr->size(); i++) {
	
		if (numero == i) {
			arrr[0].erase(arrr[0].begin()+i-1);
		}
	}
}




int main() {
	arrr = new vector<Cliente>;
	int opcion;
	while (1) {
		cin >> opcion;
		switch (opcion) {
		case 1:agregarCliente(); break;
		case 2:mostrarClientes(); break;
		case 3:eliminar(); break;
		}
	}


}