#pragma once
#include<vector>
#include "Header.h"
using namespace std;
class arregloProductos
{
public:
	arregloProductos();
	~arregloProductos();
	void insertar(Producto* p);
	Producto* recuperar(short pos);
	void eliminarPosicion(short pos);


private:
	vector<Producto*>lista;
};

