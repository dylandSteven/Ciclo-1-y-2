#pragma once
#include"Primitiva.h"
#include<vector>
using namespace std;
using namespace System::Drawing;

class CColeccion
{
public:
	CColeccion() {
		lista = new vector<CPrimitiva^>();

	}
	void generar()
	{
		for(int i =0;i<rand()%21+5;++i)
		{
			lista->push_back(new CPrimitiva());
		}
	}

	void dibujarPrimitivas(Graphics^ lienzo)
	{
		for (int i = 0; i < lista->size(); ++i)
		{
			lista->at(i)->dibujar(lienzo);
		}
	}

	bool colision(Rectangle r1) {

		bool band = false;
		CPrimitiva* tmp;
		for (int i = 0; i < lista->size(); ++i)
		{
			tmp = lista->at(i);
			Rectangle r2(tmp->getX(), tmp->getY(), tmp->getAncho();tmp->getAlto())
				if (r2.IntersectsWith(r1)) {

					lista->erase(lista->begin() + i);
					band = true;
			}
		}
		return band;

	}

	int cantidad() {
		return lista->size();
	}
	~CColeccion() {
		lista->clear();
		delete lista;
	}
private:
	vector<CPrimitiva^>^ lista;


}