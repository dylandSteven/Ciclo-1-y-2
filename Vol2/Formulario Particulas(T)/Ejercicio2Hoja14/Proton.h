#pragma once
#include "Particula.h"

class Proton : public Particula
{
public:
	Proton() : Particula()
	{
		radio = 30;
		tipo = PROT;
	}
	void Mover(Graphics^ g)
	{
		g->FillEllipse(Brushes::Orange, Area());
	}
};