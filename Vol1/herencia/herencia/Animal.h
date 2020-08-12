#pragma once
#include <iostream>
#include<string>
using namespace std;


class Animal {

protected:
	string raza;
	int dulzura;
public:
	string especie = "Mamifero";
	Animal(string raza, int dulzura) {}
	void setRaza(string r) { raza = r; }
	int getdulzure() { return dulzura; }
	void setDulzura(int d) { dulzura = d; }
	string getraza() { return raza; }
	string getEspecie() { return especie; }
	int getNUmPatas() { return 4; }
	virtual void sonido() {}


};