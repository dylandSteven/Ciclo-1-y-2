#pragma once
#include "Particula.h"

class Neutron : public Particula
{
public:
	Neutron() : Particula()
	{
		radio = 20;
		tipo = NEU;
	}
	void Mover(Graphics^ g)
	{
		g->FillEllipse(Brushes::Violet, Area());
	}
};