#include"comprobante.h"


comprobante::comprobante()
{
	fecha = new char[12];
	detalle = new arregloProductos();
}
comprobante::comprobante(char* fecha, arregloProductos* detalle)
{
	this->fecha = fecha;
	this->detalle = detalle;
}

comprobante::~comprobante()
{
}
char* comprobante::getFecha() { return fecha; }
arregloProductos* comprobante::getDetalle(){ return detalle; }
