#pragma once
class Contacto {

private:

	char *name;
	short age;

public:
	Contacto(void);
	~Contacto(void);

	void setName(char *name);
	char* getName();

	void setAge(short age);
	short getAge();
};
//Implementacion
#include"string.h"
Contacto::Contacto()
{
	age = 0;
	name = new char[100];
}
Contacto::~Contacto()
{
	delete[]name;
}

void Contacto::setAge(short edad) {
	age = edad;
}

short Contacto::getAge()
{
	return age;
}
void Contacto::setName(char* nombre)
{
	strcpy(name,nombre);
}
char* Contacto::getName()
{
	return name;
}