#pragma once
using namespace std;
#include<iostream>
#include<string>

class Fecha {

private:
	int dia;
	int anho;
	int mes;

public:
	Fecha() {
		dia = rand() % 31;
		mes = rand() % 13;
		anho = rand() % 20;
	}

	~Fecha() {}

	int getdia() { return dia; }
	int getanho() { return anho;}
	int getmes() { return mes; }


	string getFechaCompleta() {
		string aux;
		aux.append(to_string(dia));
		aux.append("/");
		aux.append(to_string(mes));
		aux.append("/");
		aux.append(to_string(anho));
		return aux;
	}
};