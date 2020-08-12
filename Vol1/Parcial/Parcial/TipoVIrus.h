#pragma once
#include<string>
using namespace std;

class Virus {
private:

	string nombre;

public:
	Virus() {}

	void setNAme(string _name) { nombre = _name; }
	string getname() { return nombre; }



};