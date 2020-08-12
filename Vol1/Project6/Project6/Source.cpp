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


void listarElementos(int* pntr,int *t ) {

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

int* agregarFinal(int* pntr, int* t,int elemento) {
	   
	int *temporal = new int[*t + 1];
	
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

int* eliminarPOsicion(int*pntr,int *t,int elemento) {

	int* temporal = new int[*t - 1];
	
	for (int i = 0, int k=0; i < *t; i++) {
		if (i != elemento) {
			temporal[k] = pntr[i];
			k++;
		}
		}
	*t = *t - 1;
  return temporal;
	}

void ordenar(int* ptrn, int* t) {

	int aux;

	for (int i = 0; i < *t-1; i++) {

		for (int j = i + 1; j < *t + 1; j++) {
			if (ptrn[i]>ptrn[j]) {

				aux = ptrn[i];
				ptrn[i] = ptrn[j];
				ptrn[j] = aux;

			}
		}
	}

	for (int i = 0; i < *t; i++) {
		cout << ptrn[i] << "  ";
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

		switch (op)
		{
		case 1: {listarElementos(puntero,tam);

			}break;
		case 2: {
			int elemento;
			cout<<"Escuibir el elemento ";
			cin >> elemento;
				agregarFinal(puntero, tam,elemento);
}break;
			case 3: {
				int elemento;
				cout << "Escuibir el elemento ";
				cin >> elemento;

				eliminarPOsicion(puntero, tam, elemento);

}
				  break;
			case 4: {

				int elemento;
				cout << "Escuibir el elemento ";
				cin >> elemento;
				agregarInicio(puntero, tam, elemento);

}break;
			case 5: {

				int elemento;
				cout << "Escuibir el elemento ";
				cin >> elemento;
				ordenar(puntero, tam);

}break;

		default:
			break;
		}

	}

	
	return 0;
}
