#pragma once
#include"Circulo.h"

class ArrCirculo 

{
private:
	int aN;
	Circulo** aVecCirculo;

public:

	ArrCirculo(void);
	~ArrCirculo(void);
	void Agregar(int pPosX, int pPosY);
	void Mover(System::Drawing::Graphics^ pCanvas);

};

ArrCirculo::ArrCirculo(void)
{
	aN = 0;
	aVecCirculo = new Circulo * [aN];

}
ArrCirculo::~ArrCirculo(void)
{}

void ArrCirculo::Agregar(int pPosX, int pPosY) 
{
	System::Random^ r = gcnew System::Random();

	Circulo** oTemp = new Circulo * [aN + 1];

	for (int i = 0; i < aN; i++)
		oTemp[i] = aVecCirculo[i];

	oTemp[aN] = new Circulo(pPosX, pPosY, r->Next(1, 4), r->Next(1, 4),
		r->Next(10, 60), 0, aN);

	aN++;

	if (aVecCirculo != nullptr)
		delete[]aVecCirculo;
	aVecCirculo = oTemp;

}
void ArrCirculo::Mover(System::Drawing::Graphics^ pCanvas)
{
	for (int i = 0; i < aN; i++) {
		aVecCirculo[i]->mover(pCanvas);
		aVecCirculo[i]->dibujar(pCanvas);
	}
}