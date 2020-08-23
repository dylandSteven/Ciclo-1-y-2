#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Header.h"

using namespace std;

int main() {
	srand(time(NULL));
	int index = 0;
	int* arr = new int[30];

	cout << "Arreglo " << endl;
	generateData(arr, index);
	printArray(arr, index);

	cout << endl << endl;
	cout << "Arreglo Ordenado: " << endl;
	sort(arr);
	printArray(arr, index);

	cout << endl << endl;
	cout << "Numeros repetidos: " << endl;
	countNumbers(arr);



}