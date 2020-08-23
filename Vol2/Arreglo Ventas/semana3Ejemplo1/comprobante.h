#pragma once
#include"arregloPro.h"

class comprobante
{
public:
	comprobante();
	comprobante(char*fecha,arregloProductos *detalle);
	~comprobante();
	char* getFecha();
	arregloProductos* getDetalle();
private:
	char* fecha;
	arregloProductos* detalle;

};
