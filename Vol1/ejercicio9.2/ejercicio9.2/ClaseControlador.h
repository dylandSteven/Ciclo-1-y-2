#pragma once
#include"Figura.h"
class Controladora {
private : 
	Figura fig1;
	Figura fig2;
public:
	Controladora(Figura fig1, Figura fig2) {
		this->fig1 = fig1;
		this->fig2 = fig2;
	}
	void colision() {
		if (fig1.getX() == fig2.getX()) { }
		if (fig1.getY() == fig2.getY()) {}
	}

};