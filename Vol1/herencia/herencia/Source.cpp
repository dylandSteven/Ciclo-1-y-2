#include<iostream>
#include"Animal.h"
#include"Gato.h"
#include"Perro.h"

using namespace std;

int main() {
	Perro* p1 = new Perro("sfsfsfsf", 10);
	Animal* a1 = p1;
	a1->sonido();

	cin.get();
		cin.ignore();

		delete p1;
	return 0;
}
