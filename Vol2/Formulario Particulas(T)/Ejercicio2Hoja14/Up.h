#pragma once
#include "Particula.h"

class Up : public Particula
{
public:
	Up() : Particula()
	{
		radio = 10;
		tipo = UP;
	}
	void Mostrar(Graphics^ g)
	{
		g->FillEllipse(Brushes::Yellow, Area());
		g->FillEllipse(Brushes::Green, Area2());
		g->DrawString("U", gcnew Font("Consolas", 8), Brushes::White, x - 5, y - 5);
	}
};