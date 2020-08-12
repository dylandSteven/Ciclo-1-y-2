#pragma once
#include<iostream>
#include<string>
#include"Animal.h"
using namespace std;

class Gato:public Animal {

private:

public:
	string especie="Mamifero";
	Gato(string razas, int dulzure):Animal(razas , dulzure) {
			}
	~Gato() {}

	void sonido() {
		cout << "Miau Miau" << endl;
	}

};