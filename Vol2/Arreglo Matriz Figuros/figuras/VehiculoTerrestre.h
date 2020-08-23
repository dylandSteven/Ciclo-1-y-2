#pragma once
#include"Vehiculo.h"

class VehiculoTerrestre :public Vehiculo
{

public:
	VehiculoTerrestre(int, int);
	~VehiculoTerrestre();
};

VehiculoTerrestre::VehiculoTerrestre(int _filas, int _columnas):Vehiculo(_filas,_columnas)
{}

VehiculoTerrestre::~VehiculoTerrestre(void)
{}