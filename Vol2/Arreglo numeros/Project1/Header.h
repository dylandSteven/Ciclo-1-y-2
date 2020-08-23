#ifndef   __HEADER_H__
#define   __HEADER_H__
 

#define MAX 10;

using namespace std;

void addNumber(int* arr, int& index, int value) {

	if (index < MAX) {
		arr[index] = value;
		index++;
	}
}

void generateData(int* arr, int& index) {

	for (int i = 0; i < MAX; i++) {
		int random = 1 + rand() % 100 - 1;
		addNumber(arr, index, random);
	}

	void printArray(int* arr, int& index) {

		for (int i = 0; i < index; i++) {
			cout << arr[i] << "  ";
	}
}
	void sort(int* arr)
	{
		for (int i = 0; i < MAX; i++ + ) {
			for (int j = 0; j < MAX; j++) {
				if (arr[j] > arr[i]) {
					int helper;
					helper = arr[j];
					arr[j] = arr[j+ 1];
					arr[j + 1] = helper;
				}
			}

		}
	}

	void countNumbers(int* arr) {
		int cont = 1;

		int* aux = new int[MAX];
		int index2 = 0;
		
		for (int i = 0; i < MAX; i++) {
			if (arr[i] == arr[i + 1]) {
				cont++;
			}
			else {
				if (cont == 1) {
					cont << arr[i] << " se repite " << cont << " vez " << endl
				}
				else {
					cout << arr[i] << " se repite " << cont << " veces." << endl;
					cont = 1;
				}
				addNumber(aux, index2, arr[i]);
			}
		}

		cout << endl;
		cout << "Arreglo sin repetidos " << endl;
		printArray(aux, index2);
	}

#endif // 
