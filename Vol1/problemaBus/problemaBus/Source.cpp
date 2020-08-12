#include<iostream>
typedef unsigned long us;

#include<string>
#include<time.h>

#include<random>
#include"combustible.h"
#include"Surtidor.h"
#include"Sucursal.h"
#include"Cliente.h"
#include"Clientes.h"
#include"Autoh.h"
using namespace std;
int main() {

	srand(time(NULL));
	/*Surtidor nueSurtidor=Surtidor();
	Combustible nueocomb= Combustible();
	Sucursal nuevasucursal;

	nuevasucursal.Añadirclases(&nueSurtidor,&nueocomb);
	cout<<nuevasucursal.MOstrarResultados();*/
	Auto* nue;
	Cliente *nuevoCLiente;
	Clientes arreglo;
	int opcion;
	while (1) {
		cin >> opcion;
		switch (opcion)
		{
		case 1:arreglo.agregarCliente(); break;
		case 2:arreglo.mostrarDatosCliente(); break;
		default: cout << "Opcion incorrecta "; break;
		}
	}




	cin.get();
	return 0;
}