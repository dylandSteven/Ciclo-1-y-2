#pragma once
#include"Vehiculo.h"

class VehiculoAereo :public Vehiculo
{

public:
	VehiculoAereo(int, int);
	~VehiculoAereo();
};

VehiculoAereo::VehiculoAereo(int _filas, int _columnas) :Vehiculo(_filas, _columnas)
{}

VehiculoAereo::~VehiculoAereo(void)
{}