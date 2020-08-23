#include<iostream>
#include<time.h>
#include"Header.h"

using namespace std;

int main() {
	srand(time(NULL));
	
	Contrasena* arreglo = new Contrasena(15);
	cout << arreglo->getContrasena() << endl;
	if (arreglo->isSafe()) {
		cout << "Es seguro " << endl;
	}
	else {
		cout << "No es seguro ";
	}
	cin.get();

	return 0;
}