#pragma once
#include "Down.h"
#include "Up.h"

class LHC
{
	Particulas* particulas;
	int cant_protones;
	int cant_neutrones;
public:
	LHC()
	{
		particulas = new Particulas();
		cant_protones = cant_neutrones = 0;
	}
	~LHC()
	{
		delete particulas;
	}

	int GetProtones()
	{
		return cant_protones;
	}
	int GetNeutrones()
	{
		return cant_neutrones;
	}

	void Colisiones()
	{
		for (int i = 0; i < particulas->GetCantidad(); i++)
			for (int j = i + 1; j < particulas->GetCantidad(); j++)
				for (int k = j + 1; k < particulas->GetCantidad(); k++)
				{
					Particula* I = particulas->Get(i);
					Particula* J = particulas->Get(j);
					Particula* K = particulas->Get(k);

					if (I->Area2().IntersectsWith(J->Area2()) && I->Area2().IntersectsWith(K->Area2()) && K->Area2().IntersectsWith(J->Area2()))
					{
						int disponible = I->GetEnlace() + J->GetEnlace() + K->GetEnlace();

						if (disponible == 0)
						{
							int up = I->GetTipo(UP) + J->GetTipo(UP) + K->GetTipo(UP);
							int down = I->GetTipo(DOWN) + J->GetTipo(DOWN) + K->GetTipo(DOWN);

		
							if (up == 2 && down == 1)
								cant_protones++;
							if (up == 1 && down == 2)
								cant_neutrones++;

							if ((up == 2 && down == 1) || (up == 1 && down == 2))
							{
								int dx = I->GetDX() + J->GetDX() + K->GetDX();
								int dy = I->GetDY() + J->GetDY() + K->GetDY();

								I->SetDX(dx); J->SetDX(dx); K->SetDX(dx);
								I->SetDY(dy); J->SetDY(dy); K->SetDY(dy);

								I->SetEnlace(true); J->SetEnlace(true); K->SetEnlace(true);
							}

						}
					}
				}
	}
	void Mover(Graphics^ g)
	{
		Colisiones();
		if (true)
		{
			if (rand() % 2 == 0)
				particulas->AgregarElemento(new Up());
			else
				particulas->AgregarElemento(new Down());
		}

		particulas->Mover(g);
	}
	void Mostrar(Graphics^ g)
	{
		particulas->Mostrar(g);
	}
};