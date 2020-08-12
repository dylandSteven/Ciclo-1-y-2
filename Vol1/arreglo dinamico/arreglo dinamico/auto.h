#pragma once

class Carro

{
public:
	Carro(char* modelo, char* color, double precio,
		int anho,
		double Ps,
		bool lunasPolarizadas) {

		this->modelo = new char[10];
		this->color = new  char[10];
		this->modelo = modelo;
		this->color = color;
		this->precio = precio;
		this->anho = anho;
		this->Ps = Ps;
		this->lunasPolarizadas = lunasPolarizadas;
	}
	~Carro() {}

	char* getmodelo() { return modelo; }
	char* getcolor() { return color; }
	double getprecio() { return precio; }
	int    getanho() { return anho; }
	double getPs() { return Ps; }
	bool   getlunasPolarizadas() { return lunasPolarizadas; }




private:

	char* modelo;
	char* color;
	double precio;
	int anho;
	double Ps;
	bool lunasPolarizadas;
};

