#pragma once
#include<string>
#include<cstdlib>
#include<iostream>
using namespace std;
class Fecha {

private:

	int dia, mes, anho;
public:

	Fecha() {
		dia = rand() % 31;
		mes = rand() % 13;
		anho = 1950 + rand() % 70;
	}
	~Fecha() {}
	int getdia() { return dia;}
	int getmes() { return mes;}
	int getanho() { return anho;}

	
	string toString() {
		string aux;
		aux.append(to_string(dia));
		aux.append("/");
		aux.append(to_string(mes));
		aux.append("/");
		aux.append(to_string(anho));
		return aux;
	}
};