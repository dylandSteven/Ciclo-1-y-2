#include<iostream>
#include"Pacuientes.h"
#include"TipoVIrus.h";
using namespace std;
#include"Robot.h"
void Menu() 
{
	cout << "    Menu   " << endl;
	cout << "===========" << endl;;
	cout << "[1]SARS-COV" << endl;
	cout << "[2]MERS-COV" << endl;
	cout << "[3]COVID-19" << endl;
	cout << "[4]REPORTE TOTAL" << endl;
	cout << "[5]SALIR" << endl;
}

int main()
{
	Robot nuro;
	vector<Paciente*> arrPacientes;
	Paciente pac;
	Virus nuevo;
	string nombe;
	int opcion;
	char segundoresultado;
	short cont1=0, cont2=0, cont3=0;
	short edad;



	do {
		system("cls");
		Menu();
		cin >> opcion;


		if (opcion == 1) {
			nuro.opcion1();


		}

		if (opcion == 2) {
			nuro.opcion2();

		}

		if (opcion == 3) {
			nuro.opcion3();
		}

		if (opcion == 4) {
		
			nuro.opcion4();
		
		
		}

	} while (!(opcion == 5));
	cin.get();

}