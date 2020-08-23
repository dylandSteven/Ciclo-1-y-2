#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include"arreglo.h"
using namespace std;
int main() {

	Arreglo* nuevo = new Arreglo();

	short opcion;

	do {
		cin >> opcion;
		switch (opcion)
 		{
		case 1:nuevo->Registrar(); break;
		case 2:nuevo->mostrar(); break;
		}
		} while (!(opcion == 3));
	}



