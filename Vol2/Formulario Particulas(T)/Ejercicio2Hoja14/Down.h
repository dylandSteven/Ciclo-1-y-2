#pragma once
#include "Particula.h"

class Down : public Particula
{
public:
	Down() : Particula()
	{
		radio = 15;
		tipo = DOWN;
	}
	void Mostrar(Graphics^ g)
	{
		g->FillEllipse(Brushes::Blue, Area());
		g->FillEllipse(Brushes::Red, Area2());
		g->DrawString("D", gcnew Font("Consolas", 12), Brushes::White, x - 8, y - 8);
	}
};