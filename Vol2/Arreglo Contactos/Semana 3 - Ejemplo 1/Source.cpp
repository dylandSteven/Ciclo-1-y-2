#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include "ArregloContacto.h"
using namespace System;
using namespace std;

int menu() {

	int opcion;
	do {
		cout << "MENU" << endl << endl;
		cout << "1.Mostrar Contactos"<<endl;
		cout << "2.Agregar Contactos" << endl;
		cout << "INGRESE OPCION :"; cin >> opcion;
	} while (!(opcion > 0 && opcion < 3));

	return opcion;
}

int main(){

	int op;
	char* nombreCOntacto = new char[20];
	int edadContacto;

	Contacto *objeto;
	ArregloContacto *objArre;

	objArre = new ArregloContacto();


	while (1)
	{
		Console::Clear;
		op = menu();

		if (op == 1) {
			if (objArre->getN() > 0)
			{
				cout << "NOMBRE \t\t EDAD\n";
				for (int i = 0; i < objArre->getN(); i++) {
					objeto = objArre->getContacto(i);

					cout << objeto->getName(); cout << "\t\t";
					cout << objeto->getAge()<< endl;
				}
				cin.ignore();
				cin.get();
			}
			else {
				cout << "El arreglo no tiene datos ";
			}
		}
		if (op == 2) {

			objeto = new Contacto();
			cout << "\nNUEVO CONTACTO\n";
			cin.ignore();
			cout << "Ingrese Nombre: "; cin.getline(nombreCOntacto, 20);
			cout << "Ingrese Edad: "; cin >> edadContacto;

			objeto->setAge(edadContacto);
			objeto->setName(nombreCOntacto);

			objArre->AgregarContacto(objeto);

		}
		cin.get();
	}
	return 0;
}