#pragma once
#include <iostream>
#include <string>

using namespace std;
class Hora{
private:
	int hora;
	int minuto;
	int segundo;
public:
	Hora() {
		hora = rand() % 24;
		minuto = rand() % 61;
		segundo = rand() % 61;
		}

	~Hora() {}

	int getHora() { return hora; }
	int getminutos() { return minuto; }
	int getSegundo() { return segundo; }


	string getHoraCompleta() {
		string aux;
		aux.append(to_string(hora));
		aux.append(":");
		aux.append(to_string(minuto));
		aux.append(":");
		aux.append(to_string(segundo));
		return aux;
	}
};