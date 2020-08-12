#pragma once
#include<iostream>
using namespace std;

#include<string>
#include<time.h>
#include<iostream>
#include<random>
#include"combustible.h"


class Surtidor {

protected:
	int numero;
	Combustible nuevoComb ;

public:

	Surtidor() {}

	void usarCombustible(Combustible _nuevoComb) { nuevoComb = _nuevoComb; }
	int getNumero() {
		numero = 1+rand() % (9-1);
		return numero;
	}
};