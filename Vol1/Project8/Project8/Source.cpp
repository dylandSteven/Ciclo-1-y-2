#include<iostream>
using namespace std;

int menu() {

	int opcion;
	do {
		system("cls");
		cout << "\n\tMENU";
		cout << "\n1.- Listar Elementos";
		cout << "\2.-Agregar al final";
		cout << "\n3.-Eliminar en posicion";
		cout << "\n4.-Agregar al inicio";
		cout << "\n5.Ordenar";
		cout << "\nIngrese la opcion: "; cin >> opcion;

	} while (opcion > 5 || opcion < 1);
	return opcion;
}


void listarElementos(int* pntr, int* t) {

	if (pntr != nullptr) {
		for (int i = 0; i < *t; i++) {
			cout << "\n" << pntr[i];
		}
	}
	else {
		cout << "El arreglo esta vacio";
	}
	cin.ignore();
	cin.get();
}

int* agregarFinal(int* pntr, int* t, int elemento) {

	int* temporal = new int[*t + 1];

	for (int i = 0; i < *t; i++) {
		temporal[i] = pntr[i];
	}
	temporal[*t] = elemento;
	*t = *t + 1;
	return temporal;
}

int* agregarInicio(int* pntr, int* t, int elemento) {
	int* temporal = new int[*t + 1];
	temporal[0] = elemento;
	*t = *t + 1;

	if (pntr != nullptr) {
		for (int i = 0; i < *t; i++) {
			temporal[i + 1] = pntr[i];
		}
	}
	return temporal;

}

int* eliminarPOsicion(int* pntr, int* t, int elemento) {

	int* temporal = new int[*t - 1];
	int k=0;
	for (int i = 0; i < *t; i++) {
		if (i != elemento) {
			temporal[k] = pntr[i];
			++k;
		}
	}
	*t = *t - 1;
	return temporal;
}

void ordenar(int* ptrn, int* t) {

	int aux;

	for (int i = 0; i < *t - 1; i++) {

		for (int j = i + 1; j < *t ; j++) {
			if (ptrn[i] > ptrn[j]) {

				aux = ptrn[i];
				ptrn[i] = ptrn[j];
				ptrn[j] = aux;

			}
		}
	}
}


int main() {

	int* puntero;
	puntero = nullptr;
	int* tam = new int;
	*tam = 0;
	int op;
	while (1) {
		
		op = menu();
		if (op == 1) {
			listarElementos(puntero, tam);
		}
		if (op == 2) {
			int elemento;
			cout << "\nIngrese elemento: "; cin >> elemento;
			puntero = agregarFinal(puntero, tam, elemento);
		}
		if (op == 3) {
			int pos;
			cout << "\nINgrese posicion a eliminar: "; cin >> pos;
			puntero = eliminarPOsicion(puntero, tam, pos);
		}
		if (op == 4) {
			int elemento;
			cout << "\nIngrese el elemento: "; cin >> elemento;
			puntero = agregarInicio(puntero, tam, elemento);
		}
		if (op == 5) {

			ordenar(puntero, tam);
			cin.ignore();
				cin.get();

		}
		
		}
	return 0;
}
