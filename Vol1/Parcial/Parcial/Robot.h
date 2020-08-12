#pragma once
#include<vector>
using namespace std;

#include"Pacuientes.h"
#include"TipoVIrus.h"
class Robot {

private :




short 	opcion;
vector<Paciente*> arrPacientes;
Paciente pac;
Virus nuevo;
string nombe;
int opciones;
char segundoresultado;
short cont1 = 0, cont2 = 0, cont3 = 0;
short edad;


public :


	Robot() {}
	
	void opcion1() {

		opcion = 1;
		if (opcion == 1) {
			nuevo.setNAme("SARSCOV");
			cout << "Ingrese nombre de paciente: "; cin >> nombe;
			pac.setNombre(nombe);
			pac.VerificarSintomas();
			cout << "¿Tiene Escalofríos, dolores musculares,dolor de cabeza y, ocasionalmente, diarrea?";
			cin >> segundoresultado;
			cout << "¿Que edad tiene?";
			cin >> edad;
			pac.setEdad(edad);
			cout << pac.getNombre();

			if (pac.getContador() == 1 && segundoresultado == 'S') {
				cout << pac.getNombre() << endl;
				cout << "Tiene: " << nuevo.getname() << endl << endl;;
				cout << "<Se propaga a traves de gotitas cuando tose>" << endl;
				cout << "<Debe de Internarse>";
				cont1++;
			}
			else {

				cout << pac.getNombre() << endl;
				cout << "No Tiene: " << nuevo.getname();
			}
			pac = Paciente(nombe, edad);
			arrPacientes.push_back(&pac);
			cin.ignore();
			cin.get();
		}

	}



	void opcion2() {
		opcion = 2;
		if (opcion == 2) {
			nuevo.setNAme("MERSCOV");
			cout << "Ingrese nombre de paciente: "; cin >> nombe;
			pac.setNombre(nombe);
			pac.VerificarSintomas();
			cout << "¿Tiene problemas gastrointestinales(diarrea) ?";
			cin >> segundoresultado;
			cout << "¿Que edad tiene?";
			cin >> edad;
			pac.setEdad(edad);
			cout << pac.getNombre();

			if (pac.getContador() == 1 || pac.getContador() == 0 || segundoresultado == 'S') {
				cout << pac.getNombre() << endl;
				cout << "Tiene: " << nuevo.getname() << endl << endl;;
				cout << "<Algunos casos son asintomaticos>" << endl;
				cout << "<Debe de Internarse>";
				cont2++;
			}
			else {

				cout << pac.getNombre() << endl;
				cout << "No Tiene: " << nuevo.getname();
				cout << "Deberia aislarse Algunos casos son asintomaticos";
			}
			pac = Paciente(nombe, edad);
			arrPacientes.push_back(&pac);
			cin.ignore();
			cin.get();
		}
	}

	void opcion3() {
		opcion = 3;
		if (opcion == 3) {
			nuevo.setNAme("COVID19");
			cout << "Ingrese nombre de paciente: "; cin >> nombe;
			pac.setNombre(nombe);
			pac.VerificarSintomas();
			cout << "¿Tiene Escalofríos, dolores musculares,dolor de cabeza y, ocasionalmente, diarrea?";
			cin >> segundoresultado;
			cout << "¿Que edad tiene?";
			cin >> edad;
			pac.setEdad(edad);
			cout << pac.getNombre();

			if (pac.getContador() == 1 && segundoresultado == 'S' && edad > 60) {
				cout << pac.getNombre() << endl;
				cout << "Tiene: " << nuevo.getname() << endl << endl;;
				cout << "<Debe aislarse>" << endl;
				cout << "<Paciente de alto riesgo>";
				cont3++;
			}
			else {

				cout << pac.getNombre() << endl;
				cout << "No Tiene: " << nuevo.getname();
			}
			pac = Paciente(nombe, edad);
			arrPacientes.push_back(&pac);
			cin.ignore();
			cin.get();

		}
	}


	void opcion4(){
		opcion = 4;
		if (opcion == 4) {
			cout << "Reporte total " << endl;
			cout << "SARS-CoV" << "\t";
			cout << cont1;
			cout << endl;
			cout << "MERS-CoV" << "\t";
			cout << cont2;
			cout << endl;
			cout << "COVID-19" << "\t";
			cout << cont3;
			cout << endl;
			cin.ignore();
			cin.get();

		}
	}





};